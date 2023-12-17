/*
	
  ******************************************************************************
  * @file 			( фаил ):   PAJ7620U2.h
  * @brief 		( описание ):  	
  ******************************************************************************
  * @attention 	( внимание ):	author: Golinskiy Konstantin	e-mail: golinskiy.konstantin@gmail.com
  ******************************************************************************
  
*/

#ifndef _PAJ7620U2_H
#define _PAJ7620U2_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------*/

#include "main.h"


// num i2c ---------------------------------------------
#define PAJ7620U2_I2C										hi2c1

//------------------------------------------------------




extern I2C_HandleTypeDef PAJ7620U2_I2C;

#define DEV_Delay_ms(__xms)							HAL_Delay(__xms)

/*-----------------------------------------------------------------------------*/

//i2c address
#define PAJ7620U2_I2C_ADDRESS				(0x73<<1)


//Register Bank select
#define PAJ_BANK_SELECT							0xEF		//Bank0=0x00,Bank1=0x01

//Register ID ( read only )
#define PAJ_PART_ID_L								0x00		// result 0x20
#define PAJ_PART_ID_H								0x01		// result 0x76
#define PAJ_VERSION_ID							0x02		// result 0x01


//Register Bank 0
#define PAJ_SUSPEND			 						0x03		//I2C suspend command (Write 0x01 to enter suspend state). I2C wake-up command is slave ID wake-up. Refer to topic I2C Bus Timing Characteristics and Protocol
#define PAJ_INT_FLAG1_MASK					0x41		//Gesture detection interrupt flag mask
#define PAJ_INT_FLAG2_MASK					0x42		//Gesture/PS detection interrupt flag mask
#define PAJ_INT_FLAG1		    				0x43		//Gesture detection interrupt flag
#define PAJ_INT_FLAG2								0x44		//Gesture/PS detection interrupt flag
#define PAJ_STATE										0x45		//State indicator for gesture detection (Only functional at gesture detection mode)
#define PAJ_PS_HIGH_THRESHOLD				0x69		//PS hysteresis high threshold (Only functional at proximity detection mode)	
#define PAJ_PS_LOW_THRESHOLD				0x6A		//PS hysteresis low threshold (Only functional at proximity detection mode)
#define PAJ_PS_APPROACH_STATE				0x6B		//PS approach state,  Approach = 1 , (8 bits PS data >= PS high threshold),  Not Approach = 0 , (8 bits PS data <= PS low threshold)(Only functional at proximity detection mode)
#define PAJ_PS_DATA									0x6C		//PS 8 bit data(Only functional at gesture detection mode)
#define PAJ_OBJ_BRIGHTNESS					0xB0		//Object Brightness (Max. 255)
#define PAJ_OBJ_SIZE_L							0xB1		//Object Size(Low 8 bit)		
#define PAJ_OBJ_SIZE_H							0xB2		//Object Size(High 8 bit)

//Register Bank 1
#define PAJ_PS_GAIN									0x44		//PS gain setting (Only functional at proximity detection mode)
#define PAJ_IDLE_S1_STEP_L					0x67		//IDLE S1 Step, for setting the S1, Response Factor(Low 8 bit)
#define PAJ_IDLE_S1_STEP_H					0x68		//IDLE S1 Step, for setting the S1, Response Factor(High 8 bit)	
#define PAJ_IDLE_S2_STEP_L					0x69		//IDLE S2 Step, for setting the S2, Response Factor(Low 8 bit)
#define PAJ_IDLE_S2_STEP_H					0x6A		//IDLE S2 Step, for setting the S2, Response Factor(High 8 bit)
#define PAJ_OPTOS1_TIME_L						0x6B		//OPtoS1 Step, for setting the OPtoS1 time of operation state to standby 1 state(Low 8 bit)
#define PAJ_OPTOS2_TIME_H						0x6C		//OPtoS1 Step, for setting the OPtoS1 time of operation state to standby 1 stateHigh 8 bit)
#define PAJ_S1TOS2_TIME_L						0x6D		//S1toS2 Step, for setting the S1toS2 time of standby 1 state to standby 2 state(Low 8 bit)
#define PAJ_S1TOS2_TIME_H						0x6E		//S1toS2 Step, for setting the S1toS2 time of standby 1 state to standby 2 stateHigh 8 bit)
#define PAJ_EN											0x72		//Enable/Disable PAJ7620U2


//Gesture detection interrupt flag
#define PAJ_NONE										0x0000	// отсутствует
#define PAJ_UP				    					0x0001 	// вверх
#define PAJ_DOWN			    					0x0002	// вниз
#define PAJ_LEFT			    					0x0004 	// влево
#define PAJ_RIGHT			    					0x0008	// вправо
#define PAJ_FORWARD			    				0x0010 	// вперед
#define PAJ_BACKWARD		    				0x0020	// назад
#define PAJ_CLOCKWISE								0x0040	// по часовой стрелке
#define PAJ_ANTI_CLOCKWISE					0x0080	// против часовой стрелки
#define PAJ_WAVE										0x0100	// волна


#define PAJ_PARTID  								0x7620


//Power up initialize array
extern const uint8_t Init_Register_Array[][2];


//Initialize array size
#define Init_Array 									sizeof(Init_Register_Array)/2


//Bank 0 or 1 
typedef enum:uint8_t{
	PAJ_BANK_0,			//Bank0 = 0x00
	PAJ_BANK_1			//Bank1 = 0x01
}Paj_Bank_Num;



/* Functions prototypes ----------------------------------------------*/


uint16_t PAJ7620U2_init(void);

uint16_t PAJ7620U2_Gesture_ReadData(void);
uint8_t PAJ7620U2_PS_ReadObjBrightness(void);
uint16_t PAJ7620U2_PS_ReadObjSize(void);

//------------------------------------------------------------------------------------


#ifdef __cplusplus
}
#endif

#endif	/*	_PAJ7620U2_H */

/************************ (C) COPYRIGHT GKP *****END OF FILE****/
