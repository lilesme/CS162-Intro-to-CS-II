
/*********************************************************************
 ** Program: Creature.cpp
 ** Author: Megan Liles
 ** Date: 05/02/2017
 ** Description: Wierd Animal sci-Fi game
 ** Input: keys/numbers/letters
 ** Output: phrases
 *********************************************************************/
#include "Creature.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

/*********************************************************************
 ** Function: getSpecies
 ** Description: returns Creature
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
string Creature::getSpecies(){
   return "Creature";
}
/*********************************************************************
 ** Function: getDamage
 ** Description: does creature damage math
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int Creature::getDamage(){
   int damage;
   damage=(rand()%strength)+1;
   cout<<getSpecies()<<" attacks for "<<damage<<" points!"<<endl;

   return damage;

}
/*********************************************************************
 ** Function:Creature()
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
Creature::Creature(){
   type=0;
   strength=0;
   hitpoints=0;
   name="";
   payoff=0;
   cost=0;
}
/*********************************************************************
 ** Function: int get_strength
 ** Description: access strenght
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int Creature::get_strength(){

   return strength;
}
/*********************************************************************
 ** Function: int get_hitpoints
 ** Description: access hitpoints
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int Creature::get_hitpoints(){

   return hitpoints;
}
/*********************************************************************
 ** Function: string get_name
 ** Description: access name
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
string Creature::get_name(){

   return name;
}
/*********************************************************************
 ** Function: double get_payoff
 ** Description: access payoff
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
double Creature::get_payoff(){

   return payoff;
}
/*********************************************************************
 ** Function: double get_cost
 ** Description: access cost
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
double Creature::get_cost(){

   return cost;
}
/*********************************************************************
 ** Function: void set_strength
 ** Description: sets strenght
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Creature::set_strength(int s){
   strength=s;
}
/*********************************************************************
 ** Function: void set_hitpoints
 ** Description:sets hitpoints
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Creature::set_hitpoints(int h){
   hitpoints=h;
}
/*********************************************************************
 ** Function: void set_name
 ** Description: sets name
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Creature::set_name(string n){
   name=n;
}
/*********************************************************************
 ** Function: void set_payoff
 ** Description: sets payoff
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Creature::set_payoff(int p){
   payoff=p;
}
/*********************************************************************
 ** Function: void set_cost
 ** Description: sets cost
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void Creature::set_cost(int c){
   cost=c;
}
