program1: main/main.c
	gcc -o main/main main/main.c lib/boolean/boolean.h lib/account/account.c lib/datetime/datetime.c lib/listdin/listdin.c lib/listlinier/listlinier.c lib/liststatik/liststatik.c lib/matrix/matrix.c lib/queue/queue.c lib/stack/stack.c lib/time/time.c lib/wordmachine/charmachine.c lib/wordmachine/wordmachine.c -lm
	clear
	./main/main