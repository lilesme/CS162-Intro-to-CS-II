#include "Dwarf.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/*********************************************************************
 ** Function: getSpecies
 ** Description: returns Dwarf
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
string Dwarf::getSpecies(){
   return "Dwarf";
}
/*********************************************************************
 ** Function:getDamage
 ** Description: calls creature getDamage
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int Dwarf:: getDamage(){
   int damage=0;
   damage=Creature::getDamage();

   return damage;
}
/*********************************************************************
 ** Function: Dwarf()
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
Dwarf::Dwarf():Creature(){
   type=4;
   strength=25;
   hitpoints=125;
   cout<<"What is the name of your Dwarf?"<<endl;
   cin>>name;
   payoff=50;
   cost=10;
}
/*********************************************************************
 ** Function:void changehitpoints
 ** Description:subtracts damage from hitpoints
 ** Parameters: int damage
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Dwarf::changehitpoints(int damage){
   hitpoints=hitpoints-damage;

}
