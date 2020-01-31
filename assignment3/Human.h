#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "Creature.h"

using namespace std;

class Human: public Creature{
   protected:
     string getSpecies(); //returns type of species
   public:
     Human();
     int getDamage();
     void changehitpoints(int);


};

#endif
