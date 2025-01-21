/* -------------------------------------------

	Copyright Amlal EL Mahrouss.

	FILE: ddk.h
	PURPOSE: DDK Driver model base header.

------------------------------------------- */

#pragma once

#include <stdint.h>
#include <stddef.h>

#if defined(__cplusplus)
#define BOOL bool
#define YES true
#define NO false
#define DK_EXTERN extern "C" __declspec(dllexport)
#define nil		  nullptr
#undef NULL
#define NULL	 0
#define DK_FINAL final
#else
#define BOOL char
#define YES 1
#define NO 0
#define DK_EXTERN extern __declspec(dllexport)
#define nil		  ((void*)0)
#undef NULL
#define NULL ((void*)0)
#define DK_FINAL
#endif // defined(__cplusplus)

#ifndef __DDK__
#undef DK_EXTERN
#if defined(__cplusplus)
#define DK_EXTERN extern "C" __declspec(dllimport)
#else
#define DK_EXTERN __declspec(dllimport)
#endif
#endif

#define ATTRIBUTE(X) __attribute__((X))

#ifndef __MINOSKRNL__
#error !!! Do not include header in EL0/Ring 3 mode !!!
#endif // __MINOSKRNL__

struct DDK_STATUS_STRUCT;
struct DDK_OBJECT_MANIFEST;

/// \brief Object handle manifest.
struct DDK_OBJECT_MANIFEST DK_FINAL
{
	char*	p_name;
	int32_t p_kind;
	void*	p_object;
};

/// \brief DDK status ping structure.
struct DDK_STATUS_STRUCT DK_FINAL
{
	int32_t s_action_id;
	int32_t s_issuer_id;
	int32_t s_group_id;
	void*	s_object;
};

/// @brief Call Kernel procedure.
/// @param name the procedure name.
/// @param cnt number of elements in **dat**
/// @param dat data argument pointer.
/// @param sz sz of whole data argument pointer.
/// @return result of call
DK_EXTERN void* KernelCall(const char* name, int32_t cnt, void* dat, size_t sz);

/// @brief add a system call.
/// @param slot system call slot id.
/// @param slotFn, syscall slot.
DK_EXTERN void KernelAddSyscall(const int32_t slot, void (*slotFn)(void* a0));

/// @brief Allocates an heap ptr.
/// @param sz size of the allocated struct/type.
/// @return the pointer allocated or **nil**.
DK_EXTERN void* KernelAlloc(size_t sz);

/// @brief Frees an heap ptr.
/// @param pointer kernel pointer to free.
DK_EXTERN void KernelFree(void* the_ptr);

/// @brief Gets a Kernel object.
/// @param slot object id (can be 0)
/// @param name the property's name.
/// @return DDK_OBJECT_MANIFEST.
DK_EXTERN struct DDK_OBJECT_MANIFEST* KernelGetObject(const int slot, const char* name);

/// @brief Set a Kernel object.
/// @param slot object id (can be 0)
/// @param name the property's name.
/// @param ddk_pr pointer to a object's DDK_OBJECT_MANIFEST.
/// @return returned object.
DK_EXTERN void* KernelSetObject(const int32_t slot, const struct DDK_OBJECT_MANIFEST* ddk_pr);

/// @brief The highest API version of the DDK.
DK_EXTERN int32_t c_api_version_highest;

/// @brief The lowest API version of the DDK.
DK_EXTERN int32_t c_api_version_least;

/// @brief c_api_version_least+c_api_version_highest combined version.
DK_EXTERN int32_t c_api_version;
