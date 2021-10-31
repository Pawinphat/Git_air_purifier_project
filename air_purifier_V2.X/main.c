/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.169.0
        Device            :  PIC24EP256GP206
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.50
        MPLAB 	          :  MPLAB X v5.40
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/* ******************************************* 
 *
 * BOARD        : AIR PURIFIER V 1.1
 * FIRMWARE     : V 2.0 BETA 1
 * CPU          : PIC24EP256GP206 
 * SPEED        : XTAL 8 MHZ
 * PLL          : PLLPRE 2; DOZE 1:8; PLLPOST 1:4
 * FEEDBACK PLL : PLLFBD 50;
 * FOSC         : 50 MHz
 * FOSC/2       : 25 MHz
 * TIMER 2      : INTRRVAL 238 uS 
 *              : DESIGNED FOR PWM (LED, SEVENSEGMENT) AND BUZZER (2100 KHz)
 * TIMER 4      : INTRTVAL 1.5 mS
 *              : DESIGNED FOR TIMING TASK MANAGER
 * COMPAMY      : ES
 * ENGINEER     : TIRAPORN.
 * 
 * *******************************************
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr2.h"
#include "main.h"
#include "74595.h"

void Delaytime (uint16_t del);

/*
                         Main application
 */
int main(void)
{
    uint8_t u8Loop;
    // initialize the device
    SYSTEM_Initialize();
    
  //  OP_BUZZER_SetLow();
    TMR2_Stop();
    
    
    HC595Init_PORT_1();
    OP_LED_PWM_SetHigh();

    HC595SendValue_many_IC_PORT_1(0x00,HC595_LSB_FIRST,0);
    HC595SendValue_many_IC_PORT_1(0x00,HC595_LSB_FIRST,1);
    
    while (1)
    {
        HC595SendValue_many_IC_PORT_1(0xF,HC595_LSB_FIRST,0);
        HC595SendValue_many_IC_PORT_1(0x4,HC595_LSB_FIRST,1);
        __delay_ms(2000);  
        HC595SendValue_many_IC_PORT_1(0x4,HC595_LSB_FIRST,0);
        HC595SendValue_many_IC_PORT_1(0xF,HC595_LSB_FIRST,1);
        __delay_ms(2000); 
      //  OP_BUZZER_Toggle();
      //  __delay_us(100);
      /*  OP_BUZZER_Toggle();
        for(u8Loop = 0; u8Loop < 100; u8Loop++){
            Delaytime(3);
        }*/
        



        
        
        // Add your application code
    }

    return 1;
}

void Delaytime (uint16_t del)
{
    for(del=del; del>0; del--);
}


/**
 End of File
*/

