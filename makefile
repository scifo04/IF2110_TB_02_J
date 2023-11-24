programmain: main/main.c
	gcc -o main/main main/main.c lib/pcolor/pcolor.c lib/account/account.c lib/affection/affection.c lib/datetime/datetime.c lib/listdin/listdin.c lib/liststatik/liststatik.c lib/matrix/matrix.c lib/queue/queue.c lib/draft/draft.c lib/datetime/time.c lib/teman/temanreq.c lib/wordmachine/charmachine.c lib/wordmachine/wordmachine.c lib/kicauan/kicauan.c lib/utas/utas.c lib/tree/tree.c -lm
	clear
	./main/main