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