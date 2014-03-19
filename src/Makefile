# flags to pass compiler
OTHER_FLAGS =

# Standard all target
all: Graphs.o Parser.o

Graphs.o: Graphs.cpp Graphs.hpp
	g++ $(OTHER_FLAGS) -Wall -c Graphs.cpp

Parser.o: Parser.cpp Parser.hpp
	g++ $(OTHER_FLAGS) -Wall -c Parser.cpp

clean:
	rm -f *.o