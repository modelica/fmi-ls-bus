#include "fmi_3_ls_bus_header_test_helper_ethernet.h"
#include <gtest/gtest.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244)
#endif

void CheckEthernetTransmitOperation(int startDelimiter, int fragmentCounter, int lastFragment, unsigned char destinationAddress[6], unsigned char sourceAddress[6], int typeOrLength, size_t dataSize, fmi3UInt8 data[], bool correctData) {

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
//
//void CheckConfirmOperation(long long int id, bool correctData) {
//
//	// Create data needed for creation.
//	fmi3LsBusUtilBufferInfo firstBufferInfo;
//	fmi3LsBusUtilBufferInfo secondBufferInfo;
//	fmi3UInt8 txData[2048];
//	fmi3UInt8 rxData[2048];
//	fmi3LsBusOperationHeader* operationHeader;
//	fmi3LsBusCanOperationConfirm* operation;
//
//	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
//	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));
//
//	// Create operation.
//	FMI3_LS_BUS_CAN_CREATE_OP_CONFIRM(&firstBufferInfo, id);
//
//	// Write operation to a second buffer.
//	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));
//
//	// Read and check created method from second buffer.
//	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
//
//	operation = (fmi3LsBusCanOperationConfirm*)operationHeader;
//
//	// Specify whether the created data are checked for correctness or an overflow.
//	int multiplier = (correctData) ? 1 : 0;
//
//	EXPECT_EQ(secondBufferInfo.status, fmi3True);
//
//	EXPECT_EQ(operation->id, id * multiplier);
//}
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
//void CheckBusErrorOperation(long long int id, int errorCode, int errorFlag, fmi3UInt8 isSender, bool correctData) {
//
//	// Create data needed for creation.
//	fmi3LsBusUtilBufferInfo firstBufferInfo;
//	fmi3LsBusUtilBufferInfo secondBufferInfo;
//	fmi3UInt8 txData[2048];
//	fmi3UInt8 rxData[2048];
//	fmi3LsBusOperationHeader* operationHeader;
//	fmi3LsBusCanOperationBusError* operation;
//
//	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
//	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));
//
//	// Create operation.
//	FMI3_LS_BUS_CAN_CREATE_OP_BUS_ERROR(&firstBufferInfo, id, errorCode, errorFlag, isSender);
//
//	// Write operation to a second buffer.
//	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));
//
//	// Read and check created method from second buffer.
//	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
//
//	operation = (fmi3LsBusCanOperationBusError*)operationHeader;
//
//	// Specify whether the created data are checked for correctness or an overflow.
//	int multiplier = (correctData) ? 1 : 0;
//
//	EXPECT_EQ(secondBufferInfo.status, fmi3True);
//
//	EXPECT_EQ(operation->id, id * multiplier);
//	EXPECT_EQ(operation->errorCode, errorCode);
//	EXPECT_EQ(operation->errorFlag, errorFlag);
//	EXPECT_EQ(operation->isSender, isSender);
//}
// 
//void CheckWakeupOperation() {
//
//	// Create data needed for creation.
//	fmi3LsBusUtilBufferInfo firstBufferInfo;
//	fmi3LsBusUtilBufferInfo secondBufferInfo;
//	fmi3UInt8 txData[2048];
//	fmi3UInt8 rxData[2048];
//	fmi3LsBusOperationHeader* operationHeader;
//
//	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
//	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));
//
//	// Create operation.
//	FMI3_LS_BUS_CAN_CREATE_OP_WAKEUP(&firstBufferInfo);
//
//	// Write operation to a second buffer.
//	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));
//
//	// Read and check created method from second buffer.
//	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
//
//	EXPECT_EQ(secondBufferInfo.status, fmi3True);
//
//	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_CAN_OP_WAKEUP);
//}
//
//void CheckFormatErrorOperation(Operation operationType) {
//
//	// Create data needed for creation.
//	fmi3LsBusUtilBufferInfo firstBufferInfo;
//	fmi3LsBusUtilBufferInfo secondBufferInfo;
//	fmi3LsBusUtilBufferInfo thirdBufferInfo;
//	fmi3UInt8 txData[2048];
//	fmi3UInt8 rxData[2048];
//	fmi3UInt8 zxData[128];
//
//	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
//
//	fmi3LsBusOperationHeader* operationHeader;
//	fmi3LsBusOperationFormatError* operation;
//
//	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
//	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));
//	FMI3_LS_BUS_BUFFER_INFO_INIT(&thirdBufferInfo, zxData, sizeof(zxData));
//
//	// Create operation depending on which operation is requested as data for the FormatError operation.
//	switch (operationType)
//	{
//	case CanTransmit:
//		FMI3_LS_BUS_CAN_CREATE_OP_CAN_TRANSMIT(&thirdBufferInfo, 0, 0, 0, sizeof(data), data);
//		break;
//	case CanFdTransmit:
//		FMI3_LS_BUS_CAN_CREATE_OP_CAN_FD_TRANSMIT(&thirdBufferInfo, 0, 0, 0, 0, sizeof(data), data);
//		break;
//	case CanXlTransmit:
//		FMI3_LS_BUS_CAN_CREATE_OP_CAN_XL_TRANSMIT(&thirdBufferInfo, 0, 0, 0, 0, 0, 0, sizeof(data), data);
//		break;
//	case Confirm:
//		FMI3_LS_BUS_CAN_CREATE_OP_CONFIRM(&thirdBufferInfo, 0);
//		break;
//	case ConfigurationBaudrate:
//		FMI3_LS_BUS_CAN_CREATE_OP_CONFIGURATION_CAN_BAUDRATE(&thirdBufferInfo, 0);
//		break;
//	case ConfigurationFdBaudrate:
//		FMI3_LS_BUS_CAN_CREATE_OP_CONFIGURATION_CAN_FD_BAUDRATE(&thirdBufferInfo, 0);
//		break;
//	case ConfigurationXlBaudrate:
//		FMI3_LS_BUS_CAN_CREATE_OP_CONFIGURATION_CAN_XL_BAUDRATE(&thirdBufferInfo, 0);
//		break;
//	case ConfigurationArbitrationLostBehavior:
//		FMI3_LS_BUS_CAN_CREATE_OP_CONFIGURATION_ARBITRATION_LOST_BEHAVIOR(&thirdBufferInfo, FMI3_LS_BUS_CAN_CONFIG_PARAM_ARBITRATION_LOST_BEHAVIOR_BUFFER_AND_RETRANSMIT);
//		break;
//	case ArbitrationLost:
//		FMI3_LS_BUS_CAN_CREATE_OP_ARBITRATION_LOST(&thirdBufferInfo, 0);
//		break;
//	case BusError:
//		FMI3_LS_BUS_CAN_CREATE_OP_BUS_ERROR(&thirdBufferInfo, 0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BROKEN_ERROR_FRAME, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_TRUE);
//		break;
//	case Status:
//		FMI3_LS_BUS_CAN_CREATE_OP_STATUS(&thirdBufferInfo, FMI3_LS_BUS_CAN_STATUS_PARAM_STATUS_KIND_BUS_OFF);
//		break;
//	case Wakeup:
//		FMI3_LS_BUS_CAN_CREATE_OP_WAKEUP(&thirdBufferInfo);
//		break;
//	default:
//		FAIL() << "Unsupported operation type.";
//	}
//
//	// Create FormatError operation with previously created operation as data.
//	FMI3_LS_BUS_CREATE_OP_FORMAT_ERROR(&firstBufferInfo, sizeof(zxData), zxData);
//
//	// Write operation to a second buffer.
//	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));
//
//	// Read and check created method from second buffer.
//	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
//
//	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_OP_FORMAT_ERROR);
//
//	operation = (fmi3LsBusOperationFormatError*)operationHeader;
//
//	EXPECT_EQ(operation->dataLength, sizeof(zxData));
//	for (size_t i = 0; i < sizeof(data); i++)
//	{
//		EXPECT_EQ(operation->data[i], zxData[i]);
//	}
//}
//
//void CheckDataSizeError(Operation operation) {
//
//	// Create data needed for creation.
//	fmi3LsBusUtilBufferInfo bufferInfo;
//	fmi3UInt8 txData[1];
//
//	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
//
//	FMI3_LS_BUS_BUFFER_INFO_INIT(&bufferInfo, txData, sizeof(txData));
//
//	// Create operation based on which operation is requested with data that is too big.
//	switch (operation)
//	{
//	case CanTransmit:
//		FMI3_LS_BUS_CAN_CREATE_OP_CAN_TRANSMIT(&bufferInfo, 0, 0, 0, sizeof(data), data);
//		break;
//	case CanFdTransmit:
//		FMI3_LS_BUS_CAN_CREATE_OP_CAN_FD_TRANSMIT(&bufferInfo, 0, 0, 0, 0, sizeof(data), data);
//		break;
//	case CanXlTransmit:
//		FMI3_LS_BUS_CAN_CREATE_OP_CAN_XL_TRANSMIT(&bufferInfo, 0, 0, 0, 0, 0, 0, sizeof(data), data);
//		break;
//	case Confirm:
//		FMI3_LS_BUS_CAN_CREATE_OP_CONFIRM(&bufferInfo, 0);
//		break;
//	case ConfigurationBaudrate:
//		FMI3_LS_BUS_CAN_CREATE_OP_CONFIGURATION_CAN_BAUDRATE(&bufferInfo, 0);
//		break;
//	case ConfigurationFdBaudrate:
//		FMI3_LS_BUS_CAN_CREATE_OP_CONFIGURATION_CAN_FD_BAUDRATE(&bufferInfo, 0);
//		break;
//	case ConfigurationXlBaudrate:
//		FMI3_LS_BUS_CAN_CREATE_OP_CONFIGURATION_CAN_XL_BAUDRATE(&bufferInfo, 0);
//		break;
//	case ConfigurationArbitrationLostBehavior:
//		FMI3_LS_BUS_CAN_CREATE_OP_CONFIGURATION_ARBITRATION_LOST_BEHAVIOR(&bufferInfo, FMI3_LS_BUS_CAN_CONFIG_PARAM_ARBITRATION_LOST_BEHAVIOR_BUFFER_AND_RETRANSMIT);
//		break;
//	case ArbitrationLost:
//		FMI3_LS_BUS_CAN_CREATE_OP_ARBITRATION_LOST(&bufferInfo, 0);
//		break;
//	case BusError:
//		FMI3_LS_BUS_CAN_CREATE_OP_BUS_ERROR(&bufferInfo, 0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BROKEN_ERROR_FRAME, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_TRUE);
//		break;
//	case Status:
//		FMI3_LS_BUS_CAN_CREATE_OP_STATUS(&bufferInfo, FMI3_LS_BUS_CAN_STATUS_PARAM_STATUS_KIND_BUS_OFF);
//		break;
//	case Wakeup:
//		FMI3_LS_BUS_CAN_CREATE_OP_WAKEUP(&bufferInfo);
//		break;
//	case FormatError:
//		FMI3_LS_BUS_CREATE_OP_FORMAT_ERROR(&bufferInfo, sizeof(txData), txData);
//		break;
//	}
//
//	// Check that the creation of the operation returns status 'fmi3False'.
//	EXPECT_EQ(bufferInfo.status, fmi3False);
//}