OBJECTS = fifteen.o board.o solver.o

fifteen: $(OBJECTS)
	g++ -o fifteen $(OBJECTS)

fifteen.o: fifteen.cpp

%.o: %.hpp

clean:
	rm -rf *.o *.h.gch fifteen
