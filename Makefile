OBJECTS = fifteen.o board.o solver.o

fifteen: $(OBJECTS)
	g++ -O2 -o Fifteen $(OBJECTS)

fifteen.o: fifteen.cpp

%.o: %.hpp

debug: $(OBJECTS)
	g++ -g -o Fifteen $(OBJECTS)


clean:
	rm -rf *.o *.h.gch fifteen
