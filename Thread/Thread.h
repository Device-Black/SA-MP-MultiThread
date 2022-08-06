#pragma once
// -------------------------------------------------------------------------------------*-

class
	S_Thread
{
public:
						S_Thread			( const char * pub, AMX * amx, int threadid, int type = 1 );
						~S_Thread			( void );

	void				StartThread			( void );
	void				StopThread			( void );	

	boost::mutex		mutex;

private:
	void				DoWorkThread		( void );

	int					thrtype;

	int					ID;
	AMX					* pAmx;	

	boost::thread		* thr;
	bool				canceled;

	std::string			pubname;
	int					amx_idx;
};

// -------------------------------------------------------------------------------------*-