#pragma once
// -------------------------------------------------------------------------------------*-

#define PLUGIN_VERSION			"0.1.6"

// -------------------------------------------------------------------------------------*-

#ifdef WIN32	
	#include <windows.h>
#endif

#include <time.h>
#include <malloc.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include <string>
#include <limits>
#include <set>
#include <map>
#include <vector>
#include <queue>

#include <boost/thread/thread.hpp>

#include "SDK/amx/amx.h"
#include "SDK/plugincommon.h"

// -------------------------------------------------------------------------------------*-

typedef void
	(* logprintf_t)(char *, ...);

extern logprintf_t
	logprintf;

// -------------------------------------------------------------------------------------*-