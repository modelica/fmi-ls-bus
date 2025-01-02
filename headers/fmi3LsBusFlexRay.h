#ifndef fmi3LsBusFlexRay_h
#define fmi3LsBusFlexRay_h

/*
This header file declares FlexRay bus specific constants and data types as defined by the
FMI-LS-BUS layered standard specification (https://github.com/modelica/fmi-ls-bus).

It should be used when creating FlexRay Network FMUs according to the FMI-LS-BUS layered standard.

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

#include "fmi3LsBus.h"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4200)
#pragma warning(disable : 4815)
#endif

#pragma pack(1)


/**
 * \defgroup FLEXRAY_OPERATION_CODES FlexRay bus-specific operation codes
 * \brief Operation codes for FlexRay-specific bus operations.
 * \{
 */

/**
 * \brief FMI virtual bus operation of type 'Transmit'.
 *
 * Indicates the transmission of a single FlexRay frame.
 */
#define FMI3_LS_BUS_FLEXRAY_OP_TRANSMIT ((fmi3LsBusOperationCode)0x0010)

/**
 * \brief FMI virtual bus operation of type 'FlexRay Cancel'.
 *
 * Indicates the cancellation of a single FlexRay frame transmission.
 */
#define FMI3_LS_BUS_FLEXRAY_OP_CANCEL ((fmi3LsBusOperationCode)0x0011)

/**
 * \brief FMI virtual bus operation of type 'Confirm'.
 *
 * Indicates the confirmation of a single FlexRay frame transmission.
 */
#define FMI3_LS_BUS_FLEXRAY_OP_CONFIRM ((fmi3LsBusOperationCode)0x0012)

/**
 * \brief FMI virtual bus operation of type 'Bus Error'.
 *
 * Indicates a (simulated) bus error.
 */
#define FMI3_LS_BUS_FLEXRAY_OP_BUS_ERROR ((fmi3LsBusOperationCode)0x0020)

/**
 * \brief FMI virtual bus operation of type 'Configuration'.
 *
 * Provides configuration data for the bus simulation.
 */
#define FMI3_LS_BUS_FLEXRAY_OP_CONFIGURATION ((fmi3LsBusOperationCode)0x0030)

/**
 * \brief FMI virtual bus operation of type 'Start Communication'.
 *
 * Indicates a start of the communication.
 */
#define FMI3_LS_BUS_FLEXRAY_OP_START_COMMUNICATION ((fmi3LsBusOperationCode)0x0040)

/**
 * \brief FMI virtual bus operation of type 'Symbol'.
 *
 * Indicates the transmission of a symbol in the symbol window.
 */
#define FMI3_LS_BUS_FLEXRAY_OP_SYMBOL ((fmi3LsBusOperationCode)0x0050)

/** \} */


/**
 * \defgroup FLEXRAY_DATA_TYPES FlexRay bus-specific data types
 * \brief Data types used in FlexRay-specific bus operations.
 * \{
 */

/**
 * \defgroup FLEXRAY_TYPE_CHANNEL fmi3LsBusFlexRayChannel
 * \brief Data type and macros representing FlexRay channels.
 * \{
 */

/**
 * \brief Data type representing a FlexRay channel.
 *
 * This type may be used to describe a single channel or a bitmask of channels.
 */
typedef fmi3UInt8 fmi3LsBusFlexRayChannel;

/**
 * \brief Represents the FlexRay channel A.
 */
#define FMI3_LS_BUS_FLEXRAY_CHANNEL_A \
    ((fmi3LsBusFlexRayChannel)0x1)

/**
 * \brief Represents the FlexRay channel B.
 */
#define FMI3_LS_BUS_FLEXRAY_CHANNEL_B \
    ((fmi3LsBusFlexRayChannel)0x2)

/** \} */


/**
 * \defgroup FLEXRAY_TYPE_SEGMENT_INDICATOR_TYPE fmi3LsBusFlexRaySegmentType
 * \brief  Data type and macros identifying a part of the FlexRay cycle.
 * \{
 */

/**
 * \brief Data type identifying a part of the FlexRay cycle.
 */
typedef fmi3UInt16 fmi3LsBusFlexRaySegmentIndicator;

/**
 * \brief Represents the FlexRay symbol window.
 */
#define FMI3_LS_BUS_FLEXRAY_SEGMENT_INDICATOR_SYMBOL_WINDOW \
    ((fmi3LsBusFlexRaySegmentIndicator)0xFFFE)

 /**
  * \brief Represents the FlexRay NIT segment.
  */
#define FMI3_LS_BUS_FLEXRAY_SEGMENT_INDICATOR_NIT \
    ((fmi3LsBusFlexRaySegmentIndicator)0xFFFF)

/** \} */


/**
 * \brief Data type identifying a FlexRay cycle.
 *
 * \note Only values from 0 to 63 represent valid FlexRay cycles.
 */
typedef fmi3UInt8 fmi3LsBusFlexRayCycleId;

/**
 * \brief Data type identifying a FlexRay slot in the static or dynamic segment.
 *
 * \note Only values from 1 to 2047 represent valid slots in the static segment
 *       and values from 0 to 7986 represent valid (mini)slots in the dynamic segment.
 */
typedef fmi3UInt16 fmi3LsBusFlexRaySlotId;

/**
 * \brief Data type representing the FlexRay frame payload length.
 */
typedef fmi3UInt8 fmi3LsBusFlexRayDataLength;

/**
 * \brief Data type representing the FlexRay frame payload data.
 */
typedef fmi3UInt8 fmi3LsBusFlexRayData;


/**
 * \defgroup FLEXRAY_TYPE_FLEXRAY_ERROR fmi3LsBusFlexRayError
 * \brief Data type and macros representing a FlexRay error.
 * \{
 */

/**
 * \brief Data type representing a FlexRay error.
 *
 * \note This is a bitmask of FlexRay error flags described below.
 */
typedef fmi3UInt8 fmi3LsBusFlexRayError;

/**
 * \brief Indicates a valid Transmit operation and can be used to point out a valid FlexRay transmission in combination with another error.
 */
#define FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_VALID_FRAME \
    ((fmi3LsBusFlexRayError)0x01)

/**
 * \brief Indicates a syntactic error in a time slot of a 'Transmit' operation.
 */
#define FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_SYNTAX_ERROR \
    ((fmi3LsBusFlexRayError)0x02)

/**
 * \brief Indicates a content error of a receiving 'Transmit' operation on the receiver side.
 */
#define FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR \
    ((fmi3LsBusFlexRayError)0x04)

/**
 * \brief Indicates that a boundary violation occurred at boundary of the corresponding slot.
 */
#define FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_BOUNDARY_VIOLATION \
    ((fmi3LsBusFlexRayError)0x08)

/**
 * \brief Indicates that a reception from another Network FMU is already ongoing while the specified
 *      Network FMU starts a transmission using a 'Transmit' operation.
 */
#define FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_TX_CONFLICT \
    ((fmi3LsBusFlexRayError)0x16)

/** \} */


/**
 * \defgroup FLEXRAY_TYPE_CONFIG_PARAMETER_TYPE fmi3LsBusFlexRayConfigParameterType
 * \brief Data type and macros representing the parameter configured with a configuration operation.
 * \{
 */

/**
 * \brief Data type representing the parameter configured with a configuration operation.
 */
typedef fmi3UInt8 fmi3LsBusFlexRayConfigParameterType;

/**
 * \brief Indicates the FlexRay bus-specific parameters configured for this node.
 */
#define FMI3_LS_BUS_FLEXRAY_CONFIG_PARAM_TYPE_FLEXRAY_CONFIG \
    ((fmi3LsBusFlexRayConfigParameterType)0x01)

/** \} */

/**
 * \defgroup FLEXRAY_TYPE_COLDSTART_NODE_TYPE fmi3LsBusFlexRayColdstartNodeType
 * \brief Data type and macros specifying coldstart capabilities of a specified FlexRay node.
 * \{
 */

/**
 * \brief Data type representing the type of coldstart capabilities.
 */
typedef fmi3UInt8 fmi3LsBusFlexRayColdstartNodeType;

/**
 * \brief Describes that the current node has no coldstart capabilities.
 */
#define FMI3_LS_BUS_FLEXRAY_CONFIG_PARAM_COLDSTART_NODE_TYPE_NONE \
    ((fmi3LsBusFlexRayColdstartNodeType)0x1)

/**
 * \brief Indicates a TT-D coldstart node.
 */
#define FMI3_LS_BUS_FLEXRAY_CONFIG_PARAM_COLDSTART_NODE_TYPE_TT_D_COLDSTART_NODE \
    ((fmi3LsBusFlexRayColdstartNodeType)0x2)

/**
 * \brief Indicates a TT-E coldstart node.
 */
#define FMI3_LS_BUS_FLEXRAY_CONFIG_PARAM_COLDSTART_NODE_TYPE_TT_E_COLDSTART_NODE \
    ((fmi3LsBusFlexRayColdstartNodeType)0x3)

/**
 * \brief Indicates a TT-L coldstart node.
 */
#define FMI3_LS_BUS_FLEXRAY_CONFIG_PARAM_COLDSTART_NODE_TYPE_TT_L_COLDSTART_NODE \
    ((fmi3LsBusFlexRayColdstartNodeType)0x4)

/** \} */

/**
 * \brief Data type representing a macrotick duration in nanoseconds.
 */
typedef fmi3UInt32 fmi3LsBusFlexRayMacrotickDurationNs;

/**
 * \brief Data type representing a duration in macroticks.
 */
typedef fmi3UInt16 fmi3LsBusFlexRayDurationMt16;

/**
 * \brief Data type representing a duration in macroticks.
 */
typedef fmi3UInt8 fmi3LsBusFlexRayDurationMt8;

/**
 * \brief Data type representing a duration in macroticks.
 */
typedef fmi3UInt32 fmi3LsBusFlexRayDurationMt32;

/**
 * \brief Data type representing the number of slots in a cycle.
 */
typedef fmi3UInt16 fmi3LsBusFlexRaySlotCount;

/**
 * \brief Data type representing the maximum number of cycles.
 */
typedef fmi3UInt8 fmi3LsBusFlexRayMaxCycleCount;

/**
 * \brief Data type representing the length of the Network Management Vector.
 */
typedef fmi3UInt8 NetworkManagementVectorLength;

/**
 * \brief Data type representing the start time of the first FlexRay cycle in nanoseconds.
 */
typedef fmi3UInt64 fmi3LsBusFlexRayStartTime;


/**
 * \defgroup FLEXRAY_TYPE_SYMBOL_TYPE fmi3LsBusFlexRaySymbolType
 * \brief Data type and macros representing the type of symbol transmitted in the symbol window.
 * \{
 */

/**
 * \brief Data type representing the type of symbol transmitted in the symbol window.
 */
typedef fmi3UInt8 fmi3LsBusFlexRaySymbolType;

/**
 * \brief The collision avoidance symbol is used to indicate the start of the first communication cycle.
 */
#define FMI3_LS_BUS_FLEXRAY_SYMBOL_COLLISION_AVOIDANCE_SYMBOL \
    ((fmi3LsBusFlexRaySymbolType)0x1)

/**
 * \brief The media test symbol is used for testing of a bus guardian.
 */
#define FMI3_LS_BUS_FLEXRAY_SYMBOL_MEDIA_TEST_SYMBOL \
    ((fmi3LsBusFlexRaySymbolType)0x2)

/**
 * \brief The wake up symbol is used for waking up other FlexRay nodes of the specified network.
 */
#define FMI3_LS_BUS_FLEXRAY_SYMBOL_WAKEUP_SYMBOL \
    ((fmi3LsBusFlexRaySymbolType)0x3)

/** \} */

/** \} */


/**
 * \defgroup FLEXRAY_OPERATION_TYPES FlexRay bus-specific operation types
 * \brief Operation types for FlexRay-specific bus operations.
 * \{
 */

/**
 * \brief FMI virtual bus operation structure of type 'Transmit'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;                    /**< Operation header. */
    fmi3LsBusFlexRayCycleId cycleId;                    /**< The cycle the message is transferred in. */
    fmi3LsBusFlexRaySlotId slotId;                      /**< The slot the message is transferred in. */
    fmi3LsBusFlexRayChannel channel;                    /**< The channel(s) on which the transmission takes place. */
    fmi3LsBusBoolean startupFrameIndicator;             /**< Indicates a startup frame. */
    fmi3LsBusBoolean syncFrameIndicator;                /**< Indicates a sync frame. */
    fmi3LsBusBoolean nullFrameIndicator;                /**< Indicates a null frame. */
    fmi3LsBusBoolean payloadPreambleIndicator;          /**< Indicates whether the frame contains a NM vector or message ID. */
    fmi3LsBusFlexRayDataLength dataLength;              /**< Data length. */
    fmi3LsBusFlexRayData data[];                        /**< Data. */
} fmi3LsBusFlexRayOperationTransmit;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusFlexRayOperationTransmit) == (8 + 1 + 2 + 1 + 1 + 1 + 1 + 1 + 1),
              "'fmi3LsBusFlexRayOperationTransmit' does not match the expected data size");
#endif


/**
 * \brief FMI virtual bus operation structure of type 'Cancel'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;                    /**< Operation header. */
    fmi3LsBusFlexRayCycleId cycleId;                    /**< The cycle the message is transferred in. */
    fmi3LsBusFlexRaySlotId slotId;                      /**< The slot the message is transferred in. */
    fmi3LsBusFlexRayChannel channel;                    /**< The channel(s) on which the transmission takes place. */
} fmi3LsBusFlexRayOperationCancel;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusFlexRayOperationCancel) == (8 + 1 + 2 + 1),
    "'fmi3LsBusFlexRayOperationCancel' does not match the expected data size");
#endif


/**
 * \brief FMI virtual bus operation structure of type 'Confirm'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;                    /**< Operation header. */
    fmi3LsBusFlexRayCycleId cycleId;                    /**< The cycle the message is transferred in. */
    fmi3LsBusFlexRaySlotId slotId;                      /**< The slot the message is transferred in. */
    fmi3LsBusFlexRayChannel channel;                    /**< The channel(s) on which the transmission takes place. */
} fmi3LsBusFlexRayOperationConfirm;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusFlexRayOperationConfirm) == (8 + 1 + 2 + 1),
    "'fmi3LsBusFlexRayOperationConfirm' does not match the expected data size");
#endif


/**
 * \brief FMI virtual bus operation structure of type 'Bus Error'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;                        /**< Operation header. */
    fmi3LsBusFlexRayError errorFlags;                       /**< The error flags describing the error. */
    fmi3LsBusFlexRayCycleId cycleId;                        /**< The cycle in which the error occurred. */
    fmi3LsBusFlexRaySegmentIndicator segmentIndicator;      /**< The segment in which the error occurred. */
    fmi3LsBusFlexRayChannel channel;                        /**< The channel(s) on which the error occurred. */
} fmi3LsBusFlexRayOperationBusError;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusFlexRayOperationBusError) == (sizeof(fmi3LsBusOperationHeader) + (1 + 1 + 2 + 1)),
              "'fmi3LsBusFlexRayOperationBusError' does not match the expected data size");
#endif


/**
 * \brief Configuration data sent with 'Configuration' operation of type 'FLEXRAY_CONFIG'.
 */
typedef struct
{
    fmi3LsBusFlexRayMacrotickDurationNs macrotickDuration;  /**< Duration of a macrotick in ns. */
    fmi3LsBusFlexRayDurationMt16 macroticksPerCycle;        /**< The length of the cycle in macroticks. */
    fmi3LsBusFlexRayMaxCycleCount cycleCountMax;            /**< The maximum number of cycles. */
    fmi3LsBusFlexRayDurationMt8 actionPointOffset;          /**< The action point offset of a static slot in macroticks. */
    fmi3LsBusFlexRayDurationMt16 staticSlotLength;          /**< The length of a slot in the static segment in macroticks. */
    fmi3LsBusFlexRaySlotCount numberOfStaticSlots;          /**< The number of static slots in a cycle. */
    fmi3LsBusFlexRayDataLength staticPayloadLength;         /**< The length of static slot payload in bytes. */
    fmi3LsBusFlexRayDurationMt8 minislotActionPointOffset;  /**< The action point offset of a dynamic slot in macroticks. */
    fmi3LsBusFlexRaySlotCount numberOfMinislots;            /**< The number of minislots in a cycle. */
    fmi3LsBusFlexRayDurationMt8 minislotLength;             /**< The length of a minislot in the dynamic segment in macroticks. */
    fmi3LsBusFlexRayDurationMt8 symbolActionPointOffset;    /**< The action point offset of a symbol window in macroticks. */
    fmi3LsBusFlexRayDurationMt8 symbolWindowLength;         /**< The length of the symbol window in macroticks. */
    fmi3LsBusFlexRayDurationMt8 nitLength;                  /**< The length of the NIT in macroticks. */
    NetworkManagementVectorLength nmVectorLength;           /**< The length of the Network Management Vector. */
    fmi3LsBusFlexRayDurationMt32 dynamicSlotIdleTime;       /**< The length of dynamic slot idle time within a dynamic segment in macroticks. */  
    fmi3LsBusFlexRayColdstartNodeType coldstartNode;        /**< Specifies the coldstart capabilities of a FlexRay node. */
} fmi3LsBusFlexRayConfigurationFlexRayConfig;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusFlexRayConfigurationFlexRayConfig) == (4 + 2 + 1 + 1 + 1 + 2 + 2 + 1 + 1 + 2 + 1 + 1 + 1 + 1 + 4 + 1),
              "'fmi3LsBusFlexRayConfigurationFlexRayConfig' does not match the expected data size");
#endif

/**
 * \brief FMI virtual bus operation structure of type 'Configuration'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;                              /**< Operation header. */
    fmi3LsBusFlexRayConfigParameterType parameterType;            /**< Defines the configuration parameter sent with this operation. */
    union
    {
        fmi3LsBusFlexRayConfigurationFlexRayConfig flexRayConfig; /**< Configuration data for parameter 'FLEXRAY_CONFIG'. */
    };
} fmi3LsBusFlexRayOperationConfiguration;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusFlexRayOperationConfiguration) == (8 + 1 + sizeof(fmi3LsBusFlexRayConfigurationFlexRayConfig)),
              "'fmi3LsBusFlexRayOperationConfiguration' does not match the expected data size");
#endif


/**
 * \brief FMI virtual bus operation structure of type 'Start Communication'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;          /**< Operation header. */
    fmi3LsBusFlexRayStartTime startTime;      /**< Start time of the first FlexRay cycle in nanoseconds. */
} fmi3LsBusFlexRayOperationStartCommunication;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusFlexRayOperationStartCommunication) == (8 + 8),
              "'fmi3LsBusFlexRayOperationStartCommunication' does not match the expected data size");
#endif


/**
 * \brief FMI virtual bus operation structure of type 'Symbol'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;      /**< Operation header. */
    fmi3LsBusFlexRayCycleId cycleId;      /**< The cycle the symbol is transmitted in. */
    fmi3LsBusFlexRayChannel channel;      /**< The channel(s) on which the symbol is transmitted. */
    fmi3LsBusFlexRaySymbolType type;      /**< The type of symbol. */
} fmi3LsBusFlexRayOperationSymbol;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusFlexRayOperationSymbol) == (8 + 1 + 1 + 1),
              "'fmi3LsBusFlexRayOperationSymbol' does not match the expected data size");
#endif

/** \} */


#pragma pack()

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif /* fmi3LsBusFlexRay_h */
