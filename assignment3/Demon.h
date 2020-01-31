#ifndef DEMON_H
#define DEMON_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Creature.h"

using namespace std;

class Demon: public Creature{
protected:
  string getSpecies(); //returns type of species
public:
  Demon();
  int getDamage(); //returns amount of damge this creature inflicts in one round of combat

};
#endif
