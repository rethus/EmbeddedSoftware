#include <REGX52.H>

/**
  *	@brief	定时器0初始化，1毫秒@12.000MHz
  *	@param	无
  *	@retval	无
  */
void Timer0_Init(void) {
	TMOD &= 0xF0;		// 把TMOD的低四位清零，高四位保持不变；& 1111 0000
	TMOD |= 0x01;		// 把TMOD的最低位置一，高四位保持不变；| 0000 0001
	TL0 = 0x18;		// 设置定时初值，64535 / 256
	TH0 = 0xFC;		// 设置定时初值，64535 % 256 + 1
	TF0 = 0;		// 清除TF0标志
	TR0 = 1;		// 定时器0开始计时
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}

/*
// 定时器中断函数模板，不方便模块化
void Timer0_Routine() interrupt 1 { 
	static unsigned int T0Count;
	TL0 = 0x18;
	TH0 = 0xFC;
	T0Count ++;
	if(T0Count >= 1000) {
		T0Count = 0;
		// function()
		// eg: P2_0 = ~P2_0;
	}	
}
*/