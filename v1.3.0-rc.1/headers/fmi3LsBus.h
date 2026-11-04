#ifndef fmi3LsBus_h
#define fmi3LsBus_h

/*
This header file declares bus independent constants and data types as defined by the
FMI-LS-BUS layered standard specification (https://github.com/modelica/fmi-ls-bus).

It should be used when creating Network FMUs according to the FMI-LS-BUS layered standard.

Copyright (C) 2023-2026 Modelica Association Project "FMI"
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

#if !defined(FMI3_LS_BUS_CHECK_OPERATION_SIZE)
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)) || (defined(__cplusplus) && (__cplusplus >= 201103L))
#define FMI3_LS_BUS_CHECK_OPERATION_SIZE 1
#else
#define FMI3_LS_BUS_CHECK_OPERATION_SIZE 0
#endif
#endif


#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L) && (FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1)
#include <assert.h>
#endif

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
 * Common data types.
 */

/**
 * \brief Data type representing a boolean value.
 *
 * \note The only valid values are FMI3_LS_BUS_TRUE and FMI3_LS_BUS_FALSE.
 */
typedef fmi3UInt8 fmi3LsBusBoolean;

/**
 * \brief Defines the value 'TRUE' of the FMI-LS-BUS.
 */
#define FMI3_LS_BUS_TRUE ((fmi3UInt8)0x01)

/**
 * \brief Defines the value 'FALSE' of the FMI-LS-BUS.
 */
#define FMI3_LS_BUS_FALSE ((fmi3UInt8)0x00)

/**
 * \brief FMI virtual bus operation of type 'Format Error'.
 */
#define FMI3_LS_BUS_OP_FORMAT_ERROR ((fmi3LsBusOperationCode)0x0001)


/**
 * Common operation types.
 */
#pragma pack(1)

/**
 * \brief Data type representing the type of a bus operation.
 */
typedef fmi3UInt32 fmi3LsBusOperationCode;

/**
 * \brief Data type representing the length of a bus operation.
 */
typedef fmi3UInt32 fmi3LsBusOperationLength;

/**
 * \brief FMI virtual bus operation header structure.
 */
typedef struct
{
    fmi3LsBusOperationCode opCode;   /**< Type of the operation. */
    fmi3LsBusOperationLength length; /**< Total length of the operation. */
} fmi3LsBusOperationHeader;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
/* Checks the size of 'fmi3LsBusOperationHeader' to make sure the instruction #pragma pack(1) is taken into account. */
static_assert(sizeof(fmi3LsBusOperationHeader) == 8, "'fmi3LsBusOperationHeader' does not match the expected data size");
#endif

/**
 * \brief Data type representing a common length for data.
 */
typedef fmi3UInt16 fmi3LsBusDataLength;

/**
 * \brief Data type representing common data.
 */
typedef fmi3UInt8 fmi3LsBusData;

/**
 * \brief FMI virtual bus operation structure of type 'Format Error'.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;   /**< Operation header. */
    fmi3LsBusDataLength dataLength;    /**< Data length. */
    fmi3LsBusData data[];              /**< Data. */
} fmi3LsBusOperationFormatError;

#if FMI3_LS_BUS_CHECK_OPERATION_SIZE == 1
/* Checks the size of 'fmi3LsBusOperationFormatError' to make sure the instruction #pragma pack(1) is taken into account. */
static_assert(sizeof(fmi3LsBusOperationFormatError) == 10, "'fmi3LsBusOperationFormatError' does not match the expected data size");
#endif

#pragma pack()

#ifdef __cplusplus
} /* end of extern "C" { */
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif /* fmi3LsBus_h */
