/* 
 * File:   DHT10.h
 * Author: Tiraporn
 *
 * Created on November 5, 2021, 6:58 PM
 */

#ifndef DHT10_H
#define	DHT10_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* DHT10_H */


#include <stdbool.h>
#include <stdint.h>
#include "mcc_generated_files/i2c2.h"
#ifndef MAIN_H
    #include "main.h"
#endif

#define SLAVE_I2C_GENERIC_RETRY_MAX           100
#define SLAVE_I2C_GENERIC_DEVICE_TIMEOUT      50   // define slave timeout 

#define DHT10_ADDRESS         0x38 // slave device address

#define DHT10_RETRY_MAX       100  // define the retry count
#define DHT10_DEVICE_TIMEOUT  50   // define slave timeout

extern I2C2_MESSAGE_STATUS status_dht_wr;
extern I2C2_MESSAGE_STATUS status_dht_rd;

void DHT10_initization (void);
uint8_t DHT10_Writer (uint8_t *pData, uint8_t u16Totalsize_data);
uint8_t DHT20_Sequential_Read(uint16_t address, uint8_t *pData, uint16_t nCount);


