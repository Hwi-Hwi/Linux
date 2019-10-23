lib_add_sub.a : add.o sub.o
	ar rcs lib_add_sub.a add.o sub.o
add.o : add.c
	gcc -c add.c
sub.o : sub.c
	gcc -c sub.c
clean :
	rm -f lib_add_sub.a add.o sub.o
