#ifndef fmi3LsBus_h
#define fmi3LsBus_h

/*
This header file declares bus independent constants and data types as defined by the
fmi-ls-bus layered standard specification (https://github.com/modelica/fmi-ls-bus).

It should be used when creating Network FMUs according to the fmi-ls-bus layered standard.

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

#include "fmi3PlatformTypes.h"
#include <assert.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * FMI virtual bus operation which indicates an operation format error.
 */
#define FMI3_LS_BUS_OP_FORMAT_ERROR ((fmi3LsBusOperationType)0x0001)

/**
 * Data type for OP codes.
 */
typedef fmi3UInt8 fmi3LsBusOperationType;

/**
 * \brief FMI data type representing the length of payload data.
 */
typedef fmi3UInt32 fmi3LsBusOperationLength;


#pragma pack(1)
/**
 * Operation header data type.
 */
typedef struct
{
    fmi3LsBusOperationType type; /**< Operation type. */
    fmi3LsBusOperationLength length; /**< Total length of the operation. */
} fmi3LsBusOperationHeader;

#pragma pack()

/* Checks the size of 'fmi3LsBusOperationHeader' to make sure the instruction #pragma pack(1) is taken into account  */
static_assert(sizeof(fmi3LsBusOperationHeader) == 5, "'fmi3LsBusOperationHeader' does not match the expected data size");

#ifdef __cplusplus
} /* end of extern "C" { */
#endif


#endif /* fmi3LsBus_h */
