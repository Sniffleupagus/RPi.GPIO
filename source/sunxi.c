/*
*  Bananapi specific code borrowed from Bananapi's wiringPi port
*/

/*
 * wiringPi:
 *	Arduino compatable (ish) Wiring library for the Raspberry Pi
 *	Copyright (c) 2012 Gordon Henderson
 *	Additional code for pwmSetClock by Chris Hall <chris@kchall.plus.com>
 *
 *	Thanks to code samples from Gert Jan van Loo and the
 *	BCM2835 ARM Peripherals manual, however it's missing
 *	the clock section /grr/mutter/
 ***********************************************************************
 * This file is part of wiringPi:
 *	https://projects.drogon.net/raspberry-pi/wiringpi/
 *
 *    wiringPi is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as
 *    published by the Free Software Foundation, either version 3 of the
 *    License, or (at your option) any later version.
 *
 *    wiringPi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with wiringPi.
 *    If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************
 */

// Revisions:
//	19 Jul 2012:
//		Moved to the LGPL
//		Added an abstraction layer to the main routines to save a tiny
//		bit of run-time and make the clode a little cleaner (if a little
//		larger)
//		Added waitForInterrupt code
//		Added piHiPri code
//
//	 9 Jul 2012:
//		Added in support to use the /sys/class/gpio interface.
//	 2 Jul 2012:
//		Fixed a few more bugs to do with range-checking when in GPIO mode.
//	11 Jun 2012:
//		Fixed some typos.
//		Added c++ support for the .h file
//		Added a new function to allow for using my "pin" numbers, or native
//			GPIO pin numbers.
//		Removed my busy-loop delay and replaced it with a call to delayMicroseconds
//
//	02 May 2012:
//		Added in the 2 UART pins
//		Change maxPins to numPins to more accurately reflect purpose

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/mman.h>

#include "cpuinfo.h"
#define DEFINE_SUNXI_VARS
#include "bananapi.h"
#include "sunxi.h"

/*
int wiringPiFailure (int fatal, const char *message, ...)
{
  va_list argp ;
  char buffer [1024] ;

  if (!fatal && wiringPiReturnCodes)
    return -1 ;

  va_start (argp, message) ;
    vsnprintf (buffer, 1023, message, argp) ;
  va_end (argp) ;

  fprintf (stderr, "%s", buffer) ;
  exit (EXIT_FAILURE) ;

  return 0 ;
}
*/

/*
* Note: Unlike the above code, this is not copied directly from wiringPi
* Much of the code is identical, but un-necessary parts are deleted
*/

int wiringPiSetupSunxi (void)
{
    int fd;

    // Open the master /dev/memory device
    if (access("/dev/gpiomem", 0) == 0)
    {
        if ((fd = open("/dev/gpiomem", O_RDWR | O_SYNC | O_CLOEXEC)) < 0)
            return wiringPiFailure(WPI_ALMOST, "wiringPiSetupSunxi: Unable to open /dev/gpiomem: %s\n", strerror(errno));
    }
    else
    {
        if (geteuid() != 0)
            (void)wiringPiFailure(WPI_FATAL, "wiringPiSetupSunxi: Must be root. (Did you forget sudo?)\n");

        if ((fd = open("/dev/mem", O_RDWR | O_SYNC | O_CLOEXEC)) < 0)
            return wiringPiFailure(WPI_ALMOST, "wiringPiSetupSunxi: Unable to open /dev/mem: %s\n", strerror(errno));
    }


    if (piModel == PI_MODEL_BANANAPIM4BERRY || piModel == PI_MODEL_BANANAPIM4ZERO) {
        sunxi_gpio = (uint32_t *)mmap(0, BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, SUNXI_GPIO_BASE);
        if ((int32_t)sunxi_gpio == -1)
            return wiringPiFailure(WPI_ALMOST, "wiringPiSetupSunxi: mmap (GPIO) failed: %s\n", strerror(errno));
    }

    return 0;
}

void wiringPiCleanupSunxi (void)
{
    munmap((void *)sunxi_gpio, BLOCK_SIZE);
}

/*
 * Sets the mode of a pin to be input, output or PWM output
 *********************************************************************************
 */

void pinModeSunxi (int pin, int mode)
{
    int bank, index, offset, phyaddr, mmap_seek;

    //Sunxi: For our purposes pin comes in as gpio, original code converted
    //pin to gpio and kept origPin as pin#
	
    bank = pin >> 5;
    index = pin - (bank << 5);
    offset = ((index - ((index >> 3) << 3)) << 2);
    phyaddr = (bank * 36) + ((index >> 3) << 2);
    mmap_seek = phyaddr >> 2;

    if (mode == SUNXI_INPUT)
    {
        if (piModel == PI_MODEL_BANANAPIM4BERRY||
            piModel == PI_MODEL_BANANAPIM4ZERO) {
            *(sunxi_gpio + mmap_seek) &= ~(7 << offset);
        }
        else
            wiringPiFailure(WPI_FATAL, "pinModeSunxi: This code should only be called for Bananapi\n");
    }
    else if (mode == SUNXI_OUTPUT)
    {
        if (piModel == PI_MODEL_BANANAPIM4BERRY||
            piModel == PI_MODEL_BANANAPIM4ZERO) {
            *(sunxi_gpio + mmap_seek) &= ~(7 << offset);
            *(sunxi_gpio + mmap_seek) |=  (1 << offset);
        }
        else
            wiringPiFailure(WPI_FATAL, "pinModeSunxi: This code should only be called for Bananapi\n");
    }
}


/*
 * Control the internal pull-up/down resistors on a GPIO pin
 * The Arduino only has pull-ups and these are enabled by writing 1
 * to a port when in input mode - this paradigm doesn't quite apply
 * here though.
 *********************************************************************************
 */

void pullUpDnControlSunxi (int pin, int pud)
{
    int bank, index, offset, phyaddr, mmap_seek;

    bank = pin >> 5;
    index = pin - (bank << 5);
    offset = ((index % 16) << 1);
    phyaddr = (bank * 36) + ((index >> 4) << 2) + 0x1c;
    mmap_seek = phyaddr >> 2;

    if (piModel == PI_MODEL_BANANAPIM4BERRY||
            piModel == PI_MODEL_BANANAPIM4ZERO) {
        *(sunxi_gpio + mmap_seek) &= ~(3 << offset);
        *(sunxi_gpio + mmap_seek) |= (pud & 3) << offset;
    }
    else
        wiringPiFailure(WPI_FATAL, "pullUpDnControlSunxi: This code should only be called for Bananapi\n");
}

/*
 * Read the value of a given Pin, returning HIGH or LOW
 *********************************************************************************
 */

int digitalReadSunxi (int pin)
{
    int bank, index, offset, phyaddr, mmap_seek, retval;

    bank = pin >> 5;
    index = pin - (bank << 5);
    phyaddr = (bank * 36) + 0x10;
    mmap_seek = phyaddr >> 2;

    if (piModel == PI_MODEL_BANANAPIM4BERRY||
            piModel == PI_MODEL_BANANAPIM4ZERO) {
        if (*(sunxi_gpio + mmap_seek) & (1 << index))
            retval = HIGH;
        else
            retval = LOW;
    }
    else
        wiringPiFailure(WPI_FATAL, "digitalReadSunxi: This code should only be called for Bananapi\n");

    return retval;
}

/*
 * Set an output bit
 *********************************************************************************
 */

void digitalWriteSunxi (int pin, int value)
{
    int bank, index, offset, phyaddr, mmap_seek;

    bank = pin >> 5;
    index = pin - (bank << 5);
    phyaddr = (bank * 36) + 0x10;
    mmap_seek = phyaddr >> 2;


    if (piModel == PI_MODEL_BANANAPIM4BERRY||
            piModel == PI_MODEL_BANANAPIM4ZERO) {
        if (value == LOW)
            *(sunxi_gpio + mmap_seek) &= ~(1 << index);
        else
            *(sunxi_gpio + mmap_seek) |= (1 << index);
    }
    else
        wiringPiFailure(WPI_FATAL, "digitalWriteSunxi: This code should only be called for Bananapi\n");
}

/*
 * ead the analog value of a given Pin.
 * here is no on-board Pi analog hardware,
 * so this needs to go to a new node.
 *********************************************************************************
 */

int analogReadSunxi (int pin)
{
    wiringPiFailure(WPI_FATAL, "analogReadSunxi: No ADC pin on Bananapi\n");
}

/*
 * Write the analog value to the given Pin.
 * There is no on-board Pi analog hardware,
 * so this needs to go to a new node.
 *********************************************************************************
 */

void analogWriteSunxi (int pin, int value)
{
    wiringPiFailure(WPI_FATAL, "analogWriteSunxi: No DAC pin on Bananapi\n");
}

/*
 * Gets the mode of a pin to be input, output
 *********************************************************************************
 */

int pinGetModeSunxi (int pin)
{
    int bank, index, offset, phyaddr, mmap_seek, retval;

    bank = pin >> 5;
    index = pin - (bank << 5);
    offset = ((index - ((index >> 3) << 3)) << 2);
    phyaddr = (bank * 36) + ((index >> 3) << 2);
    mmap_seek = phyaddr >> 2;

    if (piModel == PI_MODEL_BANANAPIM4BERRY||
            piModel == PI_MODEL_BANANAPIM4ZERO) {
            retval = (*(sunxi_gpio + mmap_seek) >> offset) & 7;
    }
    else
        wiringPiFailure(WPI_FATAL, "pinGetModeSunxi: This code should only be called for Bananapi\n");

    return retval;
}

void setInfoSunxi(char *hardware, void *vinfo)
{
   rpi_info *info = (rpi_info *)vinfo;

   if (strcmp(hardware, "BPI-M4Berry") == 0)
    {
        piModel = PI_MODEL_BANANAPIM4BERRY;
        info->type = "BPI-M4Berry";
        info->p1_revision = 1;
        info->ram = "2048M/4096M";
        info->manufacturer = "Bananapi";
        info->processor = "AW SUN50IW9";
    }
    else if ((strcmp(hardware, "BPI-M4Zero") == 0) )
    {
        piModel = PI_MODEL_BANANAPIM4ZERO;
        info->type = "BPI-M4Zero";
        info->p1_revision = 3;
        info->ram = "2048M/4096M";
        info->manufacturer = "Bananapi";
        info->processor = "AW SUN50IW9";
    }
    else
        wiringPiFailure(WPI_FATAL, "setInfoSunxi: This code should only be called for Bananapi\n");
   
    return;
}

void setMappingPtrsSunxi(void)
{
    if (piModel == PI_MODEL_BANANAPIM4BERRY)
    {
        pin_to_gpio = (const int(*)[41]) & physToGpioBananapiM4Berry;
        bcm_to_sunxigpio = &bcmToOGpioBananapiM4Berry;
    }
    else if (piModel == PI_MODEL_BANANAPIM4ZERO)
    {
        pin_to_gpio = (const int(*)[41]) & physToGpioBananapiM4Zero;
        bcm_to_sunxigpio = &bcmToOGpioBananapiM4Zero;
    }
}
