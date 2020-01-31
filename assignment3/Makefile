PROGS := driver

all: $(PROGS)

driver: Driver.o Balrog.o Creature.o Cyberdemon.o Demon.o Dwarf.o Elf.o Human.o World.o
	g++ -g Driver.o Balrog.o Creature.o Cyberdemon.o Demon.o Dwarf.o Elf.o Human.o World.o

Driver.o: Driver.cpp
	g++ -c Driver.cpp

Balrog.o: Balrog.cpp Balrog.h
	g++ -c Balrog.cpp

Creature.o: Creature.cpp Creature.h
	g++ -c Creature.cpp

Cyberdemon.o: Cyberdemon.cpp Cyberdemon.h
	g++ -c Cyberdemon.cpp

Demon.o: Demon.cpp Demon.h
	g++ -c Demon.cpp

Dwarf.o: Dwarf.cpp Dwarf.h
	g++ -c Dwarf.cpp

Elf.o: Elf.cpp Elf.h
	g++ -c Elf.cpp

Human.o: Human.cpp Human.h
	g++ -c Human.cpp

World.o: World.cpp World.h
	g++ -c World.cpp

clean:
	rm -f $(PROGS) *.o *~

