programmain: main/main.c
	gcc -o lib/account/account_main lib/account/account_main.c lib/account/account.c lib/affection/affection.c lib/teman/temanreq.c lib/pcolor/pcolor.c lib/wordmachine/charmachine.c lib/wordmachine/wordmachine.c -lm
	clear
	./lib/account/account_main
	gcc -o lib/affection/affection_main lib/affection/affection_main.c lib/affection/affection.c -lm
	clear
	./lib/affection/affection_main
	gcc -o lib/datetime/datetime_main lib/datetime/datetime_main.c lib/datetime/datetime.c lib/datetime/time.c -lm
	clear
	./lib/datetime/datetime_main
	gcc -o lib/wordmachine/charword_main lib/wordmachine/charword_main.c lib/wordmachine/charmachine.c lib/wordmachine/wordmachine.c -lm
	clear
	./lib/wordmachine/charword_main
	gcc -o lib/draft/draft_main lib/draft/draft_main.c lib/draft/draft.c lib/kicauan/kicauan.c lib/account/account.c lib/wordmachine/wordmachine.c lib/wordmachine/charmachine.c lib/affection/affection.c lib/datetime/datetime.c lib/datetime/time.c lib/utas/utas.c lib/tree/tree.c lib/pcolor/pcolor.c lib/teman/temanreq.c -lm
	clear
	./lib/draft/draft_main
	gcc -o lib/teman/temanreq_main lib/teman/temanreq_main.c lib/teman/temanreq.c lib/wordmachine/wordmachine.c lib/wordmachine/charmachine.c lib/affection/affection.c -lm
	clear
	./lib/teman/temanreq_main
	gcc -o main/main main/main.c lib/pcolor/pcolor.c lib/account/account.c lib/affection/affection.c lib/datetime/datetime.c lib/draft/draft.c lib/datetime/time.c lib/teman/temanreq.c lib/wordmachine/charmachine.c lib/wordmachine/wordmachine.c lib/kicauan/kicauan.c lib/utas/utas.c lib/tree/tree.c -lm
	clear
	./main/main