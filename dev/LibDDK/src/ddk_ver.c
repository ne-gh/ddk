/* -------------------------------------------

	Copyright Amlal EL Mahrouss.

	Purpose: DDK version symbols.

------------------------------------------- */

#include <LibDDK/ddk.h>

#ifndef kDDKVersionHighest
#define kDDKVersionHighest 1
#endif // !cDDKVersionHighest

#ifndef kDDKVersionLowest
#define kDDKVersionLowest 1
#endif // !cDDKVersionLowest

#ifndef kDDKVersion
#define kDDKVersion 1
#endif // !cDDKVersion

int32_t c_api_version_highest = kDDKVersionHighest;
int32_t c_api_version_least	  = kDDKVersionLowest;
int32_t c_api_version		  = kDDKVersion;
