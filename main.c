/***************************************************************************
  FileName:        main.c
  Processor:       ATSAML10E16
  IDE :            SEGGER ver 4.16
  Created by:      http://strefapic.blogspot.com
 ***************************************************************************/
/*-------------------------------------------------------------------------*/
/* SI4463 RF Transciver TX send test                                      */
/*-------------------------------------------------------------------------*/
//    Signal SI4463 ---> MCU ATSAML10E16
//     MOSI                     --> PA10  
//     MISO                     --> PA09  
//     SCK                      --> PA11  
//     nSEL                     --> PA08  
//     SDN                      --> PA02  
//     IRQ                      --> PA03  
//     GPIO0                    --> PA16  
//                              
//----------------------------------------
//     LED                      --> PA27
//
/*-------------------------------------------------------------------------*/
/* ILI9341 LCD TFT 320x240 SPI connect                                        */
/*-------------------------------------------------------------------------*/
//    Signal LCD ---> MCU ATSAML10E16
//     CS     (Chip Select)     --> Ground
//     RESET                    --> PA06
//     DC/RS  (Command / Data)  --> PA07
//     MOSI   (Serial Data)     --> PA24
//     SCK    (Serial Clock)    --> PA25
//     LED                      --> +3.3V
//***************************************************************************

#include <saml10.h>
#include <stdio.h>
#include <stdlib.h>
#include "delay.h"
#include "system.h"
#include "spi.h"
#include "eic_manager.h"
#include "radio_config_Si4463.h"
#include "si4463.h"
#include "ili9341.h"


void SysTick_Stop(void);
void SysTick_Start(void);

#define LED_TOG (REG_PORT_OUTTGL0 = PORT_PA27)  //toggle PA27

uint8_t data_buff[]="DATA";
uint8_t send_buff[64];
uint16_t volatile licznik = 30 ; //for TX, number of message sent
volatile uint8_t Soft_Timer1 = 0 , Soft_Timer2 = 0, irq_flag = 0;

int main(void)
{
  /*Select BUCK converter as the main voltage regulator in active mode*/
  //SUPC->VREG.bit.SEL = 1; 
  /* Wait for the regulator switch to be completed */
  //while(!(SUPC->STATUS.reg & SUPC_STATUS_VREGRDY));
  
  /* Initialize the SAM system */
    SystemInit();   //standard system init
    MySystemInit(); //user system init
 
    ili9341_init(); // init LCD
    setOrientation(PORTRAIT); //PORTRAIT, LANSCAPE, PORTRAIT_REV, LANDSCAPE_REV  

    putString("Test SI4463 TX", 30, 30, 2, GREEN_YELLOW); 
    
    SI4463_Init();
    
    SI4463_Get_Interrupt(inter_buff); //get interrupt status and clear interrupt
     
    uint8_t i=0, len=0;
    len = sizeof(data_buff); //calculate the data length
    send_buff[0] = len;  //enter the data length on the first position of the transmit buffer
           
    for (i=1 ; i < len; i++){
      send_buff[i] =  data_buff[i-1]; //enter the data into the transmitting buffer starting from the second position
    }
     
    /* Set SysTick */
    SysTick_Config(4000000UL * 0.1); //0.1s, 4MHz core clock       
    SI4463_Set_Power_TX(0x0A); // 0x0A about 5 dB see datasheet page 36, Figure 11 for TX
    
    EIC3_Start(); //start interrupt from EIC
    
    while (1)
    {
      /*TX - send message*/            
       if(!Soft_Timer1) {
              Soft_Timer1 = 3 ; //Timer1 tick x Soft_Timer1 = 100ms x 3 = 300ms
              SI4463_Send_Data( send_buff, sizeof(data_buff)+1 , 0 ) ; //send data from send_buff
              }  
      /*wait for the irq_flag flag and display the counter of sent messages on the LCD display*/
       if(irq_flag) {
              irq_flag = 0;
              clr(30, 100, 5);
              putInteger(licznik,30, 100,3,YELLOW);
                      
           }
      }
  }

void EIC_3_Handler(void){
        SI4463_Get_Interrupt(inter_buff); //get interrupt status and clear interrupt
        if(inter_buff[2] & 0x20) {//PACKET_SENT_PEND interruption ? , see API Documentation GET_INT_STATUS
        if(!--licznik) SysTick_Stop();  
        irq_flag = 1;
        LED_TOG;
        }
    /* Clear EIC Flag */
    EIC->INTFLAG.reg |= EIC_INTFLAG_EXTINT(1<<3);    
}

/* Routime Interrupt */

void SysTick_Handler(void){
 uint8_t x;
        x = Soft_Timer1 ;
        if (x) Soft_Timer1 = --x ;
        x = Soft_Timer2 ;
        if (x) Soft_Timer2 = --x ;
       }


void SysTick_Stop(void){
SysTick->CTRL  =  !SysTick_CTRL_TICKINT_Msk;
SysTick->CTRL  =  !SysTick_CTRL_ENABLE_Msk;                         /* Disable SysTick IRQ and SysTick Timer */
}

void SysTick_Start(void){
SysTick->CTRL  =  SysTick_CTRL_TICKINT_Msk;
SysTick->CTRL  =  SysTick_CTRL_ENABLE_Msk;                         /* Enable SysTick IRQ and SysTick Timer */
}

