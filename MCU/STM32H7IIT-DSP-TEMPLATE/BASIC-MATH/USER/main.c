#include "sys.h"
#include "delay.h"
#include "usart.h" 
#include "led.h"
#include "key.h"
#include "ltdc.h"
#include "lcd.h"
#include "sdram.h"
#include "usmart.h"
#include "pcf8574.h"
#include "mpu.h"
#include "malloc.h"
#include "w25qxx.h"
#include "sdmmc_sdcard.h"
#include "timer.h"
#include "arm_math.h"
/************************************************
 ALIENTEK 阿波罗STM32H7开发板 实验52_1
 DSP BasicMath 实验-HAL库函数版
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

#define	DELTA	0.00005f		//误差值
 
//sin cos测试
//angle:起始角度
//times:运算次数
//mode:0,不使用DSP库;1,使用DSP库
//返回值：0,成功;0XFF,出错
u8 sin_cos_test(float angle,u32 times,u8 mode)
{
	float sinx,cosx;
	float result;
	u32 i=0;
	if(mode==0)
	{
		for(i=0;i<times;i++)
		{
			cosx=cosf(angle);			//不使用DSP优化的sin，cos函数
			sinx=sinf(angle);
			result=sinx*sinx+cosx*cosx; //计算结果应该等于1  
			result=fabsf(result-1.0f);	//对比与1的差值
			if(result>DELTA)return 0XFF;//判断失败 
			angle+=0.001f;				//角度自增
		}
	}else
	{
		for(i=0;i<times;i++)
		{
            
			cosx=arm_cos_f32(angle);	//使用DSP优化的sin，cos函数
			sinx=arm_sin_f32(angle);
			result=sinx*sinx+cosx*cosx; //计算结果应该等于1  
			result=fabsf(result-1.0f);	//对比与1的差值
			if(result>DELTA)return 0XFF;//判断失败 
			angle+=0.001f;				//角度自增
		}
	}
	return 0;//任务完成
} 
u8 timeout;

int main(void)
{
	float time; 
	u8 buf[50];
	u8 res;
	
	Cache_Enable();                			//打开L1-Cache
	MPU_Memory_Protection();        		//保护相关存储区域
	HAL_Init();				        		//初始化HAL库
	Stm32_Clock_Init(160,5,2,4);  		    //设置时钟,400Mhz 
	delay_init(400);						//延时初始化
	uart_init(115200);						//串口初始化
	usmart_dev.init(200); 		    		//初始化USMART	
	LED_Init();								//初始化LED
	KEY_Init();								//初始化按键
	SDRAM_Init();                   		//初始化SDRAM
	LCD_Init();								//初始化LCD
    TIM3_Init(65535,20000-1);               //10Khz计数频率,最大计时6.5秒超出
    POINT_COLOR=RED; 
	LCD_ShowString(30,50,200,16,16,"Apollo STM32H7");	
	LCD_ShowString(30,70,200,16,16,"DSP BasicMath TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2018/6/14");	
	LCD_ShowString(30,150,200,16,16," No DSP runtime:");	//显示提示信息
	LCD_ShowString(30,190,200,16,16,"Use DSP runtime:");	//显示提示信息	
 	POINT_COLOR=BLUE;	//设置字体为蓝色
	while(1)
	{
 		//不使用DSP优化
        __HAL_TIM_SET_COUNTER(&TIM3_Handler,0);//重设TIM3定时器的计数器值
		timeout=0;
		res=sin_cos_test(PI/6,200000,0);
        time=__HAL_TIM_GET_COUNTER(&TIM3_Handler)+(u32)timeout*65536;
		sprintf((char*)buf,"%0.1fms\r\n",time/10);
		if(res==0)LCD_ShowString(30+16*8,150,100,16,16,buf);	//显示运行时间		
		else LCD_ShowString(30+16*8,150,100,16,16,"error！");	//显示当前运行情况	
		//使用DSP优化		
		__HAL_TIM_SET_COUNTER(&TIM3_Handler,0);//重设TIM3定时器的计数器值
		timeout=0;
		res=sin_cos_test(PI/6,200000,1);
		time=__HAL_TIM_GET_COUNTER(&TIM3_Handler)+(u32)timeout*65536;
		sprintf((char*)buf,"%0.1fms\r\n",time/10);
		if(res==0)LCD_ShowString(30+16*8,190,100,16,16,buf);	//显示运行时间	
		else LCD_ShowString(30+16*8,190,100,16,16,"error！");	//显示错误	
		LED0_Toggle; 
	}		 
}

