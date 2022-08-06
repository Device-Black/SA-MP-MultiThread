#pragma once
// -------------------------------------------------------------------------------------*-

namespace
	Natives
{
	cell AMX_NATIVE_CALL	n_CreateThread			( AMX * amx, cell * params );
	cell AMX_NATIVE_CALL	n_CreateThreadEx		( AMX * amx, cell * params );
	cell AMX_NATIVE_CALL 	n_DestroyThread			( AMX * amx, cell * params );
	cell AMX_NATIVE_CALL 	n_SleepThread			( AMX * amx, cell * params );
	cell AMX_NATIVE_CALL 	n_LockThread			( AMX * amx, cell * params );
	cell AMX_NATIVE_CALL 	n_UnLockThread			( AMX * amx, cell * params );
}

// -------------------------------------------------------------------------------------*-