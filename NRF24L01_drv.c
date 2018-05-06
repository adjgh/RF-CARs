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
 文件名: NRF24L01.c
 描述:无线模块通信c 文件
 作者:
=========================================================
-----------------------------------------------------------------------------------------------------------*/
#include "NRF24L01_drv.h"
uchar  TX_ADDRESS[TX_ADR_WIDTH]= {0x12,0x34,0x56,0x78,0x90}; //本地地址
uchar  RX_ADDRESS[RX_ADR_WIDTH]= {0x12,0x34,0x56,0x78,0x90}; //接收地址

uchar  sta_A;   //状态标志
uchar  sta_B;   //状态标志

sbit right_wheel_back = P1^0;
sbit right_wheel_go = P1^1;
sbit left_wheel_back = P1^2;
sbit left_wheel_go = P1^3;
/**********************************************
功能：
    延时
输入参数：
    s: 延时时间
输出参数：
    无
返回值：
**********************************************/
//void Delay(unsigned int s)
//{
//	unsigned int i;
//	for(i=0; i<s; i++);
//	for(i=0; i<s; i++);
//}

/**********************************************
功能：
    毫秒延时
输入参数：
    count: 延时毫秒数
输出参数：
    无
返回值：
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
 功能：
	 无线模块A 初始化
 输入参数：
	 无
 输出参数：
	 无
 返回值：
 **********************************************/
//void init_NRF24L01_A(void)
//{
//	delayms(1);
//	CE_A=0;
//	CSN_A=1;
//	SCK_A=0;
//	SPI_Write_Buf_A(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // 写本地地址 
//	SPI_Write_Buf_A(WRITE_REG + RX_ADDR_P0, RX_ADDRESS, RX_ADR_WIDTH); // 写接收端地址
//	SPI_RW_Reg_A(WRITE_REG + EN_AA, 0x01);      //  频道0自动 ACK应答允许 
//	SPI_RW_Reg_A(WRITE_REG + EN_RXADDR, 0x01);  //  允许接收地址只有频道0，如果需要多频道可以参考Page21  
//	SPI_RW_Reg_A(WRITE_REG + RF_CH, 0);        //   设置信道工作为2.4GHZ，收发必须一致
//	SPI_RW_Reg_A(WRITE_REG + RX_PW_P0, 1); //设置接收数据长度，本次设置为1字节
//	SPI_RW_Reg_A(WRITE_REG + RF_SETUP, 0x07);     //设置发射速率为1MHZ，发射功率为最大值0dB
//}

/**********************************************
 功能：
	 无线模块B 初始化
 输入参数：
	 无
 输出参数：
	 无
 返回值：
 **********************************************/
void init_NRF24L01_B(void)
{
	delayms(1);
	CE_B=0;
	CSN_B=1;
	SCK_B=0;
	SPI_Write_Buf_B(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);    // 写本地地址 
	SPI_Write_Buf_B(WRITE_REG + RX_ADDR_P0, RX_ADDRESS, RX_ADR_WIDTH); // 写接收端地址
	SPI_RW_Reg_B(WRITE_REG + EN_AA, 0x01);      //  频道0自动 ACK应答允许 
	SPI_RW_Reg_B(WRITE_REG + EN_RXADDR, 0x01);  //  允许接收地址只有频道0，如果需要多频道可以参考Page21  
	SPI_RW_Reg_B(WRITE_REG + RF_CH, 0);        //   设置信道工作为2.4GHZ，收发必须一致
	SPI_RW_Reg_B(WRITE_REG + RX_PW_P0, 1); //设置接收数据长度，本次设置为1字节
	SPI_RW_Reg_B(WRITE_REG + RF_SETUP, 0x07);     //设置发射速率为1MHZ，发射功率为最大值0dB
}

/**********************************************
 功能：
	 无线模块A 的SPI写时序
 输入参数：
	 byte :写的内容(字节)
 输出参数：
	 无
 返回值：
 	读的内容
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
 功能：
	 无线模块B 的SPI写时序
 输入参数：
	 byte :写的内容(字节)
 输出参数：
	 无
 返回值：
 	读的内容
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
 功能：
	 读无线模块A 
 输入参数：
	 reg : 读的寄存器地址
 输出参数：
	 无
 返回值：
 	读到的内容
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
 功能：
	 读无线模块B
 输入参数：
	 reg : 读的寄存器地址
 输出参数：
	 无
 返回值：
 	读到的内容
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
 功能：
	 无线模块A 读写
 输入参数：
	 reg : 读的寄存器地址
	 value :写入的数据
 输出参数：
	 无
 返回值：
 	读到的内容
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
 功能：
	 无线模块B 读写
 输入参数：
	 reg : 读的寄存器地址
	 value :写入的数据
 输出参数：
	 无
 返回值：
 	读到的内容
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
 功能：
	 从无线模块A 读出数据
 输入参数：
	 reg : 寄存器地址
	 pBuf : 待读出数据地址
	 num : 读出数据的个数
 输出参数：
	 无
 返回值：
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
 功能：
	 从无线模块B 读出数据
 输入参数：
	 reg : 寄存器地址
	 pBuf : 待读出数据地址
	 num : 读出数据的个数
 输出参数：
	 无
 返回值：
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
 功能：
	 无线模块A 写入数据
 输入参数：
	 reg : 寄存器地址
	 pBuf : 待写入数据地址
	 num : 写入数据的个数
 输出参数：
	 无
 返回值：
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
 功能：
	 无线模块B 写入数据
 输入参数：
	 reg : 寄存器地址
	 pBuf : 待写入数据地址
	 num : 写入数据的个数
 输出参数：
	 无
 返回值：
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
 功能：
	 配置无线模块A 为接收模式
 输入参数：
	 无
 输出参数：
	 无
 返回值：
 **********************************************/
//void SetRX_Mode_A(void)
//{
//	CE_A = 0;
//	SPI_RW_Reg_A(WRITE_REG + CONFIG, 0x0f);     
//	CE_A = 1; 
//	delayms(1);
//}

/**********************************************
 功能：
	 配置无线模块B 为接收模式
 输入参数：
	 无
 输出参数：
	 无
 返回值：
 **********************************************/
void SetRX_Mode_B(void)
{
	CE_B = 0;
	SPI_RW_Reg_B(WRITE_REG + CONFIG, 0x0f);  
	CE_B = 1; 
	delayms(1);
}

/**********************************************
 功能：
	 无线模块A 接收到的数据
 输入参数：
	 rx_buf : 收到的数据放在rx_buf里面
 输出参数：
	 无
 返回值：
 	是否接收到数据
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
 功能：
	 无线模块B 接收到的数据
 输入参数：
	 rx_buf : 收到的数据放在rx_buf里面
 输出参数：
	 无
 返回值：
 	是否接收到数据
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
 功能：
	 无线模块A 发送数据
 输入参数：
	 tx_buf : 发送的内容
 输出参数：
	 无
 返回值：
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
 功能：
	 无线模块B 发送数据
 输入参数：
	 tx_buf : 发送的内容
 输出参数：
	 无
 返回值：
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