CXX = g++
CXXFLAGS = -Wall -g

kvstore: main.cpp REPL.o KeyValueStore.o RB_TREE.h
	$(CXX) $(CXXFLAGS) main.cpp REPL.o KeyValueStore.o RB_TREE.h -o main

REPL.o: REPL.cpp REPL.h KeyValueStore.o RB_TREE.h
	$(CXX) $(CXXFLAGS) -c REPL.cpp

KeyValueStore.o: KeyValueStore.cpp KeyValueStore.h RB_Tree.h
	$(CXX) $(CXXFLAGS) -c KeyValueStore.cpp

RB_TREE.o: RB_Tree.h
	$(CXX) $(CXXFLAGS) -c RB_TREE.h

run:
	./main

val:
	valgrind ./main