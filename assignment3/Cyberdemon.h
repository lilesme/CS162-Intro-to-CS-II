#ifndef CYBERDEMON_H
#define CYBERDEMON_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Demon.h"

using namespace std;

class Cyberdemon: public Demon{
   protected:
     string getSpecies();
   public:
     Cyberdemon();
     int getDamage();
     void changehitpoints(int);
};

#endif
