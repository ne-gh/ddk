/* -------------------------------------------

	Copyright Amlal EL Mahrouss.

	FILE: sms.h
	PURPOSE: Standard DDK message struct.

------------------------------------------- */

#pragma once

#include <LibDDK/ddk.h>

#define DDK_SMS_MAX_SZ (256U)

/// \brief Simple Message Struct.
/// \file sms.h

struct DDK_SMS_STRUCT DK_FINAL
{
	char	s_msg[DDK_SMS_MAX_SZ];
	int32_t s_type;
	int64_t s_sender;
	int64_t s_receiver;
};

/// \brief Send a SMS with body of len.
BOOL KernelSendSMS(struct DDK_SMS_STRUCT* header, const char* body, const size_t len);

/// \biref SMS port type.
typedef int32_t (*SMSFunc)(struct DDK_SMS_STRUCT* sms);

/// \biref Bind SMS to namespace.
BOOL KernelBindSMS(const char* ns, SMSFunc function);

/// \biref Unbind SMS to namespace.
BOOL KernelUnbindSMS(const char* ns);
