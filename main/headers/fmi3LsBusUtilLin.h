#ifndef fmi3LsBusUtilLin_h
#define fmi3LsBusUtilLin_h

/*
This header file contains utility macros to read and write FMI-LS-BUS
LIN specific bus operations from\to dedicated buffer variables.

This header file can be used when creating Network FMI-LS-BUS FMUs with LIN.

Copyright (C) 2025-2026 Modelica Association Project "FMI"
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

#include "fmi3LsBusUtil.h"
#include "fmi3LsBusLin.h"


/**
 * \brief Represents an operation for the transmission of a LIN message, aggregating a representation for a LIN Frame Header and a LIN Frame Response.
 *
 * This macro can be used to create an LIN 'Transmit' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo
 *     Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] FramePart
 *     Indicates the part of the specified LIN frame (\ref fmi3LsBusLinFramePart).
 * \param[in] Id
 *     The specified ID of the LIN message (\ref fmi3LsBusLinID).
 * \param[in] ChecksumType
 *     Indicates the checksum type of the specified LIN frame (\ref fmi3LsBusLinChecksumType).
 * \param[in] DataLength
 *     The length of the data of this LIN frame (\ref fmi3LsBusLinDataLength).
 * \param[in] Data
 *     The payload data of the LIN frame (pointer of \ref fmi3LsBusLinData).
 */
#define FMI3_LS_BUS_LIN_CREATE_OP_TRANSMIT(BufferInfo, \
        FramePart, \
        Id, \
        ChecksumType, \
        DataLength, \
        Data \
    ) do { \
        fmi3LsBusLinOperationTransmit _op; \
        _op.header.opCode = FMI3_LS_BUS_LIN_OP_TRANSMIT; \
        _op.header.length = sizeof(fmi3LsBusOperationHeader) \
            + sizeof(fmi3LsBusLinFramePart) \
            + sizeof(fmi3LsBusLinID) \
            + sizeof(fmi3LsBusLinChecksumType) \
            + sizeof(fmi3LsBusLinDataLength) \
            + (DataLength); \
        \
        _op.framePart = FramePart; \
        _op.id = Id; \
        _op.checksumType = ChecksumType; \
        _op.dataLength = DataLength; \
        \
        FMI_LS_BUS_SUBMIT_OPERATION_INTERNAL((BufferInfo), _op, (DataLength), (Data)); \
    } while (0)


/**
 * \brief Signals a successful transmitted LIN Header or/and Response.
 *
 * This macro can be used to create an LIN 'Confirm' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo
 *     Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] Id
 *     The specified ID of the LIN message (\ref fmi3LsBusLinID).
 */
#define FMI3_LS_BUS_LIN_CREATE_OP_CONFIRM(BufferInfo, \
        Id \
    ) do { \
        fmi3LsBusLinOperationConfirm _op; \
        _op.header.opCode = FMI3_LS_BUS_LIN_OP_CONFIRM; \
        _op.header.length = sizeof(fmi3LsBusOperationHeader) \
            + sizeof(fmi3LsBusLinID); \
        \
        _op.id = Id; \
        \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op); \
    } while (0)


/**
 * \brief Indicates an error during the transmission of an LIN frame.
 *
 * This macro can be used to create an LIN 'Bus Error' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo
 *     Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] Id
 *     The ID of the LIN message that was transmitted while the error happened (\ref fmi3LsBusLinID).
 * \param[in] ErrorCode
 *     Represents the specified bus error to simulate (\ref fmi3LsBusLinBusErrorCode).
 */
#define FMI3_LS_BUS_LIN_CREATE_OP_BUS_ERROR(BufferInfo, \
        Id, \
        ErrorCode \
    ) do { \
        fmi3LsBusLinOperationBusError _op; \
        _op.header.opCode = FMI3_LS_BUS_LIN_OP_BUS_ERROR; \
        _op.header.length = sizeof(fmi3LsBusOperationHeader) \
            + sizeof(fmi3LsBusLinID) \
            + sizeof(fmi3LsBusLinBusErrorCode); \
        \
        _op.id = Id; \
        _op.errorCode = ErrorCode; \
        \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op); \
    } while (0)


/**
 * \brief Provides information to configure the LIN bus.
 *
 * This macro can be used to create an LIN 'Configuration' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo
 *     Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] Baudrate
 *     Defines the baudrate of the specified LIN node to configure (\ref fmi3LsBusLinBaudrate).
 */
#define FMI3_LS_BUS_LIN_CREATE_OP_CONFIGURATION_BAUDRATE(BufferInfo, \
        Baudrate \
    ) do { \
        fmi3LsBusLinOperationConfiguration _op; \
        _op.header.opCode = FMI3_LS_BUS_LIN_OP_CONFIGURATION; \
        _op.header.length = sizeof(fmi3LsBusOperationHeader) \
            + sizeof(fmi3LsBusLinConfigParameterType) \
            + sizeof(fmi3LsBusLinConfigurationNodeBaudrateConfig); \
        \
        _op.parameterType = FMI3_LS_BUS_LIN_CONFIG_PARAMETER_TYPE_BAUDRATE; \
        _op.nodeBaudrate.baudrate = Baudrate; \
        \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op); \
    } while (0)

/**
 * \brief Provides information to configure the LIN bus.
 *
 * This macro can be used to create an LIN 'Configuration' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo
 *     Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] Baudrate
 *     Indicates the type of a LIN node (LIN Commander or LIN Responder) (\ref fmi3LsBusLinNodeType).
 */
#define FMI3_LS_BUS_LIN_CREATE_OP_CONFIGURATION_NODE_TYPE(BufferInfo, \
        NodeType \
    ) do { \
        fmi3LsBusLinOperationConfiguration _op; \
        _op.header.opCode = FMI3_LS_BUS_LIN_OP_CONFIGURATION; \
        _op.header.length = sizeof(fmi3LsBusOperationHeader) \
            + sizeof(fmi3LsBusLinConfigParameterType) \
            + sizeof(fmi3LsBusLinConfigurationNodeTypeConfig); \
        \
        _op.parameterType = FMI3_LS_BUS_LIN_CONFIG_PARAMETER_TYPE_NODE_TYPE; \
        _op.nodeType.nodeType = NodeType; \
        \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op); \
    } while (0)


/**
 * \brief Indicates a wakeup.
 *
 * This macro can be used to create an LIN 'Wakeup' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo
 *     Pointer to \ref fmi3LsBusUtilBufferInfo.
 */
#define FMI3_LS_BUS_LIN_CREATE_OP_WAKEUP(BufferInfo \
    ) do { \
        fmi3LsBusLinOperationWakeup _op; \
        _op.header.opCode = FMI3_LS_BUS_LIN_OP_WAKEUP; \
        _op.header.length = sizeof(fmi3LsBusOperationHeader); \
        \
        \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op); \
    } while (0)


#endif /* fmi3LsBusUtilLin_h */