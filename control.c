#include "control.h"


void ENTER_CONTROL_MODE(void)
{
	uint8_t txBuff[5]={0};
	txBuff[0] = 0xAA;
	txBuff[1] = 5;
	txBuff[2] = CMD_ENTER_CONTROL_MODE;
	txBuff[3] = xor_check(txBuff,5);
	txBuff[4] = 0xBB;
	
	HAL_UART_Transmit(&huart1,txBuff,sizeof(txBuff),1000);
}

uint8_t xor_check(uint8_t *buff, uint8_t size)
{
	uint8_t VS = 0x0;
	for(uint8_t i = 0;i<size-3;i++)//异或检验，不校验帧头帧尾
	{
		VS ^= buff[i+1];
	}
	return VS;
}
