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
enum FlexRayOperation { FlexRayTransmit, BusError, ConfigurationGlobal, StartCommunication, Symbol };

/**
 * \brief Checks if the FlexRay Transmit operation is created correctly by the corresponding macro.
 *
 * \param[in] cycleId                   The cycleId of the FlexRay Transmit operation.
 * \param[in] slotId                    The slotId of the FlexRay Transmit operation.
 * \param[in] channel                   The channel of the FlexRay Transmit operation.
 * \param[in] segment                   The segment of the FlexRay Transmit operation.
 * \param[in] startUpFrameIndicator     The startUpFrameIndicator of the FlexRay Transmit operation.
 * \param[in] syncFrameIndicator        The syncUpFrameIndicator of the FlexRay Transmit operation.
 * \param[in] nullFrameIndicator        The nullUpFrameIndicator of the FlexRay Transmit operation.
 * \param[in] payloadPreambleIndicator  The payloadPreambleIndicator of the FlexRay Transmit operation.
 * \param[in] dataSize                  The size of the data for the FlexRay Transmit operation.
 * \param[in] data                      The data for the FlexRay Transmit operation.
 * \param[in] correctData               Indicator if the method checks for a match of provided and created values or for an overflow of values.
 */
void CheckFlexRayTransmitOperation(int cycleId, int slotId, int channel, int segment, fmi3UInt8 startUpFrameIndicator,
                                   fmi3UInt8 syncFrameIndicator, fmi3UInt8 nullFrameIndicator,
                                   fmi3UInt8 payloadPreambleIndicator, fmi3UInt64 minislotDuration, size_t dataSize, fmi3UInt8 data[],
                                   bool correctData);

/**
 * \brief Checks if the FlexRay Bus Error operation is created correctly by the corresponding macro.
 *
 * \param[in] ErrorFlags        The error flags describing the error (\ref fmi3LsBusFlexRayError).
 * \param[in] CycleId           The cycle in which the error occurred (\ref fmi3LsBusFlexRayCycleId).
 * \param[in] SegmentInicator   Identifies the specified FlexRay segment, where the error occured (\ref fmi3LsBusFlexRaySegmentInicatorType).
 * \param[in] Channel           The channel(s) on which the error occurred (\ref fmi3LsBusFlexRayChannel).
 * \param[in] correctData       Indicator if the method checks for a match of provided and created values or for an overflow of values.
 */
void CheckFlexRayBusErrorOperation(int errorFlags, int cycleId, int segmentIndicator, int channel, bool correctData);

/**
 * \brief Checks if the FlexRay Configuration operation is created correctly by the corresponding macro.
 *
 * \param[in] operationType             Indicates whether it is a Configuration Global or Configuration Startup operation.
 * \param[in] macrotickDuration         The macrotickDuration of the FlexRay Configuration Global operation.
 * \param[in] macroticksPerCycle        The macroticksPerCycle of the FlexRay Configuration Global operation.
 * \param[in] actionPointOffset         The actionPointOffset of the FlexRay Configuration Global operation.
 * \param[in] staticSlotLength          The staticSlotLength of the FlexRay Configuration Global operation.
 * \param[in] numberOfStaticSlots       The numberOfStaticSlots of the FlexRay Configuration Global operation.
 * \param[in] staticPayloadLength       The staticPayloadLength of the FlexRay Configuration Global operation.
 * \param[in] minislotActionPointOffset The minislotActionPointOffset of the FlexRay Configuration Global operation.
 * \param[in] numberOfMinislots         The numberOfMinislots of the FlexRay Configuration Global operation.
 * \param[in] minislotLength            The minislotLength of the FlexRay Configuration Global operation.
 * \param[in] symbolWindowLength        The symbolWindowLength of the FlexRay Configuration Global operation.
 * \param[in] coldStartNode             The coldStartNode of the FlexRay Configuration Startup operation.
 * \param[in] correctData               Indicator if the method checks for a match of provided and created values or for an overflow of values.
 */
void CheckFlexRayConfigurationOperation(FlexRayOperation operationType, long long int macrotickDuration,
                                        int macroticksPerCycle, int maxCycleCount, int actionPointOffset, int staticSlotLength,
                                        int numberOfStaticSlots, int staticPayloadLength, int minislotActionPointOffset,
                                        int numberOfMinislots, int minislotLength, int symbolActionPointOffset, int symbolWindowLength,
                                        int nitLength, long long int dynamicSlotIdleTime,   fmi3Boolean coldStartNode, bool correctData);

/**
 * \brief Checks if the FlexRay Start Communication operation is created correctly by the corresponding macro.
 *
 * \param[in] StartTime    Start time of the first FlexRay cycle in nanoseconds.
 * \param[in] correctData Indicator if the method checks for a match of provided and created values or for an overflow of values.
 */
void CheckFlexRayStartCommunicationOperation(unsigned long long int startTime, bool correctData);

/**
 * \brief Checks if the FlexRay Symbol operation is created correctly by the corresponding macro.
 *
 * \param[in] cycleId     The status of the FlexRay Status operation.
 * \param[in] channel     The cycleOffset of the FlexRay Status operation.
 * \param[in] type        The type of the FlexRay Status operation.
 * \param[in] correctData Indicator if the method checks for a match of provided and created values or for an overflow of values.
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
