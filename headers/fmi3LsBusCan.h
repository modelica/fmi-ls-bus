#ifndef fmi3LsBusCan_h
#define fmi3LsBusCan_h

/*
This header file declares CAN bus specific constants and data types as defined by the
fmi-ls-bus layered standard specification (https://github.com/modelica/fmi-ls-bus).

It should be used when creating CAN Network FMUs according to the fmi-ls-bus layered standard.

Copyright (C) 2024 Modelica Association Project "FMI"
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

#ifdef __cplusplus
extern "C"
{
#endif


/**
 * CAN bus-specific operation codes.
 */

/**
 * \brief FMI virtual bus operation of type 'CAN Transmit'.
 *
 * Indicates the transmission of a single CAN frame.
 */
#define FMI3_LS_BUS_CAN_OP_CAN_TRANSMIT ((fmi3LsBusOperationCode)0x0010)

/**
 * \brief FMI virtual bus operation of type 'CAN FD Transmit'.
 *
 * Indicates the transmission of a single CAN FD frame.
 */
#define FMI3_LS_BUS_CAN_OP_CANFD_TRANSMIT ((fmi3LsBusOperationCode)0x0011)

 /**
  * \brief FMI virtual bus operation of type 'CAN XL Transmit'.
  *
  * Indicates the transmission of a single CAN XL frame.
  */
#define FMI3_LS_BUS_CAN_OP_CANXL_TRANSMIT ((fmi3LsBusOperationCode)0x0012)

/**
 * \brief FMI virtual bus operation of type 'Confirm'.
 *
 * Indicates that a CAN frame was successfully transmitted on the virtual bus.
 */
#define FMI3_LS_BUS_CAN_OP_CONFIRM ((fmi3LsBusOperationCode)0x0020)

/**
 * \brief FMI virtual bus operation of type 'Arbitration Lost'.
 *
 * Indicates that a CAN frame could not be sent immediately and was therefore
 * discarded by the Bus Simulation.
 */
#define FMI3_LS_BUS_CAN_OP_ARBITRATION_LOST ((fmi3LsBusOperationCode)0x0030)

/**
 * \brief FMI virtual bus operation of type 'Bus Error'.
 *
 * Indicates that an error occurred on the virtual bus.
 */
#define FMI3_LS_BUS_CAN_OP_BUS_ERROR ((fmi3LsBusOperationCode)0x0031)

/**
 * \brief FMI virtual bus operation of type 'Configuration'.
 *
 * Performs configuration of the bus simulation.
 * The configuration of a CAN, CAN FD and CAN XL baud rate
 * as well as further options, such as like arbitration behavior, is supported by this operation.
 */
#define FMI3_LS_BUS_CAN_OP_CONFIGURATION ((fmi3LsBusOperationCode)0x0040)

/**
 * \brief FMI virtual bus operation of type 'Status'.
 *
 * Indicates a change in status of a Network FMU.
 */
#define FMI3_LS_BUS_CAN_OP_STATUS ((fmi3LsBusOperationCode)0x0041)

/**
 * \brief FMI virtual bus operation of type 'Wakeup'.
 *
 * Triggers a bus-specific wake up.
 */
#define FMI3_LS_BUS_CAN_OP_WAKEUP ((fmi3LsBusOperationCode)0x0042)


/**
 * CAN bus-specific operation types.
 */

#pragma pack(1)

/**
 * \brief Data type representing a CAN identifier.
 */
typedef fmi3UInt32 fmi3LsBusCanId;

/**
 * \brief Data type indicating whether a frame is a standard or extended message.
 */
typedef fmi3UInt8 fmi3LsBusCanIde;

/**
 * \brief Data type indicating whether a frame is a Remote Transmission Request.
 */
typedef fmi3UInt8 fmi3LsBusCanRtr;

/**
 * \brief Data type representing the CAN frame payload length.
 */
typedef fmi3UInt16 fmi3LsBusCanDataLength;

/**
 * \brief Data type representing the CAN frame payload data.
 */
typedef fmi3UInt8 fmi3LsBusCanData;

/**
 * \brief FMI virtual bus operation structure of type 'CAN Transmit'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;   /**< Operation header. */
    fmi3LsBusCanId  id;                /**< CAN message ID. */
    fmi3LsBusCanIde ide;               /**< Standard (11-bit) or Extended (29-bit) message identifier. */
    fmi3LsBusCanRtr rtr;               /**< Remote Transmission Request frame. */
    fmi3LsBusCanDataLength dataLength; /**< Data length. */
    fmi3LsBusCanData data[];           /**< Data. */
} fmi3LsBusCanOperationCanTransmit;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusCanOperationCanTransmit) == (8 + 4 + 1 + 1 + 2),
              "'fmi3LsBusCanOperationCanTransmit' does not match the expected data size");
#endif

/**
 * \brief Data type indicating whether a Bit Rate Switch occurs during transmission.
 */
typedef fmi3UInt8 fmi3LsBusCanBrs;

/**
 * \brief Data type representing the Error State Indicator.
 */
typedef fmi3UInt8 fmi3LsBusCanEsi;

/**
 * \brief FMI virtual bus operation structure of type 'CAN FD Transmit'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;   /**< Operation header. */
    fmi3LsBusCanId id;                 /**< CAN message ID. */
    fmi3LsBusCanIde ide;               /**< Standard (11-bit) or Extended (29-bit) message identifier. */
    fmi3LsBusCanBrs brs;               /**< Bit Rate Switch. */
    fmi3LsBusCanEsi esi;               /**< Error State Indicator. */
    fmi3LsBusCanDataLength dataLength; /**< Data length. */
    fmi3LsBusCanData data[];           /**< Data. */
} fmi3LsBusCanOperationCanFdTransmit;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusCanOperationCanFdTransmit) == (8 + 4 + 1 + 1 + 1 + 2),
              "'fmi3LsBusCanOperationCanFdTransmit' does not match the expected data size");
#endif

/**
 * \brief Data type representing the Simple Extended Content.
 */
typedef fmi3UInt8 fmi3LsBusCanSec;

/**
 * \brief Data type representing the Service Data Unit Type.
 */
typedef fmi3UInt8 fmi3LsBusCanSdt;

/**
 * \brief Data type representing the Virtual CAN Network ID.
 */
typedef fmi3UInt8 fmi3LsBusCanVcId;

/**
 * \brief Data type representing the Acceptance Field.
 */
typedef fmi3UInt32 fmi3LsBusCanAf;

/**
 * \brief FMI virtual bus operation structure of type 'CAN XL Transmit'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;   /**< Operation header. */
    fmi3LsBusCanId id;                 /**< CAN message ID. */
    fmi3LsBusCanIde ide;               /**< Standard (11-bit) or Extended (29-bit) message identifier. */
    fmi3LsBusCanSec sec;               /**< Simple Extended Content. */
    fmi3LsBusCanSdt sdt;               /**< Service Data Unit Type. */
    fmi3LsBusCanVcId vcid;             /**< Virtual CAN Network ID. */
    fmi3LsBusCanAf af;                 /**< Acceptance Field. */
    fmi3LsBusCanDataLength dataLength; /**< Data length. */
    fmi3LsBusCanData data[];           /**< Data.*/
} fmi3LsBusCanOperationCanXlTransmit;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusCanOperationCanXlTransmit) == (8 + 4 + 1 + 1 + 1 + 1 + 4 + 2),
              "'fmi3LsBusCanOperationCanXlTransmit' does not match the expected data size");
#endif

/**
 * \brief FMI virtual bus operation structure of type 'Confirm'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header; /**< Operation header */
    fmi3LsBusCanId id;               /**< CAN message ID. */
} fmi3LsBusCanOperationConfirm;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusCanOperationConfirm) == (8 + 4),
              "'fmi3LsBusCanOperationConfirm' does not match the expected data size");
#endif

/**
 * \brief FMI virtual bus operation structure of type 'Arbitration Lost'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header; /**< Operation header */
    fmi3LsBusCanId id;               /**< CAN message ID. */
} fmi3LsBusCanOperationArbitrationLost;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusCanOperationArbitrationLost) == (8 + 4),
              "'fmi3LsBusCanOperationArbitrationLost' does not match the expected data size");
#endif

/**
 * \brief Data type representing a CAN bus error code.
 */
typedef fmi3UInt8 fmi3LsBusCanErrorCode;

/**
 * \brief Represents a CAN bus error of type 'BIT_ERROR'.
 *
 *  Within the CAN standard, the sender also receives transmitted data for comparison.
 *  If the sent and received bits are not identical, this failure results in a Bit Error.
 */
#define FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR \
    ((fmi3LsBusCanErrorCode)0x1)

/**
 * \brief Represents a CAN bus error of type 'BIT_STUFFING_ERROR'.
 *
 *  A bit stuffing error occurs if 6 consecutive bits of equal value are detected on the bus.
 */
#define FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_STUFFING_ERROR \
    ((fmi3LsBusCanErrorCode)0x2)

/**
 * \brief Represents a CAN bus error of type 'FORM_ERROR'.
 *
 * Occurs during a violation of End-of-Frame (EOF) format.
 */
#define FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_FORM_ERROR \
    ((fmi3LsBusCanErrorCode)0x3)

/**
 * \brief Represents a CAN bus error of type 'CRC_ERROR'.
 *
 * Occurs when the data of a frame and the related checksum do not harmonize.
 */
#define FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_CRC_ERROR \
    ((fmi3LsBusCanErrorCode)0x4)

/**
 * \brief Represents a CAN bus error of type 'ACK_ERROR'.
 *
 * At least one receiving node identifies an invalid CAN frame.
 */
#define FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_ACK_ERROR \
    ((fmi3LsBusCanErrorCode)0x5)

/**
 * \brief Represents a CAN bus error of type 'BROKEN_ERROR_FRAME'.
 *
 * Represents an invalid transmission of a CAN error frame.
 * Within CAN, an error frame is transmitted by any unit on detection of a bus error.
 */
#define FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BROKEN_ERROR_FRAME \
    ((fmi3LsBusCanErrorCode)0x6)

/**
 * \brief Data type representing a CAN bus error flag indicating which node detected the error first.
 */
typedef fmi3UInt8 fmi3LsBusCanErrorFlag;

/**
 * \brief Indicates that a specified Network FMU is detecting the given Bus Error first.
 */
#define FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG ((fmi3LsBusCanErrorFlag)0x1)

/**
 * \brief Indicates that a specified Network FMU is reacting on a Bus Error and does not detect it.
 */
#define FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG ((fmi3LsBusCanErrorFlag)0x2)

/**
 * \brief Data type indicating whether a bus error occurred in response to a transmit operation of this Network FMU.
 */
typedef fmi3UInt8 fmi3LsBusCanIsSender;

/**
 * \brief FMI virtual bus operation structure of type 'Bus Error'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header; /**< Operation header. */
    fmi3LsBusCanId id;               /**< CAN message ID. */
    fmi3LsBusCanErrorCode errorCode; /**< Bus error code. */
    fmi3LsBusCanErrorFlag errorFlag; /**< Bus error flag. */
    fmi3LsBusCanIsSender isSender;   /**< Whether the error occurred in response to a transmission of this FMU. */
} fmi3LsBusCanOperationBusError;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusCanOperationBusError) == (8 + 4 + 1 + 1 + 1),
              "'fmi3LsBusCanOperationBusError' does not match the expected data size");
#endif

/**
 * \brief Data type indicating the status of a CAN node.
 */
typedef fmi3UInt8 fmi3LsBusCanStatusKind;

/**
 * \brief Indicates that the CAN node is in state 'ERROR_ACTIVE'.
 */
#define FMI3_LS_BUS_CAN_STATUS_PARAM_STATUS_KIND_ERROR_ACTIVE ((fmi3LsBusCanStatusKind)0x1)

/**
 * \brief Indicates that the CAN node is in state 'ERROR_PASSIVE'.
 */
#define FMI3_LS_BUS_CAN_STATUS_PARAM_STATUS_KIND_ERROR_PASSIVE ((fmi3LsBusCanStatusKind)0x2)

/**
 * \brief Indicates that the CAN node is in state 'BUS_OFF'.
 */
#define FMI3_LS_BUS_CAN_STATUS_PARAM_STATUS_KIND_BUS_OFF ((fmi3LsBusCanStatusKind)0x3)

/**
 * \brief FMI virtual bus operation structure of type 'Status'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header; /**< Operation header. */
    fmi3LsBusCanStatusKind status;   /**< Status of the FMU. */
} fmi3LsBusCanOperationStatus;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusCanOperationStatus) == (8 + 1),
              "'fmi3LsBusCanOperationStatus' does not match the expected data size");
#endif

/**
 * \brief Data type representing a CAN baud rate in bit/s.
 */
typedef fmi3UInt32 fmi3LsBusCanBaudrate;

/**
 * \brief Data type representing the parameter configured with a configuration operation.
 */
typedef fmi3UInt8 fmi3LsBusCanConfigParameterType;

/**
 * \brief Indicates the configuration of the CAN baud rate.
 * \note The baud rate is configured using the field 'baudrate'.
 */
#define FMI3_LS_BUS_CAN_CONFIG_PARAM_TYPE_CAN_BAUDRATE ((fmi3LsBusCanConfigParameterType)0x1)

/**
 * \brief Indicates the configuration of the CAN FD baud rate.
 * \note The baud rate is configured using the field 'baudrate'.
 */
#define FMI3_LS_BUS_CAN_CONFIG_PARAM_TYPE_CANFD_BAUDRATE ((fmi3LsBusCanConfigParameterType)0x2)

/**
 * \brief Indicates the configuration of the CAN XL baud rate.
 * \note The baud rate is configured using the field 'baudrate'.
 */
#define FMI3_LS_BUS_CAN_CONFIG_PARAM_TYPE_CANXL_BAUDRATE ((fmi3LsBusCanConfigParameterType)0x3)

/**
 * \brief Indicates the configuration of the arbitration lost behavior.
 * \note The behavior is configured using the field 'arbitrationLostBehavior'.
 */
#define FMI3_LS_BUS_CAN_CONFIG_PARAM_TYPE_ARBITRATION_LOST_BEHAVIOR ((fmi3LsBusCanConfigParameterType)0x4)

/**
 * \brief Data type representing the arbitration lost behavior.
 */
typedef fmi3UInt8 fmi3LsBusCanArbitrationLostBehavior;

/**
 * \brief Represents the arbitration lost behavior 'BUFFER_AND_RETRANSMIT':
 *  Transmit operations shall be buffered by the Bus Simulation.
 */
#define FMI3_LS_BUS_CAN_CONFIG_PARAM_ARBITRATION_LOST_BEHAVIOR_BUFFER_AND_RETRANSMIT \
    ((fmi3LsBusCanArbitrationLostBehavior)0x1)

/**
 * \brief Represents the arbitration lost behavior 'DISCARD_AND_NOTIFY':
 *  Transmit operations shall be discarded and the specified Network FMU shall be notified
 *  by the Bus Simulation using an 'Arbitration Lost' operation.
 */
#define FMI3_LS_BUS_CAN_CONFIG_PARAM_ARBITRATION_LOST_BEHAVIOR_DISCARD_AND_NOTIFY \
    ((fmi3LsBusCanArbitrationLostBehavior)0x2)

/**
 * \brief FMI virtual bus operation structure of type 'Configuration'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;                                 /**< Operation header. */
    fmi3LsBusCanConfigParameterType parameterType;                   /**< Defines the current configuration parameter.
                                                                          \note Only one parameter can be set per Configuration operation. */
    union
    {
        fmi3LsBusCanBaudrate baudrate;                               /**< The configured baud rate. */
        fmi3LsBusCanArbitrationLostBehavior arbitrationLostBehavior; /**< The configured arbitration lost behavior. */
    };
} fmi3LsBusCanOperationConfiguration;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusCanOperationConfiguration) >= (8 + 4 + 1),
              "'fmi3LsBusCanOperationConfiguration' does not match the expected data size");
#endif

/**
 * \brief FMI virtual bus operation structure of type 'Wakeup'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header; /**< Operation header. */
} fmi3LsBusCanOperationWakeup;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusCanOperationWakeup) == (8),
              "'fmi3LsBusCanOperationWakeup' does not match the expected data size");
#endif

#pragma pack()

#ifdef __cplusplus
} /* end of extern "C" { */
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif /* fmi3LsBusCan_h */
