lib_multi.so.1.0.1 : multi.o
	ar rcs lib_multi.a multi.o
	gcc -shared -Wl,-soname,lib_multi.so.1 -o lib_multi.so.1.0.1 multi.o
	ln -s lib_multi.1.0.1 lib_multi.so.1
	ln -s lib_multi.1.0.1 lib_multi.so
multi.o : multi.c
	gcc -c multi.c
#lib_multi.a : multi.o
#	ar rcs lib_multi.a multi.o
clean :
	rm -f *multi.so* multi.o lib_multi.a
