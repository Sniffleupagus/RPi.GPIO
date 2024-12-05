/*
 * Bananapi specific code
 */

#ifndef BANANAPI_H_INCLUDED
#define BANANAPI_H_INCLUDED

#define	PI_MODEL_UNKNOWN		0
#define	PI_MODEL_A			1
#define	PI_MODEL_B			2
#define	PI_MODEL_BP			3
#define	PI_MODEL_CM			4
#define	PI_MODEL_AP			5
#define	PI_MODEL_BANANAPIM5		6
#define	PI_MODEL_BANANAPIM2S		7
#define	PI_MODEL_BANANAPICM4		8
#define	PI_MODEL_BANANAPIRPICM4		9
#define	PI_MODEL_BANANAPICM5IO		10
#define	PI_MODEL_BANANAPICM5BPICM4IO	11
#define	PI_MODEL_BANANAPIM4BERRY	12
#define	PI_MODEL_BANANAPIM4ZERO		13
#define	PI_MODEL_BANANAPIM4ZERO_V2	14
#define	PI_MODEL_BANANAPIF3		15

#define AML_SUPPORT
#define SUNXI_SUPPORT
#define SPACEMIT_SUPPORT

#define INPUT  1 // is really 0 for control register!
#define OUTPUT 0 // is really 1 for control register!
#define ALT0   4

#define HIGH 1
#define LOW  0

#define PUD_OFF  0
#define PUD_DOWN 1
#define PUD_UP   2

// Failure modes
#define	WPI_FATAL	(1==1)
#define	WPI_ALMOST	(1==2)

#ifndef	TRUE
#define	TRUE		(1==1)
#define	FALSE		(1==2)
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x)	(sizeof(x) / sizeof((x)[0]))
#endif

#define PAGE_SIZE	(4*1024)
#define BLOCK_SIZE	(4*1024)

#define MAXPINCOUNT	40

extern const int (*pin_to_gpio)[MAXPINCOUNT+1];

#ifdef DEFINE_BANANAPI_VARS
int piModel;
int wiringPiReturnCodes = FALSE ;


/* =======================================================================================
 *
 * Amlogic specific
 *
 * ========================================================================================
 */
#ifdef AML_SUPPORT

#define CM5_GPIO_MASK			(0xFFFFFF00)
#define CM5_GPIO_BASE			0xFE004000

#define CM5_GPIO_PIN_BASE		355

#define CM5_GPIOD_PIN_START       (CM5_GPIO_PIN_BASE + 57)
#define CM5_GPIOD_PIN_END       (CM5_GPIO_PIN_BASE + 69)
#define CM5_GPIOT_PIN_START       (CM5_GPIO_PIN_BASE + 91)
#define CM5_GPIOT_PIN_END       (CM5_GPIO_PIN_BASE + 114)
#define CM5_GPIOY_PIN_START       (CM5_GPIO_PIN_BASE + 129)
#define CM5_GPIOY_PIN_END       (CM5_GPIO_PIN_BASE + 147)

#define CM5_GPIOD_INP_REG_OFFSET		0x030
#define CM5_GPIOD_OUTP_REG_OFFSET		0x031
#define CM5_GPIOD_FSEL_REG_OFFSET		0x032
#define CM5_GPIOD_PUEN_REG_OFFSET		0x033
#define CM5_GPIOD_PUPD_REG_OFFSET		0x034
#define CM5_GPIOD_DS_REG_OFFSET		0x037
#define CM5_GPIOD_MUX_A_REG_OFFSET		0x00A
#define CM5_GPIOD_MUX_B_REG_OFFSET		0x00B

#define CM5_GPIOT_INP_REG_OFFSET		0x070
#define CM5_GPIOT_OUTP_REG_OFFSET		0x071
#define CM5_GPIOT_FSEL_REG_OFFSET		0x072
#define CM5_GPIOT_PUEN_REG_OFFSET    		0x073
#define CM5_GPIOT_PUPD_REG_OFFSET		0x074
#define CM5_GPIOT_DS_REG_OFFSET		0x077
#define CM5_GPIOT_DS_EXT_REG_OFFSET   	0x078
#define CM5_GPIOT_MUX_F_REG_OFFSET   		0x00F
#define CM5_GPIOT_MUX_G_REG_OFFSET		0x010
#define CM5_GPIOT_MUX_H_REG_OFFSET		0x011

#define CM5_GPIOY_INP_REG_OFFSET		0x080
#define CM5_GPIOY_OUTP_REG_OFFSET		0x081
#define CM5_GPIOY_FSEL_REG_OFFSET		0x082
#define CM5_GPIOY_PUEN_REG_OFFSET    		0x083
#define CM5_GPIOY_PUPD_REG_OFFSET		0x084
#define CM5_GPIOY_DS_REG_OFFSET		0x087
#define CM5_GPIOY_DS_EXT_REG_OFFSET   	0x088
#define CM5_GPIOY_MUX_J_REG_OFFSET   		0x013
#define CM5_GPIOY_MUX_K_REG_OFFSET		0x014
#define CM5_GPIOY_MUX_L_REG_OFFSET		0x015

//
// For Bananapi CM4 Board
//
#define CM4_GPIO_MASK			(0xFFFFFF00)
#define CM4_GPIO_BASE			0xff634000
#define CM4_GPIO_AO_BASE		0xFF800000

#define CM4_GPIO_PIN_BASE		410

#define CM4_GPIOH_PIN_START		(CM4_GPIO_PIN_BASE + 17) // GPIOH_0
#define CM4_GPIOH_PIN_END		(CM4_GPIO_PIN_BASE + 25) // GPIOH_8
#define CM4_GPIOA_PIN_START		(CM4_GPIO_PIN_BASE + 50) // GPIOA_0
#define CM4_GPIOA_PIN_END		(CM4_GPIO_PIN_BASE + 65) // GPIOA_15
#define CM4_GPIOX_PIN_START		(CM4_GPIO_PIN_BASE + 66) // GPIOX_0
#define CM4_GPIOX_PIN_MID		(CM4_GPIO_PIN_BASE + 81) // GPIOX_15
#define CM4_GPIOX_PIN_END		(CM4_GPIO_PIN_BASE + 85) // GPIOX_19
#define CM4_GPIOAO_PIN_START		(CM4_GPIO_PIN_BASE + 86) // GPIOAO_0
#define CM4_GPIOAO_PIN_END		(CM4_GPIO_PIN_BASE + 97) // GPIOAO_11

#define CM4_GPIOH_FSEL_REG_OFFSET		0x119
#define CM4_GPIOH_OUTP_REG_OFFSET		0x11A
#define CM4_GPIOH_INP_REG_OFFSET		0x11B
#define CM4_GPIOH_PUPD_REG_OFFSET		0x13D
#define CM4_GPIOH_PUEN_REG_OFFSET		0x14B
#define CM4_GPIOH_DS_REG_3A_OFFSET      	0x1D4
#define CM4_GPIOH_MUX_B_REG_OFFSET      	0x1BB

#define CM4_GPIOX_FSEL_REG_OFFSET		0x116
#define CM4_GPIOX_OUTP_REG_OFFSET		0x117
#define CM4_GPIOX_INP_REG_OFFSET		0x118
#define CM4_GPIOX_PUPD_REG_OFFSET		0x13C
#define CM4_GPIOX_PUEN_REG_OFFSET		0x14A
#define CM4_GPIOX_DS_REG_2A_OFFSET      	0x1D2
#define CM4_GPIOX_DS_REG_2B_OFFSET      	0x1D3
#define CM4_GPIOX_MUX_3_REG_OFFSET      	0x1B3
#define CM4_GPIOX_MUX_4_REG_OFFSET      	0x1B4
#define CM4_GPIOX_MUX_5_REG_OFFSET      	0x1B5

#define CM4_GPIOA_FSEL_REG_OFFSET		0x120
#define CM4_GPIOA_OUTP_REG_OFFSET		0x121
#define CM4_GPIOA_INP_REG_OFFSET		0x122
#define CM4_GPIOA_PUPD_REG_OFFSET		0x13F
#define CM4_GPIOA_PUEN_REG_OFFSET		0x14D
#define CM4_GPIOA_DS_REG_5A_OFFSET      	0x1D6
#define CM4_GPIOA_MUX_D_REG_OFFSET      	0x1BD
#define CM4_GPIOA_MUX_E_REG_OFFSET      	0x1BE

#define CM4_GPIOAO_FSEL_REG_OFFSET		0x109
#define CM4_GPIOAO_OUTP_REG_OFFSET		0x10D
#define CM4_GPIOAO_INP_REG_OFFSET		0x10A
#define CM4_GPIOAO_PUPD_REG_OFFSET		0x10B
#define CM4_GPIOAO_PUEN_REG_OFFSET		0x10C
#define CM4_GPIOAO_DS_REG_A_OFFSET      	0x107
#define CM4_GPIOAO_DS_REG_B_OFFSET      	0x108
#define CM4_GPIOAO_MUX_REG0_OFFSET      	0x105
#define CM4_GPIOAO_MUX_REG1_OFFSET      	0x106

//
// For Bananapi M2S Board
//
#define M2S_GPIO_MASK			(0xFFFFFF00)
#define M2S_GPIO_BASE			0xff634000
#define M2S_GPIO_AO_BASE		0xFF800000

#define M2S_GPIO_PIN_BASE		410

#define M2S_GPIOH_PIN_START		(M2S_GPIO_PIN_BASE + 17) // GPIOH_0
#define M2S_GPIOH_PIN_END		(M2S_GPIO_PIN_BASE + 25) // GPIOH_8
#define M2S_GPIOA_PIN_START		(M2S_GPIO_PIN_BASE + 50) // GPIOA_0
#define M2S_GPIOA_PIN_END		(M2S_GPIO_PIN_BASE + 65) // GPIOA_15
#define M2S_GPIOX_PIN_START		(M2S_GPIO_PIN_BASE + 66) // GPIOX_0
#define M2S_GPIOX_PIN_MID		(M2S_GPIO_PIN_BASE + 81) // GPIOX_15
#define M2S_GPIOX_PIN_END		(M2S_GPIO_PIN_BASE + 85) // GPIOX_19
#define M2S_GPIOAO_PIN_START		(M2S_GPIO_PIN_BASE + 86) // GPIOAO_0
#define M2S_GPIOAO_PIN_END		(M2S_GPIO_PIN_BASE + 97) // GPIOAO_11

#define M2S_GPIOH_FSEL_REG_OFFSET		0x119
#define M2S_GPIOH_OUTP_REG_OFFSET		0x11A
#define M2S_GPIOH_INP_REG_OFFSET		0x11B
#define M2S_GPIOH_PUPD_REG_OFFSET		0x13D
#define M2S_GPIOH_PUEN_REG_OFFSET		0x14B
#define M2S_GPIOH_DS_REG_3A_OFFSET      	0x1D4
#define M2S_GPIOH_MUX_B_REG_OFFSET      	0x1BB

#define M2S_GPIOX_FSEL_REG_OFFSET		0x116
#define M2S_GPIOX_OUTP_REG_OFFSET		0x117
#define M2S_GPIOX_INP_REG_OFFSET		0x118
#define M2S_GPIOX_PUPD_REG_OFFSET		0x13C
#define M2S_GPIOX_PUEN_REG_OFFSET		0x14A
#define M2S_GPIOX_DS_REG_2A_OFFSET      	0x1D2
#define M2S_GPIOX_DS_REG_2B_OFFSET      	0x1D3
#define M2S_GPIOX_MUX_3_REG_OFFSET      	0x1B3
#define M2S_GPIOX_MUX_4_REG_OFFSET      	0x1B4
#define M2S_GPIOX_MUX_5_REG_OFFSET      	0x1B5

#define M2S_GPIOA_FSEL_REG_OFFSET		0x120
#define M2S_GPIOA_OUTP_REG_OFFSET		0x121
#define M2S_GPIOA_INP_REG_OFFSET		0x122
#define M2S_GPIOA_PUPD_REG_OFFSET		0x13F
#define M2S_GPIOA_PUEN_REG_OFFSET		0x14D
#define M2S_GPIOA_DS_REG_5A_OFFSET      	0x1D6
#define M2S_GPIOA_MUX_D_REG_OFFSET      	0x1BD
#define M2S_GPIOA_MUX_E_REG_OFFSET      	0x1BE

#define M2S_GPIOAO_FSEL_REG_OFFSET		0x109
#define M2S_GPIOAO_OUTP_REG_OFFSET		0x10D
#define M2S_GPIOAO_INP_REG_OFFSET		0x10A
#define M2S_GPIOAO_PUPD_REG_OFFSET		0x10B
#define M2S_GPIOAO_PUEN_REG_OFFSET		0x10C
#define M2S_GPIOAO_DS_REG_A_OFFSET      	0x107
#define M2S_GPIOAO_DS_REG_B_OFFSET      	0x108
#define M2S_GPIOAO_MUX_REG0_OFFSET      	0x105
#define M2S_GPIOAO_MUX_REG1_OFFSET      	0x106

//
// For Bananapi M5 Board
//
#define M5_GPIO_MASK			(0xFFFFFF00)
#define M5_GPIO_BASE			0xFF634000
#define M5_GPIO_AO_BASE			0xFF800000

#define M5_GPIO_PIN_BASE		410

#define M5_GPIOH_PIN_START		(M5_GPIO_PIN_BASE + 17)	// GPIOH_0
#define M5_GPIOH_PIN_END		(M5_GPIO_PIN_BASE + 25)	// GPIOH_8
#define M5_GPIOA_PIN_START		(M5_GPIO_PIN_BASE + 50)	// GPIOA_0
#define M5_GPIOA_PIN_END		(M5_GPIO_PIN_BASE + 65)	// GPIOA_15
#define M5_GPIOX_PIN_START		(M5_GPIO_PIN_BASE + 66)	// GPIOX_0
#define M5_GPIOX_PIN_MID		(M5_GPIO_PIN_BASE + 81)   // GPIOX_15
#define M5_GPIOX_PIN_END		(M5_GPIO_PIN_BASE + 85)	// GPIOX_15
#define M5_GPIOAO_PIN_START		(M5_GPIO_PIN_BASE + 86)   // GPIOAO_0
#define M5_GPIOAO_PIN_END		(M5_GPIO_PIN_BASE + 97)   // GPIOAO_11

#define M5_GPIOH_FSEL_REG_OFFSET		0x119
#define M5_GPIOH_OUTP_REG_OFFSET		0x11A
#define M5_GPIOH_INP_REG_OFFSET			0x11B
#define M5_GPIOH_PUPD_REG_OFFSET		0x13D
#define M5_GPIOH_PUEN_REG_OFFSET		0x14B
#define M5_GPIOH_DS_REG_3A_OFFSET       	0x1D4
#define M5_GPIOH_MUX_B_REG_OFFSET       	0x1BB

#define M5_GPIOA_FSEL_REG_OFFSET		0x120
#define M5_GPIOA_OUTP_REG_OFFSET		0x121
#define M5_GPIOA_INP_REG_OFFSET			0x122
#define M5_GPIOA_PUPD_REG_OFFSET		0x13F
#define M5_GPIOA_PUEN_REG_OFFSET		0x14D
#define M5_GPIOA_DS_REG_5A_OFFSET       	0x1D6
#define M5_GPIOA_MUX_D_REG_OFFSET       	0x1BD
#define M5_GPIOA_MUX_E_REG_OFFSET       	0x1BE

#define M5_GPIOX_FSEL_REG_OFFSET		0x116
#define M5_GPIOX_OUTP_REG_OFFSET		0x117
#define M5_GPIOX_INP_REG_OFFSET			0x118
#define M5_GPIOX_PUPD_REG_OFFSET		0x13C
#define M5_GPIOX_PUEN_REG_OFFSET		0x14A
#define M5_GPIOX_DS_REG_2A_OFFSET       	0x1D2
#define M5_GPIOX_DS_REG_2B_OFFSET       	0x1D3
#define M5_GPIOX_MUX_3_REG_OFFSET       	0x1B3
#define M5_GPIOX_MUX_4_REG_OFFSET       	0x1B4
#define M5_GPIOX_MUX_5_REG_OFFSET       	0x1B5

#define M5_GPIOAO_FSEL_REG_OFFSET		0x109
#define M5_GPIOAO_OUTP_REG_OFFSET		0x10D
#define M5_GPIOAO_INP_REG_OFFSET		0x10A
#define M5_GPIOAO_PUPD_REG_OFFSET		0x10B
#define M5_GPIOAO_PUEN_REG_OFFSET		0x10C
#define M5_GPIOAO_DS_REG_A_OFFSET       	0x107
#define M5_GPIOAO_DS_REG_B_OFFSET       	0x108
#define M5_GPIOAO_MUX_REG0_OFFSET       	0x105
#define M5_GPIOAO_MUX_REG1_OFFSET       	0x106

static volatile uint32_t *aml_gpio, *aml_gpioao;

/* Non-static add extern definition below */
int aml_found;
const int (*bcm_to_amlgpio)[64];

//
// pinToGpio:
//	Take a Wiring pin (0 through X) and re-map it to the AML_GPIO pin
//
static const int pinToGpioBananapiCM5IO[64] = {
	// wiringPi number to native gpio number
	496, 447,	//  0 |  1 : GPIOY.12, GPIOT.1
	497, 494,	//  2 |  3 : GPIOY.13, GPIOY.10
	493, 492,	//  4 |  5 : GPIOY.9, GPIOY.8(PWM_F)
	489, 498,	//  6 |  7 : GPIOY.5, GPIOY.14
	502, 501,	//  8 |  9 : GPIOY.18(I2C-5_SDA), GPIOY.17(I2C-5_SCL)
	487, 488,	// 10 | 11 : GPIOY.3(SPI_SS), GPIOY.4
	484, 485,	// 12 | 13 : GPIOY.0(SPI_MOSI), GPIOY.1(SPI_MISO)
	486, 490,	// 14 | 15 : GPIOY.2(SPI_CLK), GPIOY.6(UART_E_TX)
	491,  -1,	// 16 | 17 : GPIOY.7(UART_E_RX),
	 -1,  -1,	// 18 | 19 :
	 -1, 495,	// 20 | 21 : , GPIOY.11
	417, 416,	// 22 | 23 : GPIOD.5, GPIOD.4
	448, 446,	// 24 | 25 : GPIOT.2, GPIOT.0
	420, 450,	// 26 | 27 : GPIOD.8, GPIOT.4
	457, 449,	// 28 | 29 : GPIOT.11, GPIOT.3
	500, 499,	// 30 | 31 : GPIOY.16, GPIOY_15
	// Padding:
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 32...47
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 48...63
};

const int bcmToOGpioBananapiCM5IO[64] = {	// BCM ModE
     -1,  -1, 502, 501, 498, 495, 417, 488, // 0..7
    487, 485, 484, 486, 420, 416, 490, 491, // 8..15
    450, 496, 447, 448, 457, 449, 494, 493, // 16..23
    492, 489, 446, 497,  -1,  -1,  -1,  -1, // 24..31
// Padding:
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 32..39
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 40..47
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 48..55
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1  // 56..63
};

static const int physToGpioBananapiCM5IO[64] = {
	// physical header pin number to native gpio number
	 -1,		//  0
	 -1,  -1,	//  1 |  2 : 3.3V, 5.0V
	502,  -1,	//  3 |  4 : GPIOY.18(I2C-5_SDA), 5.0V
	501,  -1,	//  5 |  6 : GPIOY.17(I2C-5_SCL), GND
	498, 490,	//  7 |  8 : GPIOY.14, GPIOY.6(UART_E_TX)
	 -1, 491,	//  9 | 10 : GND, GPIOY.7(UART_E_RX)
	496, 447,	// 11 | 12 : GPIOY.12, GPIOT.1
	497,  -1,	// 13 | 14 : GPIOY.13, GND
	494, 493,	// 15 | 16 : GPIOY.10, GPIOY.9
	 -1, 492,	// 17 | 18 : 3.3V, GPIOX.8(PWM_F)
	484,  -1,	// 19 | 20 : GPIOY.0(SPI_MOSI), GND
	485, 489,	// 21 | 22 : GPIOY.1(SPI_MISO), GPIOY.5
	486, 487,	// 23 | 24 : GPIOY.2(SPI_CLK), GPIOY.3(SPI_SS)
	 -1, 488,	// 25 | 26 : GND, GPIOY.4
	500, 499,	// 27 | 28 : GPIOY.16, GPIOY_15
	495,  -1,	// 29 | 30 : GPIOY.11, GND
	417, 420,	// 31 | 32 : GPIOD.5, GPIOD.8
	416,  -1,	// 33 | 34 : GPIOD.4, GND
	448, 450,	// 35 | 36 : GPIOT.2, GPIOT.4
	446, 457,	// 37 | 38 : GPIOT.0, GPIOT.11
	 -1, 449,	// 39 | 40 : GND, GPIOT.3
	// Not used
	-1, -1, -1, -1, -1, -1, -1, -1,	// 41...48
	-1, -1, -1, -1, -1, -1, -1, -1,	// 49...56
	-1, -1, -1, -1, -1, -1, -1	// 57...63
};

//
// pinToGpio:
//	Take a Wiring pin (0 through X) and re-map it to the AML_GPIO pin
//
static const int pinToGpioBananapiCM5BPICM4IO[64] = {
	// wiringPi number to native gpio number
	417, 447,	//  0 |  1 : GPIOD.5(PWM_AO_H), GPIOT.1
	495, 488,	//  2 |  3 : GPIOY.11, GPIOY.4
	446, 448,	//  4 |  5 : GPIOT.0, GPIOT.2
	416, 420,	//  6 |  7 : GPIOD.4, GPIOD.8
	502, 501,	//  8 |  9 : GPIOY.18(I2C-5_SDA), GPIOY.17(I2C-5_SCL)
	487, 449,	// 10 | 11 : GPIOY.3(SPI_SS), GPIOT.3
	484, 485,	// 12 | 13 : GPIOY.0(SPI_MOSI), GPIOY.1(SPI_MISO)
	486, 490,	// 14 | 15 : GPIOY.2(SPI_CLK), GPIOY.6(UART_E_TX)
	491,  -1,	// 16 | 17 : GPIOY.7(UART_E_RX),
	// Padding:
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,         // 18...31
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 32...47
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 48...63
};

const int bcmToOGpioBananapiCM5BPICM4IO[64] = { // BCM ModE
     -1,  -1, 502, 501, 420,  -1,  -1, 449, // 0..7
    487, 485, 484, 486,  -1,  -1, 490, 491, // 8..15
     -1, 417, 447,  -1,  -1,  -1, 488, 446, // 16..23
    448, 416,  -1, 495,  -1,  -1,  -1,  -1, // 24..31
// Padding:
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 32..39
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 40..47
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 48..55
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1  // 56..63
};

static const int physToGpioBananapiCM5BPICM4IO[64] = {
	// physical header pin number to native gpio number
	 -1,		//  0
	 -1,  -1,	//  1 |  2 : 3.3V, 5.0V
	502,  -1,	//  3 |  4 : GPIOY.18(I2C-5_SDA), 5.0V
	501,  -1,	//  5 |  6 : GPIOY.17(I2C-5_SCL), GND
	420, 490,	//  7 |  8 : GPIOD.8, GPIOY.6(UART_E_TX)
	 -1, 491,	//  9 | 10 : GND, GPIOY.7(UART_E_RX)
	417, 447,	// 11 | 12 : GPIOD.5(PWM_AO_H), GPIOT.1
	495,  -1,	// 13 | 14 : GPIOY.11, GND
	488, 446,	// 15 | 16 : GPIOY.4, GPIOT.0
	 -1, 448,	// 17 | 18 : 3.3V, GPIOT.2
	484,  -1,	// 19 | 20 : GPIOY.0(SPI_MOSI), GND
	485, 416,	// 21 | 22 : GPIOY.1(SPI_MISO), GPIOD.4
	486, 487,	// 23 | 24 : GPIOY.2(SPI_CLK), GPIOY.3(SPI_SS)
	 -1, 449,	// 25 | 26 : GND, GPIOT.3
	// Not used
	-1, -1, -1, -1, -1, -1, -1, -1, // 27...34
	-1, -1, -1, -1, -1, -1,         // 35...40
	-1, -1, -1, -1, -1, -1, -1, -1,	// 41...48
	-1, -1, -1, -1, -1, -1, -1, -1,	// 49...56
	-1, -1, -1, -1, -1, -1, -1	// 57...63
};

//
// pinToGpio:
//	Take a Wiring pin (0 through X) and re-map it to the AML_GPIO pin
//
static const int pinToGpioBananapiCM4[64] = {
        // wiringPi number to native gpio number
        506, 461,       //  0 |  1 : GPIOAO.10, GPIOA.1
        431, 501,       //  2 |  3 : GPIOH.4, GPIOAO.5
        460, 462,       //  4 |  5 : GPIOA.0, GPIOA.2
        467, 432,       //  6 |  7 : GPIOA.7, GPIOH.5
        493, 494,       //  8 |  9 : GPIOX.17(I2C-2_SDA), GPIOX.18(I2C-2_SCL)
        486, 463,       // 10 | 11 : GPIOX.10(SPI_SS), GPIOA.3
        484, 485,       // 12 | 13 : GPIOX.8(SPI_MOSI,PWM_C), GPIOX.9(SPI_MISO)
        487, 482,       // 14 | 15 : GPIOX.11(SPI_CLK), GPIOX.6(UART_B_TX,PWM_D)
        483,  -1,       // 16 | 17 : GPIOX.7(UART_B_RX,PWM_F),
        // Padding:
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,         // 18...31
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 32...47
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 48...63
};

const int bcmToOGpioBananapiCM4[64] = { // BCM ModE
     -1,  -1, 493, 494, 506,  -1,  -1, 463, // 0..7
    486, 485, 484, 487,  -1,  -1, 482, 483, // 8..15
     -1, 432, 461,  -1,  -1,  -1, 501, 460, // 16..23
    462, 467,  -1, 431,  -1,  -1,  -1,  -1, // 24..31
// Padding:
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 32..39
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 40..47
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 48..55
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1  // 56..63
};

static const int physToGpioBananapiCM4[64] = {
        // physical header pin number to native gpio number
	-1,            //  0
         -1,  -1,       //  1 |  2 : 3.3V, 5.0V
        493,  -1,       //  3 |  4 : GPIOX.17(I2C-2_SDA), 5.0V
        494,  -1,       //  5 |  6 : GPIOX.18(I2C-2_SCL), GND
        432, 482,       //  7 |  8 : GPIOH.5, GPIOX.6(UART_B_TX,PWM_D)
         -1, 483,       //  9 | 10 : GND, GPIOX.7(UART_B_RX,PWM_F)
        506, 461,       // 11 | 12 : GPIOAO.10, GPIOA.1
        431,  -1,       // 13 | 14 : GPIOH.4, GND
        501, 460,       // 15 | 16 : GPIOAO.5, GPIOA.0
         -1, 462,       // 17 | 18 : 3.3V, GPIOA.2
        484,  -1,       // 19 | 20 : GPIOX.8(SPI_MOSI,PWM_C), GND
        485, 467,       // 21 | 22 : GPIOX.9(SPI_MISO), GPIOA.7
        487, 486,       // 23 | 24 : GPIOX.11(SPI_CLK), GPIOX.10(SPI_SS)
         -1, 463,       // 25 | 26 : GND, GPIOA.3
        // Not used
        -1, -1, -1, -1, -1, -1, -1, -1, // 27...34
        -1, -1, -1, -1, -1, -1,         // 35...40
        -1, -1, -1, -1, -1, -1, -1, -1, // 41...48
        -1, -1, -1, -1, -1, -1, -1, -1, // 49...56
        -1, -1, -1, -1, -1, -1, -1      // 57...63
};

static const int pinToGpioBananapiRPICM4[64] = {
        // wiringPi number to native gpio number
        469, 461,       //  0 |  1 : GPIOA.9, GPIOA.1
        466, 465,       //  2 |  3 : GPIOA.6, GPIOA.5
        473, 472,       //  4 |  5 : GPIOA.13, GPIOA.12
        471, 470,       //  6 |  7 : GPIOA.11, GPIOA.10
        493, 494,       //  8 |  9 : GPIOX.17(I2C-2_SDA), GPIOX.18(I2C-2_SCL)
        486, 501,       // 10 | 11 : GPIOX.10(SPI_SS), GPIOAO.5
        484, 485,       // 12 | 13 : GPIOX.8(SPI_MOSI,PWM_C), GPIOX.9(SPI_MISO)
        487, 482,       // 14 | 15 : GPIOX.11(SPI_CLK), GPIOX.6(UART_B_TX,PWM_D)
        483,  -1,       // 16 | 17 : GPIOX.7(UART_B_RX,PWM_F),
         -1,  -1,       // 18 | 19 :
         -1, 431,       // 20 | 21 : , GPIOH.4
        506, 467,       // 22 | 23 : GPIOAO.10, GPIOA.7
        462, 460,       // 24 | 25 : GPIOA.2, GPIOA.0
        432, 507,       // 26 | 27 : GPIOH.5, GPIOAO.11
        464, 463,       // 28 | 29 : GPIOA.4, GPIOA.3
        474, 475,       // 30 | 31 : GPIOA.14(I2C-3_SDA), GPIOA_15(I2C3_SCL)
        // Padding:
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 32...47
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 48...63

};

const int bcmToOGpioBananapiRPICM4[64] = {  // BCM ModE
     -1,  -1, 493, 494, 470, 431, 432, 501, // 0..7
    486, 485, 484, 487, 506, 467, 482, 483, // 8..15
    507, 469, 461, 462, 464, 463, 465, 473, // 16..23
    472, 471, 460, 466,  -1,  -1,  -1,  -1, // 24..31
// Padding:
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 32..39
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 40..47
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 48..55
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1  // 56..63
};

static const int physToGpioBananapiRPICM4[64] = {
	// physical header pin number to native gpio number
	 -1,		//  0
	 -1,  -1,	//  1 |  2 : 3.3V, 5.0V
	493,  -1,	//  3 |  4 : GPIOX.17(I2C-2_SDA), 5.0V
	494,  -1,	//  5 |  6 : GPIOX.18(I2C-2_SCL), GND
	470, 482,	//  7 |  8 : GPIOA.10, GPIOX.6(UART_B_TX,PWM_D)
	 -1, 483,	//  9 | 10 : GND, GPIOX.7(UART_B_RX,PWM_F)
	469, 461,	// 11 | 12 : GPIOA.9, GPIOA.1
	466,  -1,	// 13 | 14 : GPIOA.6, GND
	465, 473,	// 15 | 16 : GPIOA.5, GPIOA.13
	 -1, 472,	// 17 | 18 : 3.3V, GPIOA.12
	484,  -1,	// 19 | 20 : GPIOX.8(SPI_MOSI,PWM_C), GND
	485, 471,	// 21 | 22 : GPIOX.9(SPI_MISO), GPIOA.11
	487, 486,	// 23 | 24 : GPIOX.11(SPI_CLK), GPIOX.10(SPI_SS)
	 -1, 501,	// 25 | 26 : GND, GPIOAO.5
	474, 475,	// 27 | 28 : GPIOA_14(I2C-3_SDA), GPIOA_15(I2C-3_SCL)
	431,  -1,	// 29 | 30 : GPIOH.4, GND
	506, 432,	// 31 | 32 : GPIOAO.10, GPIOH.5
	467,  -1,	// 33 | 34 : GPIOA.7, GND
	462, 507,	// 35 | 36 : GPIOA.2, GPIOAO.11
	460, 464,	// 37 | 38 : GPIOA.0, GPIOA.4
	 -1, 463,	// 39 | 40 : GND, GPIOA.3
	// Not used
	-1, -1, -1, -1, -1, -1, -1, -1,	// 41...48
	-1, -1, -1, -1, -1, -1, -1, -1,	// 49...56
	-1, -1, -1, -1, -1, -1, -1	// 57...63
};

//
// pinToGpio:
//	Take a Wiring pin (0 through X) and re-map it to the AML_GPIO pin
//
static const int pinToGpioBananapiM2S[64] = {
	// wiringPi number to native gpio number
	479, 461,	//  0 |  1 : GPIOX.3, GPIOA.1
	480, 483,	//  2 |  3 : GPIOX.4, GPIOX.7(PWM_F)
	476, 477,	//  4 |  5 : GPIOX.0, GPIOX.1
	478, 481,	//  6 |  7 : GPIOX.2, GPIOX.5(PWM_C)
	493, 494,	//  8 |  9 : GPIOX.17(I2C-2_SDA), GPIOX.18(I2C-2_SCL)
	486, 492,	// 10 | 11 : GPIOX.10(SPI_SS), GPIOX.16(PWM_E)
	484, 485,	// 12 | 13 : GPIOX.8(SPI_MOSI), GPIOX.9(SPI_MISO)
	487, 488,	// 14 | 15 : GPIOX.11(SPI_CLK), GPIOX.12(UART_A_TX)
	489,  -1,	// 16 | 17 : GPIOX.13(UART_A_RX),
	 -1,  -1,	// 18 | 19 :
	 -1, 490,	// 20 | 21 : , GPIOX.14
	491, 482,	// 22 | 23 : GPIOX.15, GPIOX.6(PWM_D)
	462, 460,	// 24 | 25 : GPIOA.2, GPIOA.0
	495, 501,	// 26 | 27 : GPIOX.19, GPIOAO.5
	464, 463,	// 28 | 29 : GPIOA.4, GPIOA.3
	432, 431,	// 30 | 31 : GPIOH.5, GPIOH_4
	// Padding:
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 32...47
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 48...63

};

const int bcmToOGpioBananapiM2S[64] = {	// BCM ModE
     -1,  -1, 493, 494, 481, 490, 491, 492, // 0..7
    486, 485, 484, 487, 495, 482, 488, 489, // 8..15
    501, 479, 461, 462, 464, 463, 483, 476, // 16..23
    477, 478, 460, 480,  -1,  -1,  -1,  -1, // 24..31
// Padding:
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 32..39
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 40..47
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 48..55
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1  // 56..63
};

static const int physToGpioBananapiM2S[64] = {
	// physical header pin number to native gpio number
	 -1,		//  0
	 -1,  -1,	//  1 |  2 : 3.3V, 5.0V
	493,  -1,	//  3 |  4 : GPIOX.17(I2C-2_SDA), 5.0V
	494,  -1,	//  5 |  6 : GPIOX.18(I2C-2_SCL), GND
	481, 488,	//  7 |  8 : GPIOX.5(PWM_C), GPIOX.12(UART_A_TX)
	 -1, 489,	//  9 | 10 : GND, GPIOX.13(UART_A_RX)
	479, 461,	// 11 | 12 : GPIOX.3, GPIOA.1
	480,  -1,	// 13 | 14 : GPIOX.4, GND
	483, 476,	// 15 | 16 : GPIOX.7(PWM_F), GPIOX.0
	 -1, 477,	// 17 | 18 : 3.3V, GPIOX.1
	484,  -1,	// 19 | 20 : GPIOX.8(SPI_MOSI), GND
	485, 478,	// 21 | 22 : GPIOX.9(SPI_MISO), GPIOX.2
	487, 486,	// 23 | 24 : GPIOX.11(SPI_CLK), GPIOX.10(SPI_SS)
	 -1, 492,	// 25 | 26 : GND, GPIOX.16(PWM_E)
	432, 431,	// 27 | 28 : GPIOH_5, GPIOH_4
	490,  -1,	// 29 | 30 : GPIOX.14, GND
	491, 495,	// 31 | 32 : GPIOX.15, GPIOX.19
	482,  -1,	// 33 | 34 : GPIOX.6(PWM_D), GND
	462, 501,	// 35 | 36 : GPIOA.2, GPIOAO.5
	460, 464,	// 37 | 38 : GPIOA.0, GPIOA.4
	 -1, 463,	// 39 | 40 : GND, GPIOA.3
	// Not used
	-1, -1, -1, -1, -1, -1, -1, -1,	// 41...48
	-1, -1, -1, -1, -1, -1, -1, -1,	// 49...56
	-1, -1, -1, -1, -1, -1, -1	// 57...63
};

static const int pinToGpioBananapiM5[64] = {
    // wiringPi number to native gpio number
	479, 504,	//  0 |  1 : GPIOX.3, GPIOAO.8
	480, 483,	//  2 |  3 : GPIOX.4, GPIOX.7(PWM_F)
	476, 477,	//  4 |  5 : GPIOX.0, GPIOX.1
	478, 481,	//  6 |  7 : GPIOX.2, GPIOX.5PWM_C)
	493, 494,	//  8 |  9 : GPIOX.17(I2C-2_SDA), GPIOX.18(I2C-2_SCL)
	486, 492,	// 10 | 11 : GPIOX.10(SPI_SS), GPIOX.16(PWM_E)
	484, 485,	// 12 | 13 : GPIOX.8(SPI_MOSI), GPIOX.9(SPI_MISO)
	487, 488,	// 14 | 15 : GPIOX.11(SPI_CLK), GPIOX.12(UART_A_TX)
	489,  -1,	// 16 | 17 : GPIOX.13(UART_A_RX),
	 -1,  -1,	// 18 | 19 :
	 -1, 490,	// 20 | 21 : , GPIOX.14
	491, 482,	// 22 | 23 : GPIOX.15, GPIOX.6(PWM_D)
	503, 505,	// 24 | 25 : GPIOAO.7, GPIOAO.9
	495, 432,	// 26 | 27 : GPIOX.19, GPIOH.5
	506, 500,	// 28 | 29 : GPIOAO.10, GPIOAO.4
	474, 475,	// 30 | 31 : GPIOA.14(I2C-3_SDA), GPIOA.15(I2C-3_SCL)
	// Padding:
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 32...47
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 48...63
};

const int bcmToOGpioBananapiM5[64] = {	// BCM ModE
     -1,  -1, 493, 494, 481, 490, 491, 492, // 0..7
    486, 485, 484, 487, 495, 482, 488, 489, // 8..15
    432, 479, 504, 503, 506, 500, 483, 476, // 16..23
    477, 478, 505, 480,  -1,  -1,  -1,  -1, // 24..31
// Padding:
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 32..39
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 40..47
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 48..55
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1  // 56..63
};

static const int physToGpioBananapiM5[64] = {
	// physical header pin number to native gpio number
	 -1,		//  0
	 -1,  -1,	//  1 |  2 : 3.3V, 5.0V
	493,  -1,	//  3 |  4 : GPIOX.17(I2C-2_SDA), 5.0V
	494,  -1,	//  5 |  6 : GPIOX.18(I2C-2_SCL), GND
	481, 488,	//  7 |  8 : GPIOX.5, GPIOX.12(UART_A_TX)
	 -1, 489,	//  9 | 10 : GND, GPIOX.13(UART_A_RX)
	479, 504,	// 11 | 12 : GPIOX.3, GPIOAO.8
	480,  -1,	// 13 | 14 : GPIOX.4, GND
	483, 476,	// 15 | 16 : GPIOX.7, GPIOX.0
	 -1, 477,	// 17 | 18 : 3.3V, GPIOX.1
	484,  -1,	// 19 | 20 : GPIOX.8(SPI_MOSI), GND
	485, 478,	// 21 | 22 : GPIOX.9(SPI_MISO), GPIOX.2
	487, 486,	// 23 | 24 : GPIOX.11(SPI_CLK), GPIOX.10(SPI_SS)
	 -1, 492,	// 25 | 26 : GND, GPIOX.16
	474, 475,	// 27 | 28 : GPIOA.14(I2C-3_SDA), GPIOA.15(I2C-3_SCL)
	490,  -1,	// 29 | 30 : GPIOX.14, GND
	491, 495,	// 31 | 32 : GPIOX.15, GPIOX.19
	482,  -1,	// 33 | 34 : GPIOX.6(PWM_D), GND
	503, 432,	// 35 | 36 : GPIOAO.7, GPIOH.5
	505, 506,	// 37 | 38 : GPIOAO.9, GPIOAO.10
	 -1, 500,	// 39 | 40 : GND, GPIOAO.4
	// Not used
	-1, -1, -1, -1, -1, -1, -1, -1,	// 41...48
	-1, -1, -1, -1, -1, -1, -1, -1,	// 49...56
	-1, -1, -1, -1, -1, -1, -1	// 57...63

};
#endif /* end AML_SUPPORT */

/* =======================================================================================
 *
 * Sunxi specific
 *
 * ========================================================================================
 */
#ifdef SUNXI_SUPPORT

#define SUNXI_GPIO_MASK			(0xFFFFFF00)
#define SUNXI_GPIO_BASE			0x0300B000

#define SUNXI_GPIO_PIN_BASE		0

static volatile uint32_t *sunxi_gpio;

/* Non-static add extern definition below */
int sunxi_found;
const int (*bcm_to_sunxigpio)[64];

//
// pinToGpio:
//	Take a Wiring pin (0 through X) and re-map it to the AML_GPIO pin
//
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

static const int pinToGpioBananapiM4Zero[64] = {   // for original boards with realtek wifi
	// wiringPi number to native gpio number
	226,   192+11,	//  0 |  1 : PH2, PG11/PI1
	227,   192+2,	//  2 |  3 : PH3, PG2/PI11
	192+8,   192+9,	//  4 |  5 : PG8/PI15, PG9/PI16
	192+1, 192+19,	//  6 |  7 : PG1/PC2, PG19/PI12(PWM2)
	192+16, 192+15,	//  8 |  9 : PG16/PI6(I2C0_SDA), PG15/PI5(I2C0_SCL)
	229,    233,	// 10 | 11 : PH5(SPI1_SS), PH9
	231,    232,	// 12 | 13 : PH7(SPI1_MOSI), PH8(SPI1_MISO)
	230,    192+6,	// 14 | 15 : PH6(SPI1_CLK), PG6/PI13(UART4_TX)
	192+7  -1,	// 16 | 17 : PG7/PI14(UART4_RX),
	 -1,   -1,	// 18 | 19 :
	 -1, 192+3,	// 20 | 21 : , PG3/PI10
	192+4, 192+5,	// 22 | 23 : PG4/PI9, PG5/PH10
	192+12, 192+10,	// 24 | 25 : PG12/PI2, PG10/PI0
	192+0, 224+4,	// 26 | 27 : PG0/PH4, PH4/PC7
	192+14, 192+13,	// 28 | 29 : PG14/PI4, PG13/PI3
	192+18, 192+17,	// 30 | 31 : PG18/PI8(I2C1_SDA), PG17/PI7(I2C1_SCL)
	// Padding:
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 32...47
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 48...63
};

const int bcmToOGpioBananapiM4Zero[64] = {       	      // BCM ModE
     -1,  -1, 192+16, 192+15, 192+19, 192+3, 192+4, 233,      // 0..7
     229, 232, 231, 230, 228, 192+5, 192+6, 192+7         ,      // 8..15
    224+4, 226, 192+11, 192+12, 192+14, 192+13, 192+2, 192+8, // 16..23
    192+9, 192+1, 192+19, 227,  -1,  -1,  -1,  -1, // 24..31
// Padding:
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 32..39
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 40..47
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 48..55
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1  // 56..63
};

static const int physToGpioBananapiM4Zero[64] = {
	// physical header pin number to native gpio number
	 -1,		//  0
	 -1,   -1,	//  1 |  2 : 3.3V, 5.0V
	192+16,   -1,	//  3 |  4 : PG16(I2C4_SDA), 5.0V
	192+15,   -1,	//  5 |  6 : PG15(I2C4_SCL), GND
	192+19, 192+6,	//  7 |  8 : PG19, PG6(UART1_TX)
	 -1,    192+7,	//  9 | 10 : GND(PWM1), PG7(UAR1_RX)
	226,    192+11,	// 11 | 12 : PH2, PG11
	227,   -1,	// 13 | 14 : PH3, GND
	192+2,  192+8,	// 15 | 16 : PG2, PG8
	 -1,    192+9,	// 17 | 18 : 3.3V, PG9
	231,   -1,	// 19 | 20 : PH7(SPI1_MOSI), GND
	232,    192+1,	// 21 | 22 : PH8(SPI1_MISO), PG1
	230,    229,	// 23 | 24 : PH6(SPI1_CLK), PH5(SPI1_SS)
	 -1,    233,	// 25 | 26 : GND, PH9
	192+18, 192+17,	// 27 | 28 : PG18(I2C3_SDA), PG17(I2C3_SCL)
        192+3,  -1,	// 29 | 30 : PG3, GND
	192+4,  192+0,	// 31 | 32 : PG4, PG0
	192+5,  -1,	// 33 | 34 : PG5, GND
	192+12, 224+4,	// 35 | 36 : PG12, PH4
	192+10, 192+14,	// 37 | 38 : PG10, PG14
	 -1,    192+13,	// 39 | 40 : GND, PG13
	// Not used
	-1, -1, -1, -1, -1, -1, -1, -1,	// 41...48
	-1, -1, -1, -1, -1, -1, -1, -1,	// 49...56
	-1, -1, -1, -1, -1, -1, -1	// 57...63
};

static const int pinToGpioBananapiM4ZeroV2[64] = { // bananapi m4zero V2 with broadcom wifi
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
	265, 234,	// 22 | 23 : PI9, PG5/PH10
	258, 256,	// 24 | 25 : PI2, PI0
	228,  71,	// 26 | 27 : PH4, PC7
	260, 259,	// 28 | 29 : PI4, PI3
	264, 263,	// 30 | 31 : PI8(I2C1_SDA), PI7(I2C1_SCL)
	// Padding:
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 32...47
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,	// 48...63
};

const int bcmToOGpioBananapiM4ZeroV2[64] = {	// BCM ModE
     -1,  -1, 262, 261, 192+19, 192+6, 192+4, 233, // 0..7
    229, 232, 231, 230, 228, 234, 269, 270, // 8..15
    71, 226, 257, 258, 260, 259, 267, 271, // 16..23
    272, 66, 256, 227,  -1,  -1,  -1,  -1, // 24..31
// Padding:
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 32..39
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 40..47
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 48..55
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1  // 56..63
};

static const int physToGpioBananapiM4ZeroV2[64] = {
	// physical header pin number to native gpio number
	 -1,		//  0
	 -1,  -1,	//  1 |  2 : 3.3V, 5.0V
	262,  -1,	//  3 |  4 : PG16/PI6(I2C4_SDA), 5.0V
	261,  -1,	//  5 |  6 : PG15/PI5(I2C4_SCL), GND
	268, 269,	//  7 |  8 : PG19/PI12, PG6/PI13(UART1_TX)
	 -1, 270,	//  9 | 10 : GND(PWM1), PG7/PI14(UAR1_RX)
	226, 257,	// 11 | 12 : PH2, PG11/PI1
	227,  -1,	// 13 | 14 : PH3, GND
	267, 271,	// 15 | 16 : PG2/PH11, PG8/PI15
	 -1, 272,	// 17 | 18 : 3.3V, PG9/PI16
	231,  -1,	// 19 | 20 : PH7(SPI1_MOSI), GND
	232,  66,	// 21 | 22 : PH8(SPI1_MISO), PG1/PC2
	230, 229,	// 23 | 24 : PH6(SPI1_CLK), PH5(SPI1_SS)
	 -1, 233,	// 25 | 26 : GND, PH9
	264, 263,	// 27 | 28 : PG18/PI8(I2C3_SDA), PG17/PI7(I2C3_SCL)
	266,  -1,	// 29 | 30 : PG3/PI10, GND
	265, 228,	// 31 | 32 : PG4/PI9, PG0/PH4
	234,  -1,	// 33 | 34 : PG5/PH10, GND
	258,  71,	// 35 | 36 : PG12/PI2, PH4/PC7
	256, 260,	// 37 | 38 : PG10/PI0, PG14/PI4
	 -1, 259,	// 39 | 40 : GND, PG13/PI3
	// Not used
	-1, -1, -1, -1, -1, -1, -1, -1,	// 41...48
	-1, -1, -1, -1, -1, -1, -1, -1,	// 49...56
	-1, -1, -1, -1, -1, -1, -1	// 57...63
};

#endif /* end SUNXI_SUPPORT */

/* =======================================================================================
 *
 * Spacemit specific
 *
 * ========================================================================================
 */
#ifdef SPACEMIT_SUPPORT

#define SPACEMIT_GPIO_MASK		(0xFFFFFF00)
#define SPACEMIT_GPIO_BASE		0xd4019000
#define SPACEMIT_PINCTRL_BASE		0xd401e000

#define F3_BANK012_OFFSET(x)    ((x) << 2)
#define F3_BANK3_OFFSET         0x100

#define F3_GPLR                 0x0
#define F3_GPDR                 0xc
#define F3_GPSR                 0x18
#define F3_GPCR                 0x24
#define F3_GRER                 0x30
#define F3_GFER                 0x3c
#define F3_GEDR                 0x48
#define F3_GSDR                 0x54
#define F3_GCDR                 0x60
#define F3_GSRER                0x6c
#define F3_GCRER                0x78
#define F3_GSFER                0x84
#define F3_GCFER                0x90
#define F3_GAPMASK              0x9c
#define F3_GCPMASK              0xa8

#define F3_MFPR(x) \
    (((x) <= 85) ? (((x) + 1) << 2) : \
    (((x) <= 92) ? (((x) + 1) << 2) + 0x90 : \
    (((x) <= 127) ? (((x) + 1) << 2) + 0x4c : 0)))

#define F3_AF_SEL_OFFSET        (0)
#define F3_AF_SEL_MASK          (7 << 0)
#define F3_GPIO_ALT(x) \
    (((x) >= 70 && (x) <= 73) || ((x) >= 93 && (x) <= 103)) ? 1 : \
    (((x) >= 104 && (x) <= 109)) ? 4 : \
    0

/* pull up/down */
#define F3_PULL_DIS        (0)     /* bit[15:13] 000 */
#define F3_PULL_UP         (6)     /* bit[15:13] 110 */
#define F3_PULL_DOWN       (5)     /* bit[15:13] 101 */
#define F3_PULL_OFFSET     (13)
#define F3_PULL_MASK       (7 << 13)

static volatile uint32_t *spacemit_gpio;
static volatile uint32_t *spacemit_pinctrl;

/* Non-static add extern definition below */
int spacemit_found;
const int (*bcm_to_spacemitgpio)[64];

//
// pinToGpio:
//	Take a Wiring pin (0 through X) and re-map it to the AML_GPIO pin
//
static const int pinToGpioBananapiF3[64] = {
    // wiringPi number to native gpio number
    71, 74, //  0 |  1 : GPIO.71, GPIO.74(PWM_9)
    72, 73, //  2 |  3 : GPIO.72, GPIO.73
    91, 92, //  4 |  5 : GPIO.91, GPIO.92
    49, 70, //  6 |  7 : GPIO.49, GPIO.70
    52, 51, //  8 |  9 : GPIO.52(I2C-4_SDA), GPIO.51(I2C-4_SCL)
    76, 50, // 10 | 11 : GPIO.76(SPI_SS), GPIO.50
    77, 78, // 12 | 13 : GPIO.77(SPI_MOSI), GPIO.78(SPI_MISO)
    75, 47, // 14 | 15 : GPIO.75(SPI_CLK), GPIO.47(UART_0_TX)
    48, -1, // 16 | 17 : GPIO.48(UART_0_RX),
    // Padding:
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,         // 18...31
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 32...47
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // 48...63
};

const int bcmToOGpioBananapiF3[64] = { // BCM ModE
     -1,  -1,  52,  51,  70,  -1,  -1,  50, // 0..7
     76,  78,  77,  75,  -1,  -1,  47,  48, // 8..15
     -1,  71,  74,  -1,  -1,  -1,  73,  91, // 16..23
     92,  49,  -1,  72,  -1,  -1,  -1,  -1, // 24..31
// Padding:
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 32..39
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 40..47
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, // 48..55
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1  // 56..63
};

static const int physToGpioBananapiF3[64] = {
    // physical header pin number to native gpio number
    -1,             //  0
    -1, -1, //  1 |  2 : 3.3V, 5.0V
    52, -1, //  3 |  4 : GPIO.52(I2C-4_SDA), 5.0V
    51, -1, //  5 |  6 : GPIO.51(I2C-4_SCL), GND
    70, 47, //  7 |  8 : GPIO.70, GPIO.47(UART_0_TX)
    -1, 48, //  9 | 10 : GND, GPIO.48(UART_0_RX)
    71, 74, // 11 | 12 : GPIO.71, GPIO.74(PWM_9)
    72, -1, // 13 | 14 : GPIO.72, GND
    73, 91, // 15 | 16 : GPIO.73, GPIO.91
    -1, 92, // 17 | 18 : 3.3V, GPIO.92
    77, -1, // 19 | 20 : GPIO.77(SPI_MOSI), GND
    78, 49, // 21 | 22 : GPIO.78(SPI_MISO), GPIO.49
    75, 76, // 23 | 24 : GPIO.75(SPI_CLK), GPIO.76(SPI_SS)
    -1, 50, // 25 | 26 : GND, GPIO.50
    // Not used
    -1, -1, -1, -1, -1, -1, -1, -1, // 27...34
    -1, -1, -1, -1, -1, -1,         // 35...40
    -1, -1, -1, -1, -1, -1, -1, -1, // 41...48
    -1, -1, -1, -1, -1, -1, -1, -1, // 49...56
    -1, -1, -1, -1, -1, -1, -1      // 57...63
};
#endif /* end SPACEMIT_SUPPORT */

#else /* DEFINE_AML_VARS */

extern int  piModel;

/* =======================================================================================
 *
 * Amlogic specific
 *
 * ========================================================================================
 */
#ifdef AML_SUPPORT
extern int aml_found;
extern const int (*bcm_to_amlgpio)[64];

extern const int physToGpioBananapiCM5IO[64];
extern const int bcmToOGpioBananapiCM5IO[64];
extern const int physToGpioBananapiCM5BPICM4IO[64];
extern const int bcmToOGpioBananapiCM5BPICM4IO[64];
extern const int physToGpioBananapiRPICM4[64];
extern const int bcmToOGpioBananapiRPICM4[64];
extern const int physToGpioBananapiCM4[64];
extern const int bcmToOGpioBananapiCM4[64];
extern const int physToGpioBananapiM2S[64];
extern const int bcmToOGpioBananapiM2S[64];
extern const int physToGpioBananapiM5[64];
extern const int bcmToOGpioBananapiM5[64];

int wiringPiSetupAml (void);
void wiringPiCleanupAml (void);
void pinModeAml (int pin, int mode);
void pullUpDnControlAml (int pin, int pud);
int digitalReadAml (int pin);
void digitalWriteAml (int pin, int value);
int analogReadAml (int pin);
void analogWriteAml (int pin, int value);
int pinGetModeAml (int pin);
void setInfoAml(char *hardware, void *vinfo);
void setMappingPtrsAml(void);

#endif /* end AML_SUPPORT */

/* =======================================================================================
 *
 * Sunxi specific
 *
 * ========================================================================================
 */
 #ifdef SUNXI_SUPPORT
 
extern int sunxi_found;
extern const int (*bcm_to_sunxigpio)[64];

extern const int physToGpioBananapiM4Berry[64];
extern const int bcmToOGpioBananapiM4Berry[64];
extern const int physToGpioBananapiM4Zero[64];
extern const int bcmToOGpioBananapiM4Zero[64];
extern const int physToGpioBananapiM4ZeroV2[64];
extern const int bcmToOGpioBananapiM4ZeroV2[64];

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
#endif /* end SUNXI_SUPPORT */

/* =======================================================================================
 *
 * Spacemit specific
 *
 * ========================================================================================
 */
 #ifdef SPACEMIT_SUPPORT
 
extern int spacemit_found;
extern const int (*bcm_to_spacemitgpio)[64];

extern const int physToGpioBananapiF3[64];
extern const int bcmToOGpioBananapiF3[64];

int wiringPiSetupSpacemit (void);
void wiringPiCleanupSpacemit (void);
void pinModeSpacemit (int pin, int mode);
void pullUpDnControlSpacemit (int pin, int pud);
int digitalReadSpacemit (int pin);
void digitalWriteSpacemit (int pin, int value);
int analogReadSpacemit (int pin);
void analogWriteSpacemit (int pin, int value);
int pinGetModeSpacemit (int pin);
void setInfoSpacemit(char *hardware, void *vinfo);
void setMappingPtrsSpacemit(void);
#endif /* end SPACEMIT_SUPPORT */

#endif /* DEFINE_SUNXI_VARS */

#endif /* BANANAPI_H_INCLUDED */
