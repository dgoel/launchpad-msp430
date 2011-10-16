
#include <init.h>
//#include "launchpad-msp430.h"
#include <io.h>

void system_init(void)
{
    WDTCTL = WDTPW + WDTHOLD;	// Stop WDT

	//BCSCTL1 = CALBC1_1MHZ;			// Set range
	// DCOCTL = CALDCO_1MHZ;			// SMCLK = DCO = 1MHz  

    DCOCTL |= (DCO0 | DCO1 | DCO2); // highest frequency
    BCSCTL1 |= (RSEL0 | RSEL1 | RSEL2); // config DCOCLK as 1MHz

    // set ACLK divider to nothing
    BCSCTL1 &= ~(DIVA0 | DIVA1);

    // select DCOCLK as MCLK with no divider
    BCSCTL2 &= ~(SELM0 | SELM1 | DIVM_0);

    // select DCOCLK as SMCLK source with no divider
    BCSCTL2 &= ~(SELS | DIVS_3);

    // set ACLK to use internal VLO (12 kHz clock)
    BCSCTL3 |= LFXT1S_2;
}
