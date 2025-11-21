#ifndef fmi3LsBusUtilFlexRay_h
#define fmi3LsBusUtilFlexRay_h

/*
This header file contains utility macros to read and write FMI-LS-BUS
FlexRay specific bus operations from/to dedicated buffer variables.

This header file can be used when creating FMI-LS-BUS network FMUs with FlexRay busses.

Copyright (C) 2023-2025 Modelica Association Project "FMI"
              All rights reserved.

This file is licensed by the copyright holders under the 2-Clause BSD License
(https://opensource.org/licenses/BSD-2-Clause):

----------------------------------------------------------------------------
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice,
 this list of conditions and the following disclaimer.

- Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
----------------------------------------------------------------------------
*/

#include "fmi3LsBusFlexRay.h"
#include "fmi3LsBusUtil.h"


/**
 * \brief Creates a FlexRay 'Transmit' operation.
 *
 * This macro can be used to create a FlexRay 'Transmit' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo                Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] CycleId                   The cycle the message is transferred in (\ref fmi3LsBusFlexRayCycleId).
 * \param[in] SlotId                    The slot the message is transferred in (\ref fmi3LsBusFlexRaySlotId).
 * \param[in] Channel                   The channel(s) on which the transmission takes place (\ref fmi3LsBusFlexRayChannel).
 * \param[in] Segment                   The data segment in which the frame is transmitted (\ref fmi3LsBusFlexRaySegmentType).
 * \param[in] StartupFrameIndicator     Indicates a startup frame (\ref fmi3LsBusBoolean).
 * \param[in] SyncFrameIndicator        Indicates a sync frame (\ref fmi3LsBusBoolean).
 * \param[in] NullFrameIndicator        Indicates a null frame (\ref fmi3LsBusBoolean).
 * \param[in] PayloadPreambleIndicator  Indicates whether the frame contains a NM vector or message ID (\ref fmi3LsBusBoolean).
 * \param[in] DataLength                Message data length (\ref fmi3LsBusFlexRayDataLength).
 * \param[in] Data                      Message data (pointer to \ref fmi3LsBusFlexRayData).
 */
#define FMI3_LS_BUS_FLEXRAY_CREATE_OP_TRANSMIT(BufferInfo,                             \
            CycleId, SlotId, Channel, StartupFrameIndicator, SyncFrameIndicator,       \
            NullFrameIndicator, PayloadPreambleIndicator, DataLength, Data)            \
    do                                                                                 \
    {                                                                                  \
        fmi3LsBusFlexRayOperationTransmit _op;                                         \
        _op.header.opCode = FMI3_LS_BUS_FLEXRAY_OP_TRANSMIT;                           \
        _op.header.length = sizeof(_op) + (DataLength);                                \
        _op.cycleId = (CycleId);                                                       \
        _op.slotId = (SlotId);                                                         \
        _op.channel = (Channel);                                                       \
        _op.startupFrameIndicator = (StartupFrameIndicator);                           \
        _op.syncFrameIndicator = (SyncFrameIndicator);                                 \
        _op.nullFrameIndicator = (NullFrameIndicator);                                 \
        _op.payloadPreambleIndicator = (PayloadPreambleIndicator);                     \
        _op.dataLength = (DataLength);                                                 \
                                                                                       \
        FMI_LS_BUS_SUBMIT_OPERATION_INTERNAL((BufferInfo), _op, (DataLength), (Data)); \
    }                                                                                  \
    while (0)


 /**
  * \brief Creates a FlexRay 'Cancel' operation.
  *
  * This macro can be used to create a FlexRay 'Cancel' operation.
  * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
  * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
  * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
  *
  * \param[in] BufferInfo                Pointer to \ref fmi3LsBusUtilBufferInfo.
  * \param[in] CycleId                   The cycle the message is transferred in (\ref fmi3LsBusFlexRayCycleId).
  * \param[in] SlotId                    The slot the message is transferred in (\ref fmi3LsBusFlexRaySlotId).
  * \param[in] Channel                   The channel(s) on which the transmission takes place (\ref fmi3LsBusFlexRayChannel).
  */
#define FMI3_LS_BUS_FLEXRAY_CREATE_OP_CANCEL(BufferInfo, CycleId, SlotId, Channel)     \
    do                                                                                 \
    {                                                                                  \
        fmi3LsBusFlexRayOperationCancel _op;                                           \
        _op.header.opCode = FMI3_LS_BUS_FLEXRAY_OP_CANCEL;                             \
        _op.header.length = sizeof(_op);                                               \
        _op.cycleId = (CycleId);                                                       \
        _op.slotId = (SlotId);                                                         \
        _op.channel = (Channel);                                                       \
                                                                                       \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op);               \
    }                                                                                  \
    while (0)


  /**
    * \brief Creates a FlexRay 'Confirm' operation.
    *
    * This macro can be used to create a FlexRay 'Confirm' operation.
    * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
    * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
    * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
    *
    * \param[in] BufferInfo                Pointer to \ref fmi3LsBusUtilBufferInfo.
    * \param[in] CycleId                   The cycle the message is transferred in (\ref fmi3LsBusFlexRayCycleId).
    * \param[in] SlotId                    The slot the message is transferred in (\ref fmi3LsBusFlexRaySlotId).
    * \param[in] Channel                   The channel(s) on which the transmission takes place (\ref fmi3LsBusFlexRayChannel).
    */
#define FMI3_LS_BUS_FLEXRAY_CREATE_OP_CONFIRM(BufferInfo, CycleId, SlotId, Channel)    \
    do                                                                                 \
    {                                                                                  \
        fmi3LsBusFlexRayOperationConfirm _op;                                          \
        _op.header.opCode = FMI3_LS_BUS_FLEXRAY_OP_CONFIRM;                            \
        _op.header.length = sizeof(_op);                                               \
        _op.cycleId = (CycleId);                                                       \
        _op.slotId = (SlotId);                                                         \
        _op.channel = (Channel);                                                       \
                                                                                       \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op);               \
    }                                                                                  \
    while (0)


/**
 * \brief Creates a FlexRay 'Bus Error' operation.
 *
 * This macro can be used to create a FlexRay 'Bus Error' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo        Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] ErrorFlags        The error flags describing the error (\ref fmi3LsBusFlexRayError).
 * \param[in] CycleId           The cycle in which the error occurred (\ref fmi3LsBusFlexRayCycleId).
 * \param[in] SegmentIndicator  Identifies the specified FlexRay segment, where the error occurred (\ref fmi3LsBusFlexRaySegmentIndicator).
 * \param[in] Channel           The channel(s) on which the error occurred (\ref fmi3LsBusFlexRayChannel).
 */
#define FMI3_LS_BUS_FLEXRAY_CREATE_OP_BUS_ERROR(BufferInfo, ErrorFlags, CycleId, SegmentIndicator, Channel) \
    do                                                                    \
    {                                                                     \
        fmi3LsBusFlexRayOperationBusError _op;                            \
        _op.header.opCode = FMI3_LS_BUS_FLEXRAY_OP_BUS_ERROR;             \
        _op.header.length = sizeof(_op);                                  \
        _op.errorFlags = (ErrorFlags);                                    \
        _op.cycleId = (CycleId);                                          \
        _op.segmentIndicator = (SegmentIndicator);                        \
        _op.channel = (Channel);                                          \
                                                                          \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op);  \
    }                                                                     \
    while (0)


/**
 * \brief Creates a FlexRay 'Configuration' operation for the parameter 'FLEXRAY_CONFIG'.
 *
 * This macro can be used to create a FlexRay 'Configuration' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo                    Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] MacrotickDuration             Duration of a macrotick in ns (\ref fmi3LsBusFlexRayMacrotickDurationNs).
 * \param[in] MacroticksPerCycle            The length of the cycle in macroticks (\ref fmi3LsBusFlexRayDurationMt16).
 * \param[in] CycleCountMax                 The maximum number of cycles (\ref fmi3LsBusFlexRayMaxCycleCount).
 * \param[in] ActionPointOffset             The action point offset of a static slot in macroticks (\ref fmi3LsBusFlexRayDurationMt8).
 * \param[in] StaticSlotLength              The length of a slot in the static segment in macroticks (\ref fmi3LsBusFlexRayDurationMt16).
 * \param[in] NumberOfStaticSlots           The number of static slots in a cycle (\ref fmi3LsBusFlexRaySlotCount).
 * \param[in] StaticPayloadLength           The length of static slot payload in bytes (\ref fmi3LsBusFlexRayDataLength).
 * \param[in] MinislotActionPointOffset     The action point offset of a dynamic slot in macroticks (\ref fmi3LsBusFlexRayDurationMt8).
 * \param[in] NumberOfMinislots             The number of minislots in a cycle (\ref fmi3LsBusFlexRaySlotCount).
 * \param[in] MinislotLength                The length of a minislot in the dynamic segment in macroticks (\ref fmi3LsBusFlexRayDurationMt8).
 * \param[in] MaximumDynamicPayloadLength   The maximum length of a dynamic slot payload in bytes (\ref fmi3LsBusFlexRayDataLength).
 * \param[in] SymbolActionPointOffset       The action point offset within the symbol window in macroticks (\ref fmi3LsBusFlexRayDurationMt8).
 * \param[in] SymbolWindowLength            The length of the symbol window in macroticks (\ref fmi3LsBusFlexRayDurationMt8).
 * \param[in] NitLength                     The length of the NIT in macroticks (\ref fmi3LsBusFlexRayDurationMt8).
 * \param[in] DynamicSlotIdleTime           The length of dynamic slot idle time within a dynamic segment in macroticks (\ref fmi3LsBusFlexRayDurationMt32).
 * \param[in] ColdstartNode                 Specifies the coldstart capabilities of a FlexRay node (\ref fmi3LsBusFlexRayColdstartNodeType).
 */
#define FMI3_LS_BUS_FLEXRAY_CREATE_OP_CONFIGURATION_FLEXRAY_CONFIG(BufferInfo, \
            MacrotickDuration, MacroticksPerCycle, CycleCountMax, ActionPointOffset, StaticSlotLength, \
            NumberOfStaticSlots, StaticPayloadLength, MinislotActionPointOffset, \
            NumberOfMinislots, MinislotLength, MaximumDynamicPayloadLength, SymbolActionPointOffset, SymbolWindowLength, \
            NitLength, NMVectorLength, DynamicSlotIdleTime, ColdstartNode) \
    do                                                                                 \
    {                                                                                  \
        fmi3LsBusFlexRayOperationConfiguration _op;                                    \
        _op.header.opCode = FMI3_LS_BUS_FLEXRAY_OP_CONFIGURATION;                      \
        _op.header.length = sizeof(fmi3LsBusOperationHeader) +                         \
            sizeof(fmi3LsBusFlexRayConfigParameterType) +                              \
            sizeof(fmi3LsBusFlexRayConfigurationFlexRayConfig);                        \
        _op.parameterType = FMI3_LS_BUS_FLEXRAY_CONFIG_PARAM_TYPE_FLEXRAY_CONFIG;      \
        _op.flexRayConfig.macrotickDuration = (MacrotickDuration);                     \
        _op.flexRayConfig.macroticksPerCycle = (MacroticksPerCycle);                   \
        _op.flexRayConfig.cycleCountMax = (CycleCountMax);                             \
        _op.flexRayConfig.actionPointOffset = (ActionPointOffset);                     \
        _op.flexRayConfig.staticSlotLength = (StaticSlotLength);                       \
        _op.flexRayConfig.numberOfStaticSlots = (NumberOfStaticSlots);                 \
        _op.flexRayConfig.staticPayloadLength = (StaticPayloadLength);                 \
        _op.flexRayConfig.minislotActionPointOffset = (MinislotActionPointOffset);     \
        _op.flexRayConfig.numberOfMinislots = (NumberOfMinislots);                     \
        _op.flexRayConfig.minislotLength = (MinislotLength);                           \
        _op.flexRayConfig.maximumDynamicPayloadLength = (MaximumDynamicPayloadLength); \
        _op.flexRayConfig.symbolActionPointOffset = (SymbolActionPointOffset);         \
        _op.flexRayConfig.symbolWindowLength = (SymbolWindowLength);                   \
        _op.flexRayConfig.nitLength = (NitLength);                                     \
        _op.flexRayConfig.nmVectorLength = (NMVectorLength);                           \
        _op.flexRayConfig.dynamicSlotIdleTime = (DynamicSlotIdleTime);                 \
        _op.flexRayConfig.coldstartNode = (ColdstartNode);                             \
                                                                                       \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op);               \
    }                                                                                  \
    while (0)


/**
 * \brief Creates a FlexRay 'Start Communication' operation.
 *
 * This macro can be used to create a FlexRay 'Start Communication' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo   Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] StartTime    Start time of the first FlexRay cycle in nanoseconds (\ref fmi3LsBusFlexRayStartTime).
 */
#define FMI3_LS_BUS_FLEXRAY_CREATE_OP_START_COMMUNICATION(BufferInfo, StartTime) \
    do                                                                    \
    {                                                                     \
        fmi3LsBusFlexRayOperationStartCommunication _op;                  \
        _op.header.opCode = FMI3_LS_BUS_FLEXRAY_OP_START_COMMUNICATION;   \
        _op.header.length = sizeof(_op);                                  \
        _op.startTime = (StartTime);                                      \
                                                                          \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op);  \
    }                                                                     \
    while (0)


/**
 * \brief Creates a FlexRay 'Symbol' operation.
 *
 * This macro can be used to create a FlexRay 'Symbol' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo   Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] CycleId      The cycle the symbol is transmitted in (\ref fmi3LsBusFlexRayCycleId).
 * \param[in] Channel      The channel(s) on which the symbol is transmitted (\ref fmi3LsBusFlexRayChannel).
 * \param[in] Type         The type of symbol (\ref fmi3LsBusFlexRaySymbolType).
 */
#define FMI3_LS_BUS_FLEXRAY_CREATE_OP_SYMBOL(BufferInfo, CycleId, Channel, Type) \
    do                                                                    \
    {                                                                     \
        fmi3LsBusFlexRayOperationSymbol _op;                              \
        _op.header.opCode = FMI3_LS_BUS_FLEXRAY_OP_SYMBOL;                \
        _op.header.length = sizeof(_op);                                  \
        _op.cycleId = (CycleId);                                          \
        _op.channel = (Channel);                                          \
        _op.type = (Type);                                                \
                                                                          \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op);  \
    }                                                                     \
    while (0)


/**
 * \brief Gets the current global time
 *
 * \param[in] simulationTime       Simulation time (in ns).
 * \param[in] startTime            Start time of the first FlexRay cycle (in ns).
 * \param[in] macroTickDuration    Macro tick duration (in ns).
 * \param[in] macroTicksPerCycle   Macro ticks per cycle.
 * \param[in] cycleCount           Cycle count.
 * \param[out] cycle               Returns the current cycle.
 * \param[out] macroTick           Returns the current macro tick.
 */
#define FMI3_LS_BUS_FLEXRAY_GET_GLOBAL_TIME(                                                                            \
    simulationTime, startTime, macroTickDuration, macroTicksPerCycle, cycleCount, cycle, macroTick)                     \
    do                                                                                                                  \
    {                                                                                                                   \
        /* Calculate the number of macro ticks since the start of the simulation */                                     \
        const fmi3UInt64 frSimulationTimeMt = (fmi3UInt64)(((simulationTime) - (startTime) + ((macroTickDuration) / 2)) \
            / (macroTickDuration));                                                                                     \
                                                                                                                        \
        /* Calculate the current cycle and macro tick */                                                                \
        *(cycle) = (fmi3UInt8)(frSimulationTimeMt / (macroTicksPerCycle) % (cycleCount));                               \
        *(macroTick) = (fmi3UInt16)(frSimulationTimeMt % (macroTicksPerCycle));                                         \
    }                                                                                                                   \
    while (0)

#endif /* fmi3LsBusUtilFlexRay_h */
