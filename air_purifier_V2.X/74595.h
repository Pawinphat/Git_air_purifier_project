#include "mcc_generated_files/pin_manager.h"
#define DEF74595_NUMBER_PORT 8

#define Latch_Off 0
#define Latch_On 1

#if DEF74595_NUMBER_PORT >=8
    #define PIN_HC74595_CLK_TRIS_PORT_8    TRISAbits.TRISA11
    #define PIN_HC74595_CLK_LAT_PORT_8     LATAbits.LATA11
    #define PIN_HC74595_LATCH_TRIS_PORT_8    TRISAbits.TRISA11
    #define PIN_HC74595_LATCH_LAT_PORT_8    TRISAbits.TRISA11
    #define PIN_HC74595_DATA_TRIS_PORT_8    TRISAbits.TRISA11
    #define PIN_HC74595_DATA_LAT_PORT_8     LATAbits.LATA11
    #define PIN_HC74595_OEN_TRIS_PORT_8    TRISAbits.TRISA11
    #define PIN_HC74595_OEN_LAT_PORT_8     LATAbits.LATA11

    //@HOME Developer 74HC595 (OCt 30,2021)

    #define HC595_LSB_FIRST_PORT_8 0
    #define HC595_MSB_FIRST_PORT_8 1

    /**
    * Initialize HC595 module
    **/
    void HC595Init_PORT_8(void);

    /**
    * Clear the output.
    **/
    void HC595Clear_PORT_8(void);

    /**
    * Send a value to the HC595 for 1 74HC595 only
    * @param value
    **/
    void HC595SendValue_PORT_8(uint8_t ui8tvalue, uint8_t direction);
    
    /**
    * Send a value to the HC595 for many 74HC595
    * @param value
    **/
    
    void HC595SendValue_many_IC_PORT_8(uint8_t ui8tvalue, uint8_t direction, uint8_t Latchdisplay); 

    /**
    * Toggle the SRCLK pin of the HC595
    **/
    void HC595ToggleClk_PORT_8(void);

    /**
    * Toggle the RCLK pin of the HC595 to register output
    **/
    void HC595TriggerOutput_PORT_8(void);
#endif

#if DEF74595_NUMBER_PORT >= 7
    #define PIN_HC74595_CLK_TRIS_PORT_7    TRISDbits.TRISD12
    #define PIN_HC74595_CLK_LAT_PORT_7     LATDbits.LATD12
    #define PIN_HC74595_LATCH_TRIS_PORT_7    TRISDbits.TRISD13
    #define PIN_HC74595_LATCH_LAT_PORT_7     LATDbits.LATD13
    #define PIN_HC74595_DATA_TRIS_PORT_7    TRISAbits.TRISA6
    #define PIN_HC74595_DATA_LAT_PORT_7    LATAbits.LATA6
    #define PIN_HC74595_OEN_TRIS_PORT_7    TRISDbits.TRISD3
    #define PIN_HC74595_OEN_LAT_PORT_7   LATDbits.LATD3

    //@HOME Developer 74HC595 (OCt 30,2021)

    #define HC595_LSB_FIRST_PORT_7 0
    #define HC595_MSB_FIRST_PORT_7 1

    /**
    * Initialize HC595 module
    **/
    void HC595Init_PORT_7(void);

    /**
    * Clear the output.
    **/
    void HC595Clear_PORT_7(void);

    /**
    * Send a value to the HC595 for 1 74HC595 only
    * @param value
    **/
    void HC595SendValue_PORT_7(uint8_t ui8tvalue, uint8_t direction);
    
    /**
    * Send a value to the HC595 for many 74HC595
    * @param value
    **/
    
    void HC595SendValue_many_IC_PORT_7(uint8_t ui8tvalue, uint8_t direction, uint8_t Latchdisplay); 

    /**
    * Toggle the SRCLK pin of the HC595
    **/
    void HC595ToggleClk_PORT_7(void);

    /**
    * Toggle the RCLK pin of the HC595 to register output
    **/
    void HC595TriggerOutput_PORT_7(void);
#endif

#if DEF74595_NUMBER_PORT >= 6
    #define PIN_HC74595_CLK_TRIS_PORT_6    TRISDbits.TRISD12
    #define PIN_HC74595_CLK_LAT_PORT_6     LATDbits.LATD12
    #define PIN_HC74595_LATCH_TRIS_PORT_6    TRISDbits.TRISD13
    #define PIN_HC74595_LATCH_LAT_PORT_6     LATDbits.LATD13
    #define PIN_HC74595_DATA_TRIS_PORT_6    TRISAbits.TRISA6
    #define PIN_HC74595_DATA_LAT_PORT_6    LATAbits.LATA6
    #define PIN_HC74595_OEN_TRIS_PORT_6    TRISDbits.TRISD3
    #define PIN_HC74595_OEN_LAT_PORT_6   LATDbits.LATD3

     //@HOME Developer 74HC595 (OCt 30,2021)

    #define HC595_LSB_FIRST_PORT_6 0
    #define HC595_MSB_FIRST_PORT_6 1

    /**
    * Initialize HC595 module
    **/
    void HC595Init_PORT_6(void);

    /**
    * Clear the output.
    **/
    void HC595Clear_PORT_6(void);

    /**
    * Send a value to the HC595 for 1 74HC595 only
    * @param value
    **/
    void HC595SendValue_PORT_6(uint8_t ui8tvalue, uint8_t direction);
    
    /**
    * Send a value to the HC595 for many 74HC595
    * @param value
    **/
    
    void HC595SendValue_many_IC_PORT_6(uint8_t ui8tvalue, uint8_t direction, uint8_t Latchdisplay); 

    /**
    * Toggle the SRCLK pin of the HC595
    **/
    void HC595ToggleClk_PORT_6(void);

    /**
    * Toggle the RCLK pin of the HC595 to register output
    **/
    void HC595TriggerOutput_PORT_6(void);
#endif

#if DEF74595_NUMBER_PORT >= 5
    #define PIN_HC74595_CLK_TRIS_PORT_5    TRISDbits.TRISD12
    #define PIN_HC74595_CLK_LAT_PORT_5     LATDbits.LATD12
    #define PIN_HC74595_LATCH_TRIS_PORT_5    TRISDbits.TRISD13
    #define PIN_HC74595_LATCH_LAT_PORT_5     LATDbits.LATD13
    #define PIN_HC74595_DATA_TRIS_PORT_5    TRISAbits.TRISA6
    #define PIN_HC74595_DATA_LAT_PORT_5    LATAbits.LATA6
    #define PIN_HC74595_OEN_TRIS_PORT_5    TRISDbits.TRISD3
    #define PIN_HC74595_OEN_LAT_PORT_5   LATDbits.LATD3

     //@HOME Developer 74HC595 (OCt 30,2021)

    #define HC595_LSB_FIRST_PORT_5 0
    #define HC595_MSB_FIRST_PORT_5 1

    /**
    * Initialize HC595 module
    **/
    void HC595Init_PORT_5(void);

    /**
    * Clear the output.
    **/
    void HC595Clear_PORT_5(void);

    /**
    * Send a value to the HC595 for 1 74HC595 only
    * @param value
    **/
    void HC595SendValue_PORT_5(uint8_t ui8tvalue, uint8_t direction);
    
    /**
    * Send a value to the HC595 for many 74HC595
    * @param value
    **/
    
    void HC595SendValue_many_IC_PORT_5(uint8_t ui8tvalue, uint8_t direction, uint8_t Latchdisplay); 

    /**
    * Toggle the SRCLK pin of the HC595
    **/
    void HC595ToggleClk_PORT_5(void);

    /**
    * Toggle the RCLK pin of the HC595 to register output
    **/
    void HC595TriggerOutput_PORT_5(void);
#endif

#if DEF74595_NUMBER_PORT >= 4
    #define PIN_HC74595_CLK_TRIS_PORT_4    TRISDbits.TRISD12
    #define PIN_HC74595_CLK_LAT_PORT_4     LATDbits.LATD12
    #define PIN_HC74595_LATCH_TRIS_PORT_4    TRISDbits.TRISD13
    #define PIN_HC74595_LATCH_LAT_PORT_4     LATDbits.LATD13
    #define PIN_HC74595_DATA_TRIS_PORT_4    TRISAbits.TRISA6
    #define PIN_HC74595_DATA_LAT_PORT_4    LATAbits.LATA6
    #define PIN_HC74595_OEN_TRIS_PORT_4    TRISDbits.TRISD3
    #define PIN_HC74595_OEN_LAT_PORT_4   LATDbits.LATD3

 //@HOME Developer 74HC595 (OCt 30,2021)

    #define HC595_LSB_FIRST_PORT_4 0
    #define HC595_MSB_FIRST_PORT_4 1

    /**
    * Initialize HC595 module
    **/
    void HC595Init_PORT_4(void);

    /**
    * Clear the output.
    **/
    void HC595Clear_PORT_4(void);

    /**
    * Send a value to the HC595 for 1 74HC595 only
    * @param value
    **/
    void HC595SendValue_PORT_4(uint8_t ui8tvalue, uint8_t direction);
    
    /**
    * Send a value to the HC595 for many 74HC595
    * @param value
    **/
    
    void HC595SendValue_many_IC_PORT_4(uint8_t ui8tvalue, uint8_t direction, uint8_t Latchdisplay); 

    /**
    * Toggle the SRCLK pin of the HC595
    **/
    void HC595ToggleClk_PORT_4(void);

    /**
    * Toggle the RCLK pin of the HC595 to register output
    **/
    void HC595TriggerOutput_PORT_4(void);
#endif

#if DEF74595_NUMBER_PORT >= 3
    #define PIN_HC74595_CLK_TRIS_PORT_3    TRISDbits.TRISD12
    #define PIN_HC74595_CLK_LAT_PORT_3     LATDbits.LATD12
    #define PIN_HC74595_LATCH_TRIS_PORT_3    TRISDbits.TRISD13
    #define PIN_HC74595_LATCH_LAT_PORT_3     LATDbits.LATD13
    #define PIN_HC74595_DATA_TRIS_PORT_3    TRISAbits.TRISA6
    #define PIN_HC74595_DATA_LAT_PORT_3    LATAbits.LATA6
    #define PIN_HC74595_OEN_TRIS_PORT_3    TRISDbits.TRISD3
    #define PIN_HC74595_OEN_LAT_PORT_3   LATDbits.LATD3

 //@HOME Developer 74HC595 (OCt 30,2021)

    #define HC595_LSB_FIRST_PORT_3 0
    #define HC595_MSB_FIRST_PORT_3 1

    /**
    * Initialize HC595 module
    **/
    void HC595Init_PORT_3(void);

    /**
    * Clear the output.
    **/
    void HC595Clear_PORT_3(void);

    /**
    * Send a value to the HC595 for 1 74HC595 only
    * @param value
    **/
    void HC595SendValue_PORT_3(uint8_t ui8tvalue, uint8_t direction);
    
    /**
    * Send a value to the HC595 for many 74HC595
    * @param value
    **/
    
    void HC595SendValue_many_IC_PORT_3(uint8_t ui8tvalue, uint8_t direction, uint8_t Latchdisplay); 

    /**
    * Toggle the SRCLK pin of the HC595
    **/
    void HC595ToggleClk_PORT_3(void);

    /**
    * Toggle the RCLK pin of the HC595 to register output
    **/
    void HC595TriggerOutput_PORT_3(void);
#endif

#if DEF74595_NUMBER_PORT >= 2
    #define PIN_HC74595_CLK_TRIS_PORT_2    TRISDbits.TRISD12
    #define PIN_HC74595_CLK_LAT_PORT_2     LATDbits.LATD12
    #define PIN_HC74595_LATCH_TRIS_PORT_2    TRISDbits.TRISD13
    #define PIN_HC74595_LATCH_LAT_PORT_2     LATDbits.LATD13
    #define PIN_HC74595_DATA_TRIS_PORT_2    TRISAbits.TRISA6
    #define PIN_HC74595_DATA_LAT_PORT_2    LATAbits.LATA6
    #define PIN_HC74595_OEN_TRIS_PORT_2    TRISDbits.TRISD3
    #define PIN_HC74595_OEN_LAT_PORT_2   LATDbits.LATD3

  //@HOME Developer 74HC595 (OCt 30,2021)

    #define HC595_LSB_FIRST_PORT_2 0
    #define HC595_MSB_FIRST_PORT_2 1

    /**
    * Initialize HC595 module
    **/
    void HC595Init_PORT_2(void);

    /**
    * Clear the output.
    **/
    void HC595Clear_PORT_2(void);

    /**
    * Send a value to the HC595 for 1 74HC595 only
    * @param value
    **/
    void HC595SendValue_PORT_2(uint8_t ui8tvalue, uint8_t direction);
    
    /**
    * Send a value to the HC595 for many 74HC595
    * @param value
    **/
    
    void HC595SendValue_many_IC_PORT_2(uint8_t ui8tvalue, uint8_t direction, uint8_t Latchdisplay); 

    /**
    * Toggle the SRCLK pin of the HC595
    **/
    void HC595ToggleClk_PORT_2(void);

    /**
    * Toggle the RCLK pin of the HC595 to register output
    **/
    void HC595TriggerOutput_PORT_2(void);
#endif

#if DEF74595_NUMBER_PORT >= 1
    #define PIN_HC74595_CLK_TRIS_PORT_1     TRISAbits.TRISA11
    #define PIN_HC74595_CLK_LAT_PORT_1      LATAbits.LATA12
    #define PIN_HC74595_LATCH_TRIS_PORT_1   TRISAbits.TRISA11
    #define PIN_HC74595_LATCH_LAT_PORT_1    LATAbits.LATA12
    #define PIN_HC74595_DATA_TRIS_PORT_1    TRISAbits.TRISA11
    #define PIN_HC74595_DATA_LAT_PORT_1     LATAbits.LATA12
    #define PIN_HC74595_OEN_TRIS_PORT_1     TRISAbits.TRISA11
    #define PIN_HC74595_OEN_LAT_PORT_1      LATAbits.LATA12

 //@HOME Developer 74HC595 (OCt 30,2021)

    #define HC595_LSB_FIRST_PORT_1 0
    #define HC595_MSB_FIRST_PORT_1 1

    /**
    * Initialize HC595 module
    **/
    void HC595Init_PORT_1(void);

    /**
    * Clear the output.
    **/
    void HC595Clear_PORT_1(void);

    /**
    * Send a value to the HC595 for 1 74HC595 only
    * @param value
    **/
    void HC595SendValue_PORT_1(uint8_t ui8tvalue, uint8_t direction);
    
    /**
    * Send a value to the HC595 for many 74HC595
    * @param value
    **/
    
    void HC595SendValue_many_IC_PORT_1(uint8_t ui8tvalue, uint8_t direction, uint8_t Latchdisplay); 
    
    /**
    * Send a value to the HC595 for many 74HC595
    * @param value
    **/
    
    void HC595SendValue_many_IC_PORT_1(uint8_t ui8tvalue, uint8_t direction, uint8_t Latchdisplay);    
    
    /**
    * Toggle the SRCLK pin of the HC595
    **/
    void HC595ToggleClk_PORT_1(void);

    /**
    * Toggle the RCLK pin of the HC595 to register output
    **/
    void HC595TriggerOutput_PORT_1(void);
#endif
