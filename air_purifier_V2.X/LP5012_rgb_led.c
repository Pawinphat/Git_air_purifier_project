#include "LP5012_rgb_led.h"
#include "main.h"

            #define MCHP24AA512_RETRY_MAX       100  // define the retry count
            #define MCHP24AA512_ADDRESS         0x50 // slave device address
            #define MCHP24AA512_DEVICE_TIMEOUT  50   // define slave timeout
#define EMC1001_ADDRESS     0x38   // slave device address



void Intial_LP5012(void)
{
    
  /*
    I2C1_Start();
    I2C1_WriteByte(LP5012_SLAVE_ADR);
    I2C1_WriteByte(DEVICE_CONFIG0);
    I2C1_WriteByte(0x40); // DEVICE_CONFIG0, default 0x00
    I2C1_WriteByte(0x1C); // DEVICE_CONFIG1, default 0x3C
    I2C1_WriteByte(0x0F); // LED_CONFIG0, default 0x00
    I2C1_WriteByte(0x00); // BANK_BRIGHTNESS, default 0xFF
    I2C1_WriteByte(0x00); // BANK_A_COLOR, default 0x00
    I2C1_WriteByte(0x00); // BANK_B_COLOR, default 0x00
    I2C1_WriteByte(0x00); // BANK_C_COLOR, default 0x00
    I2C1_Stop();
  */
}

void TestRead ()
{
    uint8_t pdata_write = 0; // 0 to 'seconds' register
    uint8_t pdata_read; // will hold 'seconds'

    I2C2_MESSAGE_STATUS status = I2C2_MESSAGE_PENDING;


    I2C2_MasterWrite(&pdata_write, 1, 0b1101000, &status);
    // at this point, your status will probably be I2C2_MESSAGE_PENDING
    while (status == I2C2_MESSAGE_PENDING); // wait for status to to change
    if (status == I2C2_MESSAGE_COMPLETE) {
        I2C2_MasterRead(&pdata_read, 1, 0b1101000, &status);
        while (status == I2C2_MESSAGE_PENDING); // again, wait for status to to change
        if (status == I2C2_MESSAGE_COMPLETE) {
        // pdata_read should now be the number of seconds (in binary-coded decimal)
        }
    } 
}

uint8_t EMC1001_Read(uint8_t reg, uint8_t *pData)
{
    I2C2_MESSAGE_STATUS status = I2C2_MESSAGE_PENDING;
    static I2C2_TRANSACTION_REQUEST_BLOCK trb[2];
 
    I2C2_MasterWriteTRBBuild(&trb[0], &reg, 1, EMC1001_ADDRESS);
    I2C2_MasterReadTRBBuild(&trb[1], pData, 1, EMC1001_ADDRESS);                
    I2C2_MasterTRBInsert(2, &trb[0], &status);
 
    while(status == I2C2_MESSAGE_PENDING);      // blocking
 
    return (status == I2C2_MESSAGE_COMPLETE); 
}


uint8_t MCHP24AA512_Read(
                                            uint16_t address,
                                            uint8_t *pData,
                                            uint16_t nCount)
            {
                I2C2_MESSAGE_STATUS status;
                uint8_t showstatus;
                
                uint8_t     writeBuffer[3];
                uint16_t    addr_and_config_mode;
                uint16_t    retryTimeOut, slaveTimeOut;
                uint16_t    counter;
                uint8_t     *pD;

                pD = pData;
                
                status = I2C2_MESSAGE_PENDING;

                for (counter = 0; counter < nCount; counter++)
                {
                    // build the write buffer first
                    // starting address of the EEPROM memory
                    writeBuffer[0] = (address >> 8);                // high address
                    writeBuffer[1] = (uint8_t)(address);            // low low address

                    // Now it is possible that the slave device will be slow.
                    // As a work around on these slaves, the application can
                    // retry sending the transaction
                    retryTimeOut = 0;
                    slaveTimeOut = 0;

                    while(status != I2C2_MESSAGE_FAIL)
                    {
                        // write one byte to EEPROM (2 is the count of bytes to write)
                        I2C2_MasterWrite(    pData,
                                                3,
                                                (uint8_t)0x38,
                                                 &status);

                        // wait for the message to be sent or status has changed.
                        while(status == I2C2_MESSAGE_PENDING)
                        {
                            // add some delay here

                            // timeout checking
                            // check for max retry and skip this byte
                            if (slaveTimeOut == MCHP24AA512_DEVICE_TIMEOUT)
                                return (0);
                            else
                                slaveTimeOut++;
                        }

                        if (status == I2C2_MESSAGE_COMPLETE)
                            break;

                        // if status is  I2C2_MESSAGE_ADDRESS_NO_ACK,
                        //               or I2C2_DATA_NO_ACK,
                        // The device may be busy and needs more time for the last
                        // write so we can retry writing the data, this is why we
                        // use a while loop here

                        // check for max retry and skip this byte
                        if (retryTimeOut == MCHP24AA512_RETRY_MAX)
                            break;
                        else
                            retryTimeOut++;
                    }

                    if (status == I2C2_MESSAGE_COMPLETE)
                    {

                        // this portion will read the byte from the memory location.
                        retryTimeOut = 0;
                        slaveTimeOut = 0;

                        while(status != I2C2_MESSAGE_FAIL)
                        {
                            // write one byte to EEPROM (2 is the count of bytes to write)
                            I2C2_MasterRead(     pD,
                                                    1,
                                                    (uint8_t)0x38,
                                                    &status);

                            // wait for the message to be sent or status has changed.
                            while(status == I2C2_MESSAGE_PENDING)
                            {
                                // add some delay here

                                // timeout checking
                                // check for max retry and skip this byte
                                if (slaveTimeOut == MCHP24AA512_DEVICE_TIMEOUT)
                                    return (0);
                                else
                                    slaveTimeOut++;
                            }

                            if (status == I2C2_MESSAGE_COMPLETE)
                                break;

                            // if status is  I2C2_MESSAGE_ADDRESS_NO_ACK,
                            //               or I2C2_DATA_NO_ACK,
                            // The device may be busy and needs more time for the last
                            // write so we can retry writing the data, this is why we
                            // use a while loop here

                            // check for max retry and skip this byte
                            if (retryTimeOut == MCHP24AA512_RETRY_MAX)
                                break;
                            else
                                retryTimeOut++;
                        }
                    }

                    // exit if the last transaction failed
                    if (status == I2C2_MESSAGE_FAIL)
                    {
                        return(0);
                        break;
                    }

                    pD++;
                    address++;

                }
                return(1);
}

void LP5012_SetColor(uint8_t r, uint8_t g, uint8_t b)
{
    /*
    if(appConfig.flag.bits.lightIsOn == 0) // do not update brightness if turn-off all light
        return;
    I2C1_Start();
    I2C1_WriteByte(LP5012_SLAVE_ADR);
    I2C1_WriteByte(BANK_A_COLOR);
    I2C1_WriteByte(b); // BANK_A_COLOR, default 0x00
    I2C1_WriteByte(r); // BANK_B_COLOR, default 0x00
    I2C1_WriteByte(g); // BANK_C_COLOR, default 0x00
    I2C1_Stop();
    */
}

void LP5012_SetColor_down_led(uint8_t r, uint8_t g, uint8_t b)
{
    /*
    I2C1_Start();
    I2C1_WriteByte(LP5012_SLAVE_ADR);
    I2C1_WriteByte(OUT0_COLOR);
    I2C1_WriteByte(b); // OUTPUT 0
    I2C1_WriteByte(r); // OUTPUT 1 
    I2C1_WriteByte(g); // OUTPUT 2
    I2C1_Stop();
    */
}

void LP5012_SetColor_left_led(uint8_t r, uint8_t g, uint8_t b)
{
    /*
    I2C1_Start();
    I2C1_WriteByte(LP5012_SLAVE_ADR);
    I2C1_WriteByte(OUT3_COLOR);
    I2C1_WriteByte(b); // OUTPUT 3
    I2C1_WriteByte(r); // OUTPUT 4 
    I2C1_WriteByte(g); // OUTPUT 5
    I2C1_Stop();
    */
}

void LP5012_SetColor_right_led(uint8_t r, uint8_t g, uint8_t b) 
{
    /*
    I2C1_Start();
    I2C1_WriteByte(LP5012_SLAVE_ADR);
    I2C1_WriteByte(OUT6_COLOR);
    I2C1_WriteByte(b); // OUTPUT 6
    I2C1_WriteByte(r); // OUTPUT 7 
    I2C1_WriteByte(g); // OUTPUT 8
    I2C1_Stop();
    */
}

void LP5012_SetColor_top_led(uint8_t r, uint8_t g, uint8_t b)
{
    /*
    I2C1_Start();
    I2C1_WriteByte(LP5012_SLAVE_ADR);
    I2C1_WriteByte(OUT9_COLOR);
    I2C1_WriteByte(b); // OUTPUT 9
    I2C1_WriteByte(r); // OUTPUT 10 
    I2C1_WriteByte(g); // OUTPUT 11
    I2C1_Stop();
     */
}

void LP5012_SetBrightness(uint8_t brightness)
{
    /*
    I2C1_Start();
    I2C1_WriteByte(LP5012_SLAVE_ADR);
    I2C1_WriteByte(BANK_BRIGHTNESS);
    I2C1_WriteByte(brightness); // BANK_BRIGHTNESS, default 0xFF
    I2C1_Stop();
   */
}

void LP5012_Set_DIMMER_LED_PER_UNITS (uint8_t led_down, uint8_t led_left,  
                                      uint8_t led_right,uint8_t led_top)
{   
    /*
    LED_bank_or_Independent_mode(0); 

        I2C1_Start();
        I2C1_WriteByte(LP5012_SLAVE_ADR);
        I2C1_WriteByte(LED0_BRIGHTNESS);
        I2C1_WriteByte(led_down);
        I2C1_WriteByte(led_left);
        I2C1_WriteByte(led_right);
        I2C1_WriteByte(led_top);
        I2C1_Stop();
    */
    
}

/*
 * Set LED Mode
 * Bank mode for Setting All led (RGB)
 * Independent is setting led per unit 
 * if bool_setting is 0 = independent mode
 * if bool_setting is 1 = bank mode
 */

/*
void LED_bank_or_Independent_mode (bool bool_setting)
{
    uint8_t u8bank_or_independent = bool_setting * 0x0f;

    I2C1_Start();
    I2C1_WriteByte(LP5012_SLAVE_ADR);
    I2C1_WriteByte(LED_CONFIG0);
    I2C1_WriteByte(u8bank_or_independent);
    I2C1_Stop();
}
*/
