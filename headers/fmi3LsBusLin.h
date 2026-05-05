#ifndef fmi3LsBusLin_h
#define fmi3LsBusLin_h

/*
This header file contains utility macros to read and write FMI-LS-BUS
LIN specific bus operations from / to dedicated buffer variables.

This header file can be used when creating FMI-LS-BUS network FMUs with LIN busses.

Copyright (C) 2025 Modelica Association Project "FMI"
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
#include "fmi3PlatformTypes.h"

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
 * \defgroup FMI3_LS_BUS_LIN_OPERATION_CODES LIN bus-specific operation codes
 * \brief Operation codes for LIN-specific bus operations.
 * \{
 */

/**
 * \brief FMI virtual bus operation of type 'Transmit'.
 *
 * Represents an operation for the transmission of a LIN message, aggregating a representation for a LIN Frame Header and a LIN Frame Response.
 */
#define FMI3_LS_BUS_LIN_OP_TRANSMIT ((fmi3LsBusOperationCode)0x10)

/**
 * \brief FMI virtual bus operation of type 'Confirm'.
 *
 * Signals a successful transmitted LIN Header or/and Response.
 */
#define FMI3_LS_BUS_LIN_OP_CONFIRM ((fmi3LsBusOperationCode)0x20)

/**
 * \brief FMI virtual bus operation of type 'Bus Error'.
 *
 * Indicates an error during the transmission of an LIN frame.
 */
#define FMI3_LS_BUS_LIN_OP_BUS_ERROR ((fmi3LsBusOperationCode)0x30)

/**
 * \brief FMI virtual bus operation of type 'Configuration'.
 *
 * Provides information to configure the LIN bus.
 */
#define FMI3_LS_BUS_LIN_OP_CONFIGURATION ((fmi3LsBusOperationCode)0x40)

/**
 * \brief FMI virtual bus operation of type 'Wakeup'.
 *
 * Indicates a wakeup.
 */
#define FMI3_LS_BUS_LIN_OP_WAKEUP ((fmi3LsBusOperationCode)0x50)

/** \} */

#pragma pack(1)

/**
 * \defgroup FMI3_LS_BUS_LIN_DATA_TYPES Lin-specific data types
 * \brief Data types used for Lin.
 * \{
 */

/**
 * \brief The specified ID of the LIN message.
 */
typedef fmi3UInt8 fmi3LsBusLinID;

/**
 * \brief Indicates the part of the specified LIN frame.
 */
typedef fmi3UInt8 fmi3LsBusLinFramePart;

/**
 * \brief Indicates a LIN Frame Header. In this case the Data Length argument of a Transmit operation is always set to zero.
 */
#define FMI3_LS_BUS_LIN_FRAME_PART_HEADER ((fmi3LsBusLinFramePart)0x1)
/**
 * \brief Indicates a LIN Frame Response. In this case the Data Length argument of a Transmit operation contains the length of the Data argument value.
 */
#define FMI3_LS_BUS_LIN_FRAME_PART_RESPONSE ((fmi3LsBusLinFramePart)0x2)

/**
 * \brief Indicates the checksum type of the specified LIN frame.
 */
typedef fmi3UInt8 fmi3LsBusLinChecksumType;

/**
 * \brief Indicates that the specified LIN frame uses the classic checksum mechanism.
 */
#define FMI3_LS_BUS_LIN_CHECKSUM_TYPE_CLASSIC_CHECKSUM ((fmi3LsBusLinChecksumType)0x1)
/**
 * \brief Indicates that the specified LIN frame uses the enhanced checksum mechanism.
 */
#define FMI3_LS_BUS_LIN_CHECKSUM_TYPE_ENHANCED_CHECKSUM ((fmi3LsBusLinChecksumType)0x2)

/**
 * \brief Data type representing the LIN frame payload data.
 */
typedef fmi3UInt8 fmi3LsBusLinData;

/**
 * \brief Data type representing the LIN frame payload length.
 */
typedef fmi3UInt8 fmi3LsBusLinDataLength;

/**
 * \brief Indicates the type of a bus error.
 */
typedef fmi3UInt8 fmi3LsBusLinBusErrorCode;

/**
 * \brief A BIT_ERROR means that a received bit does not match the expected value. This Bus Error operation is a direct reaction to a Transmit operation (Frame Part is set to HEADER) and shall be delivered to the Network FMU that is configured as LIN_COMMANDER within the specified LIN network.
 */
#define FMI3_LS_BUS_LIN_BUS_ERROR_CODE_BIT_ERROR ((fmi3LsBusLinBusErrorCode)0x1)
/**
 * \brief Represents a CRC error. The error can occur during a collision of multiple response frames when Event-Triggered-Frames are used. This Bus Error operation is a direct reaction to a Transmit operation (Frame Part is set to RESPONSE) and shall be delivered to the Network FMU that is configured as LIN_COMMANDER of the specified LIN network.
 */
#define FMI3_LS_BUS_LIN_BUS_ERROR_CODE_CHECKSUM_ERROR ((fmi3LsBusLinBusErrorCode)0x2)
/**
 * \brief Represents an Identifier Parity Error. The error can occur during a collision of multiple LIN headers. This Bus Error operation is a direct reaction to a Transmit operation (Frame Part is set to HEADER) and shall be delivered to all Network FMUs of the specified LIN network..
 */
#define FMI3_LS_BUS_LIN_BUS_ERROR_CODE_IDENTIFIER_PARITY_ERROR ((fmi3LsBusLinBusErrorCode)0x3)
/**
 * \brief Represents a No Response Error. The error can occur if LIN Responders does not respond to a specified LIN header. This Bus Error operation is a direct reaction to a Transmit operation (Frame Part is set to HEADER) and shall be delivered to the Network FMU that is configured as LIN_COMMANDER within the specified LIN network.
 */
#define FMI3_LS_BUS_LIN_BUS_ERROR_CODE_NO_RESPONSE_ERROR ((fmi3LsBusLinBusErrorCode)0x4)
/**
 * \brief Represents an Inconsistent-Synch Field Error. This Bus Error operation is a direct reaction to a Transmit operation (Frame Part is set to HEADER) and shall be delivered to the Network FMUs that are configured as LIN_RESPONDER within the specified LIN network.
 */
#define FMI3_LS_BUS_LIN_BUS_ERROR_CODE_SYNCH_FIELD_ERROR ((fmi3LsBusLinBusErrorCode)0x5)
/**
 * \brief The calculated baud rate deviates too much from the original baud rate after clock synchronization (tolerance exceeded). This Bus Error operation is a direct reaction to a Transmit operation (Frame Part is set to HEADER) and shall be delivered to the Network FMUs that are configured as LIN_RESPONDER within the specified LIN network.
 */
#define FMI3_LS_BUS_LIN_BUS_ERROR_CODE_SYNCH_TOLERANCE_ERROR ((fmi3LsBusLinBusErrorCode)0x6)
/**
 * \brief A header timeout error means that a LIN Responder node did not receive a complete header from the LIN Commander within the specified time frame. This Bus Error operation is a direct reaction to a Transmit operation (Frame Part is set to HEADER) and shall be delivered to the Network FMUs that are configured as LIN_RESPONDER within the specified LIN network.
 */
#define FMI3_LS_BUS_LIN_BUS_ERROR_CODE_HEADER_TIMEOUT_ERROR ((fmi3LsBusLinBusErrorCode)0x7)
/**
 * \brief This represents an error in the stop bit or in the frame format. This Bus Error operation is a direct reaction to a Transmit operation and shall be delivered to all Network FMUs of the specified LIN network.
 */
#define FMI3_LS_BUS_LIN_BUS_ERROR_CODE_FRAME_ERROR ((fmi3LsBusLinBusErrorCode)0x8)
/**
 * \brief Represents a Physical Bus Error. This Bus Error operation is a direct reaction to a Transmit operation and shall be delivered to all Network FMUs of the specified LIN network.
 */
#define FMI3_LS_BUS_LIN_BUS_ERROR_CODE_PHYSICAL_BUS_ERROR ((fmi3LsBusLinBusErrorCode)0x9)

/**
 * \brief Data type identifying the baudrate of a specified LIN bus.
 */
typedef fmi3UInt32 fmi3LsBusLinBaudrate;

/**
 * \brief Indicates the type of a LIN node (LIN Commander or LIN Responder).
 */
typedef fmi3UInt8 fmi3LsBusLinNodeType;

/**
 * \brief Represents a LIN Commander network node.
 */
#define FMI3_LS_BUS_LIN_NODE_TYPE_LIN_COMMANDER ((fmi3LsBusLinNodeType)0x1)
/**
 * \brief Represents a LIN Responder network node.
 */
#define FMI3_LS_BUS_LIN_NODE_TYPE_LIN_RESPONDER ((fmi3LsBusLinNodeType)0x2)

/**
 * \brief Data type representing the parameter configured with a configuration operation.
 */
typedef fmi3UInt8 fmi3LsBusLinConfigParameterType;

/**
 * \brief The specified baud rate value to configure, whereby the specified ranges are defined by the LIN standard. The required unit for the baud rate value is bit/s.
 */
#define FMI3_LS_BUS_LIN_CONFIG_PARAMETER_TYPE_BAUDRATE ((fmi3LsBusLinConfigParameterType)0x1)
/**
 * \brief Configures the required node type (LIN COMMANDER or LIN RESPONDER) within a Bus Simulation.
 */
#define FMI3_LS_BUS_LIN_CONFIG_PARAMETER_TYPE_NODE_TYPE ((fmi3LsBusLinConfigParameterType)0x2)

/**
 * \brief Configuration data sent with 'Configuration' operation of type 'BAUDRATE'.
 */
typedef struct
{
    fmi3LsBusLinBaudrate baudrate;  /**< Defines the baudrate of the specified LIN node to configure */
} fmi3LsBusLinConfigurationNodeBaudrateConfig;

/**
 * \brief Configuration data sent with 'Configuration' operation of type 'NODE_TYPE'.
 */
typedef struct
{
    fmi3LsBusLinNodeType nodeType;  /**< Indicates the type of a LIN node (LIN Commander or LIN Responder) */
} fmi3LsBusLinConfigurationNodeTypeConfig;

/** \} */

/**
 * \defgroup FMI3_LS_BUS_LIN_OPERATION_TYPES Lin-specific operation types
 * \brief Operations used for Lin.
 * \{
 */

/**
 * \brief Represents an operation for the transmission of a LIN message, aggregating a representation for a LIN Frame Header and a LIN Frame Response.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;  /**< Operation header */
    fmi3LsBusLinFramePart framePart;  /**< Indicates the part of the specified LIN frame */
    fmi3LsBusLinID id;  /**< The specified ID of the LIN message */
    fmi3LsBusLinChecksumType checksumType;  /**< Indicates the checksum type of the specified LIN frame */
    fmi3LsBusLinDataLength dataLength;  /**< The length of the data of this LIN frame */
    fmi3LsBusLinData data[];  /**< The payload data of the LIN frame */
} fmi3LsBusLinOperationTransmit;

/**
 * \brief Signals a successful transmitted LIN Header or/and Response.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;  /**< Operation header */
    fmi3LsBusLinID id;  /**< The specified ID of the LIN message */
} fmi3LsBusLinOperationConfirm;

/**
 * \brief Indicates an error during the transmission of an LIN frame.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;  /**< Operation header */
    fmi3LsBusLinID id;  /**< The specified ID of the LIN message */
    fmi3LsBusLinBusErrorCode errorCode;  /**< Represents the specified bus error to simulate */
} fmi3LsBusLinOperationBusError;

/**
 * \brief Provides information to configure the LIN bus.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;  /**< Operation header */
    fmi3LsBusLinConfigParameterType parameterType;  /**< Defines the current configuration parameter */
    union
    {
        fmi3LsBusLinConfigurationNodeBaudrateConfig nodeBaudrate;  /**< Configuration data for parameter 'BAUDRATE'. */
        fmi3LsBusLinConfigurationNodeTypeConfig nodeType;  /**< Configuration data for parameter 'NODE_TYPE'. */
    };
} fmi3LsBusLinOperationConfiguration;

/**
 * \brief Indicates a wakeup.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;  /**< Operation header */
} fmi3LsBusLinOperationWakeup;

/** \} */

#pragma pack()

#ifdef __cplusplus
} /* end of extern "C" { */
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif /* fmi3LsBusLin_h */