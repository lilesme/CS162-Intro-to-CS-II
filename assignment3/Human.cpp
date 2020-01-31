#include "Human.h"
#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

/*********************************************************************
 ** Function: getSpecies
 ** Description: returns Human
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
string Human::getSpecies(){
   return "Human";
}
/*********************************************************************
 ** Function: getDamage
 ** Description: calls the creature get damage
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int Human:: getDamage(){
   int damage=0;
   damage=Creature::getDamage();
   return damage;
}
/*********************************************************************
 ** Function: Creature()
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
Human::Human():Creature(){
   type=0;
   strength=5;
   hitpoints=105;
   cout<<"What is the name of your human?"<<endl;
   cin>>name;
   payoff=25;
   cost=5;

}
/*********************************************************************
 ** Function:void changehitpoints
 ** Description: subtracts damage from hitpoints
 ** Parameters: int damage
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Human::changehitpoints(int damage){
   hitpoints=hitpoints-damage;

}
