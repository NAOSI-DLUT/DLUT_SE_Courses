lex : lex.l todo.txt
	flex lex.l
	gcc -o alaze lex.yy.c -lfl
	./alaze todo.txt result.txt
	cat result.txt

clean : alaze result.txt lex.yy.c
	rm alaze result.txt lex.yy.c