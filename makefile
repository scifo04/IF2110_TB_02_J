programmain: main/main.c
	gcc -o lib/account/account_main lib/account/account_main.c lib/account/account.c lib/pcolor/pcolor.c lib/wordmachine/charmachine.c lib/wordmachine/wordmachine.c -lm
	clear
	./lib/account/account_main
	gcc -o lib/affection/affection_main lib/affection/affection_main.c lib/affection/affection.c -lm
	clear
	./lib/affection/affection_main
	gcc -o lib/datetime/datetime_main lib/datetime/datetime_main.c lib/datetime/datetime.c lib/time/time.c -lm
	clear
	./lib/datetime/datetime_main
	gcc -o lib/listdin/listdin_main lib/listdin/listdin_main.c lib/listdin/listdin.c -lm
	clear
	./lib/listdin/listdin_main
	gcc -o lib/listlinier/listlinier_main lib/listlinier/listlinier_main.c lib/listlinier/listlinier.c -lm
	clear
	./lib/listlinier/listlinier_main
	gcc -o lib/liststatik/liststatik_main lib/liststatik/liststatik_main.c lib/liststatik/liststatik.c -lm
	clear
	./lib/liststatik/liststatik_main
	gcc -o lib/matrix/matrix_main lib/matrix/matrix_main.c lib/matrix/matrix.c -lm
	clear
	./lib/matrix/matrix_main
	gcc -o lib/pcolor/pcolor_driver lib/pcolor/pcolor_driver.c lib/pcolor/pcolor.c -lm
	clear
	./lib/pcolor/pcolor_driver
	gcc -o lib/queue/queue_main lib/queue/queue_main.c lib/queue/queue.c -lm
	clear
	./lib/queue/queue_main
	gcc -o lib/stack/stack_main lib/stack/stack_main.c lib/stack/stack.c -lm
	clear
	./lib/stack/stack_main
	gcc -o lib/wordmachine/charword_main lib/wordmachine/charword_main.c lib/wordmachine/charmachine.c lib/wordmachine/wordmachine.c -lm
	clear
	./lib/wordmachine/charword_main
	gcc -o main/main main/main.c lib/boolean/boolean.h lib/pcolor/pcolor.c lib/account/account.c lib/affection/affection.c lib/datetime/datetime.c lib/listdin/listdin.c lib/listlinier/listlinier.c lib/liststatik/liststatik.c lib/matrix/matrix.c lib/queue/queue.c lib/stack/stack.c lib/time/time.c lib/wordmachine/charmachine.c lib/wordmachine/wordmachine.c -lm
	clear
	./main/main