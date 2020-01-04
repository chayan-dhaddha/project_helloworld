all: auth fmtstring vtable

CFLAGS=-O3

vtable: vtable.cpp
	g++ -o vtable vtable.cpp
auth: auth.c
	gcc -o auth $(CFLAGS) auth.c
fmtstring: fmtstring.c
	gcc -D_FORTIFY_SOURCE=0 -o fmtstring $(CFLAGS) fmtstring.c
clean:
	rm -f *auth fmtstring vtable
