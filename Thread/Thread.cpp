// -------------------------------------------------------------------------------------*-

#include "main.h"

#include "Core.h"

#include "Thread.h"

// -------------------------------------------------------------------------------------*-

S_Thread::S_Thread( const char * pub, AMX * amx, int threadid, int type ) 
: 
	pubname( pub ),
	pAmx( amx ),
	thr( NULL ),
	ID( threadid ),
	thrtype( type ),
	canceled( true )
{
	StartThread(  );
}

// -------------------------------------------------------------------------------------*-

S_Thread::~S_Thread( void )
{
	StopThread(  );
}

// -------------------------------------------------------------------------------------*-

void
	S_Thread::StartThread( void )
{	
	if ( canceled )
	{
		canceled = false;

		boost::thread thr( boost::bind( &S_Thread::DoWorkThread, this ) );
	}
}

// -------------------------------------------------------------------------------------*-

void
	S_Thread::StopThread( void )
{
	if ( !canceled )
	{
		canceled = true;

		thr->interrupt(  );
		thr->join(  );
	}
}

// -------------------------------------------------------------------------------------*-

void
	S_Thread::DoWorkThread( void )
{
	switch ( thrtype )
	{
	case 1:
		{
			while ( !canceled )
			{
				if ( !amx_FindPublic( pAmx, pubname.c_str(  ), &amx_idx ) )
				{			
					amx_Push( pAmx, ID );
					amx_Exec( pAmx, NULL, amx_idx );
				}
			}
		}
		break;
	case 2:
		{
			if ( !canceled )
			{
				if ( !amx_FindPublic( pAmx, pubname.c_str(  ), &amx_idx ) )
				{			
					amx_Push( pAmx, ID );
					amx_Exec( pAmx, NULL, amx_idx );
				}

				canceled = true;
				core->threadNeedDelete.push( ID );
			}
		}
		break;
	}
}

// -------------------------------------------------------------------------------------*-