# flags to pass compiler
OTHER_FLAGS =

# Standard all target
all: myProc

myProc: main.o ../src/Graphs.o ../src/Parser.o
	g++ -o Data_Trends main.o ../src/Graphs.o ../src/Parser.o

main.o: main.cpp
	g++ $(OTHER_FLAGS) -Wall -c main.cpp

clean:
	rm -f *.o Data_Trends