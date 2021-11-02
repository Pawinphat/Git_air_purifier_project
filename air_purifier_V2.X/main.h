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
    uint8_t u8Speedfan;
}type_status_system;

extern type_status_system t_using_status_system;

void initial_program_config (void);
void ClearStatus_led (void);

