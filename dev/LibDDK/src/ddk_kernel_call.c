/* -------------------------------------------

	Copyright Amlal EL Mahrouss.

	Purpose: DDK Kernel call.

------------------------------------------- */

#include <LibDDK/ddk.h>
#include <stdarg.h>

/// @brief this is an internal call, do not use it.
DK_EXTERN ATTRIBUTE(naked) void* __KernelCallDispatch(const char* name, int32_t cnt, void* data, size_t sz);

/// @brief Interupt Kernel and call it's RPC.
/// @param KernelRpcName RPC name
/// @param cnt number of elements in **data** pointer.
/// @param data data pointer.
/// @param sz The size of the whole data pointer.
/// @retval void* Kernel call was successful.
/// @retval nil Kernel call failed, call KernelLastError(void)
DK_EXTERN void* KernelCall(const char* name, int32_t cnt, void* data, size_t sz)
{
	if (!name || *name == 0 || cnt == 0)
		return nil;

	return __KernelCallDispatch(name, cnt, data, sz);
}

/// @brief Add system call.
/// @param slot system call slot
/// @param slotFn, syscall slot.
DK_EXTERN void KernelAddSyscall(const int slot, void (*slotFn)(void* a0))
{
	KernelCall("ScAddEntry", slot, slotFn, 1);
}

/// @brief Get a Kernel object.
/// @param slot property id (always 0)
/// @param name the object's name.
/// @return Object manifest.
DK_EXTERN struct DDK_OBJECT_MANIFEST* KernelGetObject(const int slot, const char* name)
{
	struct DDK_OBJECT_MANIFEST* manifest = (struct DDK_OBJECT_MANIFEST*)KernelCall("ObjGetPtr", slot, (void*)name, 1);

	if (!manifest)
		return nil;

	return manifest;
}

/// @brief Set a Kernel object.
/// @param slot property id (always 0)
/// @param name the object's name.
/// @param ddk_pr pointer to a object's DDK_OBJECT_MANIFEST.
/// @return property's object.
DK_EXTERN void* KernelSetObject(const int slot, const struct DDK_OBJECT_MANIFEST* ddk_pr)
{
	return KernelCall("ObjSetSelf", slot, (void*)ddk_pr, 1);
}
