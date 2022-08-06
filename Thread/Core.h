#pragma once
// -------------------------------------------------------------------------------------*-

#include "Thread.h"

// -------------------------------------------------------------------------------------*-

class
	Core
{
public:
				Core				( void );
				~Core				( void );

	int			CreateThread		( const char * pub, AMX * amx, int type = 1 );	
	int			DestroyThread		( int threadid );

	int			LockThread			( int threadid );
	int			UnLockThread		( int lockid );

	std::queue<int>
		threadNeedDelete;
private:

	std::map<int, S_Thread *>
		threads;
	std::map<int, boost::mutex::scoped_lock *>
		locks;
	
};

// -------------------------------------------------------------------------------------*-

extern Core * core;

// -------------------------------------------------------------------------------------*-