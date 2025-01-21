/* -------------------------------------------

	Copyright Amlal EL Mahrouss.

	File: dev.h
	Purpose: DDK device support.

------------------------------------------- */

#pragma once

#include <LibDDK/ddk.h>

struct _DDK_DEVICE;

/// @brief Kernel Device driver.
typedef struct _DDK_DEVICE DK_FINAL
{
	char d_name[255];					 // the device name. Could be /./DEVICE_NAME/
	void* (*d_read)(void* arg, int len); // read from device.
	void (*d_write)(void* arg, int len);
	void (*d_wait)(void);							 // write to device.
	struct _DDK_DEVICE* (*d_open)(const char* path); // open device.
	void (*d_close)(struct _DDK_DEVICE* dev);		 // close device.
} DDK_DEVICE, *DDK_DEVICE_PTR;

/// @brief Open a new device from path.
/// @param devicePath the device's path.
DK_EXTERN DDK_DEVICE_PTR KernelOpenDevice(const char* devicePath);

/// @brief Close any device.
/// @param device valid device.
DK_EXTERN BOOL KernelCloseDevice(DDK_DEVICE_PTR device);
