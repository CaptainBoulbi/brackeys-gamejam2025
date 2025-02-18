all:
	gcc -Wall -Wextra main.c -o game -Ilib -l:libraylib.a -lm

win:
	x86_64-w64-mingw32-gcc -Wall -Wextra main.c -o game -Ilib -Llib -l:windows-libraylib.a -lgdi32 -lwinmm

run: all
	./game
