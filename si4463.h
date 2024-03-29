/***************************************************************************
  FileName:        si4463.h
  Processor:       ATSAML10E16
  IDE :            SEGGER ver 4.16
  Created by:      http://strefapic.blogspot.com
 ***************************************************************************/
/*-------------------------------------------------------------------------*/
/* SI4463 RF Transciver test                                        */
/*-------------------------------------------------------------------------*/
//    Signal SI4463 ---> MCU ATSAML10E16
//     MOSI                     --> PA10
//     MISO                     --> PA09
//     SCK                      --> PA11
//     nSEL                     --> PA08
//     SDN                      --> PA02
//     IRQ                      --> PA03
//     GPIO0                    --> PA16
//    ------------------------------------
//     LED                      --> PA27
//
//***************************************************************************
#include <saml10.h>
#include <stdio.h>
#include <stdlib.h>
#include "delay.h"
#include "system.h"
#include "spi.h"

#define SI4463_nSEL_HIGH            (REG_PORT_OUTSET0 = PORT_PA08) 
#define SI4463_nSEL_LOW             (REG_PORT_OUTCLR0 = PORT_PA08) 
#define SI4463_SDN_HIGH             (REG_PORT_OUTSET0 = PORT_PA02)
#define SI4463_SDN_LOW              (REG_PORT_OUTCLR0 = PORT_PA02)
#define IO_nIRQ_GetValue            (REG_PORT_IN0 & PORT_PA03)
#define CTS_GPIO0                   (REG_PORT_IN0 & PORT_PA16)

typedef enum {NOCHANGE,SLEEP,SPI_ACTIVE,READY,TX_TUNE,RX_TUNE,TX,RX} state;

extern uint8_t inter_buff[8] ; //interrupt bufor for GET_INT_STATUS
//------------------------------- SI4463_Read_Buffor ------------------------------
void SI4463_Read_Buffor( uint8_t *rd_buff, uint8_t len );

//------------------------------- SI4463_Wait_CTS ------------------------------
void SI4463_Wait_CTS( void );

//------------------------------- SI4463_Wait_GPIO_CTS ------------------------------
void SI4463_Wait_GPIO_CTS( void );

//------------------------------- SI4463_Send_Without_CTS ----------------------
void SI4463_Send_Without_CTS( uint8_t *get_buff, uint8_t len );

//------------------------------- SI4463_Send_With_CTS -------------------------
void SI4463_Send_With_CTS( uint8_t *set_buff, uint8_t len );

//------------------------------- SI4463_Get_Interrupt ------------------------------
void SI4463_Get_Interrupt( uint8_t *inter_buff );

//------------------------------- SI4463_TX_Start ------------------------------
void SI4463_TX_Start( uint8_t channel_tx, uint8_t size );

//------------------------------- SI4463_RX_Start ------------------------------
void SI4463_RX_Start( uint8_t channel_rx, uint8_t size );

//------------------------------- SI4463_TX_FIFO ------------------------------
void SI4463_TX_FIFO ( uint8_t *buff_tx, uint8_t len );

//------------------------------- SI4463_RX_FIFO ------------------------------
void SI4463_RX_FIFO ( uint8_t *buff_rx, uint8_t len );

//------------------------------- SI4463_Clear_TX_FIFO ------------------------------
void SI4463_Clear_TX_FIFO( void );

//------------------------------- SI4463_Clear_RX_FIFO ------------------------------
void SI4463_Clear_RX_FIFO( void );

//------------------------------- SI4463_Part_Info ------------------------------
void SI4463_Part_Info( uint8_t *inter_buff );

//------------------------------- SI4463_Send_Data ------------------------------
void SI4463_Send_Data( uint8_t *send_dt, uint8_t size, uint8_t channel );

//------------------------------- SI4463_Read_Data ------------------------------
void SI4463_Read_Data( uint8_t *read_dt, uint8_t size, uint8_t channel );

//------------------------------- SI4463_Init ----------------------------------
void SI4463_Init( );

//------------------------------- SI4463_Patch ---------------------------------
//void SI4463_Patch( void );

//------------------------------- SI4463_getRSSI -------------------------------
int16_t SI4463_getRSSI();

//------------------------------- SI4463_Chip_Status----------------------------
void SI4463_Get_Chip_Status( uint8_t *inter_buff );

//------------------------------- SI4463_Get_PH_Status -------------------------
void SI4463_Get_PH_Status( uint8_t *buff );

//------------------------------- SI4463_Get_Packet_Info -----------------------
uint8_t SI4463_Get_Packet_Info( void );

//------------------------------- SI4463_Set_Power_TX --------------------------
void SI4463_Set_Power_TX( uint8_t power );

//------------------------------- SI4463_Change_State --------------------------
void SI4463_Change_State( state next_state );



#define SI4463_CMD_POWER_UP			0x02
#define SI4463_CMD_NOP				0x00
#define SI4463_CMD_PART_INFO			0x01
#define SI4463_CMD_FUNC_INFO			0x10
#define SI4463_CMD_SET_PROPERTY			0x11
#define SI4463_CMD_GET_PROPERTY			0x12
#define SI4463_CMD_GPIO_PIN_CFG			0x13
#define SI4463_CMD_FIFO_INFO			0x15
#define SI4463_CMD_GET_INT_STATUS		0x20
#define SI4463_CMD_REQUEST_DEVICE_STATE         0x33
#define SI4463_CMD_CHANGE_STATE			0x34
#define SI4463_CMD_READ_CMD_BUFF		0x44
#define SI4463_CMD_READ_FRR_A			0x50
#define SI4463_CMD_READ_FRR_B			0x51
#define SI4463_CMD_READ_FRR_C			0x53
#define SI4463_CMD_READ_FRR_D			0x57
#define SI4463_CMD_IRCAL			0x17
#define SI4463_CMD_IRCAL_MANUAL			0x1a
#define SI4463_CMD_START_TX			0x31
#define SI4463_CMD_TX_HOP			0x37
#define SI4463_CMD_WRITE_TX_FIFO		0x66
#define SI4463_CMD_PACKET_INFO			0x16
#define SI4463_CMD_GET_MODEM_STATUS		0x22
#define SI4463_CMD_START_RX			0x32
#define SI4463_CMD_RX_HOP			0x36
#define SI4463_CMD_READ_RX_FIFO			0x77
#define SI4463_CMD_GET_ADC_READING		0x14
#define SI4463_CMD_GET_PH_STATUS		0x21
#define SI4463_CMD_GET_CHIP_STATUS              0x23

