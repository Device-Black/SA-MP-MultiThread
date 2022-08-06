// -------------------------------------------------------------------------------------*-

#include "main.h"

#include "Core.h"
#include "Thread.h"

#include "Natives.h"

// -------------------------------------------------------------------------------------*-

cell AMX_NATIVE_CALL // native CreateThread( const pubname[] );
	Natives::n_CreateThread( AMX * amx, cell * params )
{		
	char
		* name
	;

	amx_StrParam( amx, params[ 1 ], name );

	if ( name )
	{
		return core->CreateThread( name, amx );
	}
	return 0;
}

// -------------------------------------------------------------------------------------*-

cell AMX_NATIVE_CALL // native CreateThreadEx( const pubname[] );
	Natives::n_CreateThreadEx( AMX * amx, cell * params )
{		
	char
		* name
	;

	amx_StrParam( amx, params[ 1 ], name );

	if ( name )
	{
		return core->CreateThread( name, amx, 2 );
	}
	return 0;
}

// -------------------------------------------------------------------------------------*-

cell AMX_NATIVE_CALL // native DestroyThread( threadid );
	Natives::n_DestroyThread( AMX * amx, cell * params )
{		
	return core->DestroyThread( params[ 1 ] );
}

// -------------------------------------------------------------------------------------*-

cell AMX_NATIVE_CALL // native SleepThread( milliseconds );
	Natives::n_SleepThread( AMX * amx, cell * params )
{		
	boost::this_thread::sleep ( 
        boost::get_system_time(  ) + 
        boost::posix_time::milliseconds( params[ 1 ] ) 
	);
	return 1;
}

// -------------------------------------------------------------------------------------*-

cell AMX_NATIVE_CALL // native LockThread( threadid );
	Natives::n_LockThread( AMX * amx, cell * params )
{			
	return core->LockThread( params[ 1 ] );
}

// -------------------------------------------------------------------------------------*-

cell AMX_NATIVE_CALL // native UnLockThread( lockdid );
	Natives::n_UnLockThread( AMX * amx, cell * params )
{			
	return core->UnLockThread( params[ 1 ] );
}

// -------------------------------------------------------------------------------------*-