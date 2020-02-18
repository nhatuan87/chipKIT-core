#if !defined(BOARD_DATA_C)
#define BOARD_DATA_C

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*                  Data Tables                                 */
/* ------------------------------------------------------------ */
/* The following declarations define data used in pin mapping.  */
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_DATA)

/* ------------------------------------------------------------ */
/* This table is used to map from port number to the address of
** the TRIS register for the port. This is used for setting the
** pin direction.
*/
const uint32_t  port_to_tris_PGM[] = {
    NOT_A_PORT,             //index value 0 is not used

#if defined(_PORTA)
    (uint32_t)&TRISA,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTB)
    (uint32_t)&TRISB,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTC)
    (uint32_t)&TRISC,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTD)
    (uint32_t)&TRISD,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTE)
    (uint32_t)&TRISE,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTF)
    (uint32_t)&TRISF,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTG)
    (uint32_t)&TRISG,
#else
    NOT_A_PORT,
#endif

    NOT_A_PORT,
};

/* ------------------------------------------------------------ */
/* This table is used to map the digital pin number to the port
** containing that pin. The default mapping is to assign pin numbers
** for every possible port bit in order from PORTA to PORTG.
*/
const uint8_t digital_pin_to_port_PGM[] = {
                // Pin  Name    | Int. Func |   Serial      Analog  Interrupt   |   DevKIT
                //--------------+-----------+-----------------------------------+---------------
    _IOPORT_PA, //  0   RA0     |           |   U1TX        A0      INT4        |   USBUART_TX
    _IOPORT_PA, //  1   RA1     |           |   SDO2        A1                  |   USBUART_CTS
    _IOPORT_PB, //  2   RB0     |           |               A2      INT1        |   PGED1 (BTLDRn)
    _IOPORT_PB, //  3   RB1     |           |               A3                  |   PGEC1
    _IOPORT_PB, //  4   RB2     |           |   U1RX/SCL2   A4                  |   USBUART_RX
    _IOPORT_PB, //  5   RB3     |           |   SDA2        A5                  |   GP1
    _IOPORT_PB, //  6   RB15    |           |   SCK2        A6                  |   GP6
    _IOPORT_PB, //  7   RB12    |   SS1     |                                   |
    _IOPORT_PB, //  8   RB13    |   SDO1    |                                   |
    _IOPORT_PB, //  9   RB14    |   SCK1    |                                   |
    _IOPORT_PB, // 10   RB5     |           |                       INT3        |   GP5
    _IOPORT_PB, // 11   RB6     |           |   SDI2                INT2        |   GP3
    _IOPORT_PB, // 12   RB7     |           |                       INT0        |   GP4
    _IOPORT_PB, // 13   RB8     |           |   U2RX/SCL1                       |   GP2
    _IOPORT_PB, // 14   RB9     |           |   U2TX/SDA1                       |   USBUART_RTS
    _IOPORT_PB, // 15   RB10    |   IRQ1    |                                   |
    _IOPORT_PB  // 16   RB11    |   SDI1    |                                   |
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to a bit mask
** for the corresponding bit within the port.
*/
const uint16_t  digital_pin_to_bit_mask_PGM[] = {
    _BV(  0 ),   //   0   RA0
    _BV(  1 ),   //   1   RA1
    _BV(  0 ),   //   2   RB0
    _BV(  1 ),   //   3   RB1
    _BV(  2 ),   //   4   RB2
    _BV(  3 ),   //   5   RB3
    _BV( 15 ),   //   6   RB15
    _BV( 12 ),   //   7   RB12
    _BV( 13 ),   //   8   RB13
    _BV( 14 ),   //   9   RB14
    _BV(  5 ),   //  10   RB5
    _BV(  6 ),   //  11   RB6
    _BV(  7 ),   //  12   RB7
    _BV(  8 ),   //  13   RB8
    _BV(  9 ),   //  14   RB9
    _BV( 10 ),   //  15   RB10
    _BV( 11 )    //  16   RB11
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to the output
** compare number, input capture number, and timer external clock
** input associated with that pin.
*/
const uint16_t  digital_pin_to_timer_PGM[] = {
    _TIMER_OC1  , //   0   RA0
    _TIMER_OC2  , //   1   RA1
    _TIMER_OC3  , //   2   RB0
    _TIMER_OC2  , //   3   RB1
    _TIMER_OC4  , //   4   RB2
    _TIMER_OC1  , //   5   RB3
    _TIMER_OC1  , //   6   RB15
    NOT_ON_TIMER, //   7   RB12
    _TIMER_OC4  , //   8   RB13
    _TIMER_OC3  , //   9   RB14
    _TIMER_OC2  , //  10   RB5
    _TIMER_OC4  , //  11   RB6
    _TIMER_OC1  , //  12   RB7
    _TIMER_OC2  , //  13   RB8
    _TIMER_OC3  , //  14   RB9
    _TIMER_OC3  , //  15   RB10
    _TIMER_OC2    //  16   RB11
};

/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** PPS register. This register is used to select the peripheral output
** connected to the pin. The register is set to 0 to disconnect the
** pin from any peripheral so it can be used as GPIO.
** For PIC32MX1xx/2xx series devices, the PPS output select registers
** are arranged as a contiguous series of 32 bit registers. This table
** treats these registers as an array of DWORDs an stores the index
** to the register.
*/
const uint8_t digital_pin_to_pps_out_PGM[] = {
    _PPS_OUT(_PPS_RPA0R ),   //   0   RA0
    _PPS_OUT(_PPS_RPA1R ),   //   1   RA1
    _PPS_OUT(_PPS_RPB0R ),   //   2   RB0
    _PPS_OUT(_PPS_RPB1R ),   //   3   RB1
    _PPS_OUT(_PPS_RPB2R ),   //   4   RB2
    _PPS_OUT(_PPS_RPB3R ),   //   5   RB3
    _PPS_OUT(_PPS_RPB15R),   //   6   RB15
    NOT_PPS_PIN          ,   //   7   RB12
    _PPS_OUT(_PPS_RPB13R),   //   8   RB13
    _PPS_OUT(_PPS_RPB14R),   //   9   RB14
    _PPS_OUT(_PPS_RPB5R ),   //  10   RB5
    _PPS_OUT(_PPS_RPB6R ),   //  11   RB6
    _PPS_OUT(_PPS_RPB7R ),   //  12   RB7
    _PPS_OUT(_PPS_RPB8R ),   //  13   RB8
    _PPS_OUT(_PPS_RPB9R ),   //  14   RB9
    _PPS_OUT(_PPS_RPB10R),   //  15   RB10
    _PPS_OUT(_PPS_RPB11R)    //  16   RB11
};

/* ------------------------------------------------------------ */
/* This table maps from the digital pin number to the value to be
** loaded into a PPS input select register to select that pin.
** It also maps from digital pin number to input/output pin set to 
** which the pin belongs. The set mask is in the high four bits,
** the select value is in the low four bits.
** Note: if the PIC32 device has more than four pin sets, or more than
** 16 pin mapping choices per input function, then this table will have
** to be redefined as a table of uint16_t values and the macros used to
** access the table redefined as well.
*/
const uint8_t digital_pin_to_pps_in_PGM[] = {
    _PPS_IN(_PPS_RPA0 ),   //   0   RA0
    _PPS_IN(_PPS_RPA1 ),   //   1   RA1
    _PPS_IN(_PPS_RPB0 ),   //   2   RB0
    _PPS_IN(_PPS_RPB1 ),   //   3   RB1
    _PPS_IN(_PPS_RPB2 ),   //   4   RB2
    _PPS_IN(_PPS_RPB3 ),   //   5   RB3
    _PPS_IN(_PPS_RPB15),   //   6   RB15
    NOT_PPS_PIN        ,   //   7   RB12
    _PPS_IN(_PPS_RPB13),   //   8   RB13
    _PPS_IN(_PPS_RPB14),   //   9   RB14
    _PPS_IN(_PPS_RPB5 ),   //  10   RB5
    _PPS_IN(_PPS_RPB6 ),   //  11   RB6
    _PPS_IN(_PPS_RPB7 ),   //  12   RB7
    _PPS_IN(_PPS_RPB8 ),   //  13   RB8
    _PPS_IN(_PPS_RPB9 ),   //  14   RB9
    _PPS_IN(_PPS_RPB10),   //  15   RB10
    _PPS_IN(_PPS_RPB11)    //  16   RB11
 };

/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** analog pin number.
*/
//#if defined(_NOT_USED_)
const uint8_t digital_pin_to_analog_PGM[] = {
    0             , //  0   RA0    A0
    1             , //  1   RA1    A1
    2             , //  2   RB0    A2
    3             , //  3   RB1    A3
    4             , //  4   RB2    A4
    5             , //  5   RB3    A5
    6             , //  6   RB15   A6
    NOT_ANALOG_PIN, //  7   RB12
    NOT_ANALOG_PIN, //  8   RB13
    NOT_ANALOG_PIN, //  9   RB14
    NOT_ANALOG_PIN, // 10   RB5
    NOT_ANALOG_PIN, // 11   RB6
    NOT_ANALOG_PIN, // 12   RB7
    NOT_ANALOG_PIN, // 13   RB8
    NOT_ANALOG_PIN, // 14   RB9
    NOT_ANALOG_PIN, // 15   RB10
    NOT_ANALOG_PIN  // 16   RB11
};
//#endif

/* ------------------------------------------------------------ */
/* This table is used to map from the analog pin number to the
** actual A/D converter channel used for that pin.
** In the default case, where there is a one-to-one mapping, this
** table isn't needed as the analogInPinToChannel() macro is defined
** to provide the mapping.
*/
//#if defined(_NOT_USED_)
const uint8_t analog_pin_to_channel_PGM[] = {
                    //* Arduino Pin
    _BOARD_AN0 ,    //* A0
    _BOARD_AN1 ,    //* A1
    _BOARD_AN2 ,    //* A2
    _BOARD_AN3 ,    //* A3
    _BOARD_AN4 ,    //* A4
    _BOARD_AN5 ,    //* A5
    _BOARD_AN9      //* A6
};
//#endif

/* ------------------------------------------------------------ */
/* This table maps from an external interrupt number to the digital
** pin for that interrupt.
*/

const uint8_t external_int_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,        // INT0 is not mappable;   B7
    PIN_INT1,           // B14, B0, B10, B9;       B10  INT1R = RPB10
    PIN_INT2,           // B6, B13, B2     ;       B6   INT2R = RPB6
    PIN_INT3,           // A1, B5, B1, B11, B8;    B5   INT3R = RPB5
    PIN_INT4            // A0, B3, B15, B7;        B7   INT4R = RPB7
};

/* ------------------------------------------------------------ */
/*      Include Files for Board Customization Functions         */
/* ------------------------------------------------------------ */
#if (OPT_BOARD_INIT != 0)
#include <wiring.h>
#endif

/* ------------------------------------------------------------ */
/*              Board Customization Functions                   */
/* ------------------------------------------------------------ */
/*                                                              */
/* The following can be used to customize the behavior of some  */
/* of the core API functions. These provide hooks that can be   */
/* used to extend or replace the default behavior of the core   */
/* functions. To use one of these functions, add the desired    */
/* code to the function skeleton below and then set the value   */
/* of the appropriate compile switch above to 1. This will      */
/* cause the hook function to be compiled into the build and    */
/* to cause the code to call the hook function to be compiled   */
/* into the appropriate core function.                          */
/*                                                              */
/* ------------------------------------------------------------ */
/***    _board_init
**
**  Parameters:
**      none
**
**  Return Value:
**      none
**
**  Errors:
**      none
**
**  Description:
**      This function is called from the core init() function.
**      This can be used to perform any board specific init
**      that needs to be done when the processor comes out of
**      reset and before the user sketch is run.
*/
#if (OPT_BOARD_INIT != 0)
extern void _disableSeconaryOscillator(void);
void _softReset(void);

void _board_init(void) {
    pinMode(PIN_INT1, INPUT_PULLUP);
    attachInterrupt(1, _softReset, FALLING);
}

void _softReset() {
  executeSoftReset(ENTER_BOOTLOADER_ON_BOOT);
}
#endif

/* ------------------------------------------------------------ */
/***    _board_pinMode
**
**  Parameters:
**      pin     - digital pin number to configure
**      mode    - mode to which the pin should be configured
**
**  Return Value:
**      Returns 0 if not handled, !0 if handled.
**
**  Errors:
**      none
**
**  Description:
**      This function is called at the beginning of the pinMode
**      function. It can perform any special processing needed
**      when setting the pin mode. If this function returns zero,
**      control will pass through the normal pinMode code. If
**      it returns a non-zero value the normal pinMode code isn't
**      executed.
*/
#if (OPT_BOARD_DIGITAL_IO != 0)

int _board_pinMode(uint8_t pin, uint8_t mode) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_getPinMode
**
**  Parameters:
**      pin     - digital pin number
**      mode    - pointer to variable to receive mode value
**
**  Return Value:
**      Returns 0 if not handled, !0 if handled.
**
**  Errors:
**      none
**
**  Description:
**      This function is called at the beginning of the getPinMode
**      function. It can perform any special processing needed
**      when getting the pin mode. If this function returns zero,
**      control will pass through the normal getPinMode code. If
**      it returns a non-zero value the normal getPinMode code isn't
**      executed.
*/
#if (OPT_BOARD_DIGITAL_IO != 0)

int _board_getPinMode(uint8_t pin, uint8_t * mode) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_digitalWrite
**
**  Parameters:
**      pin     - digital pin number
**      val     - value to write to the pin
**
**  Return Value:
**      Returns 0 if not handled, !0 if handled.
**
**  Errors:
**      none
**
**  Description:
**      This function is called at the beginning of the digitalWrite
**      function. It can perform any special processing needed
**      in writing to the pin. If this function returns zero,
**      control will pass through the normal digitalWrite code. If
**      it returns a non-zero value the normal digitalWrite code isn't
**      executed.
*/
#if (OPT_BOARD_DIGITAL_IO != 0)

int _board_digitalWrite(uint8_t pin, uint8_t val) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_digitalRead
**
**  Parameters:
**      pin     - digital pin number
**      val     - pointer to variable to receive pin value
**
**  Return Value:
**      Returns 0 if not handled, !0 if handled.
**
**  Errors:
**      none
**
**  Description:
**      This function is called at the beginning of the digitalRead
**      function. It can perform any special processing needed
**      in reading from the pin. If this function returns zero,
**      control will pass through the normal digitalRead code. If
**      it returns a non-zero value the normal digitalRead code isn't
**      executed.
*/
#if (OPT_BOARD_DIGITAL_IO != 0)

int _board_digitalRead(uint8_t pin, uint8_t * val) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogRead
**
**  Parameters:
**      pin     - analog channel number
**      val     - pointer to variable to receive analog value
**
**  Return Value:
**      Returns 0 if not handled, !0 if handled.
**
**  Errors:
**      none
**
**  Description:
**      This function is called at the beginning of the analogRead
**      function. It can perform any special processing needed
**      in reading from the pin. If this function returns zero,
**      control will pass through the normal analogRead code. If
**      it returns a non-zero value the normal analogRead code isn't
**      executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int _board_analogRead(uint8_t pin, int * val) {

    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogReference
**
**  Parameters:
**
**  Return Value:
**      Returns 0 if not handled, !0 if handled.
**
**  Errors:
**      none
**
**  Description:
**      This function is called at the beginning of the analogReference
**      function. It can perform any special processing needed
**      to set the reference voltage. If this function returns zero,
**      control will pass through the normal analogReference code. If
**      it returns a non-zero value the normal analogReference code isn't
**      executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int _board_analogReference(uint8_t mode) {

    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogWrite
**
**  Parameters:
**      pin     - pin number
**      val     - analog value to write
**
**  Return Value:
**      Returns 0 if not handled, !0 if handled.
**
**  Errors:
**      none
**
**  Description:
**      This function is called at the beginning of the analogWrite
**      function. It can perform any special processing needed
**      in writing to the pin. If this function returns zero,
**      control will pass through the normal analogWrite code. If
**      it returns a non-zero value the normal analogWrite code isn't
**      executed.
*/
#if (OPT_BOARD_ANALOG_WRITE != 0)

int _board_analogWrite(uint8_t pin, int val) {

    return 0;

}

#endif

#endif // OPT_BOARD_DATA

/* ------------------------------------------------------------ */

#endif  // BOARD_DATA_C

/************************************************************************/
