#include "fmi3LsBusFlexRay.h"
#include "fmi3LsBusUtil.h"
#include "fmi3LsBusUtilFlexRay.h"
#include <iostream>

/**
 * \brief Values that cause an overflow for the tested datatype.
 */
#define FLEXRAY_WRONG_U_INT8 256
#define FLEXRAY_WRONG_U_INT16 65536
#define FLEXRAY_WRONG_U_INT32 0x100000000
#define FLEXRAY_WRONG_U_INT64 0x10000000000000000

 /**
  * \brief Enum of the available operations by name.
  */
enum FlexRayOperation { Transmit, BusError, ConfigurationConfig, StartCommunication, Symbol, Confirm, Cancel };

/**
 * \brief Checks if the FlexRay Transmit operation is created correctly by the corresponding macro.
*/
void CheckFlexRayTransmitOperation(int cycleId, int slotId, int channel, fmi3UInt8 startUpFrameIndicator,
	fmi3UInt8 syncFrameIndicator, fmi3UInt8 nullFrameIndicator,
	fmi3UInt8 payloadPreambleIndicator, size_t dataSize, fmi3UInt8 data[], bool correctData);

/**
 * \brief Checks if the FlexRay Bus Error operation is created correctly by the corresponding macro.
 */
void CheckFlexRayBusErrorOperation(int errorFlags, int cycleId, int segmentIndicator, int channel, bool correctData);

/**
 * \brief Checks if the FlexRay Configuration operation is created correctly by the corresponding macro.
 */
void CheckFlexRayConfigurationOperation(FlexRayOperation operationType, long long int macrotickDuration,
	int macroticksPerCycle, int maxCycleCount, int actionPointOffset, int staticSlotLength,
	int numberOfStaticSlots, int staticPayloadLength, int minislotActionPointOffset,
	int numberOfMinislots, int minislotLength, int symbolActionPointOffset, int symbolWindowLength,
	int nitLength, int nmVectorLength, long long int dynamicSlotIdleTime, fmi3LsBusFlexRayColdstartNodeType coldStartNode, bool correctData);

/**
 * \brief Checks if the FlexRay Confirm operation is created correctly by the corresponding macro.
 */
void CheckFlexRayConfirmOperation(int cycleId, int slotId, int channel, bool correctData);

/**
 * \brief Checks if the FlexRay Cancel operation is created correctly by the corresponding macro.
 */
void CheckFlexRayCancelOperation(int cycleId, int slotId, int channel, bool correctData);

/**
 * \brief Checks if the FlexRay Start Communication operation is created correctly by the corresponding macro.
 */
void CheckFlexRayStartCommunicationOperation(unsigned long long int startTime, bool correctData);

/**
 * \brief Checks if the FlexRay Symbol operation is created correctly by the corresponding macro.
 */
void CheckFlexRaySymbolOperation(int cycleId, int channel, fmi3LsBusFlexRaySymbolType type, bool correctData);

/**
 * \brief Checks if the corresponding macro returns fmi3False if the data for creation is too big.
 *
 * \param[in] operation  The type of operation to be checked.
 */
void CheckDataSizeError(FlexRayOperation operation);

/**
 * \brief Checks if the Format Error operation is created correctly by the corresponding macro.
 *
 * \param[in] operationType  The type of operation of the Format Error operation.
 */
void CheckFormatErrorOperation(FlexRayOperation operationType);
