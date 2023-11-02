#ifndef fmi3LsBusCan_h
#define fmi3LsBusCan_h

/*
This header file declares CAN bus specific constants and data types as defined by the
fmi-ls-bus layered standard specification (https://github.com/modelica/fmi-ls-bus).

It should be used when creating CAN Network FMUs according to the fmi-ls-bus layered standard.

Copyright (C) 2023 Modelica Association Project "FMI"
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

#include "fmi3lsBus.h"
#include <assert.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4200)
#pragma warning(disable : 4815)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************
  CAN bus specific OP code 
****************************************************/

/**
 * Initiates the transmission of CAN frames.
 */
#define FMI3_LS_BUS_CAN_OP_CAN_TRANSMIT ((fmi3LsBusOperationType)0x0010)

/**
 * Represents an operation for the transmission of a CAN FD frame.
 */
#define FMI3_LS_BUS_CAN_OP_CANFD_TRANSMIT ((fmi3LsBusOperationType)0x0011)

/**
 * Represents an operation for the transmission of a CAN XL frame.
 */
#define FMI3_LS_BUS_CAN_OP_CANXL_TRANSMIT ((fmi3LsBusOperationType)0x0012)

/**
 * Signals successful receipt of a transmitted CAN, CAN FD and CAN XL frame to simulate a CAN acknowledgment behavior.
 */
#define FMI3_LS_BUS_CAN_OP_CONFIRM ((fmi3LsBusOperationType)0x0020)

/**
 * The Arbitration Lost operation indicates that a CAN frame could not be sent immediately and was therefore
 * discarded by the Bus Simulation.
 */
#define FMI3_LS_BUS_CAN_OP_ARBITRATION_LOST ((fmi3LsBusOperationType)0x0030)

/**
 * Represents an operation for simulated bus errors.
 */
#define FMI3_LS_BUS_CAN_OP_CAN_BUS_ERROR ((fmi3LsBusOperationType)0x0031)

/**
 * Represents an operation for the configuration of a Bus Simulation. In detail, the configuration of a CAN, CAN FD
 * and CAN XL baud rate is possible. Also the configuration of further options, like buffer handling, is supported
 * by this operation.
 */
#define FMI3_LS_BUS_CAN_OP_CONFIGURATION ((fmi3LsBusOperationType)0x0040)

/**
 * FMI virtual bus operation which indicates a status operation.
 */
#define FMI3_LS_BUS_CAN_OP_STATUS ((fmi3LsBusOperationType)0x0041)

/**
 * Represents an operation for triggering a bus-specific wake up.
 */
#define FMI3_LS_BUS_CAN_OP_WAKEUP ((fmi3LsBusOperationType)0x0042)



/***************************************************
Types for CAN specific bus operations
****************************************************/

#pragma pack(1)

/**
 * Data type representing the CAN identifer.
 */
typedef fmi3UInt32 fmi3LsBusCanId;

/**
 * Data type for defining a standard or extended messages.
 */
typedef fmi3UInt8 fmi3LsBusCanIde;

/**
 * Data type for defining a Remote Transmission Request frame.
 */
typedef fmi3UInt8 fmi3LsBusCanRtr;

/**
 * Data type for data length.
 */
typedef fmi3UInt16 fmi3LsBusCanDataLength;

/**
 * Data type for data.
 */
typedef fmi3UInt8 fmi3LsBusCanData;

/**
 * Can transmit operation.
 */
typedef struct
{
    fmi3LsBusOperationHeader header; /**< Message header */
    fmi3LsBusCanId  id; /**<  CAN message ID. */
    fmi3LsBusCanIde ide; /**< Standard (11-bit) or Extended (29-bit) message identifier. */
    fmi3LsBusCanRtr rtr; /**< Remote Transmission Request frame. */
    fmi3LsBusCanDataLength dataLength; /**< Data length. */
    fmi3LsBusCanData data[]; /**< Data. */
} fmi3LsBusCanOperationCanTransmit;

static_assert(sizeof(fmi3LsBusCanOperationCanTransmit) == (5 + 4 + 1 + 1 + 2),
              "'fmi3LsBusCanOperationCanTransmit' does not match the expected data size");

/**
 * Data type for defining a Bit Rate Switch.
 */
typedef fmi3UInt8 fmi3LsBusCanBrs;

/**
 * Data type for defining a Error State Indicator.
 */
typedef fmi3UInt8 fmi3LsBusCanEsi;

/**
 * Can FD transmit operation.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;   /**< Message header */
    fmi3LsBusCanId id;                 /**<  CAN message ID. */
    fmi3LsBusCanIde ide;               /**< Standard (11-bit) or Extended (29-bit) message identifier. */
    fmi3LsBusCanBrs brs;               /**< Bit Rate Switch. */
    fmi3LsBusCanEsi esi;               /**< Error State Idicator. */
    fmi3LsBusCanDataLength dataLength; /**< Data length. */
    fmi3LsBusCanData data[]; /**< Data. */
} fmi3LsBusCanOperationCanFdTransmit;

static_assert(sizeof(fmi3LsBusCanOperationCanFdTransmit) == (5 + 4 + 1 + 1 + 1 + 2),
              "'fmi3LsBusCanOperationCanFdTransmit' does not match the expected data size");

/**
 * Data type for defining a Simple Extended Content.
 */
typedef fmi3UInt8 fmi3LsBusCanSec;

/**
 * Data type for defining a Service Data Unit Type.
 */
typedef fmi3UInt8 fmi3LsBusCanSdt;

/**
 * Data type for defining a Virtual CAN Network ID.
 */
typedef fmi3UInt8 fmi3LsBusCanVcId;

/**
 * Data type for defining an Acceptance Field.
 */
typedef fmi3UInt32 fmi3LsBusCanAf;

/**
 * Can XL transmit operation.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;   /**< Message header */
    fmi3LsBusCanId id;                 /**<  CAN message ID. */
    fmi3LsBusCanIde ide;               /**< Standard (11-bit) or Extended (29-bit) message identifier. */
    fmi3LsBusCanSec sec;               /**< Simple Extended Content. */
    fmi3LsBusCanSdt sdt;               /**< Service Data Unit Type. */
    fmi3LsBusCanVcId vcid;             /**< Virtual CAN Network ID. */
    fmi3LsBusCanAf af;                 /**< Acceptance Field. */
    fmi3LsBusCanDataLength dataLength; /**< Data length. */
    fmi3LsBusCanData data[]; /**< Data.*/
} fmi3LsBusCanOperationCanXlTransmit;

static_assert(sizeof(fmi3LsBusCanOperationCanXlTransmit) == (5 + 4 + 1 + 1 + 1 + 1 + 4 + 2),
              "'fmi3LsBusCanOperationCanXlTransmit' does not match the expected data size");

/**
 * Can confirm operation.
 */
typedef struct
{
    fmi3LsBusOperationHeader header; /**< Message header */
    fmi3LsBusCanId id; /**<  CAN message ID. */
} fmi3LsBusCanOperationConfirm;

static_assert(sizeof(fmi3LsBusCanOperationConfirm) == (5 + 4),
              "'fmi3LsBusCanOperationConfirm' does not match the expected data size");

/**
 * Can arbitration lost operation.
 */
typedef struct
{
    fmi3LsBusOperationHeader header; /**< Message header */
    fmi3LsBusCanId id;               /**<  CAN message ID. */
} fmi3LsBusCanOperationArbitrationLost;

static_assert(sizeof(fmi3LsBusCanOperationArbitrationLost) == (5 + 4),
              "'fmi3LsBusCanOperationArbitrationLost' does not match the expected data size");

/**
 * FMI data type to be used for the CAN bus error code.
 */
typedef fmi3UInt8 fmi3LsBusCanErrorCode;

#define FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR \
    ((fmi3LsBusCanErrorCode)0x1)

#define FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_STUFFING_ERROR \
    ((fmi3LsBusCanErrorCode)0x2)

#define FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_FORM_ERROR \
    ((fmi3LsBusCanErrorCode)0x3)

#define FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_CRC_ERROR \
    ((fmi3LsBusCanErrorCode)0x4)

#define FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_ACK_ERROR \
    ((fmi3LsBusCanErrorCode)0x5)

#define FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BROKEN_ERROR_FRAME \
    ((fmi3LsBusCanErrorCode)0x6)

/**
 * FMI data type to be used for the CAN bus error flag.
 */
typedef fmi3UInt8 fmi3LsBusCanErrorFlag;

#define FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG ((fmi3LsBusCanErrorFlag)0x1)

#define FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG ((fmi3LsBusCanErrorFlag)0x2)

/**
 * Data type for defining a sender or receiver situation.
 */
typedef fmi3UInt8 fmi3LsBusCanIsSender;

/**
 * Can bus error operation.
 */
typedef struct
{
    fmi3LsBusOperationHeader header; /**< Message header */
    fmi3LsBusCanId id;               /**<  CAN message ID. */
    fmi3LsBusCanErrorCode errorCode; /**<  Bus Error Code. */
    fmi3LsBusCanErrorFlag errorFlag; /**<  Bus Error Flag. */
    fmi3LsBusCanIsSender isSender;   /**<  Is Sender. */
} fmi3LsBusCanOperationBusError;

static_assert(sizeof(fmi3LsBusCanOperationBusError) == (5 + 4 + 1 + 1 + 1),
              "'fmi3LsBusCanOperationBusError' does not match the expected data size");

/**
 * FMI data type to be used for the CAN status kind.
 */
typedef fmi3UInt8 fmi3LsBusCanStatusKind;

#define FMI3_LS_BUS_CAN_STATUS_PARAM_STATUS_KIND_ERROR_ACTIVE ((fmi3LsBusCanStatusKind)0x1)

#define FMI3_LS_BUS_CAN_STATUS_PARAM_STATUS_KIND_ERROR_PASSIVE ((fmi3LsBusCanStatusKind)0x2)

#define FMI3_LS_BUS_CAN_STATUS_PARAM_STATUS_KIND_BUS_OFF ((fmi3LsBusCanStatusKind)0x3)

/**
 * Can status operation.
 */
typedef struct
{
    fmi3LsBusOperationHeader header; /**< Message header */
    fmi3LsBusCanStatusKind status;   /**<  Status Kind. */
} fmi3LsBusCanOperationStatus;

static_assert(sizeof(fmi3LsBusCanOperationStatus) == (5 + 1),
              "'fmi3LsBusCanOperationStatus' does not match the expected data size");

/**
 * FMI data type to be used for baudrate settings.
 */
typedef fmi3UInt32 fmi3LsBusCanBaudrate;

/**
 * FMI data type to be used for the configuration parameter type.
 */
typedef fmi3UInt8 fmi3LsBusCanConfigParameterType;

/**
 * Definitions of configuration parameter type.
 */
#define FMI3_LS_BUS_CAN_CONFIG_PARAM_TYPE_CAN_BAUDRATE ((fmi3LsBusCanConfigParameterType)0x1)
#define FMI3_LS_BUS_CAN_CONFIG_PARAM_TYPE_CANFD_BAUDRATE ((fmi3LsBusCanConfigParameterType)0x2)
#define FMI3_LS_BUS_CAN_CONFIG_PARAM_TYPE_CANXL_BAUDRATE ((fmi3LsBusCanConfigParameterType)0x3)
#define FMI3_LS_BUS_CAN_CONFIG_PARAM_TYPE_ARBITRATION_LOST_BEHAVIOR ((fmi3LsBusCanConfigParameterType)0x4)

/**
 * FMI data type to be used for the CAN configuration options.
 */
typedef fmi3UInt8 fmi3LsBusCanArbitrationLostBehavior;

#define FMI3_LS_BUS_CAN_CONFIG_PARAM_ARBITRATION_LOST_BEHAVIOR_BUFFER_AND_RETRANSMIT \
    ((fmi3LsBusCanArbitrationLostBehavior)0x1)

#define FMI3_LS_BUS_CAN_CONFIG_PARAM_ARBITRATION_LOST_BEHAVIOR_DISCARD_AND_NOTIFY \
    ((fmi3LsBusCanArbitrationLostBehavior)0x2)

/**
 * Can configuration operation.
 */
typedef struct
{
    fmi3LsBusOperationHeader header; /**< Message header */
    fmi3LsBusCanConfigParameterType parameterType; /**< Defines the current configuration parameter.
                                                        Note: Only one parameter can be set per Configuration operation. */
    union
    {
        fmi3LsBusCanBaudrate baudrate;
        fmi3LsBusCanArbitrationLostBehavior arbitrationLostBehavior;
    };
} fmi3LsBusOperationCanConfiguration;

static_assert(sizeof(fmi3LsBusOperationCanConfiguration) >= (5 + 4 + 1),
              "'fmi3LsBusOperationCanConfiguration' does not match the expected data size");

/**
 * Can wakeup operation.
 */
typedef struct
{
    fmi3LsBusOperationHeader header; /**< Message header */
} fmi3LsBusCanOperationWakeup;

static_assert(sizeof(fmi3LsBusCanOperationWakeup) == (5),
              "'fmi3LsBusCanOperationWakeup' does not match the expected data size");

#pragma pack()

#ifdef __cplusplus
} /* end of extern "C" { */
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif /* fmi3LsBusCan_h */
