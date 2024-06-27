/*
*  Bananapi specific code borrowed from Bananapi's wiringPi port
*/

/*
 * wiringPi:
 *	Arduino compatable (ish) Wiring library for the Raspberry Pi
 *	Copyright (c) 2012 Gordon Henderson
 ***********************************************************************
 * This file is part of wiringPi:
 *	https://projects.drogon.net/raspberry-pi/wiringpi/
 *
 *    wiringPi is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    wiringPi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with wiringPi.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************
 */

#ifndef SUNXI_H_INCLUDED
#define SUNXI_H_INCLUDED

//
// For Bananapi CM5IO Board
//
#define SUNXI_GPIO_MASK			(0xFFFFFF00)
#define SUNXI_GPIO_BASE			0x0300B000

#define SUNXI_GPIO_PIN_BASE		0
#define SUNXI_GPIO_PIN_END		319

#ifdef DEFINE_SUNXI_VARS

#define SUNXI_INPUT  0 // is really 0 for control register!
#define SUNXI_OUTPUT 1 // is really 1 for control register!

#define SUNXI_PUD_OFF  0
#define SUNXI_PUD_UP   1
#define SUNXI_PUD_DOWN 2

static volatile uint32_t *sunxi_gpio;

/* Non-static add extern definition below */
int sunxi_found;
const int (*bcm_to_sunxigpio)[64];

// pinToGpio:
//	Take a Wiring pin (0 through X) and re-map it to the BCM_GPIO pin
//	Cope for 3 different board revisions here.
//static int *pinToGpio ;
//static int pin_array_count;

// physToGpio:
//	Take a physical pin (1 through 26) and re-map it to the BCM_GPIO pin
//	Cope for 2 different board revisions here.
//	Also add in the P5 connector, so the P5 pins are 3,4,5,6, so 53,54,55,56

//static int *physToGpio ;


static const int pinToGpioBananapiM4Berry[64] = {
	// wiringPi number to native gpio number
	226, 203,	//  0 |  1 : PH2, PG11
	227, 194,	//  2 |  3 : PH3, PG2
	200, 201,	//  4 |  5 : PG8, PG9
	193, 211,	//  6 |  7 : PG1, PG19(PWM1)
	208, 207,	//  8 |  9 : PG16(I2C4_SDA), PG15(I2C4_SCL)
	229, 233,	// 10 | 11 : PH5(SPI1_SS), PH9
	231, 232,	// 12 | 13 : PH7(SPI1_MOSI), PH8(SPI1_MISO)
	230, 198,	// 14 | 15 : PH6(SPI1_CLK), PG6(UART1_TX)
	199,  -1,	// 16 | 17 : PG7(UART1_RX),
	 -1,  -1,	// 18 | 19 :
	 -1, 195,	// 20 | 21 : , PG3
	196, 197,	// 22 | 23 : PG4, PG5
	204, 202,	// 24 | 25 : PG12, PG10
	192, 228,	// 26 | 27 : PG0, PH4
	206, 205,	// 28 | 29 : PG14, PG13
	210, 209,	// 30 | 31 : PG18(I2C3_SDA), PG17(I2C3_SCL)
	// Padding:
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 32...47
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 48...63
};

const int bcmToOGpioBananapiM4Berry[64] = {	// BCM ModE
     -1,  -1, 208, 207, 211, 195, 196, 233, // 0..7
    229, 232, 231, 230, 192, 197, 198, 199, // 8..15
    228, 226, 203, 204, 206, 205, 194, 200, // 16..23
    201, 193, 202, 227,  -1,  -1,  -1,  -1, // 24..31
// Padding:
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 32..39
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 40..47
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 48..55
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1  // 56..63
};

static const int physToGpioBananapiM4Berry[64] = {
	// physical header pin number to native gpio number
	 -1,		//  0
	 -1,  -1,	//  1 |  2 : 3.3V, 5.0V
	208,  -1,	//  3 |  4 : PG16(I2C4_SDA), 5.0V
	207,  -1,	//  5 |  6 : PG15(I2C4_SCL), GND
	211, 198,	//  7 |  8 : PG19, PG6(UART1_TX)
	 -1, 199,	//  9 | 10 : GND(PWM1), PG7(UAR1_RX)
	226, 203,	// 11 | 12 : PH2, PG11
	227,  -1,	// 13 | 14 : PH3, GND
	194, 200,	// 15 | 16 : PG2, PG8
	 -1, 201,	// 17 | 18 : 3.3V, PG9
	231,  -1,	// 19 | 20 : PH7(SPI1_MOSI), GND
	232, 193,	// 21 | 22 : PH8(SPI1_MISO), PG1
	230, 229,	// 23 | 24 : PH6(SPI1_CLK), PH5(SPI1_SS)
	 -1, 233,	// 25 | 26 : GND, PH9
	210, 209,	// 27 | 28 : PG18(I2C3_SDA), PG17(I2C3_SCL)
	195,  -1,	// 29 | 30 : PG3, GND
	196, 192,	// 31 | 32 : PG4, PG0
	197,  -1,	// 33 | 34 : PG5, GND
	204, 228,	// 35 | 36 : PG12, PH4
	202, 206,	// 37 | 38 : PG19, PG14
	 -1, 205,	// 39 | 40 : GND, PG13
	// Not used
	-1, -1, -1, -1, -1, -1, -1, -1,	// 41...48
	-1, -1, -1, -1, -1, -1, -1, -1,	// 49...56
	-1, -1, -1, -1, -1, -1, -1	// 57...63
};

static const int pinToGpioBananapiM4Zero[64] = {
	// wiringPi number to native gpio number
	226, 257,	//  0 |  1 : PH2, PI1
	227, 267,	//  2 |  3 : PH3, PI11
	271, 272,	//  4 |  5 : PI15, PI16
	 66, 268,	//  6 |  7 : PC2, PI12(PWM2)
	262, 261,	//  8 |  9 : PI6(I2C0_SDA), PI5(I2C0_SCL)
	229, 233,	// 10 | 11 : PH5(SPI1_SS), PH9
	231, 232,	// 12 | 13 : PH7(SPI1_MOSI), PH8(SPI1_MISO)
	230, 269,	// 14 | 15 : PH6(SPI1_CLK), PI13(UART4_TX)
	270,  -1,	// 16 | 17 : PI14(UART4_RX),
	 -1,  -1,	// 18 | 19 :
	 -1, 266,	// 20 | 21 : , PI10
	265, 234,	// 22 | 23 : PI9, PH10
	258, 256,	// 24 | 25 : PI2, PI0
	228,  71,	// 26 | 27 : PH4, PC7
	260, 259,	// 28 | 29 : PI4, PI3
	264, 263,	// 30 | 31 : PI8(I2C1_SDA), PI7(I2C1_SCL)
	// Padding:
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 32...47
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 48...63
};

const int bcmToOGpioBananapiM4Zero[64] = {	// BCM ModE
     -1,  -1, 262, 261, 268, 266, 265, 233, // 0..7
    229, 232, 231, 230, 228, 234, 269, 270, // 8..15
    71, 226, 257, 258, 260, 259, 267, 271, // 16..23
    272, 66, 256, 227,  -1,  -1,  -1,  -1, // 24..31
// Padding:
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 32..39
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 40..47
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 48..55
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1  // 56..63
};

static const int physToGpioBananapiM4Zero[64] = {
	// physical header pin number to native gpio number
	 -1,		//  0
	 -1,  -1,	//  1 |  2 : 3.3V, 5.0V
	262,  -1,	//  3 |  4 : PG16(I2C4_SDA), 5.0V
	261,  -1,	//  5 |  6 : PG15(I2C4_SCL), GND
	268, 269,	//  7 |  8 : PG19, PG6(UART1_TX)
	 -1, 270,	//  9 | 10 : GND(PWM1), PG7(UAR1_RX)
	226, 257,	// 11 | 12 : PH2, PG11
	227,  -1,	// 13 | 14 : PH3, GND
	267, 271,	// 15 | 16 : PG2, PG8
	 -1, 272,	// 17 | 18 : 3.3V, PG9
	231,  -1,	// 19 | 20 : PH7(SPI1_MOSI), GND
	232,  66,	// 21 | 22 : PH8(SPI1_MISO), PG1
	230, 229,	// 23 | 24 : PH6(SPI1_CLK), PH5(SPI1_SS)
	 -1, 233,	// 25 | 26 : GND, PH9
	264, 263,	// 27 | 28 : PG18(I2C3_SDA), PG17(I2C3_SCL)
	266,  -1,	// 29 | 30 : PG3, GND
	265, 228,	// 31 | 32 : PG4, PG0
	234,  -1,	// 33 | 34 : PG5, GND
	258,  71,	// 35 | 36 : PG12, PH4
	256, 260,	// 37 | 38 : PG19, PG14
	 -1, 259,	// 39 | 40 : GND, PG13
	// Not used
	-1, -1, -1, -1, -1, -1, -1, -1,	// 41...48
	-1, -1, -1, -1, -1, -1, -1, -1,	// 49...56
	-1, -1, -1, -1, -1, -1, -1	// 57...63
};

#else /* DEFINE_SUNXI_VARS */

extern int sunxi_found;
extern const int (*bcm_to_sunxigpio)[64];

extern const int physToGpioBananapiM4Berry[64];
extern const int bcmToOGpioBananapiM4Berry[64];
extern const int physToGpioBananapiM4Zero[64];
extern const int bcmToOGpioBananapiM4Zero[64];

int wiringPiSetupSunxi (void);
void wiringPiCleanupSunxi (void);
void pinModeSunxi (int pin, int mode);
void pullUpDnControlSunxi (int pin, int pud);
int digitalReadSunxi (int pin);
void digitalWriteSunxi (int pin, int value);
int analogReadSunxi (int pin);
void analogWriteSunxi (int pin, int value);
int pinGetModeSunxi (int pin);
void setInfoSunxi(char *hardware, void *vinfo);
void setMappingPtrsSunxi(void);

#endif /* DEFINE_SUNXI_VARS */

#endif /* SUNXI_H_INCLUDED */
