#include "fmi_3_ls_bus_header_test_helper_flexray.h"
#include <gtest/gtest.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244)
#endif

void CheckFlexRayTransmitOperation(int cycleId, int slotId, int channel, fmi3UInt8 startUpFrameIndicator,
	fmi3UInt8 syncFrameIndicator, fmi3UInt8 nullFrameIndicator, fmi3UInt8 payloadPreambleIndicator, size_t dataSize, fmi3UInt8 data[], bool correctData)
{
	// Create data needed for creation.
	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];

	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusFlexRayOperationTransmit* operation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	// Create operation.
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_TRANSMIT(&firstBufferInfo, cycleId, slotId, channel,
		startUpFrameIndicator, syncFrameIndicator, nullFrameIndicator,
		payloadPreambleIndicator, dataSize, data);

	// Write operation to a second buffer.
	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	// Read and check created method from second buffer.
	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);

	operation = (fmi3LsBusFlexRayOperationTransmit*)operationHeader;

	// Specify whether the created data are checked for correctness or an overflow.
	int multiplier = (correctData) ? 1 : 0;

	EXPECT_EQ(secondBufferInfo.status, fmi3True);

	EXPECT_EQ(operation->cycleId, cycleId * multiplier);
	EXPECT_EQ(operation->slotId, slotId * multiplier);
	EXPECT_EQ(operation->channel, channel * multiplier);
	EXPECT_EQ(operation->startupFrameIndicator, startUpFrameIndicator);
	EXPECT_EQ(operation->syncFrameIndicator, syncFrameIndicator);
	EXPECT_EQ(operation->nullFrameIndicator, nullFrameIndicator);
	EXPECT_EQ(operation->payloadPreambleIndicator, payloadPreambleIndicator);
	EXPECT_EQ(operation->dataLength, dataSize);
	for (size_t i = 0; i < dataSize; i++)
	{
		EXPECT_EQ(operation->data[i], data[i]);
	}
}

void CheckFlexRayBusErrorOperation(int errorFlags, int cycleId, int segmentIndicator, int channel, bool correctData)
{
	// Create data needed for creation.
	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];

	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusFlexRayOperationBusError* operation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	// Create operation.
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_BUS_ERROR(&firstBufferInfo, errorFlags, cycleId, segmentIndicator, channel);

	// Write operation to a second buffer.
	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	// Read and check created method from second buffer.
	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);

	operation = (fmi3LsBusFlexRayOperationBusError*)operationHeader;

	// Specify whether the created data are checked for correctness or an overflow.
	int multiplier = (correctData) ? 1 : 0;

	EXPECT_EQ(secondBufferInfo.status, fmi3True);

	EXPECT_EQ(operation->errorFlags, errorFlags);
	EXPECT_EQ(operation->cycleId, cycleId * multiplier);
	EXPECT_EQ(operation->segmentIndicator, segmentIndicator * multiplier);
	EXPECT_EQ(operation->channel, channel * multiplier);
}

void CheckFlexRayCancelOperation(int cycleId, int slotId, int channel, bool correctData)
{
	// Create data needed for creation.
	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];

	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusFlexRayOperationCancel* operation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	// Create operation.
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_CANCEL(&firstBufferInfo, cycleId, slotId, channel);

	// Write operation to a second buffer.
	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	// Read and check created method from second buffer.
	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);

	operation = (fmi3LsBusFlexRayOperationCancel*)operationHeader;

	// Specify whether the created data are checked for correctness or an overflow.
	int multiplier = (correctData) ? 1 : 0;

	EXPECT_EQ(secondBufferInfo.status, fmi3True);

	EXPECT_EQ(operation->cycleId, cycleId * multiplier);
	EXPECT_EQ(operation->slotId, slotId * multiplier);
	EXPECT_EQ(operation->channel, channel * multiplier);
}

void CheckFlexRayConfirmOperation(int cycleId, int slotId, int channel, bool correctData)
{
	// Create data needed for creation.
	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];

	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusFlexRayOperationConfirm* operation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	// Create operation.
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_CONFIRM(&firstBufferInfo, cycleId, slotId, channel);

	// Write operation to a second buffer.
	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	// Read and check created method from second buffer.
	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);

	operation = (fmi3LsBusFlexRayOperationConfirm*)operationHeader;

	// Specify whether the created data are checked for correctness or an overflow.
	int multiplier = (correctData) ? 1 : 0;

	EXPECT_EQ(secondBufferInfo.status, fmi3True);

	EXPECT_EQ(operation->cycleId, cycleId * multiplier);
	EXPECT_EQ(operation->slotId, slotId * multiplier);
	EXPECT_EQ(operation->channel, channel * multiplier);
}

void CheckFlexRayConfigurationOperation(FlexRayOperation operationType, long long int macrotickDuration, int macroticksPerCycle, int maxCycleCount, int actionPointOffset, int staticSlotLength, int numberOfStaticSlots, int staticPayloadLength, int minislotActionPointOffset, int numberOfMinislots, int minislotLength, int symbolActionPointOffset, int symbolWindowLength, int nitLength, int nmVectorLength, long long int dynamicSlotIdleTime, fmi3Boolean coldStartNode, bool correctData)
{
	// Create data needed for creation.
	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];

	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusFlexRayOperationConfiguration* operation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	// Create operation.
	switch (operationType)
	{
	case ConfigurationGlobal:
		FMI3_LS_BUS_FLEXRAY_CREATE_OP_CONFIGURATION_FLEXRAY_CONFIG(&firstBufferInfo, macrotickDuration, macroticksPerCycle, maxCycleCount, actionPointOffset, staticSlotLength, numberOfStaticSlots, staticPayloadLength, minislotActionPointOffset, numberOfMinislots, minislotLength, symbolActionPointOffset, symbolWindowLength, nitLength, nmVectorLength, dynamicSlotIdleTime, coldStartNode);
		break;
	default:
		break;
	}

	// Write operation to a second buffer.
	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	// Read and check created method from second buffer.
	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);

	operation = (fmi3LsBusFlexRayOperationConfiguration*)operationHeader;

	// Specify whether the created data are checked for correctness or an overflow.
	int multiplier = (correctData) ? 1 : 0;

	EXPECT_EQ(secondBufferInfo.status, fmi3True);

	switch (operationType)
	{
	case ConfigurationGlobal:
		EXPECT_EQ(operation->flexRayConfig.macrotickDuration, macrotickDuration * multiplier);
		EXPECT_EQ(operation->flexRayConfig.macroticksPerCycle, macroticksPerCycle * multiplier);
		EXPECT_EQ(operation->flexRayConfig.cycleCountMax, maxCycleCount * multiplier);
		EXPECT_EQ(operation->flexRayConfig.actionPointOffset, actionPointOffset * multiplier);
		EXPECT_EQ(operation->flexRayConfig.staticSlotLength, staticSlotLength * multiplier);
		EXPECT_EQ(operation->flexRayConfig.numberOfStaticSlots, numberOfStaticSlots * multiplier);
		EXPECT_EQ(operation->flexRayConfig.staticPayloadLength, staticPayloadLength * multiplier);
		EXPECT_EQ(operation->flexRayConfig.minislotActionPointOffset, minislotActionPointOffset * multiplier);
		EXPECT_EQ(operation->flexRayConfig.numberOfMinislots, numberOfMinislots * multiplier);
		EXPECT_EQ(operation->flexRayConfig.minislotLength, minislotLength * multiplier);
		EXPECT_EQ(operation->flexRayConfig.symbolActionPointOffset, symbolActionPointOffset * multiplier);
		EXPECT_EQ(operation->flexRayConfig.symbolWindowLength, symbolWindowLength * multiplier);
		EXPECT_EQ(operation->flexRayConfig.nitLength, nitLength * multiplier);
		EXPECT_EQ(operation->flexRayConfig.nmVectorLength, nmVectorLength * multiplier);
		EXPECT_EQ(operation->flexRayConfig.dynamicSlotIdleTime, dynamicSlotIdleTime * multiplier);
		EXPECT_EQ(operation->flexRayConfig.coldstartNode, coldStartNode * multiplier);
		break;
	}

}

void CheckFlexRayStartCommunicationOperation(unsigned long long int startTime, bool correctData)
{
	// Create data needed for creation.
	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];

	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusFlexRayOperationStartCommunication* operation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	switch (correctData)
	{
	case true:
		FMI3_LS_BUS_FLEXRAY_CREATE_OP_START_COMMUNICATION(&firstBufferInfo, startTime);
		break;
	case false:
		FMI3_LS_BUS_FLEXRAY_CREATE_OP_START_COMMUNICATION(&firstBufferInfo, startTime + 1);
		break;
	}
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_START_COMMUNICATION(&firstBufferInfo, startTime + 1);

	// Write operation to a second buffer.
	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	// Read and check created method from second buffer.
	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);

	operation = (fmi3LsBusFlexRayOperationStartCommunication*)operationHeader;

	// Specify whether the created data are checked for correctness or an overflow.
	int multiplier = (correctData) ? 1 : 0;

	EXPECT_EQ(operation->startTime, startTime * multiplier);
}

void CheckFlexRaySymbolOperation(int cycleId, int channel, fmi3LsBusFlexRaySymbolType type, bool correctData)
{
	// Create data needed for creation.
	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];

	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusFlexRayOperationSymbol* operation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	// Create operation.
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_SYMBOL(&firstBufferInfo, cycleId, channel, type);

	// Write operation to a second buffer.
	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	// Read and check created method from second buffer.
	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);

	operation = (fmi3LsBusFlexRayOperationSymbol*)operationHeader;

	// Specify whether the created data are checked for correctness or an overflow.
	int multiplier = (correctData) ? 1 : 0;

	EXPECT_EQ(secondBufferInfo.status, fmi3True);

	EXPECT_EQ(operation->cycleId, cycleId * multiplier);
	EXPECT_EQ(operation->channel, channel * multiplier);
	EXPECT_EQ(operation->type, type);
}

void CheckDataSizeError(FlexRayOperation operation)
{
	// Create data needed for creation.
	fmi3LsBusUtilBufferInfo bufferInfo;
	fmi3UInt8 txData[1];

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };

	FMI3_LS_BUS_BUFFER_INFO_INIT(&bufferInfo, txData, sizeof(txData));

	// Create operation based on which operation is requested with data that is too big.
	switch (operation)
	{
	case Transmit:
		FMI3_LS_BUS_FLEXRAY_CREATE_OP_TRANSMIT(&bufferInfo, 0, 0, 0,
			fmi3True, fmi3True, fmi3True, fmi3True, sizeof(data), data);
		break;
	case BusError:
		FMI3_LS_BUS_FLEXRAY_CREATE_OP_BUS_ERROR(&bufferInfo, 0, 0, 0, 0);
		break;
	case ConfigurationGlobal:
		FMI3_LS_BUS_FLEXRAY_CREATE_OP_CONFIGURATION_FLEXRAY_CONFIG(&bufferInfo, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, fmi3True);
		break;
	case StartCommunication:
		FMI3_LS_BUS_FLEXRAY_CREATE_OP_START_COMMUNICATION(&bufferInfo, 0);
		break;
	case Symbol:
		FMI3_LS_BUS_FLEXRAY_CREATE_OP_SYMBOL(&bufferInfo, 0, 0, FMI3_LS_BUS_FLEXRAY_SYMBOL_COLLISION_AVOIDANCE_SYMBOL);
		break;
	case Cancel:
		FMI3_LS_BUS_FLEXRAY_CREATE_OP_CANCEL(&bufferInfo, 0, 0, 0);
		break;
	case Confirm:
		FMI3_LS_BUS_FLEXRAY_CREATE_OP_CONFIRM(&bufferInfo, 0, 0, 0);
		break;
	}

	// Check that the creation of the operation returns status 'fmi3False'.
	EXPECT_EQ(bufferInfo.status, fmi3False);
}

void CheckFormatErrorOperation(FlexRayOperation operationType)
{
	// Create data needed for creation.
	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3LsBusUtilBufferInfo thirdBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];
	fmi3UInt8 zxData[128];

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
		FMI3_LS_BUS_FLEXRAY_CREATE_OP_TRANSMIT(&thirdBufferInfo, 0, 0, 0,
			fmi3True, fmi3True, fmi3True,
			fmi3True, sizeof(data), data);
		break;
	case BusError:
		FMI3_LS_BUS_FLEXRAY_CREATE_OP_BUS_ERROR(&thirdBufferInfo, 0, 0, 0, 0);
		break;
	case ConfigurationGlobal:
		FMI3_LS_BUS_FLEXRAY_CREATE_OP_CONFIGURATION_FLEXRAY_CONFIG(&thirdBufferInfo, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, fmi3True);
		break;
	case StartCommunication:
		FMI3_LS_BUS_FLEXRAY_CREATE_OP_START_COMMUNICATION(&thirdBufferInfo, 0);
		break;
	case Symbol:
		FMI3_LS_BUS_FLEXRAY_CREATE_OP_SYMBOL(&thirdBufferInfo, 0, 0, FMI3_LS_BUS_FLEXRAY_SYMBOL_COLLISION_AVOIDANCE_SYMBOL);
		break;
	case Cancel:
		FMI3_LS_BUS_FLEXRAY_CREATE_OP_CANCEL(&thirdBufferInfo, 0, 0, 0);
		break;
	case Confirm:
		FMI3_LS_BUS_FLEXRAY_CREATE_OP_CONFIRM(&thirdBufferInfo, 0, 0, 0);
		break;
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
	for (int i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(operation->data[i], zxData[i]);
	}
}