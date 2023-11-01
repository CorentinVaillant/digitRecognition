CC=g++
sources=main.cpp Matrice.h NeuralNet.h
objects=$($(sources:.h=.o):.cpp=.o)

exeName=main.exe
flag=-Wall #-fsanitize=address

$(objects) :
	$(CC) -c $(sources) -o $(objects) $(flag)

main : $(objects:.h=.o)
	$(CC) -o bin/$(exeName) bin/$(objects) $(flag)

main.o : $(sources)
	$(CC) -c main.cpp -o bin/main.o $(flag)

