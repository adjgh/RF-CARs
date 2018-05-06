/*=======================================================
<<<<<<<<<<<<<<<<<<< �����׵¼����Ŷ� >>>>>>>>>>>>>>>>>>>>
<<<<<<<<<<<<<<<<<<< ����һ��׷��׿Խ >>>>>>>>>>>>>>>>>>>>
---------------------------------------------------------
�콢����: http://aplid.taobao.com/
�ٷ�����: njaplid@163.com
 ����QQ1: 535676091
 ����QQ2: 1915624375
 ����QQ3: 154211813
---------------------------------------------------------
               All right reserved.2013.01
---------------------------------------------------------
 �ļ���: NRF24L01_com_drv.h
 ����:����ģ��ͨ��ͷ�ļ�
 ����:
=========================================================
-----------------------------------------------------------------------------------------------------------*/
#ifndef __NRF24L01_H__
#define __NRF24L01_H__

#include <stc89c5xrc.h>
//#include <reg52.h>

#define uint unsigned int
#define uchar unsigned char

//****************************************IO�˿ڶ���***************************************
//****************************************NRF24L01�˿ڶ���***************************************
sbit MISO_A = P1^6;
sbit MOSI_A = P1^5;
sbit SCK_A  = P1^7;
sbit CE_A   = P3^5;
sbit CSN_A  = P3^4;
sbit IRQ_A  = P3^3;

//****************************************NRF24L01 B�˿ڶ���***************************************


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

//***************************************NRF24L01�Ĵ���ָ��*******************************************************
#define READ_REG        0x00   // ���Ĵ���ָ��
#define WRITE_REG       0x20  // д�Ĵ���ָ��
#define RD_RX_PLOAD     0x61   // ��ȡ��������ָ��
#define WR_TX_PLOAD     0xA0   // д��������ָ��
#define FLUSH_TX        0xE1  // ��ϴ���� FIFOָ��
#define FLUSH_RX        0xE2   // ��ϴ���� FIFOָ��
#define REUSE_TX_PL     0xE3   // �����ظ�װ������ָ��
#define NOP             0xFF   // ����
//*************************************SPI(nRF24L01)�Ĵ�����ַ****************************************************
#define CONFIG          0x00  // �����շ�״̬��CRCУ��ģʽ�Լ��շ�״̬��Ӧ��ʽ
#define EN_AA           0x01  // �Զ�Ӧ��������
#define EN_RXADDR       0x02  // �����ŵ�����
#define SETUP_AW        0x03  // �շ���ַ�������
#define SETUP_RETR      0x04  // �Զ��ط���������
#define RF_CH           0x05  // ����Ƶ������
#define RF_SETUP        0x06  // �������ʡ����Ĺ�������
#define STATUS          0x07  // ״̬�Ĵ���
#define OBSERVE_TX      0x08  // ���ͼ�⹦��
#define CD              0x09  // ��ַ���           
#define RX_ADDR_P0      0x0A  // Ƶ��0�������ݵ�ַ
#define RX_ADDR_P1      0x0B  // Ƶ��1�������ݵ�ַ
#define RX_ADDR_P2      0x0C  // Ƶ��2�������ݵ�ַ
#define RX_ADDR_P3      0x0D  // Ƶ��3�������ݵ�ַ
#define RX_ADDR_P4      0x0E  // Ƶ��4�������ݵ�ַ
#define RX_ADDR_P5      0x0F  // Ƶ��5�������ݵ�ַ
#define TX_ADDR         0x10  // ���͵�ַ�Ĵ���
#define RX_PW_P0        0x11  // ����Ƶ��0�������ݳ���
#define RX_PW_P1        0x12  // ����Ƶ��0�������ݳ���
#define RX_PW_P2        0x13  // ����Ƶ��0�������ݳ���
#define RX_PW_P3        0x14  // ����Ƶ��0�������ݳ���
#define RX_PW_P4        0x15  // ����Ƶ��0�������ݳ���
#define RX_PW_P5        0x16  // ����Ƶ��0�������ݳ���
#define FIFO_STATUS     0x17  // FIFOջ��ջ��״̬�Ĵ�������

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
