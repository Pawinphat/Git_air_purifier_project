#include "74595.h"
#include "Display_control.h"
#include "main.h"


//Diplay (0..9 for seven segment common anode
/*
   -------------------     -------------------
    | Digit | Hex  |        | Digit | Hex  |
   -------------------     -------------------
        0   | 0x3F |            A   | 0x77 |
        1   | 0x06 |            B   | 0x7C |
        2   | 0x5B |            C   | 0x39 |
        3   | 0x4F |            d   | 0x5E |
        4   | 0x66 |            E   | 0x79 |
        5   | 0x6D |            F   | 0x71 |
        6   | 0x7D |            H   | 0x36 |
        7   | 0x07 |            L   | 0x38 |
        8   | 0x7F |            -   | 0x40 |
        9   | 0x6F |        'blank' | 0x00 |
   -------------------     -------------------     

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
        Nop();
        u16Data_ledfan = LED_sum_valueStruct(1);
        Nop(); 
        
        HC595SendValue_many_IC_PORT_1(u16Data_ledfan,HC595_MSB_FIRST,0);
        HC595SendValue_many_IC_PORT_1(u16Data_led,HC595_MSB_FIRST,1);
    }
    t_using_status_system.bool_new_refresh_display = false;
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



void sevensegment_display (void)
{
    uint8_t pointer;
    
    pointer = table_font_sevensegment[2];
    Nop();
}



void SevenSegments_Clear (void)
{
    
}









/*
 * ********************************************************
 */

