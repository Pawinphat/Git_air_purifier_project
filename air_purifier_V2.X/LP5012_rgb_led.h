/* 
 * File:   LP5012_rgb_led.h
 * Author: Tiraporn
 *
 * Created on November 3, 2021, 4:01 PM
 */

#ifndef LP5012_RGB_LED_H
#define	LP5012_RGB_LED_H

#ifdef	__cplusplus
extern "C" {
#endif
       
#ifdef	__cplusplus
}
#endif

#endif	/* LP5012_RGB_LED_H */

#include <stdbool.h>
#include <stdint.h>
#include "mcc_generated_files/i2c1.h"
#include "mcc_generated_files/i2c2.h"

#define LP5012_SLAVE_ADR    0x18

 #define SLAVE_I2C_GENERIC_RETRY_MAX           100
 #define SLAVE_I2C_GENERIC_DEVICE_TIMEOUT      50   // define slave timeout 

#define LP5012_SetColorBlue() LP5012_SetColor(0, 0, 255)
#define LP5012_SetColorRed() LP5012_SetColor(255, 0, 0)
#define LP5012_SetColorGreen() LP5012_SetColor(0, 255, 0)
#define LP5012_SetColorOrange() LP5012_SetColor(255, 48, 0)
#define LP5012_SetColorPurple() LP5012_SetColor(48, 0, 255)

typedef enum
{
    DEVICE_CONFIG0=0,
    DEVICE_CONFIG1,
    LED_CONFIG0,
    BANK_BRIGHTNESS,
    BANK_A_COLOR,
    BANK_B_COLOR,
    BANK_C_COLOR,
    LED0_BRIGHTNESS,
    LED1_BRIGHTNESS,
    LED2_BRIGHTNESS,
    LED3_BRIGHTNESS,
    OUT0_COLOR,
    OUT1_COLOR,
    OUT2_COLOR,
    OUT3_COLOR,
    OUT4_COLOR,
    OUT5_COLOR,
    OUT6_COLOR,
    OUT7_COLOR,
    OUT8_COLOR,
    OUT9_COLOR,
    OUT10_COLOR,
    OUT11_COLOR,
    RESET,
}LP5012_REG;


 

void Intial_LP5012 (void);
void LP5012_SetColor(uint8_t r, uint8_t g, uint8_t b);
void LP5012_SetColor_down_led(uint8_t r, uint8_t g, uint8_t b);
void LP5012_SetColor_left_led(uint8_t r, uint8_t g, uint8_t b);
void LP5012_SetColor_right_led(uint8_t r, uint8_t g, uint8_t b);
void LP5012_SetColor_top_led(uint8_t r, uint8_t g, uint8_t b);
void LP5012_SetBrightness(uint8_t brightness);
void LP5012_Set_DIMMER_LED_PER_UNITS (uint8_t led_down, uint8_t led_left,  
                                      uint8_t led_right,uint8_t led_top);
//void LED_bank_or_Independent_mode (bool bool_setting);
void LP5012_Write (void);
uint8_t EMC1001_Read(uint8_t reg, uint8_t *pData);
void TestRead ();


uint8_t MCHP24AA512_Read(
                                            uint16_t address,
                                            uint8_t *pData,
                                            uint16_t nCount);

