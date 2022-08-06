GPP = g++
OUTFILE = "plugins/Thread.so"

COMPILE_FLAGS = -m32 -fPIC -c -O3 -w -D LINUX -I ./

all:
	$(GPP) $(COMPILE_FLAGS) ./SDK/*.cpp
	$(GPP) $(COMPILE_FLAGS) ./*.cpp
	$(GPP) -m32 -O3 -fshort-wchar -shared -o $(OUTFILE) *.o -L./boost/ -lboost_thread
	-rm -f *~ *.o