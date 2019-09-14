/***************************************************************************
  FileName:        eic.c
  Processor:       ATSAML21G18B
  IDE :            SEGGER ver 4.20
  Created by:      http://strefapic.blogspot.com
 ***************************************************************************/
/*-------------------------------------------------------------------------*/
/* EIC module configuration                                                */
/*-------------------------------------------------------------------------*/
#include <saml10.h>
#include <stdio.h>
#include <stdlib.h>


void EIC_Manager_init(void){;
REG_EIC_CONFIG0 |= EIC_CONFIG_SENSE3_RISE;
REG_EIC_CTRLA |= EIC_CTRLA_ENABLE;
while (EIC->SYNCBUSY.bit.ENABLE) { }; //wait synchro
 /*** Enable interrupt on EXTINT[3] (PA03) ***/
EIC->INTENSET.reg = (EIC_INTENSET_EXTINT((1<<3)));
NVIC_EnableIRQ(EIC_3_IRQn);

}