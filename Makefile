all: main.o core.o menu.o
	g++ main.o core.o menu.o -o Steam

main.o: main.cpp
	g++ -c main.cpp

core.o: core.cpp
	g++ -c core.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

clean:
	rm -rf *.o Steam 
