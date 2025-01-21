/* -------------------------------------------

	Copyright Amlal EL Mahrouss.

	Purpose: DDK Strings.

------------------------------------------- */

#pragma once

#include <LibDDK/ddk.h>

/// @brief DDK equivalent of POSIX's string.h
/// @file KernelString.h

DK_EXTERN size_t KernelStringLength(const char* in);
DK_EXTERN int	 KernelStringCopy(char* dst, const char* src, size_t len);
