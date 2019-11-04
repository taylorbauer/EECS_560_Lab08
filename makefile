Lab08: main.o Menu.o MinLeftistHeap.o Node.o
	g++ -std=c++11 main.o Menu.o MinLeftistHeap.o Node.o -o Lab08
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Menu.o: Menu.cpp Menu.h
	g++ -std=c++11 -c Menu.cpp
MinLeftistHeap.o: MinLeftistHeap.cpp MinLeftistHeap.h
	g++ -std=c++11 -c MinLeftistHeap.cpp
Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp
clean:
	rm -f test *.o