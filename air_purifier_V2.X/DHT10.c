#include "DHT10.h"

//static const uint8_t au8init_DHT10 [3] = {0xe1, 0x08, 0x00};


uint8_t DHT10_Writer (uint8_t *pData, uint8_t u16Totalsize_data)
{
    I2C2_MESSAGE_STATUS status;
                
    uint8_t     writeBuffer[3];
    uint16_t    addr_and_config_mode;
    uint16_t    retryTimeOut, slaveTimeOut;
    uint16_t    counter;
    uint8_t     *pD;
    
    
    pD = pData;
                
    status = I2C2_MESSAGE_PENDING;

    retryTimeOut = 0;
    slaveTimeOut = 0;

    while(status != I2C2_MESSAGE_FAIL){
        //*******************************************
        // write address and data to DTH10 (I2C signal send thru pin)
        //*******************************************
        I2C2_MasterWrite(pData,3,0x38,&status);
        // wait for the message to be sent or status has changed.
        while(status == I2C2_MESSAGE_PENDING){
        // add some delay here
        //  .....            
        // timeout checking
            // check for max retry and skip this byte
            if (slaveTimeOut == DHT10_DEVICE_TIMEOUT)
                return (0);
            else
                slaveTimeOut++;
        }// End loo while I2C2_MESSAGE_PENDING
    }
        
        if (status == I2C2_MESSAGE_COMPLETE){
            // this portion will read the byte from the memory location.
            retryTimeOut = 0;
            slaveTimeOut = 0;
           // break;
        }
    /*
        if(I2C2_MasterQueueIsFull() == true){
         //   I2C2_Initialize();
            Nop();
            return(0);
        }
    */
        // exit if the last transaction failed
        if (status == I2C2_MESSAGE_FAIL){
            return(0);
        }
    
    return(1);
}

void DHT10_initization (void)
{
    static uint8_t au8init_DHT10 [3] = {0xe1, 0x08, 0x00};
    
    DHT10_Writer(au8init_DHT10, 3);
}
