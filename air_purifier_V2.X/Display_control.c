#include "74595.h"
#include "Display_control.h"
#include "main.h"


//Diplay (0..9 for seven segment common anode
/*
   ------------------------      ------------------------             
    | NUMBER| FONT | Hex  |      | NUMBER|  FONT  | Hex  | 
   ------------------------      ------------------------  
       0   |   0   | 0x3F |           10 |   A    | 0x77 |
       1   |   1   | 0x06 |           11 |   B    | 0x7C |
       2   |   2   | 0x5B |           12 |   C    | 0x39 |
       3   |   3   | 0x4F |           13 |   d    | 0x5E |
       4   |   4   | 0x66 |           14 |   E    | 0x79 |
       5   |   5   | 0x6D |           15 |   F    | 0x71 |
       6   |   6   | 0x7D |           16 |   H    | 0x36 |
       7   |   7   | 0x07 |           17 |   L    | 0x38 |
       8   |   8   | 0x7F |           18 |   -    | 0x40 |
       9   |   9   | 0x6F |           19 |'blank' | 0x00 |
    ------------------------         ----------------------     

 */
__eds__ char table_font_sevensegment[] __attribute__((space(psv))) = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 
                                                                      0x6D, 0x7D, 0x07, 0x7F, 0x6F,
                                                                      0x77, 0x7C, 0x39, 0x5E, 0x79, 
                                                                      0x71, 0x76, 0x38, 0x40, 0x00};

void Refresh_Display (void)
{
    uint16_t u16Data_led;
    uint16_t u16Data_ledfan;
    uint16_t u16Data_sevensegment;
   
    if(t_using_status_system.bool_new_refresh_display){
        u16Data_led = LED_sum_valueStruct(0);
        u16Data_ledfan = LED_sum_valueStruct(1);
        
        t_using_status_system.u8Display_mode = 0;
        load_data_to_display();
        
        HC595SendValue_many_IC_PORT_1(u16Data_ledfan,HC595_MSB_FIRST,0);
        HC595SendValue_many_IC_PORT_1(u16Data_led,HC595_MSB_FIRST,1);
       
        HC595SendValue_many_IC_PORT_2(table_font_sevensegment[t_using_status_system.au8Send_to_sevensegments[0]]
                                                              ,HC595_MSB_FIRST,0);
        HC595SendValue_many_IC_PORT_2(table_font_sevensegment[t_using_status_system.au8Send_to_sevensegments[1]]
                                                              ,HC595_MSB_FIRST,0);
        HC595SendValue_many_IC_PORT_2(table_font_sevensegment[t_using_status_system.au8Send_to_sevensegments[2]]
                                                              ,HC595_MSB_FIRST,1);
         
        t_using_status_system.bool_new_refresh_display = false;
    }
}



/*
 * Display Control LED Status
 * ********************************************************
 */

typeLED t_UsingStructLED;
typeLED_FAN t_UsingStructLED_FAN;

uint16_t LED_sum_valueStruct (uint8_t u8SelectStruct)
{
    uint16_t u16ReturnValue;
    
    if(u8SelectStruct == 0){
        u16ReturnValue = (uint16_t)((t_UsingStructLED.u8Led_on*1) +
                                    (t_UsingStructLED.u8Led_off*2)+
                                    (t_UsingStructLED.u8Led_1hr*4) +
                                    (t_UsingStructLED.u8Led_2hr*8) + 
                                    (t_UsingStructLED.u8Led_4hr*16) + 
                                    (t_UsingStructLED.u8Led_8hr*32) + 
                                    (t_UsingStructLED.u8Led_dimmer*64) +
                                    (t_UsingStructLED.u8Led_uv*128));
    } 
    else{
        u16ReturnValue = (uint16_t)((t_UsingStructLED_FAN.u8Ledfan_auto_spa*1) +
                                    (t_UsingStructLED_FAN.u8Ledfan_low_spl*2) +
                                    (t_UsingStructLED_FAN.u8Ledfan_medium_spm*4) +
                                    (t_UsingStructLED_FAN.u8Ledfan_high_sph*8) +
                                    (t_UsingStructLED_FAN.u8Ledfan_lock*16) +
                                    (t_UsingStructLED_FAN.u8Ledfan_reset_filter*32) +
                                    (t_UsingStructLED_FAN.u8Ledfan_ion*64));
    }
    return u16ReturnValue;
}



/*
 * ********************************************************
 */



/*
 * Display Control Seven Segments Status
 * ********************************************************
 */



void load_data_to_display (void)
{
    static uint8_t countLoop;
    static uint8_t saveloop;
    
    switch (t_using_status_system.u8Display_mode){
        case 0: // default is not code
            if(countLoop <= 17){
                t_using_status_system.au8Send_to_sevensegments[0] = countLoop;
                t_using_status_system.au8Send_to_sevensegments[1] = countLoop+1;
                t_using_status_system.au8Send_to_sevensegments[2] = countLoop+2;
            }
            else{
                countLoop = 0;
            }
                countLoop = countLoop +1;
                break;
        case 1:
                break;
        case 2:
                break;
        case 3:
                break;
        default:
                break;
    }
}



void Sevensegments_Clear (void)
{
    
}

void Sevensegments_convert_float_to_display (void)
{
    
}


/*
 * ********************************************************
 */

