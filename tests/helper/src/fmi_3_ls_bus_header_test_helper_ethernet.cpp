#include "fmi_3_ls_bus_header_test_helper_ethernet.h"
#include <gtest/gtest.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244)
#endif

void CheckEthernetTransmitOperation(int startDelimiter, int fragmentCounter, int lastFragment, unsigned char destinationAddress[6], unsigned char sourceAddress[6], int typeOrLength, uint32_t dataSize, fmi3UInt8 data[], bool correctData) {

	// Create data needed for creation.
	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];

	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusEthernetOperationTransmit* operation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	// Create operation.
	FMI3_LS_BUS_ETHERNET_CREATE_OP_TRANSMIT(&firstBufferInfo, startDelimiter, fragmentCounter, lastFragment, destinationAddress, sourceAddress, typeOrLength, dataSize, data);

	// Write operation to a second buffer.
	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	// Read and check created method from second buffer.
	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);

	operation = (fmi3LsBusEthernetOperationTransmit*)operationHeader;

	// Specify whether the created data are checked for correctness or an overflow.
	int multiplier = (correctData) ? 1 : 0;

	EXPECT_EQ(secondBufferInfo.status, fmi3True);

	EXPECT_EQ(operation->fragmentCounter, fragmentCounter * multiplier);
	EXPECT_EQ(operation->lastFragment, lastFragment * multiplier);
	EXPECT_EQ(operation->startDelimiter, startDelimiter * multiplier);
	EXPECT_EQ(operation->typeOrLength, typeOrLength * multiplier);
	EXPECT_EQ(operation->dataLength, dataSize);
	for (size_t i = 0; i < dataSize; i++)
	{
		EXPECT_EQ(operation->data[i], data[i]);
	}
}

void CheckEthernetConfirmOperation() {

	// Create data needed for creation.
	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];
	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusEthernetOperationConfirm* operation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	// Create operation.
	FMI3_LS_BUS_ETHERNET_CREATE_OP_CONFIRM(&firstBufferInfo);

	// Write operation to a second buffer.
	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	// Read and check created method from second buffer.
	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);

	operation = (fmi3LsBusEthernetOperationConfirm*)operationHeader;

	EXPECT_EQ(secondBufferInfo.status, fmi3True);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_ETHERNET_OP_CONFIRM);
}

void CheckEthernetWakeupOperation() {

	// Create data needed for creation.
	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];
	fmi3LsBusOperationHeader* operationHeader;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	// Create operation.
	FMI3_LS_BUS_ETHERNET_CREATE_OP_WAKEUP(&firstBufferInfo);

	// Write operation to a second buffer.
	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	// Read and check created method from second buffer.
	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);

	EXPECT_EQ(secondBufferInfo.status, fmi3True);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_ETHERNET_OP_WAKEUP);
}

void CheckEthernetBusErrorOperation(int errorCode, fmi3UInt8 isSender, bool correctData) {

	// Create data needed for creation.
	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];
	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusEthernetOperationBusError* operation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	// Create operation.
	FMI3_LS_BUS_ETHERNET_CREATE_OP_BUS_ERROR(&firstBufferInfo, errorCode, isSender);

	// Write operation to a second buffer.
	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	// Read and check created method from second buffer.
	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);

	operation = (fmi3LsBusEthernetOperationBusError*)operationHeader;

	EXPECT_EQ(secondBufferInfo.status, fmi3True);

	EXPECT_EQ(operation->errorCode, errorCode);
	EXPECT_EQ(operation->isSender, isSender);
}

void CheckFormatErrorOperation(EthernetOperation operationType) {

	// Create data needed for creation.
	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3LsBusUtilBufferInfo thirdBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];
	fmi3UInt8 zxData[128];

	fmi3UInt8 mdi[] = { 'T', 'E', 'S', 'T' };
	fmi3UInt8 ip[] = { 'T', 'E', 'S', 'T', 'I', 'P' };
	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };

	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusOperationFormatError* operation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&thirdBufferInfo, zxData, sizeof(zxData));

	// Create operation depending on which operation is requested as data for the FormatError operation.
	switch (operationType)
	{
	case Transmit:
		FMI3_LS_BUS_ETHERNET_CREATE_OP_TRANSMIT(&thirdBufferInfo, 0, 0, 0, ip, ip, 0, sizeof(data), data);
		break;
	case Confirm:
		FMI3_LS_BUS_ETHERNET_CREATE_OP_CONFIRM(&thirdBufferInfo);
		break;
	case BusError:
		FMI3_LS_BUS_ETHERNET_CREATE_OP_BUS_ERROR(&thirdBufferInfo, FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_COLLISION, FMI3_LS_BUS_TRUE);
		break;
	case Wakeup:
		FMI3_LS_BUS_ETHERNET_CREATE_OP_WAKEUP(&thirdBufferInfo);
		break;
	default:
		FAIL() << "Unsupported operation type.";
	}

	// Create FormatError operation with previously created operation as data.
	FMI3_LS_BUS_CREATE_OP_FORMAT_ERROR(&firstBufferInfo, sizeof(zxData), zxData);

	// Write operation to a second buffer.
	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	// Read and check created method from second buffer.
	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);

	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_OP_FORMAT_ERROR);

	operation = (fmi3LsBusOperationFormatError*)operationHeader;

	EXPECT_EQ(operation->dataLength, sizeof(zxData));
	for (size_t i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(operation->data[i], zxData[i]);
	}
}

void CheckDataSizeError(EthernetOperation operation) {

	// Create data needed for creation.
	fmi3LsBusUtilBufferInfo bufferInfo;
	fmi3UInt8 txData[1];

	fmi3UInt8 mdi[] = { 'T', 'E', 'S', 'T' };
	fmi3UInt8 ip[] = { 'T', 'E', 'S', 'T', 'I', 'P' };
	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };

	FMI3_LS_BUS_BUFFER_INFO_INIT(&bufferInfo, txData, sizeof(txData));

	// Create operation based on which operation is requested with data that is too big.
	switch (operation)
	{
	case Transmit:
		FMI3_LS_BUS_ETHERNET_CREATE_OP_TRANSMIT(&bufferInfo, 0, 0, 0, ip, ip, 0, sizeof(data), data);
		break;
	case Confirm:
		FMI3_LS_BUS_ETHERNET_CREATE_OP_CONFIRM(&bufferInfo);
		break;
	case BusError:
		FMI3_LS_BUS_ETHERNET_CREATE_OP_BUS_ERROR(&bufferInfo, FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_COLLISION, FMI3_LS_BUS_TRUE);
		break;
	case Wakeup:
		FMI3_LS_BUS_ETHERNET_CREATE_OP_WAKEUP(&bufferInfo);
		break;
	case FormatError:
		FMI3_LS_BUS_CREATE_OP_FORMAT_ERROR(&bufferInfo, sizeof(txData), txData);
		break;
	}

	// Check that the creation of the operation returns status 'fmi3False'.
	EXPECT_EQ(bufferInfo.status, fmi3False);
}











// 
//
//void CheckConfigurationArbitrationLostBehaviorOperation(int arbitrationLostBehavior) {
//
//	// Create data needed for creation.
//	fmi3LsBusUtilBufferInfo firstBufferInfo;
//	fmi3LsBusUtilBufferInfo secondBufferInfo;
//	fmi3UInt8 txData[2048];
//	fmi3UInt8 rxData[2048];
//	fmi3LsBusOperationHeader* operationHeader;
//	fmi3LsBusCanOperationConfiguration* operation;
//
//	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
//	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));
//
//	// Create operation.
//	FMI3_LS_BUS_CAN_CREATE_OP_CONFIGURATION_ARBITRATION_LOST_BEHAVIOR(&firstBufferInfo, arbitrationLostBehavior);
//
//	// Write operation to a second buffer.
//	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));
//
//	// Read and check created method from second buffer.
//	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
//
//	operation = (fmi3LsBusCanOperationConfiguration*)operationHeader;
//
//	EXPECT_EQ(secondBufferInfo.status, fmi3True);
//
//	EXPECT_EQ(operation->arbitrationLostBehavior, arbitrationLostBehavior);
//}
// 

//
