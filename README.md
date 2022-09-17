# SA-MP-MultiThread
Multithreading by Fro1sha

Natives:```pawn
native CreateThread(const pubname[]);
native CreateThreadEx(const pubname[]);
native DestroyThread(threadid);
native SleepThread(milliseconds); // Use em threads (public)
native LockThread(threadid); // Sincronizar e retornar id do bloqueio
native UnLockThread(lockid);
```
Exemplos:<br />
<li>CreateThread:</li>```pawn
new tickid;

public OnGameModeInit()
{
	tickid = CreateThread("MyFunction");
}

public OnGameModeExit()
{
	DestroyThread(tickid);
}

public MyFunction(threadid)
{
	printf("tick(%d)...", threadid );
	SleepThread(1000);
}
```� CreateThreadEx:```pawn
new bool:active;
new tickid;

public OnGameModeInit()
{
	tickid = CreateThreadEx("MyFunction");
}

public OnGameModeExit()
{
	active = false;
}

public MyFunction(threadid)
{
	active = true;
	
	while (active)
	{
		printf("tick(%d)...", threadid );
		SleepThread(1000);
	}
}
```


