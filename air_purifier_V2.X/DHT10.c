#include "DHT10.h"

//static const uint8_t au8init_DHT10 [3] = {0xe1, 0x08, 0x00};
I2C2_MESSAGE_STATUS status_dht_wr;
I2C2_MESSAGE_STATUS status_dht_rd;

uint8_t DHT10_Writer (uint8_t *pData, uint8_t u16Totalsize_data)
{

                
    uint8_t     writeBuffer[3];
    uint16_t    addr_and_config_mode;
    uint16_t    retryTimeOut, slaveTimeOut;
    uint16_t    counter;
    uint8_t     *pD;
    
    
    pD = pData;
                
    status_dht_wr = I2C2_MESSAGE_PENDING;

    retryTimeOut = 0;
    slaveTimeOut = 0;

    while(status_dht_wr != I2C2_MESSAGE_FAIL){
        //*******************************************
        // write address and data to DTH10 (I2C signal send thru pin)
        //*******************************************
        I2C2_MasterWrite(pData,3,0x38,&status_dht_wr);
        // wait for the message to be sent or status has changed.
        while(status_dht_wr == I2C2_MESSAGE_PENDING){
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
        
        if (status_dht_wr == I2C2_MESSAGE_COMPLETE){
            // this portion will read the byte from the memory location.
            retryTimeOut = 0;
            slaveTimeOut = 0;
           // break;
        }
    
        if(I2C2_MasterQueueIsFull() == true){
            I2C2_Initialize();
            return(0);
        }
   
        // exit if the last transaction failed
        if (status_dht_wr == I2C2_MESSAGE_FAIL){
            return(0);
        }
    
    return(1);
}


uint8_t DHT20_Sequential_Read(uint16_t address,
                              uint8_t *pData,
                              uint16_t nCount)
{
    static uint8_t au8init_DHT20 [3] = {0x1B, 0x1C, 0x1E};

    uint16_t    retryTimeOut, slaveTimeOut;
    uint8_t     *pD; 
    uint8_t     counter;
                
    pD = pData;
    status_dht_rd = I2C2_MESSAGE_PENDING;

    retryTimeOut = 0;
    slaveTimeOut = 0;
    
 //   for (counter = 0; counter <= 0; counter++){
        while(status_dht_rd != I2C2_MESSAGE_FAIL){
            //*******************************************
            // write address and data to DTH10 (I2C signal send thru pin)
            //*******************************************
            I2C2_MasterRead(pD, 7, 0x38, &status_dht_rd);
            if(pD[0] == 0x18){
                UART1_Write('U');  
              //  DHT20_Writer(au8init_DHT20,3);
            }

            // wait for the message to be sent or status has changed.
            while(status_dht_rd == I2C2_MESSAGE_PENDING){
            // add some delay here
            //  .....            
            // timeout checking
            // check for max retry and skip this byte
                if (slaveTimeOut == DHT10_DEVICE_TIMEOUT){
              //     UART1_Write('L');  
                    UART1_Write('T');  
                    return (0);
                }
                else
                slaveTimeOut++;
            }// End loo while I2C2_MESSAGE_PENDING
        }

        if (status_dht_rd == I2C2_MESSAGE_COMPLETE){
            // this portion will read the byte from the memory location.
            retryTimeOut = 0;
            slaveTimeOut = 0;
           // break;
        }
    
        if(I2C2_MasterQueueIsFull() == true){
            I2C2_Initialize();
            return(0);
        }
   
        // exit if the last transaction failed
        if (status_dht_rd == I2C2_MESSAGE_FAIL){
            UART1_Write('F');  
            return(0);
        }
  //  }
   // if(pD[0] == 0x18){
 //  }
    return(1);
}


void DHT10_initization (void)
{
    static uint8_t au8init_DHT10 [3] = {0xAC, 0x33, 0x00};
    static uint8_t au8init_DHT10_1 [3] = {0xAC, 0x91, 0x45};
    static uint8_t au8DHT20_Read [10];
    static uint16_t del = 0;
    uint8_t return_function ; 
    
    I2C2_MESSAGE_STATUS status;
    
    //  DHT10_Writer(au8init_DHT10, 3);
  //  for(del=0; del<= 65000; del++);
      Delaytime_ms(20);
      
      DHT10_Writer(au8init_DHT10,3);
      
      UART1_Write(0x11);
      UART1_Write(status_dht_wr);
      
      Delaytime_ms(82);
      
   //   DHT10_Writer(au8init_DHT10_1,3);
      
      DHT20_Sequential_Read(0x38, au8DHT20_Read, 6);
      
     //  UART1_Write(0x85);
     //  UART1_Write(status_dht_rd);
       
       Delaytime_ms(50);
     //  __delay_ms(10);
}

