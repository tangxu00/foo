#-----------------------start of makefile------------------------#
 
saolei:main.o init.o ui.o draw.o process.o control.o
	gcc -o saolei  main.o init.o ui.o draw.o process.o control.o -lcurses
main.o:main.c
	gcc -c main.c -lcurses
init.o:init.c init.h 
	gcc -c init.c -lcurses
ui.o:ui.c ui.h
	gcc -c ui.c -lcurses
draw.o:draw.c draw.h
	gcc -c draw.c -lcurses
process.o:process.c process.h
	gcc -c process.c -lcurses
control.o:control.c control.h
	gcc -c control.c -lcurses
clean:
	rm main.o init.o ui.o draw.o process.o control.o


#-----------------------end of makefile---------------------------#
