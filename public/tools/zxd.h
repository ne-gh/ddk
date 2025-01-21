/*
 * Created on Thu Aug 22 09:29:13 CEST 2024
 *
 * Copyright (c) 2024 Amlal EL Mahrouss
 */

#pragma once

#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <filesystem>

#define kDriverSignedExt   ".zxd"
#define kDriverExt		   ".sys"
#define kSignedDriverMagic " ZXD"

#define kZXDPaddingSize (512)
#define kZXDMagicSize	(5)

namespace ZXD
{
	/// <summary>
	/// ZXD header.
	/// </summary>
	struct ZXD_HEADER final
	{
		char d_binary_padding[kZXDPaddingSize];
		// doesn't change.
		char		 d_binary_magic[kZXDMagicSize];
		std::int32_t d_binary_version;
		// can change.
		char		  d_binary_name[4096];
		std::uint64_t d_binary_checksum;
		std::uint64_t d_binary_size;
	};

	/***********************************************************************************/
	/* @brief These two handles the detection of a MZ header. */
	/***********************************************************************************/

	inline bool zxd_check_for_mz(const char* mz_blob) noexcept
	{
		return mz_blob[0] == 'M' &&
			   mz_blob[1] == 'Z';
	}

	inline bool zxd_check_for_mz(std::string mz_blob) noexcept
	{
		return mz_blob[0] == 'M' &&
			   mz_blob[1] == 'Z';
	}
} // namespace ZXD