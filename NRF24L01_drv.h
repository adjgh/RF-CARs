/*=======================================================
<<<<<<<<<<<<<<<<<<< 爱普雷德技术团队 >>>>>>>>>>>>>>>>>>>>
<<<<<<<<<<<<<<<<<<< 我们一起追求卓越 >>>>>>>>>>>>>>>>>>>>
---------------------------------------------------------
旗舰网店: http://aplid.taobao.com/
官方邮箱: njaplid@163.com
 技术QQ1: 535676091
 技术QQ2: 1915624375
 技术QQ3: 154211813
---------------------------------------------------------
               All right reserved.2013.01
---------------------------------------------------------
 文件名: NRF24L01_com_drv.h
 描述:无线模块通信头文件
 作者:
=========================================================
-----------------------------------------------------------------------------------------------------------*/
#ifndef __NRF24L01_H__
#define __NRF24L01_H__

#include <stc89c5xrc.h>
//#include <reg52.h>

#define uint unsigned int
#define uchar unsigned char

//****************************************IO端口定义***************************************
//****************************************NRF24L01端口定义***************************************
sbit MISO_A = P1^6;
sbit MOSI_A = P1^5;
sbit SCK_A  = P1^7;
sbit CE_A   = P3^5;
sbit CSN_A  = P3^4;
sbit IRQ_A  = P3^3;

//****************************************NRF24L01 B端口定义***************************************


sbit MISO_B = P2^5;
sbit MOSI_B = P2^3;
//sbit SCK_B+  = P2^1;
sbit CE_B   = P2^7;
//sbit CSN_B  = P2^0;
sbit CSN_B  = P2^2;
sbit SCK_B  = P2^6;
sbit IRQ_B  = P2^4;

extern uchar sta_A;
#define RX_DR_A  (sta_A & 0x40)
#define TX_DS_A  (sta_A & 0x20)
#define MAX_RT_A (sta_A & 0x10)

extern uchar sta_B;
#define RX_DR_B  (sta_B & 0x40)
#define TX_DS_B  (sta_B & 0x20)
#define MAX_RT_B (sta_B & 0x10)

#define TX_ADR_WIDTH    5    // 5 uints TX address width
#define RX_ADR_WIDTH    5    // 5 uints RX address width
#define TX_PLOAD_WIDTH  20   // 20 uints TX payload
#define RX_PLOAD_WIDTH  20   // 20 uints TX payload

//***************************************NRF24L01寄存器指令*******************************************************
#define READ_REG        0x00   // 读寄存器指令
#define WRITE_REG       0x20  // 写寄存器指令
#define RD_RX_PLOAD     0x61   // 读取接收数据指令
#define WR_TX_PLOAD     0xA0   // 写待发数据指令
#define FLUSH_TX        0xE1  // 冲洗发送 FIFO指令
#define FLUSH_RX        0xE2   // 冲洗接收 FIFO指令
#define REUSE_TX_PL     0xE3   // 定义重复装载数据指令
#define NOP             0xFF   // 保留
//*************************************SPI(nRF24L01)寄存器地址****************************************************
#define CONFIG          0x00  // 配置收发状态，CRC校验模式以及收发状态响应方式
#define EN_AA           0x01  // 自动应答功能设置
#define EN_RXADDR       0x02  // 可用信道设置
#define SETUP_AW        0x03  // 收发地址宽度设置
#define SETUP_RETR      0x04  // 自动重发功能设置
#define RF_CH           0x05  // 工作频率设置
#define RF_SETUP        0x06  // 发射速率、功耗功能设置
#define STATUS          0x07  // 状态寄存器
#define OBSERVE_TX      0x08  // 发送监测功能
#define CD              0x09  // 地址检测           
#define RX_ADDR_P0      0x0A  // 频道0接收数据地址
#define RX_ADDR_P1      0x0B  // 频道1接收数据地址
#define RX_ADDR_P2      0x0C  // 频道2接收数据地址
#define RX_ADDR_P3      0x0D  // 频道3接收数据地址
#define RX_ADDR_P4      0x0E  // 频道4接收数据地址
#define RX_ADDR_P5      0x0F  // 频道5接收数据地址
#define TX_ADDR         0x10  // 发送地址寄存器
#define RX_PW_P0        0x11  // 接收频道0接收数据长度
#define RX_PW_P1        0x12  // 接收频道0接收数据长度
#define RX_PW_P2        0x13  // 接收频道0接收数据长度
#define RX_PW_P3        0x14  // 接收频道0接收数据长度
#define RX_PW_P4        0x15  // 接收频道0接收数据长度
#define RX_PW_P5        0x16  // 接收频道0接收数据长度
#define FIFO_STATUS     0x17  // FIFO栈入栈出状态寄存器设置

//void Delay(unsigned int s);
void delayms(unsigned int count);
//void init_NRF24L01_A(void);
void init_NRF24L01_B(void);
//uchar SPI_RW_A(uchar byte);
uchar SPI_RW_B(uchar byte);
//uchar SPI_Read_A(uchar reg);
uchar SPI_Read_B(uchar reg);
//uchar SPI_RW_Reg_A(uchar reg, uchar value);
uchar SPI_RW_Reg_B(uchar reg, uchar value);
//uchar SPI_Read_Buf_A(uchar reg, uchar *pBuf, uchar num);
uchar SPI_Read_Buf_B(uchar reg, uchar *pBuf, uchar num);
//uchar SPI_Write_Buf_A(uchar reg, uchar *pBuf, uchar num);
uchar SPI_Write_Buf_B(uchar reg, uchar *pBuf, uchar num);
//void SetRX_Mode_A(void);
void SetRX_Mode_B(void);
//unsigned char nRF24L01_RxPacket_A(unsigned char *rx_buf);
//unsigned char nRF24L01_RxPacket_B(unsigned char *rx_buf);
//void nRF24L01_TxPacket_A(unsigned char * tx_buf);
//void nRF24L01_TxPacket_B(unsigned char * tx_buf);
unsigned char ReadByte(void);

#endif
