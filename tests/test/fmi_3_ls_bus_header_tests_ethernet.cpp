#include "fmi_3_ls_bus_header_test_helper_ethernet.h"
#include <gtest/gtest.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4309)
#pragma warning(disable : 4305)
#endif

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverflow"
#endif

/**
 * \brief Test for the Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusEthernetTransmit, minValues) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	fmi3UInt8 src[] = { 'A', 'B', 'C', 'A', 'B', 'C' };
	fmi3UInt8 dest[] = { 'A', 'B', 'C', 'A', 'B', 'C' };

	CheckEthernetTransmitOperation(0, 0, 0, src, dest, 0, sizeof(data), data, true);
}

/**
 * \brief Test for the Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusEthernetTransmit, maxValues) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	fmi3UInt8 src[] = { 'A', 'B', 'C', 'A', 'B', 'C' };
	fmi3UInt8 dest[] = { 'A', 'B', 'C', 'A', 'B', 'C' };

	CheckEthernetTransmitOperation(UINT8_MAX, UINT8_MAX, UINT8_MAX, src, dest, UINT16_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the Transmit operation with values that are too big.
 */
TEST(Fmi3LsBusEthernetTransmit, wrongValues) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	fmi3UInt8 src[] = { 'A', 'B', 'C', 'A', 'B', 'C' };
	fmi3UInt8 dest[] = { 'A', 'B', 'C', 'A', 'B', 'C' };

	CheckEthernetTransmitOperation(WRONG_U_INT8, WRONG_U_INT8, WRONG_U_INT8, src, dest, WRONG_U_INT16, sizeof(data), data, false);
}

/**
 * \brief Test for the Confirm operation.
 */
TEST(Fmi3LsBusEthernetConfirm, defaultValues) {
	CheckEthernetConfirmOperation();
}

/**
 * \brief Test for the Wakeup operation.
 */
TEST(Fmi3LsBusEthernetWakeUp, defaultValues) {
	CheckEthernetWakeupOperation();
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorCode and isSender.
 */
TEST(Fmi3LsBusEthernetBusError, minValues1) {

	CheckEthernetBusErrorOperation(FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_COLLISION, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorCode and isSender.
 */
TEST(Fmi3LsBusEthernetBusError, minValues2) {

	CheckEthernetBusErrorOperation(FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_MEDIUM_BUSY, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorCode and isSender.
 */
TEST(Fmi3LsBusEthernetBusError, minValues3) {

	CheckEthernetBusErrorOperation(FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_UNKNOWN, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Format Error operation with data of type Transmit operation.
 */
TEST(Fmi3LsBusEtherneFormatError, Transmit)
{
	CheckFormatErrorOperation(Transmit);
}

/**
 * \brief Test for the Format Error operation with data of type Confirm operation.
 */
TEST(Fmi3LsBusEtherneFormatError, Confirm)
{
	CheckFormatErrorOperation(Confirm);
}

/**
 * \brief Test for the Format Error operation with data of type BusError operation.
 */
TEST(Fmi3LsBusEtherneFormatError, BusError)
{
	CheckFormatErrorOperation(BusError);
}

/**
 * \brief Test for the Format Error operation with data of type Wakeup operation.
 */
TEST(Fmi3LsBusEtherneFormatError, Wakeup)
{
	CheckFormatErrorOperation(Wakeup);
}

/**
 * \brief Test for the Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusEthernetTransmit, sizeError)
{
	CheckDataSizeError(Transmit);
}

/**
 * \brief Test for the Confirm operation with data that is too big.
 */
TEST(Fmi3LsBusEthernetConfirm, sizeError)
{
	CheckDataSizeError(Confirm);
}

/**
 * \brief Test for the BusError operation with data that is too big.
 */
TEST(Fmi3LsBusEthernetBusError, sizeError)
{
	CheckDataSizeError(BusError);
}

/**
 * \brief Test for the Wakeup operation with data that is too big.
 */
TEST(Fmi3LsBusEthernetWakeup, sizeError)
{
	CheckDataSizeError(Wakeup);
}

/**
 * \brief Test for resetting a buffer.
 */
TEST(Fmi3LsBusEthernetCombinationTest, resetBuffer) {

	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	fmi3UInt8 ip[] = { 'T', 'E', 'S', 'T', 'I', 'P' };
	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };

	FMI3_LS_BUS_ETHERNET_CREATE_OP_TRANSMIT(&firstBufferInfo, 0, 0, 0, ip, ip, 0, sizeof(data), data);

	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	FMI3_LS_BUS_BUFFER_INFO_RESET(&firstBufferInfo);
	EXPECT_EQ(firstBufferInfo.readPos, firstBufferInfo.writePos);

	FMI3_LS_BUS_BUFFER_INFO_RESET(&secondBufferInfo);
	EXPECT_EQ(secondBufferInfo.readPos, secondBufferInfo.writePos);
}

/**
 * \brief Test for combination of all operations with the of biggest valid values.
 */
TEST(Fmi3LsBusEthernetCombinationTest, maxValues) {

	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];
	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusEthernetOperationTransmit* ethernetTransmitOperation;
	fmi3LsBusEthernetOperationConfirm* ethernetConfirmOperation;
	fmi3LsBusEthernetOperationBusError* ethernetBusErrorOperation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	fmi3UInt8 ip[] = { 'T', 'E', 'S', 'T', 'I', 'P' };
	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };

	FMI3_LS_BUS_ETHERNET_CREATE_OP_TRANSMIT(&firstBufferInfo, UINT8_MAX, UINT8_MAX, UINT8_MAX, ip, ip, UINT16_MAX, sizeof(data), data);
	FMI3_LS_BUS_ETHERNET_CREATE_OP_CONFIRM(&firstBufferInfo);
	FMI3_LS_BUS_ETHERNET_CREATE_OP_BUS_ERROR(&firstBufferInfo, FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_COLLISION, FMI3_LS_BUS_TRUE);
	FMI3_LS_BUS_ETHERNET_CREATE_OP_WAKEUP(&firstBufferInfo);
	FMI3_LS_BUS_ETHERNET_CREATE_OP_TRANSMIT(&firstBufferInfo, UINT8_MAX, UINT8_MAX, UINT8_MAX, ip, ip, UINT16_MAX, sizeof(data), data);

	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_ETHERNET_OP_TRANSMIT);
	ethernetTransmitOperation = (fmi3LsBusEthernetOperationTransmit*)operationHeader;
	EXPECT_EQ(ethernetTransmitOperation->fragmentCounter, UINT8_MAX);
	EXPECT_EQ(ethernetTransmitOperation->lastFragment, UINT8_MAX);
	EXPECT_EQ(ethernetTransmitOperation->startDelimiter, UINT8_MAX);
	EXPECT_EQ(ethernetTransmitOperation->typeOrLength, UINT16_MAX);
	EXPECT_EQ(ethernetTransmitOperation->dataLength, sizeof(data));
	for (size_t i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(ethernetTransmitOperation->data[i], data[i]);
	}

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	ethernetConfirmOperation = (fmi3LsBusEthernetOperationConfirm*)operationHeader;

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	ethernetBusErrorOperation = (fmi3LsBusEthernetOperationBusError*)operationHeader;
	EXPECT_EQ(ethernetBusErrorOperation->errorCode, FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_COLLISION);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_ETHERNET_OP_WAKEUP);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_ETHERNET_OP_TRANSMIT);
	ethernetTransmitOperation = (fmi3LsBusEthernetOperationTransmit*)operationHeader;
	EXPECT_EQ(ethernetTransmitOperation->fragmentCounter, UINT8_MAX);
	EXPECT_EQ(ethernetTransmitOperation->lastFragment, UINT8_MAX);
	EXPECT_EQ(ethernetTransmitOperation->startDelimiter, UINT8_MAX);
	EXPECT_EQ(ethernetTransmitOperation->typeOrLength, UINT16_MAX);
	EXPECT_EQ(ethernetTransmitOperation->dataLength, sizeof(data));
	for (size_t i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(ethernetTransmitOperation->data[i], data[i]);
	}
}

/**
 * \brief Test for combination of all operations with a mix of biggest valid values and values that are too big.
 */
TEST(Fmi3LsBusEthernetCombinationTest, maxAndWrongValues) {

	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];
	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusEthernetOperationTransmit* ethernetTransmitOperation;
	fmi3LsBusEthernetOperationConfirm* ethernetConfirmOperation;
	fmi3LsBusEthernetOperationBusError* ethernetBusErrorOperation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	fmi3UInt8 ip[] = { 'T', 'E', 'S', 'T', 'I', 'P' };
	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };

	FMI3_LS_BUS_ETHERNET_CREATE_OP_TRANSMIT(&firstBufferInfo, WRONG_U_INT8, WRONG_U_INT8, WRONG_U_INT8, ip, ip, WRONG_U_INT32, sizeof(data), data);
	FMI3_LS_BUS_ETHERNET_CREATE_OP_CONFIRM(&firstBufferInfo);
	FMI3_LS_BUS_ETHERNET_CREATE_OP_BUS_ERROR(&firstBufferInfo, FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_COLLISION, FMI3_LS_BUS_TRUE);
	FMI3_LS_BUS_ETHERNET_CREATE_OP_WAKEUP(&firstBufferInfo);
	FMI3_LS_BUS_ETHERNET_CREATE_OP_TRANSMIT(&firstBufferInfo, WRONG_U_INT8, WRONG_U_INT8, WRONG_U_INT8, ip, ip, WRONG_U_INT32, sizeof(data), data);

	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_ETHERNET_OP_TRANSMIT);
	ethernetTransmitOperation = (fmi3LsBusEthernetOperationTransmit*)operationHeader;
	EXPECT_EQ(ethernetTransmitOperation->fragmentCounter, 0);
	EXPECT_EQ(ethernetTransmitOperation->lastFragment, 0);
	EXPECT_EQ(ethernetTransmitOperation->startDelimiter, 0);
	EXPECT_EQ(ethernetTransmitOperation->typeOrLength, 0);
	EXPECT_EQ(ethernetTransmitOperation->dataLength, sizeof(data));
	for (size_t i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(ethernetTransmitOperation->data[i], data[i]);
	}

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	ethernetConfirmOperation = (fmi3LsBusEthernetOperationConfirm*)operationHeader;

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	ethernetBusErrorOperation = (fmi3LsBusEthernetOperationBusError*)operationHeader;
	EXPECT_EQ(ethernetBusErrorOperation->errorCode, FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_COLLISION);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_ETHERNET_OP_WAKEUP);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_ETHERNET_OP_TRANSMIT);
	ethernetTransmitOperation = (fmi3LsBusEthernetOperationTransmit*)operationHeader;
	EXPECT_EQ(ethernetTransmitOperation->fragmentCounter, 0);
	EXPECT_EQ(ethernetTransmitOperation->lastFragment, 0);
	EXPECT_EQ(ethernetTransmitOperation->startDelimiter, 0);
	EXPECT_EQ(ethernetTransmitOperation->typeOrLength, 0);
	for (size_t i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(ethernetTransmitOperation->data[i], data[i]);
	}
}

/**
 * \brief Test for the Configuration:Phy-Types operation.
 */
TEST(Fmi3LsBusEthernetConfiguration, differentValues1) {

	fmi3Char data[8] = { 'A', 'B', 'C', '\0', 'A', 'B', 'C', '\0' };

	CheckEthernetConfigurationSupportedPhyTypesOperation(FMI3_LS_BUS_ETHERNET_MDI_MODE_NONE, 8, data);
}

/**
 * \brief Test for the Configuration:Phy-Types operation.
 */
TEST(Fmi3LsBusEthernetConfiguration, differentValues2) {

	fmi3Char data[8] = { 'A', 'B', 'C', '\0', 'A', 'B', 'C', '\0' };

	CheckEthernetConfigurationSupportedPhyTypesOperation(FMI3_LS_BUS_ETHERNET_MDI_MODE_MDI, 8, data);
}

/**
 * \brief Test for the Configuration:Phy-Types operation.
 */
TEST(Fmi3LsBusEthernetConfiguration, differentValues3) {

	fmi3Char data[8] = { 'A', '\0', 'C', '\0', 'A', '\0', 'C', '\0' };

	CheckEthernetConfigurationSupportedPhyTypesOperation(FMI3_LS_BUS_ETHERNET_MDI_MODE_MDI, 8, data);
}