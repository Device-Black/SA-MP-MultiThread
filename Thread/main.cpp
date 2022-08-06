// -------------------------------------------------------------------------------------*-

#include "main.h"

#include "Core.h"

#include "Natives.h"

using namespace Natives;

// -------------------------------------------------------------------------------------*-

logprintf_t
	logprintf;

extern void *
	pAMXFunctions;

// -------------------------------------------------------------------------------------*-

PLUGIN_EXPORT unsigned int PLUGIN_CALL
	Supports(  )
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES | SUPPORTS_PROCESS_TICK;
}

// -------------------------------------------------------------------------------------*-

PLUGIN_EXPORT bool PLUGIN_CALL
	Load( void ** ppData )
{			
	pAMXFunctions	= ppData[ PLUGIN_DATA_AMX_EXPORTS ];
	logprintf		= (logprintf_t)ppData[ PLUGIN_DATA_LOGPRINTF ];

	core = new Core;

	logprintf( "\n" );
	logprintf( "______________________________________\n" );
	logprintf( " SA:MP Thread plugin v"PLUGIN_VERSION" loaded" );
	logprintf( "______________________________________\n" );
	logprintf( " By: Fro (c) Copyright <TBG> 2009-2011");
	logprintf( "______________________________________\n" );	

	return true;
}

// -------------------------------------------------------------------------------------*-

PLUGIN_EXPORT void PLUGIN_CALL
	Unload(  )
{
	delete core;

	logprintf( "\n" );
	logprintf( "______________________________________\n" );
	logprintf( " SA:MP Thread plugin v"PLUGIN_VERSION" unloaded" );
	logprintf( "______________________________________\n" );
}

// -------------------------------------------------------------------------------------*-

AMX_NATIVE_INFO
	natives[  ] =
{
	{	"CreateThread", 		n_CreateThread		},
	{	"CreateThreadEx", 		n_CreateThreadEx	},
	{	"DestroyThread", 		n_DestroyThread		},
	{	"SleepThread", 			n_SleepThread 		},
	{	"LockThread", 			n_LockThread 		},
	{	"UnLockThread", 		n_UnLockThread 		},
	
	{ 0, 0 }
};

// -------------------------------------------------------------------------------------*-

PLUGIN_EXPORT int PLUGIN_CALL
	AmxLoad( AMX * amx )
{		
	return amx_Register( amx, natives, -1 );
}

// -------------------------------------------------------------------------------------*-

PLUGIN_EXPORT int PLUGIN_CALL
	AmxUnload( AMX * amx )
{
	return AMX_ERR_NONE;
}

// -------------------------------------------------------------------------------------*-