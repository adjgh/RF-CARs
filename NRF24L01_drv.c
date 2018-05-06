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
 �ļ���: NRF24L01.c
 ����:����ģ��ͨ��c �ļ�
 ����:
=========================================================
-----------------------------------------------------------------------------------------------------------*/
#include "NRF24L01_drv.h"
uchar  TX_ADDRESS[TX_ADR_WIDTH]= {0x12,0x34,0x56,0x78,0x90}; //���ص�ַ
uchar  RX_ADDRESS[RX_ADR_WIDTH]= {0x12,0x34,0x56,0x78,0x90}; //���յ�ַ

uchar  sta_A;   //״̬��־
uchar  sta_B;   //״̬��־

sbit right_wheel_back = P1^0;
sbit right_wheel_go = P1^1;
sbit left_wheel_back = P1^2;
sbit left_wheel_go = P1^3;
/**********************************************
���ܣ�
    ��ʱ
���������
    s: ��ʱʱ��
���������
    ��
����ֵ��
**********************************************/
//void Delay(unsigned int s)
//{
//	unsigned int i;
//	for(i=0; i<s; i++);
//	for(i=0; i<s; i++);
//}

/**********************************************
���ܣ�
    ������ʱ
���������
    count: ��ʱ������
���������
    ��
����ֵ��
**********************************************/
void delayms(unsigned int count)
{
	unsigned int i,j;
	for(i=0;i<count;i++)
	{
		for(j=0;j<120;j++);
	}
}
 
/**********************************************
 ���ܣ�
	 ����ģ��A ��ʼ��
 ���������
	 ��
 ���������
	 ��
 ����ֵ��
 **********************************************/
//void init_NRF24L01_A(void)
//{
//	delayms(1);
//	CE_A=0;
//	CSN_A=1;
//	SCK_A=0;
//	SPI_Write_Buf_A(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // д���ص�ַ 
//	SPI_Write_Buf_A(WRITE_REG + RX_ADDR_P0, RX_ADDRESS, RX_ADR_WIDTH); // д���ն˵�ַ
//	SPI_RW_Reg_A(WRITE_REG + EN_AA, 0x01);      //  Ƶ��0�Զ� ACKӦ������ 
//	SPI_RW_Reg_A(WRITE_REG + EN_RXADDR, 0x01);  //  ������յ�ַֻ��Ƶ��0�������Ҫ��Ƶ�����Բο�Page21  
//	SPI_RW_Reg_A(WRITE_REG + RF_CH, 0);        //   �����ŵ�����Ϊ2.4GHZ���շ�����һ��
//	SPI_RW_Reg_A(WRITE_REG + RX_PW_P0, 1); //���ý������ݳ��ȣ���������Ϊ1�ֽ�
//	SPI_RW_Reg_A(WRITE_REG + RF_SETUP, 0x07);     //���÷�������Ϊ1MHZ�����书��Ϊ���ֵ0dB
//}

/**********************************************
 ���ܣ�
	 ����ģ��B ��ʼ��
 ���������
	 ��
 ���������
	 ��
 ����ֵ��
 **********************************************/
void init_NRF24L01_B(void)
{
	delayms(1);
	CE_B=0;
	CSN_B=1;
	SCK_B=0;
	SPI_Write_Buf_B(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // д���ص�ַ 
	SPI_Write_Buf_B(WRITE_REG + RX_ADDR_P0, RX_ADDRESS, RX_ADR_WIDTH); // д���ն˵�ַ
	SPI_RW_Reg_B(WRITE_REG + EN_AA, 0x01);      //  Ƶ��0�Զ� ACKӦ������ 
	SPI_RW_Reg_B(WRITE_REG + EN_RXADDR, 0x01);  //  ������յ�ַֻ��Ƶ��0�������Ҫ��Ƶ�����Բο�Page21  
	SPI_RW_Reg_B(WRITE_REG + RF_CH, 0);        //   �����ŵ�����Ϊ2.4GHZ���շ�����һ��
	SPI_RW_Reg_B(WRITE_REG + RX_PW_P0, 1); //���ý������ݳ��ȣ���������Ϊ1�ֽ�
	SPI_RW_Reg_B(WRITE_REG + RF_SETUP, 0x07);     //���÷�������Ϊ1MHZ�����书��Ϊ���ֵ0dB
}

/**********************************************
 ���ܣ�
	 ����ģ��A ��SPIдʱ��
 ���������
	 byte :д������(�ֽ�)
 ���������
	 ��
 ����ֵ��
 	��������
 **********************************************/
//uchar SPI_RW_A(uchar byte)
//{
//	uchar i;
//	for(i=0;i<8;i++)
//	{
//		MOSI_A = (byte & 0x80);
//		byte = (byte << 1);  
//		SCK_A = 1;
//		byte |= MISO_A;
//		SCK_A = 0;
//	}
//	return(byte);
//}

/**********************************************
 ���ܣ�
	 ����ģ��B ��SPIдʱ��
 ���������
	 byte :д������(�ֽ�)
 ���������
	 ��
 ����ֵ��
 	��������
 **********************************************/
uchar SPI_RW_B(uchar byte)
{
	uchar i;
	for(i=0;i<8;i++)
	{
		MOSI_B = (byte & 0x80);
		byte = (byte << 1);
		SCK_B = 1;
		byte |= MISO_B;
		SCK_B = 0;
	}
	return(byte);
}

/**********************************************
 ���ܣ�
	 ������ģ��A 
 ���������
	 reg : ���ļĴ�����ַ
 ���������
	 ��
 ����ֵ��
 	����������
 **********************************************/
//uchar SPI_Read_A(uchar reg)
//{
//	uchar reg_val;
//	CSN_A = 0; 
//	SPI_RW_A(reg);  
//	reg_val = SPI_RW_A(0); 
//	CSN_A = 1;   
//	return(reg_val); 
//}

/**********************************************
 ���ܣ�
	 ������ģ��B
 ���������
	 reg : ���ļĴ�����ַ
 ���������
	 ��
 ����ֵ��
 	����������
 **********************************************/
uchar SPI_Read_B(uchar reg)
{
	uchar reg_val;
	CSN_B = 0;              
	SPI_RW_B(reg);        
	reg_val = SPI_RW_B(0);  
	CSN_B = 1;          
	return(reg_val);     
}

/**********************************************
 ���ܣ�
	 ����ģ��A ��д
 ���������
	 reg : ���ļĴ�����ַ
	 value :д�������
 ���������
	 ��
 ����ֵ��
 	����������
 **********************************************/
//uchar SPI_RW_Reg_A(uchar reg, uchar value)
//{
//	uchar status;
//	CSN_A = 0;  
//	status = SPI_RW_A(reg);    
//	SPI_RW_A(value);            
//	CSN_A = 1;                  
//	return(status);           
//}

/**********************************************
 ���ܣ�
	 ����ģ��B ��д
 ���������
	 reg : ���ļĴ�����ַ
	 value :д�������
 ���������
	 ��
 ����ֵ��
 	����������
 **********************************************/
uchar SPI_RW_Reg_B(uchar reg, uchar value)
{
	uchar status;
	CSN_B = 0;             
	status = SPI_RW_B(reg);    
	SPI_RW_B(value);          
	CSN_B = 1;               
	return(status);  
}

/**********************************************
 ���ܣ�
	 ������ģ��A ��������
 ���������
	 reg : �Ĵ�����ַ
	 pBuf : ���������ݵ�ַ
	 num : �������ݵĸ���
 ���������
	 ��
 ����ֵ��
 **********************************************/
//uchar SPI_Read_Buf_A(uchar reg, uchar *pBuf, uchar num)
//{
//	uchar status,i;
//	CSN_A = 0;               
//	status = SPI_RW_A(reg);      
//	for(i=0;i<num;i++)
//		pBuf[i] = SPI_RW_A(0);   
//	CSN_A = 1;                           
//	return(status);                
//}

/**********************************************
 ���ܣ�
	 ������ģ��B ��������
 ���������
	 reg : �Ĵ�����ַ
	 pBuf : ���������ݵ�ַ
	 num : �������ݵĸ���
 ���������
	 ��
 ����ֵ��
 **********************************************/
//uchar SPI_Read_Buf_B(uchar reg, uchar *pBuf, uchar num)
//{
//	uchar status,i;
//	CSN_B = 0;            
//	status = SPI_RW_B(reg);        
//	for(i=0;i<num;i++)
//		pBuf[i] = SPI_RW_B(0);   
//	CSN_B = 1;                           
//	return(status);              
//}

/**********************************************
 ���ܣ�
	 ����ģ��A д������
 ���������
	 reg : �Ĵ�����ַ
	 pBuf : ��д�����ݵ�ַ
	 num : д�����ݵĸ���
 ���������
	 ��
 ����ֵ��
 **********************************************/
//uchar SPI_Write_Buf_A(uchar reg, uchar *pBuf, uchar num)
//{
//	uchar status,i;
//	CSN_A = 0;           
//	status = SPI_RW_A(reg);   
//	for(i=0; i<num; i++)
//		SPI_RW_A(*pBuf++);
//	CSN_A = 1;          
//	return(status);     
//}

/**********************************************
 ���ܣ�
	 ����ģ��B д������
 ���������
	 reg : �Ĵ�����ַ
	 pBuf : ��д�����ݵ�ַ
	 num : д�����ݵĸ���
 ���������
	 ��
 ����ֵ��
 **********************************************/
uchar SPI_Write_Buf_B(uchar reg, uchar *pBuf, uchar num)
{
	uchar status,i;
	CSN_B = 0;         
	status = SPI_RW_B(reg);   
	for(i=0; i<num; i++) 
		SPI_RW_B(*pBuf++);
	CSN_B = 1;         
	return(status);    
}

/**********************************************
 ���ܣ�
	 ��������ģ��A Ϊ����ģʽ
 ���������
	 ��
 ���������
	 ��
 ����ֵ��
 **********************************************/
//void SetRX_Mode_A(void)
//{
//	CE_A = 0;
//	SPI_RW_Reg_A(WRITE_REG + CONFIG, 0x0f);     
//	CE_A = 1; 
//	delayms(1);
//}

/**********************************************
 ���ܣ�
	 ��������ģ��B Ϊ����ģʽ
 ���������
	 ��
 ���������
	 ��
 ����ֵ��
 **********************************************/
void SetRX_Mode_B(void)
{
	CE_B = 0;
	SPI_RW_Reg_B(WRITE_REG + CONFIG, 0x0f);  
	CE_B = 1; 
	delayms(1);
}

/**********************************************
 ���ܣ�
	 ����ģ��A ���յ�������
 ���������
	 rx_buf : �յ������ݷ���rx_buf����
 ���������
	 ��
 ����ֵ��
 	�Ƿ���յ�����
 **********************************************/
//unsigned char nRF24L01_RxPacket_A(unsigned char *rx_buf)
//{
//	unsigned char revale=0;
//	sta_A=SPI_Read_A(STATUS); 
//	if(RX_DR_A)   
//	{
//		CE_A = 0;    
//		SPI_Read_Buf_A(RD_RX_PLOAD,rx_buf,TX_PLOAD_WIDTH);
//		revale =1;   
//	}
//	SPI_RW_Reg_A(WRITE_REG+STATUS,sta_A);  
//	return revale;
//}

/**********************************************
 ���ܣ�
	 ����ģ��B ���յ�������
 ���������
	 rx_buf : �յ������ݷ���rx_buf����
 ���������
	 ��
 ����ֵ��
 	�Ƿ���յ�����
 **********************************************/
//unsigned char nRF24L01_RxPacket_B(unsigned char *rx_buf)
//{
//	unsigned char revale=0;
//	sta_B=SPI_Read_B(STATUS); 
//	if(RX_DR_B)   
//	{
//		CE_B = 0;  
//		SPI_Read_Buf_B(RD_RX_PLOAD,rx_buf,TX_PLOAD_WIDTH);
//		revale =1; 
//	}
//	SPI_RW_Reg_B(WRITE_REG+STATUS,sta_B); 
//	return revale;
//}

/**********************************************
 ���ܣ�
	 ����ģ��A ��������
 ���������
	 tx_buf : ���͵�����
 ���������
	 ��
 ����ֵ��
 **********************************************/
//void nRF24L01_TxPacket_A(unsigned char *tx_buf)
//{
//	CE_A=0;   
//	SPI_Write_Buf_A(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH); 
//	SPI_Write_Buf_A(WR_TX_PLOAD, tx_buf, TX_PLOAD_WIDTH);    
//	SPI_RW_Reg_A(WRITE_REG + CONFIG, 0x0e);     
//	CE_A=1;  
//	delayms(1);
//}

/**********************************************
 ���ܣ�
	 ����ģ��B ��������
 ���������
	 tx_buf : ���͵�����
 ���������
	 ��
 ����ֵ��
 **********************************************/
//void nRF24L01_TxPacket_B(unsigned char *tx_buf)
//{
//	CE_B=0;  
//	SPI_Write_Buf_B(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH);
//	SPI_Write_Buf_B(WR_TX_PLOAD, tx_buf, TX_PLOAD_WIDTH);  
//	SPI_RW_Reg_B(WRITE_REG + CONFIG, 0x0e);     
//	CE_B=1;  
//	delayms(1);
//}