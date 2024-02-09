prog: main.o pers.o
	gcc  main.o pers.o -o prog -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g
main.o: main.c
	gcc -c main.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g

pers.o: pers.c
	gcc -c pers.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -g

