/**
  I2C Reference Driver API Header File

  @Company
	Microchip Technology Inc.

  @File Name
	I2C_Master.h

  @Summary
	This is template header file for the I2C5 driver

  @Description
	This header file provides APIs for driver for I2C5.
	Generation Information:
		Product Revision  :
		Device            :  PIC32MX         PIC24FJ256GB110
		Driver Version    :  2.01 Mysil
	The generated drivers are tested against the following:
		Compiler          :  XC32 v1.42,  XC16 v1.24
		MPLAB 	          :  MPLAB X v3.55

	Template driver file modified by Mysil
	When only one instance of I2C Master is in use, I2C file and function names without any index may be used.
	When multiple instances are wanted, filename and external functions will need different global names.
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

#ifndef _I2C0_MASTER_H
#define _I2C0_MASTER_H

/**
 *  Section: Included Files
 */
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <xc.h>


/** ****************************************************************************
 *  Configuration Definitions
 */
/* defined for I2C1 */
#ifdef		_18F45K20
  #define	I2Cx_Master_MSSP_Channel		0
#elif defined  _16F1718  || defined _16F18325 || defined _18F26K22
  #define	I2Cx_Master_MSSP_Channel		1
#else
  #define	I2Cx_Master_MSSP_Channel		2
#endif
#define		I2Cx_Master_MSSP_Instance		2
  #ifndef	I2C1_CONFIG_TASK_QUEUE_LENGTH
	#define I2C1_CONFIG_TASK_QUEUE_LENGTH	4	// or 1	// or 4
  #endif
  #ifndef  _XTAL_FREQ
	#define  _XTAL_FREQ  64000000ul
  #endif
#ifndef 	MS_TICK
  #if defined __XC32__
	#define	MS_TICK		_XTAL_FREQ/2000ul
  #elif defined __XC16__
	#define   MS_TICK  1
  #endif
#endif
  #ifdef __cplusplus  // Provide C++ Compatibility
	extern "C"
	{
  #endif

/**
 *  Section: Data Type Definitions
 */

/** ****************************************************************************
  I2C Driver Message Status Type Enumeration

  @Summary
	Defines the different message status symbols used in driver API.

  @Description
	This type enumeration specifies the different types of status
	that an I2C request will have. For every submission of an I2C task,
	user code provide a pointer to a Status word,
	which should declared with this enumeration type.
	During processing, and after completion, the user status variable will have
	one of the enumeration values, indicating state of the transfer.
	Based on the status, new transactions can be requested to the
	driver or a recovery can be performed to resend the transaction.

  @Remark
 *	Even when several instances of I2C Master driver is generated,
 *	there is no good reason why differently named enumeration types have to be used.
 *	With a little conditionals, general names may be used for I2C_MESSAGE_STATUS
 */
  #ifndef I2C_MESSAGE_STATUS_H
  #define I2C_MESSAGE_STATUS_H
typedef volatile enum
{	I2C_MESSAGE_START,
	I2C_OPTION_COMMAND1,				/* _OPTION_values are not used as status return codes. */
	I2C_OPTION_COMMAND2,				/*  May only be used as option argument values, */
	I2C_OPTION_COMMAND3,				/*  when Status variable is not reused */
	I2C_OPTION_COMMAND4,				/*  with multiple active queue entries. */
	I2C_OPTION_BIGEND = 8,
	I2C_OPTION_BIGEND1,
	I2C_OPTION_BIGEND2,
	I2C_OPTION_BIGEND3,
	I2C_OPTION_BIGEND4,
	I2C_OPTION_BLOCKING = 16,
	I2C_OPTION_BLOCKING1,
	I2C_OPTION_BLOCKING2,
	I2C_OPTION_BLOCKING3,
	I2C_OPTION_BLOCKING4,
	I2C_OPTION_BIGBLOCK1 = 25,
	I2C_OPTION_BIGBLOCK2,
	I2C_OPTION_BIGBLOCK3,
	I2C_OPTION_BIGBLOCK4,
	I2C_MESSAGE_PENDING  = 128,
	I2C_MESSAGE_WAIT,
	I2C_MESSAGE_RETRY,
	I2C_MESSAGE_ACTIVE,
	I2C_MESSAGE_COMPLETE,				/* value 132, 0x84 */

	I2C_ERROR_ADDRESS_NACK,
	I2C_ERROR_DATA_NACK,
	I2C_ERROR_QUEUE_FULL,
	I2C_ERROR_STUCK_START,
	I2C_ERROR_BCL,
	I2C_ERROR_FAIL,
	I2C_ERROR_LOST_STATE,
} I2C_MESSAGE_STATUS;

	#define I2C_ADDRESS_10		1024	/* Use 10 bit address protocol. */
	#define I2C_TASK_LINK		2048	/* Linked transfer, do not send Stop signal. */
	#define I2C_MESSAGE_ADDRESS_NO_ACK	I2C_ERROR_ADDRESS_NACK
	#define I2C_MESSAGE_DATA_NO_ACK   	I2C_ERROR_DATA_NACK
	#define I2C_MESSAGE_STUCK_START   	I2C_ERROR_STUCK_START
	#define I2C_MESSAGE_FAIL			I2C_ERROR_FAIL
	#define I2C_MESSAGE_QUEUE_FULL		I2C_ERROR_QUEUE_FULL
	#define I2C_ADDRESS_NO_ACK			I2C_ERROR_ADDRESS_NACK
	#define I2C_DATA_NO_ACK				I2C_ERROR_DATA_NACK
	#define	I2C_ERROR_ADDRESS_NO_ACK	I2C_ERROR_ADDRESS_NACK
	#define I2C_ERROR_DATA_NO_ACK		I2C_ERROR_DATA_NACK
  #endif	// _I2C_MESSAGE_STATUS_H

/** ****************************************************************************
  I2C Driver Transaction Request Block (TRB) type definition.

  @Summary
	This defines the Transaction Request Block (TRB) used by the
	i2c master in sending/receiving data to the i2c bus.

  @Description
	This data type is the i2c Transaction Request Block (TRB) that
	the needs to be built and sent to the driver to handle each i2c requests.
	Using the TRB, simple to complex i2c transactions can be constructed
	and sent to the i2c bus. This data type is only used by the master mode.
 */
typedef struct
{
	uint16_t	address;		// Bits <10:1> are the 10 bit address.
								// Bits <7:1> are the 7 bit address
								// Bit 0 is R/W (1 for read)
	uint8_t		length;			// the # of bytes in the buffer
	uint8_t		*pbuffer;		// a pointer to a buffer of length bytes
} I2C_TRANSACTION_REQUEST_BLOCK;

/** ****************************************************************************
	I2C Driver Status flags Type

	@Summary
		Defines the type used for the task queue status and error logging.

	@Description
		This type is used by the error counter report function only.
 */
typedef union
{	struct
	{	unsigned	full		: 1;
		unsigned	empty		: 1;
		unsigned	reserved	: 5;
		unsigned	WriteCollision	: 1;
		unsigned	BusCollision	: 1;
		unsigned	BclStart	: 1;
		unsigned	BclAddress	: 1;
		unsigned	BclData		: 1;
		unsigned	BclIdle		: 1;
		unsigned	AddressNACK	: 1;
		unsigned	DataNACK	: 1;
		unsigned	LostState	: 1;
	};
	struct
	{	uint8_t		status;
		uint8_t		flags;
	};
} I2C_ERROR_FLAGS;

/** ****************************************************************************
 *  Section: Interface Routines
 */
/** ****************************************************************************
 *  I2C5_Initialize();
 *
  @Summary
	Initializes the I2C instance : 5

  @Description
	This routine initializes the i2c5 driver instance for : 5
	index, making it ready for clients to open and use it.
	This routine must be called before any other I2C5 routine is called.
	This routine should only be called once during system initialization.

  @Preconditions
	None.

  @Param
	None.

  @Returns
	None.

  @Example
	<code>
		#define SLAVE_I2C_GENERIC_RETRY_MAX		100
		#define I2C_DEVICE_TIMEOUT      50   // define slave timeout

		// initialize the module
		I2C5_Initialize();

		// write to an EEPROM Device

		uint16_t		dataAddress;
		uint8_t			sourceData[16] = {  0xA0, 0xA1, 0xA2, 0xA3,
											0xA4, 0xA5, 0xA6, 0xA7,
											0xA8, 0xA9, 0xAA, 0xAB,
											0xAC, 0xAD, 0xAE, 0xAF };
		uint8_t			*pData;
		uint16_t		nCount;

		uint8_t			writeBuffer[3];
		uint8_t			*pD;
		uint16_t		counter, timeOut;

		I2C_MESSAGE_STATUS status = I2C_MESSAGE_PENDING;

		dataAddress = 0x10;				// starting EEPROM address
		pD = sourceData;				// initialize the source of the data
		nCount = 16;					// number of bytes to write

		for (counter = 0; counter < nCount; counter++)
		{

			// build the write buffer first
			// starting address of the EEPROM memory
			writeBuffer[0] = (dataAddress >> 8);				// high address
			writeBuffer[1] = (uint8_t)(dataAddress);			// low low address

			// data to be written
			writeBuffer[2] = *pD++;

			// Now it is possible that the slave device will be slow.
			// As a work around on these slaves, the application can
			// retry sending the transaction
			timeOut = 0;
			while(status != I2C_MESSAGE_FAIL)
			{
				// write one byte to EEPROM (3 is the number of bytes to write)
				I2C5_MasterWrite(  writeBuffer,
										3,
										slaveDeviceAddress,
										&status);

				// wait for the message to be sent or status has changed.
				while(status < I2C_MESSAGE_COMPLETE);

				if (status == I2C_MESSAGE_COMPLETE)
					break;

				// if status is  I2C_ERROR_ADDRESS_NACK,
				//               or I2C_ERROR_DATA_NACK,
				// The device may be busy and need more time for the previous
				// write.  We may retry writing the data, this is why we
				// use a while loop here

				// check for max retry and skip this byte
				if (timeOut == SLAVE_I2C_GENERIC_RETRY_MAX)
					break;
				else
					timeOut++;
			}

			if (status == I2C_MESSAGE_FAIL)
			{
				break;
			}
			dataAddress++;
		}
	</code>
 */
//#if I2Cx_Master_MSSP_Instance == 1
void I2C1_Initialize(void);
//#elif I2Cx_Master_MSSP_Instance == 2
void I2C2_Initialize(void);
//#else
void I2C_Initialize(void);
//#endif

/** ****************************************************************************
 *	I2C_MasterWrite( data[], length, address, &status);
 *
	@Summary
		Handle one i2c master write transaction with the supplied parameters.

	@Description
		This function reserve a task queue entry, fill with arguments provided,
		and activate the interrupt driver.
		Optionally, it may wait for the transaction to complete.

	@Preconditions
		Driver must have been initialized.

	@Param
		address - 7 bit or 10 bit address of the I2C peripheral to be accessed

	@Param
		length - The length of the data block to be sent

	@Param
		*pdata - A pointer to the block of data to be sent

	@Param
		*pstatus - A pointer to the status variable that the i2c driver
			updates during the execution of the message.

	@Returns
		I2C_MESSAGE_STATUS

	@Example
		<code>
			Refer to I2C5_Initialize() and
			I2C5_MasterRead() for an examples
		</code>
 */
/*
void I2C_MasterWrite(
						uint8_t *pdata,
						uint8_t  length,
						uint16_t address,
			I2C_MESSAGE_STATUS  *pstatus);
*/
void I2C1_MasterWrite(
						uint8_t *pdata,
						uint8_t  length,
						uint16_t address,
			I2C_MESSAGE_STATUS  *pstatus);

void I2C2_MasterWrite(
						uint8_t *pdata,
						uint8_t  length,
						uint16_t address,
			I2C_MESSAGE_STATUS  *pstatus);

/*******************************************************************************
 * 	Combined operation:
 *	Start, AddressW, Write command, Write data, Stop
 */
void I2C_MasterCommandWrite(	uint32_t Command,	/* Command value */
								uint8_t *pData,		/* Buffer pointer */
								uint8_t  Length,	/* Transfer length */
								uint16_t Address,	/* I2C Slave address */
					I2C_MESSAGE_STATUS  *pStatus);	/* Pointer to User Status */

void I2C1_MasterCommandWrite(	uint32_t Command,	/* Command value */
								uint8_t *pData,		/* Buffer pointer */
								uint8_t  Length,	/* Transfer length */
								uint16_t Address,	/* I2C Slave address */
					I2C_MESSAGE_STATUS  *pStatus);	/* Pointer to User Status */

void I2C2_MasterCommandWrite(	uint32_t Command,	/* Command value */
								uint8_t *pData,		/* Buffer pointer */
								uint8_t  Length,	/* Transfer length */
								uint16_t Address,	/* I2C Slave address */
					I2C_MESSAGE_STATUS  *pStatus);	/* Pointer to User Status */

/** ****************************************************************************
 *	I2C_MasterWriteRead( Wdata[], WLength, Rdata[], Rlength, Address, &Status);
 *
 *  @Summary
 *		Combined operation:
 *		Start, AddressW, Write data, Restart, AddressR, Read data, Stop.
 *
	@Description
		This function reserve two task queue entries, fill with arguments provided,
		and activate the interrupt driver.
		Optionally, it may wait for the transfer to complete.

	@Preconditions
		There must be at least 2 entries available in Task queue.

	@Param
		*pWriteData - A pointer to the block of data to be sent

	@Param
		writelength - The length of the data block to be sent

	@Param
		*pReadData - A pointer to the array to receive data.

	@Param
		Readlength - The length of the data block to be received.

	@Param
		address - 7 bit or 10 bit address of the I2C peripheral to be accessed.

	@Param
		*pstatus - A pointer to the status variable that the I2C driver
					will update during execution of the transfer.
					Must be of enumeration type I2C_MESSAGE_STATUS
 */
void I2C_MasterWriteRead(	uint8_t *pWriteData,	/* Write buffer pointer */
							uint8_t  WriteLength,	/* Transfer length */
				volatile	uint8_t *pReadData,		/* Read buffer pointer */
							uint8_t  ReadLength,	/* Transfer length */
							uint16_t Address,		/* I2C Slave address */
				I2C_MESSAGE_STATUS  *pStatus);		/* Pointer to Status */

void I2C1_MasterWriteRead(	uint8_t *pWriteData,	/* Write buffer pointer */
							uint8_t  WriteLength,	/* Transfer length */
				volatile	uint8_t *pReadData,		/* Read buffer pointer */
							uint8_t  ReadLength,	/* Transfer length */
							uint16_t Address,		/* I2C Slave address */
				I2C_MESSAGE_STATUS  *pStatus);		/* Pointer to Status */

void I2C2_MasterWriteRead(	uint8_t *pWriteData,	/* Write buffer pointer */
							uint8_t  WriteLength,	/* Transfer length */
				volatile	uint8_t *pReadData,		/* Read buffer pointer */
							uint8_t  ReadLength,	/* Transfer length */
							uint16_t Address,		/* I2C Slave address */
				I2C_MESSAGE_STATUS  *pStatus);		/* Pointer to Status */

/** ****************************************************************************
 *  I2C5_MasterRead(	data[], length, address, *pstatus);
 *
	@Summary
		Request one i2c master read transaction with the supplied parameters.

	@Description
		This function reserve a task queue entry,
		fill it with arguments provided,
		and activate the interrupt driver.
		Optionally, it may wait for the transfer to complete.

	@Preconditions
		None

	@Param
		*pdata - A pointer to the memory location where received data will
				 be stored

	@Param
		length - The length of the data block to be sent

	@Param
		address - 7 bit or 10 bit address of the i2c peripheral to be accessed

	@Param
		*pstatus - A pointer to the status variable that the i2c driver
					will update during execution of the transfer.
					Argument must be pointer to variable of type I2C_MESSAGE_STATUS
	@Returns
		There is no function return value.

	@Example
		<code>
			#define MCHP24AA512_RETRY_MAX       100  // define the retry count
			#define MCHP24AA512_ADDRESS         0x50 // slave device address
			#define MCHP24AA512_DEVICE_TIMEOUT  50   // define slave timeout 


			uint8_t MCHP24AA512_Read(		uint16_t address,
											uint8_t *pData,
											uint16_t nCount)
			{
				I2C5_MESSAGE_STATUS status;
				uint8_t     writeBuffer[3];
				uint16_t    timeOut;
				uint16_t    counter;
				uint8_t     *pD;

				pD = pData;

				for (counter = 0; counter < nCount; counter++)
				{
					// build the write buffer first
					// starting address of the EEPROM memory
					writeBuffer[0] = (address >> 8);                // high address
					writeBuffer[1] = (uint8_t)(address);            // low low address

					// Now it is possible that the slave device will be slow.
					// As a work around on these slaves, the application can
					// retry sending the transaction
					timeOut = 0;
					while(status != I2C5_MESSAGE_FAIL)
					{
						// write one byte to EEPROM (2 is the count of bytes to write)
						I2C5_MasterWrite(    writeBuffer,
												2,
												MCHP24AA512_ADDRESS,
												&status);

						// wait for the message to be sent or status has changed.
						while(status < I2C_MESSAGE_COMPLETE);

						if (status == I2C_MESSAGE_COMPLETE)
							break;

						// if status is  I2C_ERROR_ADDRESS_NACK,
						//               or I2C_ERROR_DATA_NACK,
						// The device may be busy and need more time for the previous
						// write so we can retry writing the data, this is why we
						// use a while loop here

						// check for max retry and skip this byte
						if (timeOut == MCHP24AA512_RETRY_MAX)
							break;
						else
							timeOut++;
					}

					if (status == I2C_MESSAGE_COMPLETE)
					{
						// this portion will read the byte from the memory location.
						timeOut = 0;
						while(status != I2C_MESSAGE_FAIL)
						{
							// write one byte to EEPROM (2 is the count of bytes to write)
							I2C5_MasterRead(	pD,
													1,
													MCHP24AA512_ADDRESS,
													&status);

							// wait for the message to be sent or status has changed.
							while(status < I2C_MESSAGE_COMPLETE);

							if (status == I2C_MESSAGE_COMPLETE)
								break;

							// if status is  I2C_ERROR_ADDRESS_NACK,
							//               or I2C_ERROR_DATA_NACK,
							// The device may be busy and needs more time for the last
							// write so we can retry writing the data, this is why we
							// use a while loop here

							// check for max retry and skip this byte
							if (timeOut == MCHP24AA512_RETRY_MAX)
								break;
							else
								timeOut++;
						}
					}

					// exit if the last transaction failed
					if (status == I2C_MESSAGE_FAIL)
					{
						return(0);
						break;
					}
					pD++;
					address++;
				}
				return(1);
			}
		</code>
 */
void I2C_MasterRead(
			volatile	uint8_t *pdata,
						uint8_t  length,
						uint16_t address,
			I2C_MESSAGE_STATUS  *pstatus);

void I2C1_MasterRead(
			volatile	uint8_t *pdata,
						uint8_t  length,
						uint16_t address,
			I2C_MESSAGE_STATUS  *pstatus);

void I2C2_MasterRead(
			volatile	uint8_t *pdata,
						uint8_t  length,
						uint16_t address,
			I2C_MESSAGE_STATUS  *pstatus);

/** ****************************************************************************
 * 	Combined operation:
 *	Start, AddressW, Write command, Restart, AddressR, Read data, Stop
 */
void I2C_MasterCommandRead(uint32_t Command,	/* Command value */
				volatile	uint8_t *pData,		/* Buffer pointer */
							uint8_t  Length,	/* Transfer length */
							uint16_t Address,	/* I2C Slave address */
				I2C_MESSAGE_STATUS  *pStatus);	/* Pointer to Status */

void I2C1_MasterCommandRead(uint32_t Command,	/* Command value */
				volatile	uint8_t *pData,		/* Buffer pointer */
							uint8_t  Length,	/* Transfer length */
							uint16_t Address,	/* I2C Slave address */
				I2C_MESSAGE_STATUS  *pStatus);	/* Pointer to Status */

void I2C2_MasterCommandRead(uint32_t Command,	/* Command value */
				volatile	uint8_t *pData,		/* Buffer pointer */
							uint8_t  Length,	/* Transfer length */
							uint16_t Address,	/* I2C Slave address */
				I2C_MESSAGE_STATUS  *pStatus);	/* Pointer to Status */

/** ****************************************************************************
 *	I2C_MasterTRBInsert( count, *ptrb_list, &pflag);
 *
    @Summary
        Inserts [a list of] a single i2c transaction requests into the i2c
        transaction queue.

    @Description
        The i2c processes lists of transaction requests.  Each transaction
        list is handled as a string of i2c restarts.  When the list of
        transactions is complete, an i2c stop is produced, the flag is set
        with the correct condition code and the next list is processed
        from the queue.

        This function inserts lists of requests prepared by the user
        application into the queue along with a pointer to the completion
        flag.

        The transaction is inserted into the list only if there is space
        in the list. If there is no space, the function exits with the
        flag set to I2C_MESSAGE_FAIL.

    @Preconditions
        None

    @Param
        count - The numer of transaction requests in the trb_list.

    @Param
        *ptrb_list - A pointer to an array of transaction requests (TRB).
            See I2C_TRANSACTION_REQUEST_BLOCK definition for details.

    @Param
        *pflag - A pointer to a completion flag
              of Enumeration type I2C_MESSAGE_STATUS. Mysil

    @Returns
        None

    @Example
        <code>
            void EMULATED_EEPROM_Read(
                                           uint16_t slaveDeviceAddress,
                                           uint16_t dataAddress,
                                           uint8_t *pData,
                                           uint16_t nCount)
            {
                I2C_MESSAGE_STATUS status;
                I2C_TRANSACTION_REQUEST_BLOCK readTRB[2];
                uint8_t     writeBuffer[3];
                uint16_t    timeOut;

                // this initial value is important
                status = I2C_MESSAGE_PENDING;

                // build the write buffer first
                // starting address of the EEPROM memory
                writeBuffer[0] = (dataAddress >> 8);                        // high address
                writeBuffer[1] = (uint8_t)(dataAddress);                    // low low address

                // we need to create the TRBs for a random read sequence to the EEPROM
                // Build TRB for sending address
                I2C_MasterWriteTRBBuild(   &readTRB[0],
                                                writeBuffer,
                                                2,
                                                slaveDeviceAddress);
                // Build TRB for receiving data
                I2C_MasterReadTRBBuild(    &readTRB[1],
                                                pData,
                                                nCount,
                                                slaveDeviceAddress);
                timeOut = 0;
                while(status != I2C_MESSAGE_FAIL)
                {
                    // now send the transactions
                    I2C1_MasterTRBInsert(2, readTRB, &status);

                    // wait for the message to be sent or status has changed.
                    while(status == I2C_MESSAGE_PENDING);

                    if (status == I2C_MESSAGE_COMPLETE)
                        break;

                    // if status is  I2C_ERROR_ADDRESS_NACK,
                    //               or I2C_ERROR_DATA_NACK,
                    // The device may be busy and needs more time for the last
                    // write so we can retry writing the data, this is why we
                    // use a while loop here

                    // check for max retry and skip this byte
                    if (timeOut == SLAVE_I2C_GENERIC_RETRY_MAX)
                        break;
                    else
                        timeOut++;
                }
            }
        </code>
*/
void I2C_MasterTRBInsert(
                                uint8_t count,
                                I2C_TRANSACTION_REQUEST_BLOCK *ptrb_list,
                                I2C_MESSAGE_STATUS *pflag);

void I2C1_MasterTRBInsert(
                                uint8_t count,
                                I2C_TRANSACTION_REQUEST_BLOCK *ptrb_list,
                                I2C_MESSAGE_STATUS *pflag);

void I2C2_MasterTRBInsert(
                                uint8_t count,
                                I2C_TRANSACTION_REQUEST_BLOCK *ptrb_list,
                                I2C_MESSAGE_STATUS *pflag);

/** ****************************************************************************
 *	I2C_MasterReadTRBBuild( *ptrb, *pdata, length, address);
 *
 *	@Summary
        This function populates a trb supplied by the calling function
        with the parameters supplied by the calling function.

    @Description
        All i2c requests are in the form of TRB's. This helper function
        takes standard parameters and correctly formats the TRB. The R/W
        bit is set to ensure that the resulting TRB describes an i2c read
        operation.

        This function does not send the transaction. To send the transaction,
        the TRB insert function (I2C1_MasterTRBInsert()) must be called.

    @Preconditions
        None

    @Param
        *ptrb - A pointer to a caller supplied TRB.

    @Param
        *pdata - A pointer to the block of data to be received

    @Param
        length - The length of the data block to be received

    @Param
        address - The address of the i2c peripheral to be accessed

    @Returns
        None

    @Example
        <code>
            Refer to I2C1_MasterTRBInsert() for an example
        </code>
*/
void I2C_MasterReadTRBBuild(
                                I2C_TRANSACTION_REQUEST_BLOCK *ptrb,
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address);

/** ****************************************************************************
 *	I2C_MasterWriteTRBBuild( *ptrb, *pdata, length, address);
 *
    @Summary
        This function populates a trb supplied by the calling function
        with the parameters supplied by the calling function.

    @Description
        All i2c requests are in the form of TRB's.  This helper function
        takes standard parameters and correctly formats the TRB. The R/W
        bit is cleared to ensure that the resulting TRB describes an i2c
        write operation.

        This function does not send the transaction. To send the transaction,
        the TRB insert function (I2C1_MasterTRBInsert()) must be called.

    @Preconditions
        None

    @Param
        *ptrb - A pointer to a caller supplied TRB.

    @Param
        *pdata - A pointer to the block of data to be sent

    @Param
        length - The length of the data block to be sent

    @Param
        address - The address of the i2c peripheral to be accessed

    @Returns
        None

    @Example
        <code>
            Refer to I2C1_MasterTRBInsert() for an example	
        </code>

*/
void I2C_MasterWriteTRBBuild(
                                I2C_TRANSACTION_REQUEST_BLOCK *ptrb,
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address);

/** ****************************************************************************
 *	bool I2C1_MasterQueueIsEmpty(void);
 *
    @Summary
        This function returns the empty status of the Master
        queue.

    @Description
        This function returns the empty status of the Master
        queue. Use this function to check if the queue is empty.
        This can verify if the Master is currently idle.

    @Preconditions
        None

    @Param
        None

    @Returns
        True if the queue is empty and false if the queue is not empty.

    @Example
        <code>
            #define MCHP24AA512_ADDRESS    0x50 // slave device address

            // check until queue is empty
            while(I2C1_MasterQueueIsEmpty() == false);

            // now send more data (assume readBuffer is initialized)
            I2C_MasterRead(   readBuffer,
                                    3,
                                    MCHP24AA512_ADDRESS,
                                    &status);
        </code>
*/
bool I2C1_MasterQueueIsEmpty(void);
bool I2C2_MasterQueueIsEmpty(void);

/** ****************************************************************************
 *	bool I2C1_MasterQueueIsFull();
 *
    @Summary
        This function returns the full status of the Master
        queue.

    @Description
        This function returns the full status of the Master
        queue. Use this function to check if the queue is full.
        This can verify if the Master will not be able to accept
        addition transactions.

    @Preconditions
        None

    @Param
        None

    @Returns
        True if the queue is full and false if the queue is not full.

    @Example
        <code>
            #define MCHP24AA512_ADDRESS    0x50 // slave device address

            // check until queue has space
            while(I2C1_MasterQueueIsFull() == true);

            // now send more data (assume readBuffer is initialized)
            I2C_MasterRead(   readBuffer,
                                    3,
                                    MCHP24AA512_ADDRESS,
                                    &status);
        </code>
*/
bool I2C1_MasterQueueIsFull(void);
bool I2C2_MasterQueueIsFull(void);

/** ****************************************************************************
 *
 *	Function to return number of errors recorded and flags indicating type.
 *
 * @Param
 *		*flags	Pointer to struct of type I2C_ERROR_FLAGS
 * @Returns
 *				Number of errors recorded.
 */
uint8_t I2C1_ErrorCountGet(I2C_ERROR_FLAGS * flags);
uint8_t I2C2_ErrorCountGet(I2C_ERROR_FLAGS * flags);

#ifdef __XC8
  #if   I2Cx_Master_MSSP_Instance == 1
void I2C1_ISR ( void );
void I2C1_BusCollisionISR( void );
  #elif I2Cx_Master_MSSP_Instance == 2
void I2C2_ISR ( void );
void I2C2_BusCollisionISR( void );
  #else
void I2C_ISR ( void );
void I2C_BusCollisionISR( void );
  #endif
#endif

/******************************************************************************/
#ifdef __cplusplus  // Provide C++ Compatibility
}
#endif
#endif //_I2C0_MASTER_H
/**
 *	End of File
 */
