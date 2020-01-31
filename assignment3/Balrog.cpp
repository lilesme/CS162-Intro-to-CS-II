#include "Balrog.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


/*********************************************************************
 ** Function:getSpecies
 ** Description: returns Balrog
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
string Balrog::getSpecies(){
   return "Balrog";
}
/*********************************************************************
 ** Function:getDamage
 ** Description: calls demon getDamage then does Balrog damage math
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int Balrog:: getDamage(){
   int damage=0;
   //Balrogs are so fast they get to attack twice
   damage=Demon::getDamage();
   int damage2= (rand()% strength)+1;
   cout<<"Balrog speed attack inflicts "<<damage2<<" additional damage points!"<<endl;
   damage=damage + damage2;

   return damage;

}
/*********************************************************************
 ** Function: Balrog()
 ** Description: cosntructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
Balrog::Balrog():Demon(){

   type=2;
   strength=100;
   hitpoints=200;
   cout<<"What is the name of your balrog?"<<endl;
   cin>>name;
   payoff=125;
   cost=25;
}
/*********************************************************************
 ** Function:void changehitpoints
 ** Description:subtracts damage from hitpoints
 ** Parameters: int type
 ** Pre-Conditions: none
 ** Post-Conditions:none 
 *********************************************************************/
void Balrog::changehitpoints(int damage){
   hitpoints=hitpoints-damage;

}
