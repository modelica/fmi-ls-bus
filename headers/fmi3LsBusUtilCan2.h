#ifndef fmi3LsBusUtilCan_h
#define fmi3LsBusUtilCan_h

/*
This header file contains utility macros to read and write fmi-ls-bus
CAN specific bus operations from\to dedicated buffer variables.

This header file can be used when creating Network fmi-ls-bus FMUs with CAN busses.

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

#ifdef __cplusplus
extern "C"
{
#endif

#include "fmi3LsBusCan2.h"
#include "fmi3LsBusUtil.h"

/**
 * \brief Creates a CAN transmit operation.
 *
 *  This macro can be used to create a CAN transmit operation.
 *  The arguments are serialized according to the fmi-ls-bus specification and written to the buffer
 *  described by the argument 'BufferInfo'. If there is not enough buffer space available, the 'status'
 *  variable of the argument 'BufferInfo' is set to fmi3False.
 *   
 * \param[in] BufferInfo  Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] ID          CAN message ID (\ref fmi3LsBusCanId).
 * \param[in] Ide         CAN message ID type (standard/extended) (\ref fmi3LsBusCanIde).
 * \param[in] Rtr         Remote Transmission Request (\ref fmi3LsBusCanRtr).
 * \param[in] DataLength  Message data length (\ref fmi3LsBusCanDataLength).
 * \param[in] Data        Message data (\ref fmi3LsBusCanDataLength).
 */
#define FMI3_LS_BUS_CAN_CREATE_OP_CAN_TRANSMIT2(BufferInfo, ID, Ide, Rtr, DataLength, Data)              \
    do                                                                                                  \
    {                                                                                                   \
        fmi3LsBusCanOperationCanTransmit2 _op;                                                           \
        _op.header.opCode = FMI3_LS_BUS_CAN_OP_CAN_TRANSMIT2;                                              \
        _op.header.length = sizeof(fmi3LsBusOperationHeader) +                                          \
                            sizeof(fmi3LsBusCanId2) +                                                    \
                            sizeof(fmi3LsBusCanIde2) +                                                   \
                            sizeof(fmi3LsBusCanRtr2) +                                                   \
                            sizeof(fmi3LsBusCanDataLength2) +                                            \
                            (DataLength);                                                               \
        _op.id = (ID);                                                                                  \
        _op.ide = (Ide);                                                                                \
        _op.rtr = (Rtr);                                                                                \
                                                                                                        \
        _op.dataLength = (DataLength);                                                                  \
        if (_op.header.length <= (fmi3UInt32)((BufferInfo)->end - (BufferInfo)->writePos))              \
        {                                                                                               \
            memcpy((BufferInfo)->writePos, &_op, _op.header.length - (DataLength));                     \
            (BufferInfo)->writePos += _op.header.length - (DataLength);                                 \
            memcpy((BufferInfo)->writePos, (Data), (DataLength));                                       \
            (BufferInfo)->writePos += (DataLength);                                                     \
            (BufferInfo)->status = fmi3True;                                                            \
        }                                                                                               \
        else                                                                                            \
        {                                                                                               \
            (BufferInfo)->status = fmi3False;                                                           \
        }                                                                                               \
    }                                                                                                   \
    while (0)

#ifdef __cplusplus
} /* end of extern "C" { */
#endif


#endif /* fmi3LsBusUtilCan_h */
