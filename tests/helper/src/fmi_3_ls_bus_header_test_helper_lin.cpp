#include "fmi_3_ls_bus_header_test_helper_lin.h"
#include <gtest/gtest.h>

void CheckLinTransmitOperation(int framePart, int id, int checksumType, size_t dataSize, fmi3UInt8 data[], bool correctData) {
	fmi3LsBusUtilBufferInfo txBufferInfo;
	fmi3LsBusUtilBufferInfo rxBufferInfo;
	fmi3UInt8 txData[512];
	fmi3UInt8 rxData[512];
	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusLinOperationTransmit* operation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&txBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&rxBufferInfo, rxData, sizeof(rxData));
	FMI3_LS_BUS_LIN_CREATE_OP_TRANSMIT(&txBufferInfo, framePart, id, checksumType, dataSize, data);
	FMI3_LS_BUS_BUFFER_WRITE(&rxBufferInfo, txData, FMI3_LS_BUS_BUFFER_LENGTH(&txBufferInfo));
	FMI3_LS_BUS_READ_NEXT_OPERATION(&rxBufferInfo, operationHeader);

	operation = (fmi3LsBusLinOperationTransmit*)operationHeader;
	int multiplier = correctData ? 1 : 0;
	EXPECT_EQ(txBufferInfo.status, fmi3True);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_LIN_OP_TRANSMIT);
	EXPECT_EQ(operationHeader->length, sizeof(fmi3LsBusOperationHeader) + 4 + dataSize);
	EXPECT_EQ(operation->framePart, framePart * multiplier);
	EXPECT_EQ(operation->id, id * multiplier);
	EXPECT_EQ(operation->checksumType, checksumType * multiplier);
	EXPECT_EQ(operation->dataLength, dataSize);
	for (size_t i = 0; i < dataSize; i++) {
		EXPECT_EQ(operation->data[i], data[i]);
	}
}

void CheckLinConfirmOperation(int id, bool correctData) {
	fmi3LsBusUtilBufferInfo txBufferInfo;
	fmi3LsBusUtilBufferInfo rxBufferInfo;
	fmi3UInt8 txData[64];
	fmi3UInt8 rxData[64];
	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusLinOperationConfirm* operation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&txBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&rxBufferInfo, rxData, sizeof(rxData));
	FMI3_LS_BUS_LIN_CREATE_OP_CONFIRM(&txBufferInfo, id);
	FMI3_LS_BUS_BUFFER_WRITE(&rxBufferInfo, txData, FMI3_LS_BUS_BUFFER_LENGTH(&txBufferInfo));
	FMI3_LS_BUS_READ_NEXT_OPERATION(&rxBufferInfo, operationHeader);

	operation = (fmi3LsBusLinOperationConfirm*)operationHeader;
	EXPECT_EQ(txBufferInfo.status, fmi3True);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_LIN_OP_CONFIRM);
	EXPECT_EQ(operationHeader->length, sizeof(fmi3LsBusOperationHeader) + sizeof(fmi3LsBusLinID));
	EXPECT_EQ(operation->id, id * (correctData ? 1 : 0));
}

void CheckLinBusErrorOperation(int id, int errorCode, bool correctData) {
	fmi3LsBusUtilBufferInfo txBufferInfo;
	fmi3LsBusUtilBufferInfo rxBufferInfo;
	fmi3UInt8 txData[64];
	fmi3UInt8 rxData[64];
	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusLinOperationBusError* operation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&txBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&rxBufferInfo, rxData, sizeof(rxData));
	FMI3_LS_BUS_LIN_CREATE_OP_BUS_ERROR(&txBufferInfo, id, errorCode);
	FMI3_LS_BUS_BUFFER_WRITE(&rxBufferInfo, txData, FMI3_LS_BUS_BUFFER_LENGTH(&txBufferInfo));
	FMI3_LS_BUS_READ_NEXT_OPERATION(&rxBufferInfo, operationHeader);

	operation = (fmi3LsBusLinOperationBusError*)operationHeader;
	int multiplier = correctData ? 1 : 0;
	EXPECT_EQ(txBufferInfo.status, fmi3True);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_LIN_OP_BUS_ERROR);
	EXPECT_EQ(operationHeader->length, sizeof(fmi3LsBusOperationHeader) + sizeof(fmi3LsBusLinID) + sizeof(fmi3LsBusLinBusErrorCode));
	EXPECT_EQ(operation->id, id * multiplier);
	EXPECT_EQ(operation->errorCode, errorCode * multiplier);
}

void CheckLinConfigurationBaudrateOperation(unsigned long long int baudrate, bool correctData) {
	fmi3LsBusUtilBufferInfo txBufferInfo;
	fmi3LsBusUtilBufferInfo rxBufferInfo;
	fmi3UInt8 txData[64];
	fmi3UInt8 rxData[64];
	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusLinOperationConfiguration* operation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&txBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&rxBufferInfo, rxData, sizeof(rxData));
	FMI3_LS_BUS_LIN_CREATE_OP_CONFIGURATION_BAUDRATE(&txBufferInfo, baudrate);
	FMI3_LS_BUS_BUFFER_WRITE(&rxBufferInfo, txData, FMI3_LS_BUS_BUFFER_LENGTH(&txBufferInfo));
	FMI3_LS_BUS_READ_NEXT_OPERATION(&rxBufferInfo, operationHeader);

	operation = (fmi3LsBusLinOperationConfiguration*)operationHeader;
	EXPECT_EQ(txBufferInfo.status, fmi3True);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_LIN_OP_CONFIGURATION);
	EXPECT_EQ(operationHeader->length, sizeof(fmi3LsBusOperationHeader) + sizeof(fmi3LsBusLinConfigParameterType) + sizeof(fmi3LsBusLinConfigurationNodeBaudrateConfig));
	EXPECT_EQ(operation->parameterType, FMI3_LS_BUS_LIN_CONFIG_PARAMETER_TYPE_BAUDRATE);
	EXPECT_EQ(operation->nodeBaudrate.baudrate, correctData ? static_cast<fmi3UInt32>(baudrate) : 0u);
}

void CheckLinConfigurationNodeTypeOperation(int nodeType) {
	fmi3LsBusUtilBufferInfo txBufferInfo;
	fmi3LsBusUtilBufferInfo rxBufferInfo;
	fmi3UInt8 txData[64];
	fmi3UInt8 rxData[64];
	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusLinOperationConfiguration* operation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&txBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&rxBufferInfo, rxData, sizeof(rxData));
	FMI3_LS_BUS_LIN_CREATE_OP_CONFIGURATION_NODE_TYPE(&txBufferInfo, nodeType);
	FMI3_LS_BUS_BUFFER_WRITE(&rxBufferInfo, txData, FMI3_LS_BUS_BUFFER_LENGTH(&txBufferInfo));
	FMI3_LS_BUS_READ_NEXT_OPERATION(&rxBufferInfo, operationHeader);

	operation = (fmi3LsBusLinOperationConfiguration*)operationHeader;
	EXPECT_EQ(txBufferInfo.status, fmi3True);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_LIN_OP_CONFIGURATION);
	EXPECT_EQ(operationHeader->length, sizeof(fmi3LsBusOperationHeader) + sizeof(fmi3LsBusLinConfigParameterType) + sizeof(fmi3LsBusLinConfigurationNodeTypeConfig));
	EXPECT_EQ(operation->parameterType, FMI3_LS_BUS_LIN_CONFIG_PARAMETER_TYPE_NODE_TYPE);
	EXPECT_EQ(operation->nodeType.nodeType, nodeType);
}

void CheckLinWakeupOperation() {
	fmi3LsBusUtilBufferInfo txBufferInfo;
	fmi3LsBusUtilBufferInfo rxBufferInfo;
	fmi3UInt8 txData[64];
	fmi3UInt8 rxData[64];
	fmi3LsBusOperationHeader* operationHeader;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&txBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&rxBufferInfo, rxData, sizeof(rxData));
	FMI3_LS_BUS_LIN_CREATE_OP_WAKEUP(&txBufferInfo);
	FMI3_LS_BUS_BUFFER_WRITE(&rxBufferInfo, txData, FMI3_LS_BUS_BUFFER_LENGTH(&txBufferInfo));
	FMI3_LS_BUS_READ_NEXT_OPERATION(&rxBufferInfo, operationHeader);

	EXPECT_EQ(txBufferInfo.status, fmi3True);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_LIN_OP_WAKEUP);
	EXPECT_EQ(operationHeader->length, sizeof(fmi3LsBusOperationHeader));
}

void CheckLinDataSizeError(LinOperation operation) {
	fmi3LsBusUtilBufferInfo bufferInfo;
	fmi3UInt8 buffer[1];
	fmi3UInt8 data[] = { 'L', 'I', 'N' };

	FMI3_LS_BUS_BUFFER_INFO_INIT(&bufferInfo, buffer, sizeof(buffer));
	switch (operation) {
	case LinTransmit:
		FMI3_LS_BUS_LIN_CREATE_OP_TRANSMIT(&bufferInfo, FMI3_LS_BUS_LIN_FRAME_PART_RESPONSE, 1, FMI3_LS_BUS_LIN_CHECKSUM_TYPE_CLASSIC_CHECKSUM, sizeof(data), data);
		break;
	case LinConfirm:
		FMI3_LS_BUS_LIN_CREATE_OP_CONFIRM(&bufferInfo, 1);
		break;
	case LinBusError:
		FMI3_LS_BUS_LIN_CREATE_OP_BUS_ERROR(&bufferInfo, 1, FMI3_LS_BUS_LIN_BUS_ERROR_CODE_BIT_ERROR);
		break;
	case LinConfiguration:
		FMI3_LS_BUS_LIN_CREATE_OP_CONFIGURATION_BAUDRATE(&bufferInfo, 19200);
		break;
	case LinWakeup:
		FMI3_LS_BUS_LIN_CREATE_OP_WAKEUP(&bufferInfo);
		break;
	}

	EXPECT_EQ(bufferInfo.status, fmi3False);
}