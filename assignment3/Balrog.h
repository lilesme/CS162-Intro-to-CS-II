#ifndef BALROG_H
#define BALROG_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Demon.h"

using namespace std;


class Balrog: public Demon{
   protected:
     string getSpecies();
   public:
     Balrog();
     int getDamage();
     void changehitpoints(int);


};

#endif
