#ifndef CREATURE_H
#define CREATURE_H

#include <cstdlib>////
#include <string>
#include <iostream>

using namespace std;

class Creature{
   protected:
     int type;//0 human, 1 cyber demon, 2 balrog, 3 elf, 4 dwarf
     int strength; //how much damage we can inflict
     int hitpoints;//how much damage we can sustain
     string name;//the name of the Creature
     double payoff;//how much you win for a Creature
     double cost; //how much it costs to buy this creature
     string getSpecies(); //returns type of species
   public:
     Creature();
     //getters/setters
     int get_strength(); //return strength
     int get_hitpoints(); //return hitpoints
     string get_name(); //return name
     double get_payoff(); //return playoff
     double get_cost(); //return cost;
     void set_strength(int);
     void set_hitpoints(int);
     void set_name(string);
     void set_payoff(int);
     void set_cost(int);
     //other functions
     int getDamage(); //returns amount of damage this creature inflicts in one round of combat


};

#endif
