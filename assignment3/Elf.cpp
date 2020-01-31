#include "Elf.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/*********************************************************************
 ** Function: getSpecies
 ** Description: returns elf
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
string Elf::getSpecies(){
   return "Elf";
}
/*********************************************************************
 ** Function: getDamage
 ** Description: cals creature getDamage then does math for elf
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int Elf:: getDamage(){
   //Elves inflict double magical damage with a 10% chance
   int damage=0;
   damage=Creature::getDamage();

   if((rand()%10)==0){
      cout<<"Magical attack inflicts"<<damage<<" additional damage points!"<<endl;
      damage=damage*2;
   }

   return damage;

}
/*********************************************************************
 ** Function: Elf()
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
Elf::Elf():Creature(){
   type=3;
   strength=50;
   hitpoints=150;
   cout<<"What is the name of your elf?"<<endl;
   cin>>name;
   payoff=75;
   cost=15;

}
/*********************************************************************
 ** Function:void changehitpoints
 ** Description: subtracts damage form hitpoints
 ** Parameters: int damage
 ** Post-Conditions: none
 ** Post-Conditions:none
 *********************************************************************/
void Elf::changehitpoints(int damage){
   hitpoints=hitpoints-damage;

}
