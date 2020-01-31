#include "Cyberdemon.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/*********************************************************************
 ** Function:getSpecies
 ** Description: returns Cyberdemon
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
string Cyberdemon::getSpecies(){
   return "Cyberdemon";
}
/*********************************************************************
 ** Function:getDamage
 ** Description:calls demon getDamage
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int Cyberdemon:: getDamage(){
   int damage=0;
   damage=Demon::getDamage();

   return damage;
}
/*********************************************************************
 ** Function:Cyberdemon()
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
Cyberdemon::Cyberdemon():Demon(){
   type=1;
   strength=75;
   hitpoints=175;
   cout<<"What is the name of your cyberdemon?"<<endl;
   cin>>name;
   payoff=100;
   cost=20;

}
/*********************************************************************
 ** Function:void changehitpoints
 ** Description:subtracts damage from hitpoints
 ** Parameters: int type
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Cyberdemon::changehitpoints(int damage){
   hitpoints=hitpoints-damage;

}
