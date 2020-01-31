#include "Demon.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/*********************************************************************
 ** Function: getSpecies
 ** Description: returns Demon
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
string Demon::getSpecies(){
   return "Demon";
}
/*********************************************************************
 ** Function:getDamage
 ** Description: calls creature get damage then does demon math
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int Demon:: getDamage(){
   //Demons can inflict damage of 50 with a 5% chance
   int damage=0;
   Creature::getDamage();

   if((rand()%100)<5){
      damage=damage + 50;
      cout<<"Demonic attack inflicts 50 additional damage points!"<<endl;
   }
   return damage;

}
/*********************************************************************
 ** Function: Demon()
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
Demon::Demon():Creature(){
   type=-1;
   strength=0;
   hitpoints=0;
   name="";
   payoff=0;
   cost=0;

}
