a.out : main_multi.c multilib.h
	gcc -I./lib -L./lib main_multi.c -l_multi
	ldd a.out
	gcc -I./lib -L./lib main_multi.c -Wl,--rpath=/home/hwi/linux/4/make/multi_shared -l_multi
