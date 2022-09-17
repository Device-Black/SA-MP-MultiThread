# SA-MP-MultiThread
Multithreading by Fro1sha

```cpp
// Natives
native CreateThread(const pubname[]);
native CreateThreadEx(const pubname[]);
native DestroyThread(threadid);
native SleepThread(milliseconds);
native LockThread(threadid);
native UnLockThread(lockid);
```
```pawn
// Com CreateThread
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
	printf("tick(%d)...", threadid);
	SleepThread(1000);
}
```
```pawn
// Com CreateThreadEx
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

