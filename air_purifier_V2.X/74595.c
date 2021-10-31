#include "74595.h"
#include "main.h"

void delayloop (unsigned int del);

#if DEF74595_NUMBER_PORT >= 8
    void HC595Init_PORT_8(void) 
    {
        // I/O for digital out and relay control
        PIN_HC74595_CLK_TRIS_PORT_8 = 0; 
        PIN_HC74595_CLK_LAT_PORT_8 = 0;     // Clock or Shift PIN 11 (74595)
        PIN_HC74595_LATCH_TRIS_PORT_8 = 0;
        PIN_HC74595_LATCH_LAT_PORT_8 = 0;   // Latch PIN 12 (74595))
        PIN_HC74595_DATA_TRIS_PORT_8 = 0;
        PIN_HC74595_DATA_LAT_PORT_8 = 0;    // Data  PIN 14 (74595))
        PIN_HC74595_OEN_TRIS_PORT_8 = 0;
        PIN_HC74595_OEN_LAT_PORT_8 = 1;     // Disabled output PIN 13 (74595)
    }

    /**
    * Send a value to the HC595 for one 74HC595 only
    * @param value
    */
    void HC595SendValue_PORT_8(uint8_t ui8tvalue, uint8_t direction) 
    {
        uint8_t i;
        uint8_t ibuffer;
        
        PIN_HC74595_OEN_LAT_PORT_8 = 0; // Enabled output  PIN 13 (74595)
    
        for (i=0 ; i<8 ; i++) {
            if (direction == HC595_MSB_FIRST_PORT_8) {
                ibuffer = (uint8_t)(ui8tvalue << i);
                if((ibuffer & 0x80) == 0x80){
                    PIN_HC74595_DATA_LAT_PORT_8 = 1;
                }   
                else{
                    PIN_HC74595_DATA_LAT_PORT_8 = 0;
                }
            } 
            else {
                ibuffer = ui8tvalue >> i;
                if((ibuffer & 0x1) == 0x1){
                    PIN_HC74595_DATA_LAT_PORT_8= 1;
                }
                else{
                    PIN_HC74595_DATA_LAT_PORT_8 = 0;    
                }
            }
            HC595ToggleClk_PORT_8();
        }
        HC595TriggerOutput_PORT_8();
    }
    
    /**
    * Send a value to the HC595 for many 74HC595
    * @param value
    */

    void HC595SendValue_many_IC_PORT_8(uint8_t ui8tvalue, uint8_t direction, uint8_t Latchdisplay )
    {
        uint8_t i;
        uint8_t ibuffer;
        
        PIN_HC74595_OEN_LAT_PORT_8 = 0; // Enabled output  PIN 13 (74595)
    
        for (i=0 ; i<8 ; i++) {
            if (direction == HC595_MSB_FIRST_PORT_8) {
                ibuffer = (uint8_t)(ui8tvalue << i);
                if((ibuffer & 0x80) == 0x80){
                    PIN_HC74595_DATA_LAT_PORT_8 = 1;
                }
                else{
                    PIN_HC74595_DATA_LAT_PORT_8= 0;
                }
            } 
            else {
                ibuffer = ui8tvalue >> i;
                if((ibuffer & 0x1) == 0x1){
                    PIN_HC74595_DATA_LAT_PORT_8 = 1;
                }   
                else{
                    PIN_HC74595_DATA_LAT_PORT_8 = 0;    
                }
            }
            HC595ToggleClk_PORT_8();
        }
        if (Latchdisplay == Latch_On){
            HC595TriggerOutput_PORT_8();
        }
    }


    /**
    * Toggle the SRCLK pin of the HC595
    **/
    void HC595ToggleClk_PORT_8() 
    {
        PIN_HC74595_CLK_LAT_PORT_8 = 1;
        __delay_us(DELAY_SHORT_TIMING_uS);
        PIN_HC74595_CLK_LAT_PORT_8 = 0;
        __delay_us(DELAY_SHORT_TIMING_uS);
    }


    /**
    * Toggle the RCLK pin of the HC595 to register output
    **/
    void HC595TriggerOutput_PORT_8() {
        PIN_HC74595_LATCH_LAT_PORT_8 = 1;
        __delay_us(DELAY_LONG_TIMING_uS);
        PIN_HC74595_LATCH_LAT_PORT_8 = 0;
    }
#endif

#if DEF74595_NUMBER_PORT >= 7
    void HC595Init_PORT_7(void) 
    {
        // I/O for digital out and relay control
        PIN_HC74595_CLK_TRIS_PORT_7 = 0; 
        PIN_HC74595_CLK_LAT_PORT_7 = 0;     // Clock or Shift PIN 11 (74595)
        PIN_HC74595_LATCH_TRIS_PORT_7 = 0;
        PIN_HC74595_LATCH_LAT_PORT_7 = 0;   // Latch PIN 12 (74595))
        PIN_HC74595_DATA_TRIS_PORT_7 = 0;
        PIN_HC74595_DATA_LAT_PORT_7 = 0;    // Data PIN 14 (74595))
        PIN_HC74595_OEN_TRIS_PORT_7 = 0;
        PIN_HC74595_OEN_LAT_PORT_7 = 1;     // Disabled output PIN 13 (74595)
    }

    /**
    * Send a value to the HC595 for one 74HC595 only
    * @param value
    */
    void HC595SendValue_PORT_7(uint8_t ui8tvalue, uint8_t direction) 
    {
        uint8_t i;
        uint8_t ibuffer;
        
        PIN_HC74595_OEN_LAT_PORT_7 = 0; // Enabled output  PIN 13 (74595)
    
        for (i=0 ; i<8 ; i++) {
            if (direction == HC595_MSB_FIRST_PORT_7) {
                ibuffer = (uint8_t)(ui8tvalue << i);
                if((ibuffer & 0x80) == 0x80){
                    PIN_HC74595_DATA_LAT_PORT_7 = 1;
                }   
                else{
                    PIN_HC74595_DATA_LAT_PORT_7 = 0;
                }
            } 
            else {
                ibuffer = ui8tvalue >> i;
                if((ibuffer & 0x1) == 0x1){
                    PIN_HC74595_DATA_LAT_PORT_7= 1;
                }
                else{
                    PIN_HC74595_DATA_LAT_PORT_7 = 0;    
                }
            }
            HC595ToggleClk_PORT_7();
        }
        HC595TriggerOutput_PORT_7();
    }
    
    /**
    * Send a value to the HC595 for many 74HC595
    * @param value
    */

    void HC595SendValue_many_IC_PORT_1(uint8_t ui8tvalue, uint8_t direction, uint8_t Latchdisplay )
    {
        uint8_t i;
        uint8_t ibuffer;
        
        PIN_HC74595_OEN_LAT_PORT_7 = 0; // Enabled output  PIN 13 (74595)
    
        for (i=0 ; i<8 ; i++) {
            if (direction == HC595_MSB_FIRST_PORT_7) {
                ibuffer = (uint8_t)(ui8tvalue << i);
                if((ibuffer & 0x80) == 0x80){
                    PIN_HC74595_DATA_LAT_PORT_7 = 1;
                }
                else{
                    PIN_HC74595_DATA_LAT_PORT_7= 0;
                }
            } 
            else {
                ibuffer = ui8tvalue >> i;
                if((ibuffer & 0x1) == 0x1){
                    PIN_HC74595_DATA_LAT_PORT_7 = 1;
                }   
                else{
                    PIN_HC74595_DATA_LAT_PORT_7 = 0;    
                }
            }
            HC595ToggleClk_PORT_7();
        }
        if (Latchdisplay == Latch_On){
            HC595TriggerOutput_PORT_7();
        }
    }


    /**
    * Toggle the SRCLK pin of the HC595
    **/
    void HC595ToggleClk_PORT_7() 
    {
        PIN_HC74595_CLK_LAT_PORT_7 = 1;
        __delay_us(DELAY_SHORT_TIMING_uS);
        PIN_HC74595_CLK_LAT_PORT_7 = 0;
        __delay_us(DELAY_SHORT_TIMING_uS);
    }


    /**
    * Toggle the RCLK pin of the HC595 to register output
    **/
    void HC595TriggerOutput_PORT_7() {
        PIN_HC74595_LATCH_LAT_PORT_7 = 1;
        __delay_us(DELAY_LONG_TIMING_uS);
        PIN_HC74595_LATCH_LAT_PORT_7 = 0;
    }
#endif
    
#if DEF74595_NUMBER_PORT >= 6
    void HC595Init_PORT_6(void) 
    {
        // I/O for digital out and relay control
        PIN_HC74595_CLK_TRIS_PORT_6 = 0; 
        PIN_HC74595_CLK_LAT_PORT_6 = 0;     // Clock or Shift PIN 11 (74595)
        PIN_HC74595_LATCH_TRIS_PORT_6 = 0;
        PIN_HC74595_LATCH_LAT_PORT_6 = 0;   // Latch PIN 12 (74595))
        PIN_HC74595_DATA_TRIS_PORT_6 = 0;
        PIN_HC74595_DATA_LAT_PORT_6 = 0;    // Data PIN 14 (74595))
        PIN_HC74595_OEN_TRIS_PORT_6 = 0;
        PIN_HC74595_OEN_LAT_PORT_6 = 1;     // Disabled output PIN 13 (74595)
    }

    /**
    * Send a value to the HC595 for one 74HC595 only
    * @param value
    */
    void HC595SendValue_PORT_6(uint8_t ui8tvalue, uint8_t direction) 
    {
        uint8_t i;
        uint8_t ibuffer;
        
        PIN_HC74595_OEN_LAT_PORT_6 = 0; // Enabled output  PIN 13 (74595)
    
        for (i=0 ; i<8 ; i++) {
            if (direction == HC595_MSB_FIRST_PORT_6) {
                ibuffer = (uint8_t)(ui8tvalue << i);
                if((ibuffer & 0x80) == 0x80){
                    PIN_HC74595_DATA_LAT_PORT_6 = 1;
                }   
                else{
                    PIN_HC74595_DATA_LAT_PORT_6 = 0;
                }
            } 
            else {
                ibuffer = ui8tvalue >> i;
                if((ibuffer & 0x1) == 0x1){
                    PIN_HC74595_DATA_LAT_PORT_6= 1;
                }
                else{
                    PIN_HC74595_DATA_LAT_PORT_6 = 0;    
                }
            }
            HC595ToggleClk_PORT_6();
        }
        HC595TriggerOutput_PORT_6();
    }
    
    /**
    * Send a value to the HC595 for many 74HC595
    * @param value
    */

    void HC595SendValue_many_IC_PORT_6(uint8_t ui8tvalue, uint8_t direction, uint8_t Latchdisplay )
    {
        uint8_t i;
        uint8_t ibuffer;
        
        PIN_HC74595_OEN_LAT_PORT_6 = 0; // Enabled output  PIN 13 (74595)
    
        for (i=0 ; i<8 ; i++) {
            if (direction == HC595_MSB_FIRST_PORT_6) {
                ibuffer = (uint8_t)(ui8tvalue << i);
                if((ibuffer & 0x80) == 0x80){
                    PIN_HC74595_DATA_LAT_PORT_6 = 1;
                }
                else{
                    PIN_HC74595_DATA_LAT_PORT_6= 0;
                }
            } 
            else {
                ibuffer = ui8tvalue >> i;
                if((ibuffer & 0x1) == 0x1){
                    PIN_HC74595_DATA_LAT_PORT_6 = 1;
                }   
                else{
                    PIN_HC74595_DATA_LAT_PORT_6 = 0;    
                }
            }
            HC595ToggleClk_PORT_6();
        }
        if (Latchdisplay == Latch_On){
            HC595TriggerOutput_PORT_6();
        }
    }

    /**
    * Toggle the SRCLK pin of the HC595
    **/
    void HC595ToggleClk_PORT_6() 
    {
        PIN_HC74595_CLK_LAT_PORT_6 = 1;
        __delay_us(DELAY_SHORT_TIMING_uS);
        PIN_HC74595_CLK_LAT_PORT_6 = 0;
        __delay_us(DELAY_SHORT_TIMING_uS);
    }


    /**
    * Toggle the RCLK pin of the HC595 to register output
    **/
    void HC595TriggerOutput_PORT_6() {
        PIN_HC74595_LATCH_LAT_PORT_6 = 1;
        __delay_us(DELAY_LONG_TIMING_uS);
        PIN_HC74595_LATCH_LAT_PORT_6 = 0;
    }
#endif
    
#if DEF74595_NUMBER_PORT >= 5
    void HC595Init_PORT_5(void) 
    {
        // I/O for digital out and relay control
        PIN_HC74595_CLK_TRIS_PORT_5 = 0; 
        PIN_HC74595_CLK_LAT_PORT_5 = 0;     // Clock or Shift PIN 11 (74595)
        PIN_HC74595_LATCH_TRIS_PORT_5 = 0;
        PIN_HC74595_LATCH_LAT_PORT_5 = 0;   // Latch PIN 12 (74595))
        PIN_HC74595_DATA_TRIS_PORT_5 = 0;
        PIN_HC74595_DATA_LAT_PORT_5 = 0;    // Data PIN 14 (74595))
        PIN_HC74595_OEN_TRIS_PORT_5 = 0;
        PIN_HC74595_OEN_LAT_PORT_5 = 1;     // Disabled output PIN 13 (74595)
    }

    /**
    * Send a value to the HC595 for one 74HC595 only
    * @param value
    */
    void HC595SendValue_PORT_5(uint8_t ui8tvalue, uint8_t direction) 
    {
        uint8_t i;
        uint8_t ibuffer;
        
        PIN_HC74595_OEN_LAT_PORT_5 = 0; // Enabled output  PIN 13 (74595)
    
        for (i=0 ; i<8 ; i++) {
            if (direction == HC595_MSB_FIRST_PORT_5) {
                ibuffer = (uint8_t)(ui8tvalue << i);
                if((ibuffer & 0x80) == 0x80){
                    PIN_HC74595_DATA_LAT_PORT_5 = 1;
                }   
                else{
                    PIN_HC74595_DATA_LAT_PORT_5 = 0;
                }
            } 
            else {
                ibuffer = ui8tvalue >> i;
                if((ibuffer & 0x1) == 0x1){
                    PIN_HC74595_DATA_LAT_PORT_5= 1;
                }
                else{
                    PIN_HC74595_DATA_LAT_PORT_5 = 0;    
                }
            }
            HC595ToggleClk_PORT_5();
        }
        HC595TriggerOutput_PORT_5();
    }
    
    /**
    * Send a value to the HC595 for many 74HC595
    * @param value
    */

    void HC595SendValue_many_IC_PORT_5(uint8_t ui8tvalue, uint8_t direction, uint8_t Latchdisplay )
    {
        uint8_t i;
        uint8_t ibuffer;
        
        PIN_HC74595_OEN_LAT_PORT_5 = 0; // Enabled output  PIN 13 (74595)
    
        for (i=0 ; i<8 ; i++) {
            if (direction == HC595_MSB_FIRST_PORT_5) {
                ibuffer = (uint8_t)(ui8tvalue << i);
                if((ibuffer & 0x80) == 0x80){
                    PIN_HC74595_DATA_LAT_PORT_5 = 1;
                }
                else{
                    PIN_HC74595_DATA_LAT_PORT_5= 0;
                }
            } 
            else {
                ibuffer = ui8tvalue >> i;
                if((ibuffer & 0x1) == 0x1){
                    PIN_HC74595_DATA_LAT_PORT_5 = 1;
                }   
                else{
                    PIN_HC74595_DATA_LAT_PORT_5 = 0;    
                }
            }
            HC595ToggleClk_PORT_5();
        }
        if (Latchdisplay == Latch_On){
            HC595TriggerOutput_PORT_5();
        }
    }


    /**
    * Toggle the SRCLK pin of the HC595
    **/
    void HC595ToggleClk_PORT_5() 
    {
        PIN_HC74595_CLK_LAT_PORT_5 = 1;
        __delay_us(DELAY_SHORT_TIMING_uS);
        PIN_HC74595_CLK_LAT_PORT_5 = 0;
        __delay_us(DELAY_SHORT_TIMING_uS);
    }


    /**
    * Toggle the RCLK pin of the HC595 to register output
    **/
    void HC595TriggerOutput_PORT_5() {
        PIN_HC74595_LATCH_LAT_PORT_8 = 1;
        __delay_us(DELAY_LONG_TIMING_uS);
        PIN_HC74595_LATCH_LAT_PORT_5 = 0;
    }
#endif
    
    
#if DEF74595_NUMBER_PORT >= 4
    void HC595Init_PORT_4(void) 
    {
        // I/O for digital out and relay control
        PIN_HC74595_CLK_TRIS_PORT_4 = 0; 
        PIN_HC74595_CLK_LAT_PORT_4 = 0;     // Clock or Shift PIN 11 (74595)
        PIN_HC74595_LATCH_TRIS_PORT_4 = 0;
        PIN_HC74595_LATCH_LAT_PORT_4 = 0;   // Latch PIN 12 (74595))
        PIN_HC74595_DATA_TRIS_PORT_4 = 0;
        PIN_HC74595_DATA_LAT_PORT_4 = 0;    // Data PIN 14 (74595))
        PIN_HC74595_OEN_TRIS_PORT_4 = 0;
        PIN_HC74595_OEN_LAT_PORT_4 = 1;     // Disabled output PIN 13 (74595)
    }

    /**
    * Send a value to the HC595 for one 74HC595 only
    * @param value
    */
    void HC595SendValue_PORT_4(uint8_t ui8tvalue, uint8_t direction) 
    {
        uint8_t i;
        uint8_t ibuffer;
        
        PIN_HC74595_OEN_LAT_PORT_4 = 0; // Enabled output  PIN 13 (74595)
    
        for (i=0 ; i<8 ; i++) {
            if (direction == HC595_MSB_FIRST_PORT_4) {
                ibuffer = (uint8_t)(ui8tvalue << i);
                if((ibuffer & 0x80) == 0x80){
                    PIN_HC74595_DATA_LAT_PORT_4 = 1;
                }   
                else{
                    PIN_HC74595_DATA_LAT_PORT_4 = 0;
                }
            } 
            else {
                ibuffer = ui8tvalue >> i;
                if((ibuffer & 0x1) == 0x1){
                    PIN_HC74595_DATA_LAT_PORT_4= 1;
                }
                else{
                    PIN_HC74595_DATA_LAT_PORT_4 = 0;    
                }
            }
            HC595ToggleClk_PORT_1();
        }
        HC595TriggerOutput_PORT_1();
    }
    
    /**
    * Send a value to the HC595 for many 74HC595
    * @param value
    */

    void HC595SendValue_many_IC_PORT_4(uint8_t ui8tvalue, uint8_t direction, uint8_t Latchdisplay )
    {
        uint8_t i;
        uint8_t ibuffer;
    
        PIN_HC74595_OEN_LAT_PORT_4 = 0; // Enabled output  PIN 13 (74595)
        
        for (i=0 ; i<8 ; i++) {
            if (direction == HC595_MSB_FIRST_PORT_4) {
                ibuffer = (uint8_t)(ui8tvalue << i);
                if((ibuffer & 0x80) == 0x80){
                    PIN_HC74595_DATA_LAT_PORT_4 = 1;
                }
                else{
                    PIN_HC74595_DATA_LAT_PORT_4= 0;
                }
            } 
            else {
                ibuffer = ui8tvalue >> i;
                if((ibuffer & 0x1) == 0x1){
                    PIN_HC74595_DATA_LAT_PORT_4 = 1;
                }   
                else{
                    PIN_HC74595_DATA_LAT_PORT_4 = 0;    
                }
            }
            HC595ToggleClk_PORT_1();
        }
        if (Latchdisplay == Latch_On){
            HC595TriggerOutput_PORT_1();
        }
    }


    /**
    * Toggle the SRCLK pin of the HC595
    **/
    void HC595ToggleClk_PORT_4() 
    {
        PIN_HC74595_CLK_LAT_PORT_4 = 1;
        __delay_us(DELAY_SHORT_TIMING_uS);
        PIN_HC74595_CLK_LAT_PORT_4 = 0;
        __delay_us(DELAY_SHORT_TIMING_uS);
    }


    /**
    * Toggle the RCLK pin of the HC595 to register output
    **/
    void HC595TriggerOutput_PORT_4() {
        PIN_HC74595_LATCH_LAT_PORT_4 = 1;
        __delay_us(DELAY_LONG_TIMING_uS);
        PIN_HC74595_LATCH_LAT_PORT_4 = 0;
    }
#endif

#if DEF74595_NUMBER_PORT >= 3
    void HC595Init_PORT_3(void) 
    {
        // I/O for digital out and relay control
        PIN_HC74595_CLK_TRIS_PORT_3 = 0; 
        PIN_HC74595_CLK_LAT_PORT_3 = 0;     // Clock or Shift PIN 11 (74595)
        PIN_HC74595_LATCH_TRIS_PORT_3 = 0;
        PIN_HC74595_LATCH_LAT_PORT_3 = 0;   // Latch PIN 12 (74595))
        PIN_HC74595_DATA_TRIS_PORT_3 = 0;
        PIN_HC74595_DATA_LAT_PORT_3 = 0;    // Data PIN 14 (74595))
        PIN_HC74595_OEN_TRIS_PORT_3 = 0;
        PIN_HC74595_OEN_LAT_PORT_3 = 1;     // Disabled output PIN 13 (74595)
    }

     /**
    * Send a value to the HC595 for one 74HC595 only
    * @param value
    */
    void HC595SendValue_PORT_3(uint8_t ui8tvalue, uint8_t direction) 
    {
        uint8_t i;
        uint8_t ibuffer;
        
        PIN_HC74595_OEN_LAT_PORT_3 = 0; // Enabled output  PIN 13 (74595)
    
        for (i=0 ; i<8 ; i++) {
            if (direction == HC595_MSB_FIRST_PORT_3) {
                ibuffer = (uint8_t)(ui8tvalue << i);
                if((ibuffer & 0x80) == 0x80){
                    PIN_HC74595_DATA_LAT_PORT_3 = 1;
                }   
                else{
                    PIN_HC74595_DATA_LAT_PORT_3 = 0;
                }
            } 
            else {
                ibuffer = ui8tvalue >> i;
                if((ibuffer & 0x1) == 0x1){
                    PIN_HC74595_DATA_LAT_PORT_3= 1;
                }
                else{
                    PIN_HC74595_DATA_LAT_PORT_3 = 0;    
                }
            }
            HC595ToggleClk_PORT_3();
        }
        HC595TriggerOutput_PORT_3();
    }
    
    /**
    * Send a value to the HC595 for many 74HC595
    * @param value
    */

    void HC595SendValue_many_IC_PORT_3(uint8_t ui8tvalue, uint8_t direction, uint8_t Latchdisplay )
    {
        uint8_t i;
        uint8_t ibuffer;
        
        PIN_HC74595_OEN_LAT_PORT_3 = 0; // Enabled output  PIN 13 (74595)
    
        for (i=0 ; i<8 ; i++) {
            if (direction == HC595_MSB_FIRST_PORT_3) {
                ibuffer = (uint8_t)(ui8tvalue << i);
                if((ibuffer & 0x80) == 0x80){
                    PIN_HC74595_DATA_LAT_PORT_3 = 1;
                }
                else{
                    PIN_HC74595_DATA_LAT_PORT_3= 0;
                }
            } 
            else {
                ibuffer = ui8tvalue >> i;
                if((ibuffer & 0x1) == 0x1){
                    PIN_HC74595_DATA_LAT_PORT_3 = 1;
                }   
                else{
                    PIN_HC74595_DATA_LAT_PORT_3 = 0;    
                }
            }
            HC595ToggleClk_PORT_3();
        }
        if (Latchdisplay == Latch_On){
            HC595TriggerOutput_PORT_3();
        }
    }


    /**
    * Toggle the SRCLK pin of the HC595
    **/
    void HC595ToggleClk_PORT_3() 
    {
        PIN_HC74595_CLK_LAT_PORT_3 = 1;
        __delay_us(DELAY_SHORT_TIMING_uS);
        PIN_HC74595_CLK_LAT_PORT_3 = 0;
        __delay_us(DELAY_SHORT_TIMING_uS);
    }


    /**
    * Toggle the RCLK pin of the HC595 to register output
    **/
    void HC595TriggerOutput_PORT_3() {
        PIN_HC74595_LATCH_LAT_PORT_3 = 1;
        __delay_us(DELAY_LONG_TIMING_uS);
        PIN_HC74595_LATCH_LAT_PORT_3 = 0;
    }
#endif

    
#if DEF74595_NUMBER_PORT >= 2
    void HC595Init_PORT_2(void) 
    {
        // I/O for digital out and relay control
        PIN_HC74595_CLK_TRIS_PORT_2 = 0; 
        PIN_HC74595_CLK_LAT_PORT_2 = 0;     // Clock or Shift PIN 11 (74595)
        PIN_HC74595_LATCH_TRIS_PORT_2 = 0;
        PIN_HC74595_LATCH_LAT_PORT_2 = 0;   // Latch PIN 12 (74595))
        PIN_HC74595_DATA_TRIS_PORT_2 = 0;
        PIN_HC74595_DATA_LAT_PORT_2 = 0;    // Data PIN 14 (74595))
        PIN_HC74595_OEN_TRIS_PORT_2 = 0;
        PIN_HC74595_OEN_LAT_PORT_2 = 1;     // Disabled output PIN 13 (74595)
    }

    /**
    * Send a value to the HC595 for one 74HC595 only
    * @param value
    */
    void HC595SendValue_PORT_2(uint8_t ui8tvalue, uint8_t direction) 
    {
        uint8_t i;
        uint8_t ibuffer;
        
        PIN_HC74595_OEN_LAT_PORT_2 = 0; // Enabled output  PIN 13 (74595)
    
        for (i=0 ; i<8 ; i++) {
            if (direction == HC595_MSB_FIRST_PORT_2) {
                ibuffer = (uint8_t)(ui8tvalue << i);
                if((ibuffer & 0x80) == 0x80){
                    PIN_HC74595_DATA_LAT_PORT_2 = 1;
                }   
                else{
                    PIN_HC74595_DATA_LAT_PORT_2 = 0;
                }
            } 
            else {
                ibuffer = ui8tvalue >> i;
                if((ibuffer & 0x1) == 0x1){
                    PIN_HC74595_DATA_LAT_PORT_2= 1;
                }
                else{
                    PIN_HC74595_DATA_LAT_PORT_2 = 0;    
                }
            }
            HC595ToggleClk_PORT_2();
        }
        HC595TriggerOutput_PORT_2();
    }
    
    /**
    * Send a value to the HC595 for many 74HC595
    * @param value
    */

    void HC595SendValue_many_IC_PORT_3(uint8_t ui8tvalue, uint8_t direction, uint8_t Latchdisplay )
    {
        uint8_t i;
        uint8_t ibuffer;
        
        PIN_HC74595_OEN_LAT_PORT_2 = 0; // Enabled output  PIN 13 (74595)
    
        for (i=0 ; i<8 ; i++) {
            if (direction == HC595_MSB_FIRST_PORT_2) {
                ibuffer = (uint8_t)(ui8tvalue << i);
                if((ibuffer & 0x80) == 0x80){
                    PIN_HC74595_DATA_LAT_PORT_2 = 1;
                }
                else{
                    PIN_HC74595_DATA_LAT_PORT_2= 0;
                }
            } 
            else {
                ibuffer = ui8tvalue >> i;
                if((ibuffer & 0x1) == 0x1){
                    PIN_HC74595_DATA_LAT_PORT_2 = 1;
                }   
                else{
                    PIN_HC74595_DATA_LAT_PORT_3 = 0;    
                }
            }
            HC595ToggleClk_PORT_2();
        }
        if (Latchdisplay == Latch_On){
            HC595TriggerOutput_PORT_2();
        }
    }

    /**
    * Toggle the SRCLK pin of the HC595
    **/
    void HC595ToggleClk_PORT_2() 
    {
        PIN_HC74595_CLK_LAT_PORT_2 = 1;
        __delay_us(DELAY_SHORT_TIMING_uS);
        PIN_HC74595_CLK_LAT_PORT_2 = 0;
        __delay_us(DELAY_SHORT_TIMING_uS);
    }


    /**
    * Toggle the RCLK pin of the HC595 to register output
    **/
    void HC595TriggerOutput_PORT_2() {
        PIN_HC74595_LATCH_LAT_PORT_2 = 1;
        __delay_us(DELAY_LONG_TIMING_uS);
        PIN_HC74595_LATCH_LAT_PORT_2 = 0;
    }
#endif
    
#if DEF74595_NUMBER_PORT >= 1
    void HC595Init_PORT_1(void) 
    {
        // I/O for digital out and relay control
        PIN_HC74595_CLK_TRIS_PORT_1 = 0; 
        PIN_HC74595_CLK_LAT_PORT_1 = 0;     // Clock or Shift PIN 11 (74595)
        PIN_HC74595_LATCH_TRIS_PORT_1 = 0;
        PIN_HC74595_LATCH_LAT_PORT_1 = 0;   // Latch PIN 12 (74595))
        PIN_HC74595_DATA_TRIS_PORT_1 = 0;
        PIN_HC74595_DATA_LAT_PORT_1 = 0;    // Data PIN 14 (74595))
        PIN_HC74595_OEN_TRIS_PORT_1 = 0;
        PIN_HC74595_OEN_LAT_PORT_1 = 1;     // Disabled output PIN 13 (74595)
        PIN_HC74595_OEN_LAT_PORT_1 = 0; // Enabled output PIN 13 (74595)
    }

    /**
    * Send a value to the HC595 for one 74HC595 only
    * @param value
    */
    void HC595SendValue_PORT_1(uint8_t ui8tvalue, uint8_t direction) 
    {
        uint8_t i;
        uint8_t ibuffer;
        
        PIN_HC74595_OEN_LAT_PORT_1 = 0; // Enabled output // PIN 13 (74595)
    
        for (i=0 ; i<8 ; i++) {
            if (direction == HC595_MSB_FIRST_PORT_1) {
                ibuffer = (uint8_t)(ui8tvalue << i);
                if((ibuffer & 0x80) == 0x80){
                    PIN_HC74595_DATA_LAT_PORT_1 = 1;
                }   
                else{
                    PIN_HC74595_DATA_LAT_PORT_1 = 0;
                }
            } 
            else {
                ibuffer = ui8tvalue >> i;
                if((ibuffer & 0x1) == 0x1){
                    PIN_HC74595_DATA_LAT_PORT_1= 1;
                }
                else{
                    PIN_HC74595_DATA_LAT_PORT_1 = 0;    
                }
            }
            HC595ToggleClk_PORT_1();
        }
        HC595TriggerOutput_PORT_1();
    }
    
    /**
    * Send a value to the HC595 for many 74HC595
    * @param value
    */

     void HC595SendValue_many_IC_PORT_1(uint8_t ui8tvalue, uint8_t direction, uint8_t Latchdisplay )
    {
        uint8_t i;
        uint8_t ibuffer;
    
        for (i=0 ; i<8 ; i++) {
            if (direction == HC595_MSB_FIRST) {
                ibuffer = (uint8_t)(ui8tvalue << i);
                if((ibuffer & 0x80) == 0x80){
                    PIN_HC74595_DATA_LAT_PORT_1 = 1;
                }
                else{
                    PIN_HC74595_DATA_LAT_PORT_1= 0;
                }
            } 
            else {
                ibuffer = ui8tvalue >> i;
                if((ibuffer & 0x1) == 0x1){
                    PIN_HC74595_DATA_LAT_PORT_1 = 1;
                }   
                else{
                    PIN_HC74595_DATA_LAT_PORT_1 = 0;    
                }
            }
            HC595ToggleClk_PORT_1();
        }
        if (Latchdisplay == Latch_On){
            HC595TriggerOutput_PORT_1();
        }
    }

    /**
    * Toggle the SRCLK pin of the HC595
    **/
    void HC595ToggleClk_PORT_1() 
    {
        PIN_HC74595_CLK_LAT_PORT_1 = 1;
        __delay_us(DELAY_SHORT_TIMING_uS);
        PIN_HC74595_CLK_LAT_PORT_1 = 0;
        __delay_us(DELAY_SHORT_TIMING_uS);
    }


    /**
    * Toggle the RCLK pin of the HC595 to register output
    **/
    void HC595TriggerOutput_PORT_1() {
        PIN_HC74595_LATCH_LAT_PORT_1 = 1;
        __delay_us(DELAY_LONG_TIMING_uS);
        PIN_HC74595_LATCH_LAT_PORT_1 = 0;
    }
#endif


void delayloop (unsigned int del)
{
	for(del=del; del >0; del--);
}