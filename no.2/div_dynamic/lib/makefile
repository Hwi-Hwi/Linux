lib_div.so.1.0.1 : div.o
	ar rcs lib_div.a div.o
	gcc -shared -Wl,-soname,lib_div.so.1 -o lib_div.so.1.0.1 div.o
	ln -s lib_div.1.0.1 lib_div.so.1
	ln -s lib_div.1.0.1 lib_div.so
div.o : div.c
	gcc -c div.c
#lib_multi.a : multi.o
#	ar rcs lib_multi.a multi.o
clean :
	rm -f *div.so* div.o lib_div.a
