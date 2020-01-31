CC = g++
exe_file = lab2
$(exe_file): lab2.o webpage.o
	$(CC) lab2.o webpage.o -o $(exe_file)
lab2.o: lab2.cpp
	$(CC) -c lab2.cpp
webpage.o: webpage.cpp
	$(CC) -c webpage.cpp

clean:
	rm -f *.out*.o$(exe_file)
