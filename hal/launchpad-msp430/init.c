
#include <init.h>
//#include "launchpad-msp430.h"
#include <io.h>

void system_init(void)
{
    WDTCTL = WDTPW + WDTHOLD;	// Stop WDT
    BCSCTL3 |= LFXT1S_2;	//Set ACLK to use internal VLO (12 kHz clock)
}
