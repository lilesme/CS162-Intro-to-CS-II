PROGS := driver


all: $(PROGS)

driver: driver.o cart.o librarian.o library.o patron.o
	g++ -g driver.o cart.o librarian.o library.o patron.o -o driver

driver.o: driver.cpp driver.h
	g++ -c driver.cpp

cart.o: cart.cpp cart.h
	g++ -c cart.cpp

librarian.o: librarian.cpp librarian.h
	g++ -c librarian.cpp

library.o: library.cpp library.h
	g++ -c library.cpp


clean:
	rm -f $(PROGS) *.o *~
