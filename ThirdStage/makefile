debug_flags=-Wall -ggdb
standard_flags=-std=c++17
libs=-lncurses -lpthread
source=src/
objects=bin/obj/
program=bin/

main: clean window.o vegetable.o shoppingList.o customer.o main.o
	@g++ ${objects}window.o ${objects}vegetable.o ${objects}shoppingList.o ${objects}customer.o ${objects}main.o -o ${program}groceryStore ${libs} ${standard_flags} ${debug_flags}

main.o: ${source}main.cpp
	@g++ ${source}main.cpp -c -o ${objects}main.o ${libs} ${standard_flags} ${debug_flags}

customer.o: ${source}customer.cpp
	@g++ ${source}customer.cpp -c -o ${objects}customer.o ${libs} ${standard_flags} ${debug_flags}

shoppingList.o: ${source}shoppingList.cpp
	@g++ ${source}shoppingList.cpp -c -o ${objects}shoppingList.o ${libs} ${standard_flags} ${debug_flags}

vegetable.o: ${source}vegetable.cpp
	@g++ ${source}vegetable.cpp -c -o ${objects}vegetable.o ${libs} ${standard_flags} ${debug_flags}

window.o: ${source}window.cpp
	@g++ ${source}window.cpp -c -o ${objects}window.o ${libs} ${standard_flags} ${debug_flags}

clean:
	@rm -f ${objects}* bin/groceryStore


