/* 
 * File:   Display_control.h
 * Author: Tiraporn
 *
 * Created on November 1, 2021, 7:23 PM
 */

#ifndef DISPLAY_CONTROL_H
#define	DISPLAY_CONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* DISPLAY_CONTROL_H */


typedef struct{
    uint8_t u8Led_on;
    uint8_t u8Led_off;
    uint8_t u8Led_1hr;
    uint8_t u8Led_2hr;
    uint8_t u8Led_4hr;
    uint8_t u8Led_8hr;
    uint8_t u8Led_dimmer;
    uint8_t u8Led_uv;
}typeLED;

extern typeLED t_UsingStructLED;

typedef struct{
    uint8_t u8Ledfan_auto_spa;       // PIN SPA
    uint8_t u8Ledfan_low_spl;        // pin SPL
    uint8_t u8Ledfan_medium_spm;     // pin SPM
    uint8_t u8Ledfan_high_sph;       // pin SPH
    uint8_t u8Ledfan_lock;           // pin lock key
    uint8_t u8Ledfan_reset_filter;   // pin reset (show status filter expire)
    uint8_t u8Ledfan_ion;            // pin ion working
}typeLED_FAN;

extern typeLED_FAN t_UsingStructLED_FAN;

uint16_t LED_sum_valueStruct (uint8_t u8SelectStruct);

void LED_Clear_data (void);
void Sevensegments_Clear (void);

void Refresh_Display (void);

