#if !defined(BOARD_DEFS_H)
#define BOARD_DEFS_H

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*              Public Board Declarations                       */
/* ------------------------------------------------------------ */
/* The following define symbols that can be used in a sketch to
** refer to peripherals on the board generically.
*/

#define _BOARD_NAME_    "CressonMD920"

/* Define the peripherals available on the board.
*/
#define NUM_DIGITAL_PINS    17
#define NUM_ANALOG_PINS     7

#define NUM_SERIAL_PORTS    2       
#define NUM_DSPI_PORTS      2
#define NUM_DTWI_PORTS      2       

/* ------------------------------------------------------------ */
/*                  Button Declarations                         */
/* ------------------------------------------------------------ */

/* No buttons or this board
*/

/* Also define the virtual program button for soft reset */
#define USE_VIRTUAL_PROGRAM_BUTTON      1
#define VIRTUAL_PROGRAM_BUTTON_TRIS     TRISBbits.TRISB0
#define VIRTUAL_PROGRAM_BUTTON          LATBbits.LATB0

/* ------------------------------------------------------------ */
/*                  Switch Declarations                         */
/* ------------------------------------------------------------ */

/* No switches on this board.
*/

/* ------------------------------------------------------------ */
/*                  Servo Pin Declarations                      */
/* ------------------------------------------------------------ */

/* No servo connectors on this board.
*/

/* ------------------------------------------------------------ */
/*                  Interrupt Pin Declarations                  */
/* ------------------------------------------------------------ */

#define PIN_INT0    12      // RB7
#define PIN_INT1    2       // RB0
#define PIN_INT2    11      // RB6
#define PIN_INT3    10      // RB5
#define PIN_INT4    0       // RA0

/* ------------------------------------------------------------ */
/*                  SPI Pin Declarations                        */
/* ------------------------------------------------------------ */
/* These symbols are defined for compatibility with the original
** SPI library and the original pins_arduino.h. 
*/
static const uint8_t SS   = 7;
static const uint8_t MISO = 16;
static const uint8_t MOSI = 8;
static const uint8_t SCK  = 9;

/* The Digilent DSPI library uses these ports.
**      DSPI0   connector JB
**      DSPI1   connector J1
*/
#define PIN_DSPI0_SS    SS
#define PIN_DSPI1_SS    2

/* ------------------------------------------------------------ */
/*                  Analog Pins                                 */
/* ------------------------------------------------------------ */
/* Define symbols for accessing the analog pins. This table is  
** used to map an analog pin number to the corresponding digital
** pin number.
*/
#define A0      0
#define A1      1
#define A2      2
#define A3      3
#define A4      4
#define A5      5
#define A6      6

/* ------------------------------------------------------------ */
/*                  Pin Mapping Macros                          */
/* ------------------------------------------------------------ */
/* Macros used to access the port and pin mapping tables.
** These are mostly generic, but some of them may be board specific.
** These perform slightly better as macros compared to in-line functions
*/
// This definition can be used for the non-default case where there
// is a mapping table to go from digital pin to analog pin
#undef digitalPinToAnalog
#define digitalPinToAnalog(P) ( digital_pin_to_analog_PGM[P] )

#undef analogInPinToChannel
#define analogInPinToChannel(P) ( analog_pin_to_channel_PGM[P]  )

/* ------------------------------------------------------------ */
/*                  Data Definitions                            */
/* ------------------------------------------------------------ */

/* The following declare externals to access the pin mapping
** tables. These tables are defined in Board_Data.c.
*/

#if !defined(OPT_BOARD_DATA)

extern const uint32_t   port_to_tris_PGM[];
extern const uint8_t    digital_pin_to_port_PGM[];
extern const uint16_t   digital_pin_to_bit_mask_PGM[];
extern const uint16_t   digital_pin_to_timer_PGM[];
extern const uint8_t    digital_pin_to_pps_out_PGM[];
extern const uint8_t    digital_pin_to_pps_in_PGM[];
extern const uint8_t    digital_pin_to_analog_PGM[];
extern const uint8_t    analog_pin_to_channel_PGM[];

extern const uint8_t    output_compare_to_digital_pin_PGM[];
extern const uint8_t    external_int_to_digital_pin_PGM[];

#endif

/* ------------------------------------------------------------ */
/*              Internal Declarations                           */
/* ------------------------------------------------------------ */
/* The following declarations are used to map peripherals for   */
/* the core and libraries and to provide configuration options  */
/* for the core. They are not normally needed by a user sketch. */
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_INTERNAL)

/* ------------------------------------------------------------ */
/*              Core Configuration Declarations                 */
/* ------------------------------------------------------------ */
/*                                                              */
/* These are conditional compilation switches that control the  */
/* board core configuration functions. These functions provide  */
/* hooks that can call from some of the core functions into     */
/* functions defined below that can be used to extend or        */
/* replace the default behavior of the core function. To use    */
/* this, enter the appropriate code into the appropriate        */
/* function skeleton below and then set the appropriate switch  */
/* value to 1. This will cause the configuration function to be */
/* compiled into the build and will cause the code to call the  */
/* hook function to be compiled into the core function.         */
/*                                                              */
/* ------------------------------------------------------------ */

#define OPT_BOARD_INIT          1   //board needs special init code
#define OPT_BOARD_DIGITAL_IO    0   //board does not extend digital i/o functions
#define OPT_BOARD_ANALOG_READ   0   //board does not extend analogRead
#define OPT_BOARD_ANALOG_WRITE  0   //board does not extend analogWrite

#endif  // OPT_BOARD_INTERNAL

/* ------------------------------------------------------------ */
/*                  Serial Port Declarations                    */
/* ------------------------------------------------------------ */

/* Serial port 0 uses UART1  for the serial monitor
*/
#define       _SER0_BASE           _UART1_BASE_ADDRESS
#define       _SER0_IRQ            _UART1_ERR_IRQ
#define       _SER0_VECTOR         _UART_1_VECTOR
#define       _SER0_IPL_ISR        IPL2SOFT
#define       _SER0_IPL            2
#define       _SER0_SPL            0
#define       _SER0_TX_OUT         PPS_OUT_U1TX
#define       _SER0_TX_PIN         0
#define       _SER0_RX_IN          PPS_IN_U1RX 
#define       _SER0_RX_PIN         4            


/* Serial port 1 uses UART2
*/
#define       _SER1_BASE           _UART2_BASE_ADDRESS
#define       _SER1_IRQ            _UART2_ERR_IRQ
#define       _SER1_VECTOR         _UART_2_VECTOR
#define       _SER1_IPL_ISR        IPL2SOFT
#define       _SER1_IPL            2
#define       _SER1_SPL            0
#define       _SER1_TX_OUT         PPS_OUT_U2TX
#define       _SER1_TX_PIN         14
#define       _SER1_RX_IN          PPS_IN_U2RX
#define       _SER1_RX_PIN         13


/* ------------------------------------------------------------ */
/*                  SPI Port Declarations                       */
/* ------------------------------------------------------------ */

/* The Digilent DSPI and standard SPI libraries uses these ports.
*/
#define _DSPI0_BASE         _SPI1_BASE_ADDRESS
#define _DSPI0_ERR_IRQ      _SPI1_ERR_IRQ
#define _DSPI0_RX_IRQ       _SPI1_RX_IRQ
#define _DSPI0_TX_IRQ       _SPI1_TX_IRQ
#define _DSPI0_VECTOR       _SPI_1_VECTOR
#define _DSPI0_IPL_ISR      _SPI1_IPL_ISR
#define _DSPI0_IPL          _SPI1_IPL_IPC
#define _DSPI0_SPL          _SPI1_SPL_IPC

#define _DSPI0_MISO_IN      PPS_IN_SDI1
#define _DSPI0_MISO_PIN     MISO
#define _DSPI0_MOSI_OUT     PPS_OUT_SDO1
#define _DSPI0_MOSI_PIN     MOSI

#define _DSPI1_BASE         _SPI2_BASE_ADDRESS
#define _DSPI1_ERR_IRQ      _SPI2_ERR_IRQ
#define _DSPI1_RX_IRQ       _SPI2_RX_IRQ
#define _DSPI1_TX_IRQ       _SPI2_TX_IRQ
#define _DSPI1_VECTOR       _SPI_2_VECTOR
#define _DSPI1_IPL_ISR      _SPI2_IPL_ISR
#define _DSPI1_IPL          _SPI2_IPL_IPC
#define _DSPI1_SPL          _SPI2_SPL_IPC

#define _DSPI1_MISO_IN      PPS_IN_SDI2
#define _DSPI1_MISO_PIN     11
#define _DSPI1_MOSI_OUT     PPS_OUT_SDO2
#define _DSPI1_MOSI_PIN     1
/* ------------------------------------------------------------ */
/*                  I2C Port Declarations                       */
/* ------------------------------------------------------------ */

/* The standard I2C port uses PIC32 peripheral I2C2
** SCL is on RB3 which is Arduino analog pin A5
** SDA is on RB2 which is Arduino analog pin A4
*/
#define _TWI_BASE       _I2C1_BASE_ADDRESS
#define _TWI_BUS_IRQ    _I2C1_BUS_IRQ
#define _TWI_SLV_IRQ    _I2C1_SLAVE_IRQ
#define _TWI_MST_IRQ    _I2C1_MASTER_IRQ
#define _TWI_VECTOR     _I2C_1_VECTOR
#define _TWI_IPL_ISR    _I2C1_IPL_ISR
#define _TWI_IPL        _I2C1_IPL_IPC
#define _TWI_SPL        _I2C1_SPL_IPC

/* Declarations for Digilent DTWI library.
** DTWI0 is on PIC32 peripheral I2C2
** SCL is on RB3 which is Arduino analog pin A5
** SDA is on RB2 which is Arduino analog pin A4
*/
#define _DTWI0_BASE     _I2C1_BASE_ADDRESS
#define _DTWI0_BUS_IRQ  _I2C1_BUS_IRQ
#define _DTWI0_VECTOR   _I2C_1_VECTOR
#define _DTWI0_IPL_ISR  _I2C1_IPL_ISR
#define _DTWI0_IPL      _I2C1_IPL_IPC
#define _DTWI0_SPL      _I2C1_SPL_IPC
#define _DTWI0_SCL_PIN  13 
#define _DTWI0_SDA_PIN  14

/* ------------------------------------------------------------ */
/*                  A/D Converter Declarations                  */
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */

#endif  // BOARD_DEFS_H

/************************************************************************/
