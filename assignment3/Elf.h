#ifndef ELF_H
#define ELF_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "Creature.h"

using namespace std;

class Elf: public Creature{
   protected:
     string getSpecies();
   public:
     Elf();
     int getDamage();
     void changehitpoints(int);

};

#endif
