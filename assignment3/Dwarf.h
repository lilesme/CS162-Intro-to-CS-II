#ifndef DWARF_H
#define DWARF_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "Creature.h"

using namespace std;

class Dwarf:public Creature{
   protected:
     string getSpecies(); //returns type of species
   public:
     Dwarf();
     int getDamage();
     void changehitpoints(int);
    

};

#endif
