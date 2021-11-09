/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.c

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
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


/**
    Section: Includes
*/

#include <xc.h>
#include <stdio.h>
#include "pin_manager.h"

/**
 Section: Driver Interface Function Definitions
*/
void PIN_MANAGER_Initialize (void)
{
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0800;
    LATB = 0x0840;
    LATC = 0x0009;
    LATD = 0x0000;
    LATE = 0x0000;
    LATF = 0x0001;
    LATG = 0x0000;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x0513;
    TRISB = 0x363D;
    TRISC = 0x1FF2;
    TRISD = 0x0160;
    TRISE = 0xF000;
    TRISF = 0x0000;
    TRISG = 0x0000;

    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    CNPDA = 0x0000;
    CNPDB = 0x0000;
    CNPDC = 0x0000;
    CNPDD = 0x0000;
    CNPDE = 0x0000;
    CNPDF = 0x0000;
    CNPDG = 0x0000;
    CNPUA = 0x0000;
    CNPUB = 0x1200;
    CNPUC = 0x03C0;
    CNPUD = 0x0060;
    CNPUE = 0x0000;
    CNPUF = 0x0000;
    CNPUG = 0x0040;

    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000;
    ODCB = 0x0000;
    ODCC = 0x0000;
    ODCD = 0x0000;
    ODCE = 0x0000;
    ODCF = 0x0000;
    ODCG = 0x0040;

    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    ANSELA = 0x0003;
    ANSELB = 0x0000;
    ANSELC = 0x0800;
    ANSELE = 0xF000;
    
    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS

    RPINR18bits.U1RXR = 0x002A;    //RB10->UART1:U1RX
    RPINR19bits.U2RXR = 0x0025;    //RB5->UART2:U2RX
    RPOR4bits.RP43R = 0x0001;    //RB11->UART1:U1TX
    RPOR2bits.RP38R = 0x0003;    //RB6->UART2:U2TX

    __builtin_write_OSCCONL(OSCCON | 0x40); // lock PPS
}

