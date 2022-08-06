// -------------------------------------------------------------------------------------*-

#include "main.h"

#include "Thread.h"

#include "Core.h"

// -------------------------------------------------------------------------------------*-

Core * core;

// -------------------------------------------------------------------------------------*-

Core::Core( void )
{
}

// -------------------------------------------------------------------------------------*-

Core::~Core( void )
{	
	/*
	if ( !locks.empty(  ) )
	{
		std::map<int, boost::mutex::scoped_lock *>::iterator l = locks.begin(  );
		while ( l != locks.end(  ) )
		{
			(* l).second->unlock(  );
			delete (* l).second;
			locks.erase( l );
		}
	}
	if ( !threads.empty(  ) )
	{
		std::map<int, S_Thread *>::iterator i = threads.begin(  );
		while ( i != threads.end(  ) )
		{
			delete (* i).second;
			threads.erase( i );
		}
	}
	*/
}

// -------------------------------------------------------------------------------------*-

int
	Core::CreateThread( const char * pub, AMX * amx, int type )
{
	int
		threadID = 1
	;

	for ( std::map<int, S_Thread *>::const_iterator i = threads.begin(  ); i != threads.end(  ); ++i )
	{
		if ( (* i).first != threadID )
		{
			break;
		}
		++threadID;
	}

	S_Thread * thread = new S_Thread( pub, amx, threadID, type );

	threads.insert( std::make_pair( threadID, thread ) );

	return threadID;
}

// -------------------------------------------------------------------------------------*-

int
	Core::DestroyThread( int threadid )
{
	std::map<int, S_Thread *>::iterator i = threads.find( threadid );

	if ( i != threads.end(  ) )
	{
		delete (* i).second;
		threads.erase( i );
		return 1;
	}
	return 0;
}

// -------------------------------------------------------------------------------------*-

int
	Core::LockThread( int threadid )
{
	std::map<int, S_Thread *>::iterator i = threads.find( threadid );

	if ( i != threads.end(  ) )
	{
		int
			lockID = 1
		;

		for ( std::map<int, boost::mutex::scoped_lock *>::const_iterator l = locks.begin(  ); l != locks.end(  ); ++l )
		{
			if ( (* i).first != lockID )
			{
				break;
			}
			++lockID;
		}


		boost::mutex::scoped_lock 
			* lock = new boost::mutex::scoped_lock( (* i).second->mutex )
		;

		locks.insert( std::make_pair( lockID, lock ) );

		return lockID;
	}
	return 0;
}

// -------------------------------------------------------------------------------------*-

int
	Core::UnLockThread( int lockid )
{
	std::map<int, boost::mutex::scoped_lock *>::iterator l = locks.find( lockid );

	if ( l != locks.end(  ) )
	{
		(* l).second->unlock(  );
		delete (* l).second;
		locks.erase( l );
		return 1;
	}
	return 0;
}

// -------------------------------------------------------------------------------------*-

PLUGIN_EXPORT void PLUGIN_CALL 
	ProcessTick(  )
{
	if ( !core->threadNeedDelete.empty(  ) )
	{
		core->DestroyThread( core->threadNeedDelete.front(  ) );
		core->threadNeedDelete.pop(  );
	}
}
// -------------------------------------------------------------------------------------*-