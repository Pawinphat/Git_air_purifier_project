/* 
 * File:   main.h
 * Author: Tiraporn
 *
 * Created on October 29, 2021, 1:27 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define FCY 25000000UL
#include <libpic30.h>


#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

#include <stdbool.h>
#include <stdint.h>

typedef struct{
    bool bool_new_refresh_display;
    bool bool_new_touch_switch;
    bool bool_Lock_switch;
    uint8_t u8Mem_time_on;
    uint8_t u8Mem_time_off;
    uint32_t u32Count_timer_filter;
    uint8_t u8Speedfan;
    
    // mode 0: force display, 
    //      1: temperature
    //      2: Humidity
    //      3: PM2.5
    uint8_t u8Display_mode; 
    uint8_t au8Send_to_sevensegments[3]; // digit 1 -3 
    float fDHT10_Temperature;
    float fDHT10_Humidity;
    float fPM2_5;
}type_status_system;

extern type_status_system t_using_status_system;

void initial_program_config (void);
void ClearStatus_led (void);

