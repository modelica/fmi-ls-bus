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
#define FMI3_LS_BUS_CAN_OP_CAN_TRANSMIT2 ((fmi3LsBusOperationCode)0x0010)

/**
 * CAN bus-specific operation types.
 */

#pragma pack(1)

/**
 * \brief Data type representing a CAN identifier.
 */
typedef fmi3UInt32 fmi3LsBusCanId2;

/**
 * \brief Data type indicating whether a frame is a standard or extended message.
 */
typedef fmi3UInt8 fmi3LsBusCanIde2;

/**
 * \brief Data type indicating whether a frame is a Remote Transmission Request.
 */
typedef fmi3UInt8 fmi3LsBusCanRtr2;

/**
 * \brief Data type representing the CAN frame payload length.
 */
typedef fmi3UInt16 fmi3LsBusCanDataLength2;

/**
 * \brief Data type representing the CAN frame payload data.
 */
typedef fmi3UInt8 fmi3LsBusCanData2;

/**
 * \brief FMI virtual bus operation structure of type 'CAN Transmit'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;   /**< Operation header. */
    fmi3LsBusCanId2  id;                /**< CAN message ID. */
    fmi3LsBusCanIde2 ide;               /**< Standard (11-bit) or Extended (29-bit) message identifier. */
    fmi3LsBusCanRtr2 rtr;               /**< Remote Transmission Request frame. */
    fmi3LsBusCanDataLength2 dataLength; /**< Data length. */
    fmi3LsBusCanData2 data[];           /**< Data. */
} fmi3LsBusCanOperationCanTransmit2;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
static_assert(sizeof(fmi3LsBusCanOperationCanTransmit2) == (5 + 4 + 1 + 1 + 2),
              "'fmi3LsBusCanOperationCanTransmit' does not match the expected data size");
#endif

#pragma pack()

#ifdef __cplusplus
} /* end of extern "C" { */
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif /* fmi3LsBusCan_h */
