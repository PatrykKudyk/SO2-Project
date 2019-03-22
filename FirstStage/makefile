debugFlags=-Wall -ggdb
standardFlag=-std=c++17
libs=-lncurses
source=src/
objects=bin/obj/
program=bin/

main: ball.o window.o main.o
	@g++ ${objects}main.o ${objects}ball.o ${objects}window.o -o ${program}happyBalls ${libs} ${standardFlag} ${debugFlags}

main.o: ${source}main.cpp
	@g++ ${source}main.cpp -c -o ${objects}main.o ${libs} ${standardFlag} ${debugFlags}

window.o: ${source}window.cpp
	@g++ ${source}window.cpp -c -o ${objects}window.o ${libs} ${standart_flag} ${debug_flags}  

ball.o: ${source}ball.cpp
	@g++ ${source}ball.cpp -c -o ${objects}ball.o ${libs} ${standart_flag} ${debug_flags} 

#clean:
#	@rm -f ${objects}* bin/hapyBalls


