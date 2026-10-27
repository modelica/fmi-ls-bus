#include "fmi_3_ls_bus_header_test_helper_lin.h"
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

TEST(Fmi3LsBusLinOperationCodes, values) {
	EXPECT_EQ(FMI3_LS_BUS_LIN_OP_TRANSMIT, 0x10);
	EXPECT_EQ(FMI3_LS_BUS_LIN_OP_CONFIRM, 0x20);
	EXPECT_EQ(FMI3_LS_BUS_LIN_OP_BUS_ERROR, 0x30);
	EXPECT_EQ(FMI3_LS_BUS_LIN_OP_CONFIGURATION, 0x40);
	EXPECT_EQ(FMI3_LS_BUS_LIN_OP_WAKEUP, 0x50);
}

TEST(Fmi3LsBusLinTypes, values) {
	EXPECT_EQ(FMI3_LS_BUS_LIN_FRAME_PART_HEADER, 0x1);
	EXPECT_EQ(FMI3_LS_BUS_LIN_FRAME_PART_RESPONSE, 0x2);
	EXPECT_EQ(FMI3_LS_BUS_LIN_CHECKSUM_TYPE_CLASSIC_CHECKSUM, 0x1);
	EXPECT_EQ(FMI3_LS_BUS_LIN_CHECKSUM_TYPE_ENHANCED_CHECKSUM, 0x2);
	EXPECT_EQ(FMI3_LS_BUS_LIN_BUS_ERROR_CODE_BIT_ERROR, 0x1);
	EXPECT_EQ(FMI3_LS_BUS_LIN_BUS_ERROR_CODE_CHECKSUM_ERROR, 0x2);
	EXPECT_EQ(FMI3_LS_BUS_LIN_BUS_ERROR_CODE_IDENTIFIER_PARITY_ERROR, 0x3);
	EXPECT_EQ(FMI3_LS_BUS_LIN_BUS_ERROR_CODE_NO_RESPONSE_ERROR, 0x4);
	EXPECT_EQ(FMI3_LS_BUS_LIN_BUS_ERROR_CODE_SYNCH_FIELD_ERROR, 0x5);
	EXPECT_EQ(FMI3_LS_BUS_LIN_BUS_ERROR_CODE_SYNCH_TOLERANCE_ERROR, 0x6);
	EXPECT_EQ(FMI3_LS_BUS_LIN_BUS_ERROR_CODE_HEADER_TIMEOUT_ERROR, 0x7);
	EXPECT_EQ(FMI3_LS_BUS_LIN_BUS_ERROR_CODE_FRAME_ERROR, 0x8);
	EXPECT_EQ(FMI3_LS_BUS_LIN_BUS_ERROR_CODE_PHYSICAL_BUS_ERROR, 0x9);
	EXPECT_EQ(FMI3_LS_BUS_LIN_NODE_TYPE_LIN_COMMANDER, 0x1);
	EXPECT_EQ(FMI3_LS_BUS_LIN_NODE_TYPE_LIN_RESPONDER, 0x2);
	EXPECT_EQ(FMI3_LS_BUS_LIN_CONFIG_PARAMETER_TYPE_BAUDRATE, 0x1);
	EXPECT_EQ(FMI3_LS_BUS_LIN_CONFIG_PARAMETER_TYPE_NODE_TYPE, 0x2);
}

TEST(Fmi3LsBusLinTransmit, minValues) {
	fmi3UInt8 data[] = { 'L', 'I', 'N' };
	CheckLinTransmitOperation(FMI3_LS_BUS_LIN_FRAME_PART_HEADER, 0, FMI3_LS_BUS_LIN_CHECKSUM_TYPE_CLASSIC_CHECKSUM, sizeof(data), data, true);
}

TEST(Fmi3LsBusLinTransmit, maxValues) {
	fmi3UInt8 data[] = { 'L', 'I', 'N' };
	CheckLinTransmitOperation(UINT8_MAX, UINT8_MAX, UINT8_MAX, sizeof(data), data, true);
}

TEST(Fmi3LsBusLinTransmit, headerHasNoPayload) {
	fmi3UInt8 data[] = { 'L' };
	CheckLinTransmitOperation(FMI3_LS_BUS_LIN_FRAME_PART_HEADER, 0x3f, FMI3_LS_BUS_LIN_CHECKSUM_TYPE_CLASSIC_CHECKSUM, 0, data, true);
}

TEST(Fmi3LsBusLinTransmit, responseWithEnhancedChecksum) {
	fmi3UInt8 data[] = { 0x10, 0x20, 0x30, 0x40 };
	CheckLinTransmitOperation(FMI3_LS_BUS_LIN_FRAME_PART_RESPONSE, 0x12, FMI3_LS_BUS_LIN_CHECKSUM_TYPE_ENHANCED_CHECKSUM, sizeof(data), data, true);
}

TEST(Fmi3LsBusLinTransmit, maxPayloadLength) {
	fmi3UInt8 data[UINT8_MAX];
	for (size_t i = 0; i < sizeof(data); i++) {
		data[i] = static_cast<fmi3UInt8>(i);
	}
	CheckLinTransmitOperation(FMI3_LS_BUS_LIN_FRAME_PART_RESPONSE, UINT8_MAX, FMI3_LS_BUS_LIN_CHECKSUM_TYPE_ENHANCED_CHECKSUM, sizeof(data), data, true);
}

TEST(Fmi3LsBusLinTransmit, wrongValues) {
	fmi3UInt8 data[] = { 'L', 'I', 'N' };
	CheckLinTransmitOperation(256, 256, 256, sizeof(data), data, false);
}

TEST(Fmi3LsBusLinTransmit, sizeError) {
	CheckLinDataSizeError(LinTransmit);
}

TEST(Fmi3LsBusLinTransmitCombinations, validFieldMatrix) {
	const fmi3LsBusLinFramePart frameParts[] = {
		FMI3_LS_BUS_LIN_FRAME_PART_HEADER,
		FMI3_LS_BUS_LIN_FRAME_PART_RESPONSE
	};
	const fmi3LsBusLinID ids[] = { 0, 1, 0x3f, 0x7f, UINT8_MAX };
	const fmi3LsBusLinChecksumType checksumTypes[] = {
		FMI3_LS_BUS_LIN_CHECKSUM_TYPE_CLASSIC_CHECKSUM,
		FMI3_LS_BUS_LIN_CHECKSUM_TYPE_ENHANCED_CHECKSUM
	};
	const size_t responseLengths[] = { 0, 1, 2, 8, UINT8_MAX };
	fmi3UInt8 data[UINT8_MAX];
	for (size_t i = 0; i < sizeof(data); i++) {
		data[i] = static_cast<fmi3UInt8>(i * 17);
	}

	for (fmi3LsBusLinFramePart framePart : frameParts) {
		const size_t lengthCount = framePart == FMI3_LS_BUS_LIN_FRAME_PART_HEADER
			? 1
			: sizeof(responseLengths) / sizeof(responseLengths[0]);
		for (fmi3LsBusLinID id : ids) {
			for (fmi3LsBusLinChecksumType checksumType : checksumTypes) {
				for (size_t lengthIndex = 0; lengthIndex < lengthCount; lengthIndex++) {
					const size_t dataLength = framePart == FMI3_LS_BUS_LIN_FRAME_PART_HEADER
						? 0
						: responseLengths[lengthIndex];
					SCOPED_TRACE(::testing::Message()
						<< "framePart=" << static_cast<int>(framePart)
						<< ", id=" << static_cast<int>(id)
						<< ", checksumType=" << static_cast<int>(checksumType)
						<< ", dataLength=" << dataLength);
					CheckLinTransmitOperation(framePart, id, checksumType, dataLength, data, true);
				}
			}
		}
	}
}

TEST(Fmi3LsBusLinConfirm, minValues) {
	CheckLinConfirmOperation(0, true);
}

TEST(Fmi3LsBusLinConfirm, maxValues) {
	CheckLinConfirmOperation(UINT8_MAX, true);
}

TEST(Fmi3LsBusLinConfirm, wrongValues) {
	CheckLinConfirmOperation(256, false);
}

TEST(Fmi3LsBusLinConfirm, sizeError) {
	CheckLinDataSizeError(LinConfirm);
}

TEST(Fmi3LsBusLinConfirmCombinations, messageIds) {
	const fmi3LsBusLinID ids[] = { 0, 1, 0x3f, 0x7f, UINT8_MAX };
	for (fmi3LsBusLinID id : ids) {
		SCOPED_TRACE(::testing::Message() << "id=" << static_cast<int>(id));
		CheckLinConfirmOperation(id, true);
	}
}

TEST(Fmi3LsBusLinBusError, minValues) {
	CheckLinBusErrorOperation(0, FMI3_LS_BUS_LIN_BUS_ERROR_CODE_BIT_ERROR, true);
}

TEST(Fmi3LsBusLinBusError, checksumError) {
	CheckLinBusErrorOperation(0x12, FMI3_LS_BUS_LIN_BUS_ERROR_CODE_CHECKSUM_ERROR, true);
}

TEST(Fmi3LsBusLinBusError, identifierParityError) {
	CheckLinBusErrorOperation(0x12, FMI3_LS_BUS_LIN_BUS_ERROR_CODE_IDENTIFIER_PARITY_ERROR, true);
}

TEST(Fmi3LsBusLinBusError, noResponseError) {
	CheckLinBusErrorOperation(0x12, FMI3_LS_BUS_LIN_BUS_ERROR_CODE_NO_RESPONSE_ERROR, true);
}

TEST(Fmi3LsBusLinBusError, synchFieldError) {
	CheckLinBusErrorOperation(0x12, FMI3_LS_BUS_LIN_BUS_ERROR_CODE_SYNCH_FIELD_ERROR, true);
}

TEST(Fmi3LsBusLinBusError, synchToleranceError) {
	CheckLinBusErrorOperation(0x12, FMI3_LS_BUS_LIN_BUS_ERROR_CODE_SYNCH_TOLERANCE_ERROR, true);
}

TEST(Fmi3LsBusLinBusError, headerTimeoutError) {
	CheckLinBusErrorOperation(0x12, FMI3_LS_BUS_LIN_BUS_ERROR_CODE_HEADER_TIMEOUT_ERROR, true);
}

TEST(Fmi3LsBusLinBusError, frameError) {
	CheckLinBusErrorOperation(0x12, FMI3_LS_BUS_LIN_BUS_ERROR_CODE_FRAME_ERROR, true);
}

TEST(Fmi3LsBusLinBusError, physicalBusError) {
	CheckLinBusErrorOperation(0x12, FMI3_LS_BUS_LIN_BUS_ERROR_CODE_PHYSICAL_BUS_ERROR, true);
}

TEST(Fmi3LsBusLinBusError, maxValues) {
	CheckLinBusErrorOperation(UINT8_MAX, FMI3_LS_BUS_LIN_BUS_ERROR_CODE_PHYSICAL_BUS_ERROR, true);
}

TEST(Fmi3LsBusLinBusError, wrongValues) {
	CheckLinBusErrorOperation(256, 256, false);
}

TEST(Fmi3LsBusLinBusError, sizeError) {
	CheckLinDataSizeError(LinBusError);
}

TEST(Fmi3LsBusLinBusErrorCombinations, errorCodesAndMessageIds) {
	const fmi3LsBusLinBusErrorCode errorCodes[] = {
		FMI3_LS_BUS_LIN_BUS_ERROR_CODE_BIT_ERROR,
		FMI3_LS_BUS_LIN_BUS_ERROR_CODE_CHECKSUM_ERROR,
		FMI3_LS_BUS_LIN_BUS_ERROR_CODE_IDENTIFIER_PARITY_ERROR,
		FMI3_LS_BUS_LIN_BUS_ERROR_CODE_NO_RESPONSE_ERROR,
		FMI3_LS_BUS_LIN_BUS_ERROR_CODE_SYNCH_FIELD_ERROR,
		FMI3_LS_BUS_LIN_BUS_ERROR_CODE_SYNCH_TOLERANCE_ERROR,
		FMI3_LS_BUS_LIN_BUS_ERROR_CODE_HEADER_TIMEOUT_ERROR,
		FMI3_LS_BUS_LIN_BUS_ERROR_CODE_FRAME_ERROR,
		FMI3_LS_BUS_LIN_BUS_ERROR_CODE_PHYSICAL_BUS_ERROR
	};
	const fmi3LsBusLinID ids[] = { 0, 1, 0x3f, 0x7f, UINT8_MAX };
	for (fmi3LsBusLinBusErrorCode errorCode : errorCodes) {
		for (fmi3LsBusLinID id : ids) {
			SCOPED_TRACE(::testing::Message()
				<< "errorCode=" << static_cast<int>(errorCode)
				<< ", id=" << static_cast<int>(id));
			CheckLinBusErrorOperation(id, errorCode, true);
		}
	}
}

TEST(Fmi3LsBusLinConfigurationBaudrate, minValues) {
	CheckLinConfigurationBaudrateOperation(0, true);
}

TEST(Fmi3LsBusLinConfigurationBaudrate, maxValues) {
	CheckLinConfigurationBaudrateOperation(UINT32_MAX, true);
}

TEST(Fmi3LsBusLinConfigurationBaudrate, wrongValues) {
	CheckLinConfigurationBaudrateOperation(0x100000000ULL, false);
}

TEST(Fmi3LsBusLinConfigurationBaudrate, sizeError) {
	CheckLinDataSizeError(LinConfiguration);
}

TEST(Fmi3LsBusLinConfigurationBaudrateCombinations, commonAndBoundaryValues) {
	const unsigned long long baudrates[] = { 0, 1200, 9600, 10400, 19200, 20000, UINT32_MAX };
	for (unsigned long long baudrate : baudrates) {
		SCOPED_TRACE(::testing::Message() << "baudrate=" << baudrate);
		CheckLinConfigurationBaudrateOperation(baudrate, true);
	}
}

TEST(Fmi3LsBusLinConfigurationNodeType, commander) {
	CheckLinConfigurationNodeTypeOperation(FMI3_LS_BUS_LIN_NODE_TYPE_LIN_COMMANDER);
}

TEST(Fmi3LsBusLinConfigurationNodeType, responder) {
	CheckLinConfigurationNodeTypeOperation(FMI3_LS_BUS_LIN_NODE_TYPE_LIN_RESPONDER);
}

TEST(Fmi3LsBusLinWakeup, defaultValues) {
	CheckLinWakeupOperation();
}

TEST(Fmi3LsBusLinWakeup, sizeError) {
	CheckLinDataSizeError(LinWakeup);
}

TEST(Fmi3LsBusLinMixedOperations, bufferRoundtrip) {
	fmi3LsBusUtilBufferInfo txBufferInfo;
	fmi3LsBusUtilBufferInfo rxBufferInfo;
	fmi3UInt8 txData[256];
	fmi3UInt8 rxData[256];
	fmi3UInt8 payload[] = { 0x10, 0x20, 0x30 };
	fmi3LsBusOperationHeader* operationHeader;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&txBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&rxBufferInfo, rxData, sizeof(rxData));
	FMI3_LS_BUS_LIN_CREATE_OP_TRANSMIT(&txBufferInfo, FMI3_LS_BUS_LIN_FRAME_PART_RESPONSE, 0x12, FMI3_LS_BUS_LIN_CHECKSUM_TYPE_ENHANCED_CHECKSUM, sizeof(payload), payload);
	FMI3_LS_BUS_LIN_CREATE_OP_CONFIRM(&txBufferInfo, 0x12);
	FMI3_LS_BUS_LIN_CREATE_OP_BUS_ERROR(&txBufferInfo, 0x34, FMI3_LS_BUS_LIN_BUS_ERROR_CODE_CHECKSUM_ERROR);
	FMI3_LS_BUS_LIN_CREATE_OP_CONFIGURATION_BAUDRATE(&txBufferInfo, 19200);
	FMI3_LS_BUS_LIN_CREATE_OP_CONFIGURATION_NODE_TYPE(&txBufferInfo, FMI3_LS_BUS_LIN_NODE_TYPE_LIN_RESPONDER);
	FMI3_LS_BUS_LIN_CREATE_OP_WAKEUP(&txBufferInfo);
	ASSERT_EQ(txBufferInfo.status, fmi3True);
	FMI3_LS_BUS_BUFFER_WRITE(&rxBufferInfo, txData, FMI3_LS_BUS_BUFFER_LENGTH(&txBufferInfo));

	FMI3_LS_BUS_READ_NEXT_OPERATION(&rxBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_LIN_OP_TRANSMIT);
	auto* transmit = reinterpret_cast<fmi3LsBusLinOperationTransmit*>(operationHeader);
	EXPECT_EQ(transmit->id, 0x12);
	EXPECT_EQ(transmit->checksumType, FMI3_LS_BUS_LIN_CHECKSUM_TYPE_ENHANCED_CHECKSUM);
	EXPECT_EQ(transmit->dataLength, sizeof(payload));
	for (size_t i = 0; i < sizeof(payload); i++) {
		EXPECT_EQ(transmit->data[i], payload[i]);
	}

	FMI3_LS_BUS_READ_NEXT_OPERATION(&rxBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_LIN_OP_CONFIRM);
	EXPECT_EQ(reinterpret_cast<fmi3LsBusLinOperationConfirm*>(operationHeader)->id, 0x12);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&rxBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_LIN_OP_BUS_ERROR);
	auto* busError = reinterpret_cast<fmi3LsBusLinOperationBusError*>(operationHeader);
	EXPECT_EQ(busError->id, 0x34);
	EXPECT_EQ(busError->errorCode, FMI3_LS_BUS_LIN_BUS_ERROR_CODE_CHECKSUM_ERROR);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&rxBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_LIN_OP_CONFIGURATION);
	auto* baudrateConfig = reinterpret_cast<fmi3LsBusLinOperationConfiguration*>(operationHeader);
	EXPECT_EQ(baudrateConfig->parameterType, FMI3_LS_BUS_LIN_CONFIG_PARAMETER_TYPE_BAUDRATE);
	EXPECT_EQ(baudrateConfig->nodeBaudrate.baudrate, 19200);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&rxBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_LIN_OP_CONFIGURATION);
	auto* nodeTypeConfig = reinterpret_cast<fmi3LsBusLinOperationConfiguration*>(operationHeader);
	EXPECT_EQ(nodeTypeConfig->parameterType, FMI3_LS_BUS_LIN_CONFIG_PARAMETER_TYPE_NODE_TYPE);
	EXPECT_EQ(nodeTypeConfig->nodeType.nodeType, FMI3_LS_BUS_LIN_NODE_TYPE_LIN_RESPONDER);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&rxBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_LIN_OP_WAKEUP);
	FMI3_LS_BUS_READ_NEXT_OPERATION(&rxBufferInfo, operationHeader);
}

TEST(Fmi3LsBusLinBufferCapacity, operationBoundaryMatrix) {
	struct OperationCapacity {
		LinOperation operation;
		size_t requiredSize;
		const char* name;
	};
	const OperationCapacity operations[] = {
		{ LinTransmit, sizeof(fmi3LsBusOperationHeader) + 4 + 2, "transmit" },
		{ LinConfirm, sizeof(fmi3LsBusOperationHeader) + sizeof(fmi3LsBusLinID), "confirm" },
		{ LinBusError, sizeof(fmi3LsBusOperationHeader) + sizeof(fmi3LsBusLinID) + sizeof(fmi3LsBusLinBusErrorCode), "bus error" },
		{ LinConfiguration, sizeof(fmi3LsBusOperationHeader) + sizeof(fmi3LsBusLinConfigParameterType) + sizeof(fmi3LsBusLinConfigurationNodeBaudrateConfig), "baudrate configuration" },
		{ LinConfigurationNodeType, sizeof(fmi3LsBusOperationHeader) + sizeof(fmi3LsBusLinConfigParameterType) + sizeof(fmi3LsBusLinConfigurationNodeTypeConfig), "node type configuration" },
		{ LinWakeup, sizeof(fmi3LsBusOperationHeader), "wakeup" }
	};

	for (const OperationCapacity& operation : operations) {
		SCOPED_TRACE(operation.name);
		CheckLinBufferCapacity(operation.operation, operation.requiredSize - 1, operation.requiredSize);
		CheckLinBufferCapacity(operation.operation, operation.requiredSize, operation.requiredSize);
		CheckLinBufferCapacity(operation.operation, operation.requiredSize + 1, operation.requiredSize);
	}
}