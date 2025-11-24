#include "xc.h"
#include "stdint.h"
#include "RGBmatrixPanel.h"

// CW1: FLASH CONFIGURATION WORD 1 (see PIC24 Family Reference Manual 24.1)
#pragma config ICS = PGx1          // Comm Channel Select (Emulator EMUC1/EMUD1 pins are shared with PGC1/PGD1)
#pragma config FWDTEN = OFF        // Watchdog Timer Enable (Watchdog Timer is disabled)
#pragma config GWRP = OFF          // General Code Segment Write Protect (Writes to program memory are allowed)
#pragma config GCP = OFF           // General Code Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF        // JTAG Port Enable (JTAG port is disabled)


// CW2: FLASH CONFIGURATION WORD 2 (see PIC24 Family Reference Manual 24.1)
#pragma config I2C1SEL = PRI       // I2C1 Pin Location Select (Use default SCL1/SDA1 pins)
#pragma config IOL1WAY = OFF       // IOLOCK Protection (IOLOCK may be changed via unlocking seq)
#pragma config OSCIOFNC = ON       // Primary Oscillator I/O Function (CLKO/RC15 functions as I/O pin)
#pragma config FCKSM = CSECME      // Clock Switching and Monitor (Clock switching is enabled, 
                                       // Fail-Safe Clock Monitor is enabled)
#pragma config FNOSC = FRCPLL      // Oscillator Select (Fast RC Oscillator with PLL module (FRCPLL))

void setup(void) {
    /* Sets up the PIC24 to be used by the program. Sets the instruction cycle
     * to be 62.5 ns and initializes the digital ports.
     */
    
    CLKDIVbits.RCDIV = 0;  //Set RCDIV=1:1 (default 2:1) 32MHz or FCY/2=16M
    // Digital Port Initialization
    AD1PCFG = 0x9fff;            // sets all pins to digital I/O
    
    // TRISB or RB pins for what to output to the RGB matrix
    // Rows are decided like this:
    // C B A (3-bits that apply to both the upper and lower part of a 16x32 section)
    //
    // Assume CBA = 0b000;
    // D at 0 makes CBA represent row 0, while D at 1 makes CBA represent row 8
    
    // No UART, SPI, or I2C needed to drive the RGB matrix
}
int main(void) {
    setup();
    while (1) {
        
    }
    return 0;
}
