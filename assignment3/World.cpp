#include "World.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
//CONSTRUCTORS/BIG THREE
/*********************************************************************
 ** Function: World()
 ** Description: Default Constructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
World::World(){
   c_array=NULL;
   b_array=NULL;
   h_array=NULL;
   e_array=NULL;
   d_array=NULL;
   money=0;
   num_cyberdemons=0;
   num_balrogs=0;
   num_elves=0;
   num_humans=0;
   num_dwarves=0;

}
/*********************************************************************
 ** Function: ~World()
 ** Description: Destructor
 ** Parameters: none
 ** Pre-Conditions:none
 ** Post-Conditions:none
 *********************************************************************/
World::~World(){
   if(c_array!=NULL){
      delete [] c_array;
   }
   if(b_array!=NULL){
      delete [] b_array;
   }
   if(h_array!=NULL){
      delete [] h_array;
   }
   if(e_array!=NULL){
      delete [] e_array;
   }
   if(d_array!=NULL){
      delete [] d_array;
   }
}
/*********************************************************************
 ** Function: void operator=
 ** Description: assignment operator overload
 ** Parameters: const World &other
 ** Pre-Conditions:none
 ** Post-Conditions:none
 *********************************************************************/
void World::operator=(const World &other){

   if(other.c_array != NULL){
      delete [] c_array;
      c_array= new Cyberdemon [num_cyberdemons];
      for(int i=0; i<num_cyberdemons; i++){
	 this-> c_array[i]=other.c_array[i];
      }
   }
   if(other.b_array != NULL){
      delete [] b_array;
      b_array= new Balrog [num_balrogs];
      for(int i=0; i<num_balrogs; i++){
	 this-> b_array[i]=other.b_array[i];
      }
   }
   if(other.h_array != NULL){
      delete [] h_array;
      h_array= new Human [num_humans];
      for(int i=0; i<num_humans; i++){
	 this-> h_array[i]=other.h_array[i];
      }
   }
   if(other.e_array != NULL){
      delete [] e_array;
      e_array= new Elf [num_elves];
      for(int i=0; i<num_elves; i++){
	 this-> e_array[i]=other.e_array[i];
      }
   }
   if(other.d_array != NULL){
      delete [] d_array;
      d_array= new Dwarf [num_dwarves];
      for(int i=0; i<num_dwarves; i++){
	 this-> d_array[i]=other.d_array[i];
      }
   }


}
/*********************************************************************
 ** Function: World
 ** Description: Copy Constructor
 ** Parameters: const World &other
 ** Pre-Conditions:none
 ** Post-Conditions:none
 *********************************************************************/
World::World(const World &other){
   money=other.money;
   num_cyberdemons=other.num_cyberdemons;
   num_balrogs=other.num_balrogs;
   num_elves=other.num_elves;
   num_humans=other.num_humans;
   num_dwarves=other.num_dwarves;

   if(other.c_array != NULL){
      c_array= new Cyberdemon [num_cyberdemons];
      for(int i=0; i<num_cyberdemons; i++){
	 this-> c_array[i]=other.c_array[i];
      }
   }
   if(other.b_array != NULL){
      b_array= new Balrog [num_cyberdemons];
      for(int i=0; i<num_balrogs; i++){
	 this-> b_array[i]=other.b_array[i];
      }
   }
   if(other.h_array != NULL){
      h_array= new Human [num_humans];
      for(int i=0; i<num_humans; i++){
	 this-> h_array[i]=other.h_array[i];
      }
   }
   if(other.e_array != NULL){
      e_array= new Elf [num_elves];
      for(int i=0; i<num_humans; i++){
	 this-> e_array[i]=other.e_array[i];
      }
   }
   if(other.d_array != NULL){
      d_array= new Dwarf [num_dwarves];
      for(int i=0; i<num_dwarves; i++){
	 this-> d_array[i]=other.d_array[i];
      }
   }
}
//OTHER FUNCTIONS
/*********************************************************************
 ** Function: void buy_creatures
 ** Description: asks user which creature they want to buy
 ** Parameters: none
 ** Pre-Conditions:none
 ** Post-Conditions:none
 *********************************************************************/
void World::buy_creatures(){
   int x=0;
   cout<<"What creature would you like to buy? 1)Human $5 2)Dwarf $10 3)Elf $15 4)Cyberdemon $20 5)Balrog $25"<<endl;
   cin>>x;
   if(x==1){
      buy_human();
   }
   else if(x==2){
      buy_dwarf();
   }
   else if(x==3){
      buy_elf();
   }
   else if(x==4){
      buy_cyberdemon();
   }
   else if(x==5){
      buy_balrog();
   }
   else{
      cout<<"Invalid input!"<<endl;
   }

}
/*********************************************************************
 ** Function: void check_money
 ** Description: checks if the bank has enough money and calculates the total after a creature is bought
 ** Parameters: int total
 ** Pre-Conditions:none
 ** Post-Conditions:none
 *********************************************************************/
bool World::check_money(int total){
   int leftover=0;
   leftover=money-total;
   if(leftover>=0){
      money=leftover;
      return true;
   }
   else if(leftover<0){
      return false;
   }

}
/*********************************************************************
 ** Function: void buy_balrog
 ** Description: asks user how many balrogs to buuy and calls create balrog
 ** Parameters: none
 ** Pre-Conditions:none
 ** Post-Conditions:none
 *********************************************************************/
void World::buy_balrog(){
   int x=0;
   bool buy;
   cout<<"How many Balrogs would you like to buy?"<<endl;
   cin>>x;
   int total= x*25;
   buy=check_money(total);
   if(buy==false){
      cout<<"You do not have enough money!"<<endl;
      return;
   }
   else if(buy==true){
      for(int i=0; i<x; i++){
	 create_balrog();
      }
   }
}
/*********************************************************************
 ** Function: void create_balrog
 ** Description: creatues a balrog and resizes the array
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::create_balrog(){

   if(b_array==NULL){
      num_balrogs=1;
      b_array= new Balrog[num_balrogs];
   }
   else{
      num_balrogs++;
      Balrog *temparray= b_array;
      delete [] b_array;
      b_array=new Balrog[num_balrogs];
      for(int i=0; i<num_balrogs-1; i++)
	 b_array[i]=temparray[i];
   }

}
/*********************************************************************
 ** Function: void buy_cyberdemon
 ** Description: asks user how many cyber demons they want
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::buy_cyberdemon(){
   int x=0;
   bool buy;
   cout<<"How many Cyberdemons would you like to buy?"<<endl;
   cin>>x;
   int total= x*20;
   buy=check_money(total);
   if(buy==false){
      cout<<"You do not have enough money!"<<endl;
      return;
   }
   else if(buy=true){
      for(int i=0; i<x; i++){
	 create_cyberdemon();
      }
   }
}
/*********************************************************************
 ** Function: void create_cyberdemon
 ** Description: creates a cyberdemon and resizes the array
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::create_cyberdemon(){

   if(c_array=NULL){
      num_cyberdemons=1;
      c_array= new Cyberdemon[num_cyberdemons];
   }
   else{
      num_cyberdemons++;
      Cyberdemon *temparray= c_array;
      delete [] c_array;
      c_array=new Cyberdemon[num_cyberdemons];
      for(int i=0; i<num_cyberdemons-1; i++)
	 c_array[i]=temparray[i];
   }

}
/*********************************************************************
 ** Function: void buy_elf
 ** Description: asks user how many elves they want
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::buy_elf(){
   int x=0;
   bool buy;
   cout<<"How many Elves would you like to buy?"<<endl;
   cin>>x;
   int total= x*15;
   buy=check_money(total);
   if(buy==false){
      cout<<"You do not have enough money!"<<endl;
      return;
   }
   else if(buy==true){
      for(int i=0; i<x; i++){
	 create_elf();
      }
   }
}
/*********************************************************************
 ** Function: void create_elf
 ** Description: creates an elf and resizes the array
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::create_elf(){

   if(e_array=NULL){
      num_elves=1;
      e_array= new Elf[num_elves];
   }
   else{
      num_elves++;
      Elf *temparray= e_array;
      delete [] e_array;
      e_array=new Elf[num_elves];
      for(int i=0; i<num_elves-1; i++)
	 e_array[i]=temparray[i];
   }

}
/*********************************************************************
 ** Function: void buy_human
 ** Description: asks user how many humans they want
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::buy_human(){
   int x=0;
   bool buy;
   cout<<"How many Humans would you like to buy?"<<endl;
   cin>>x;
   int total=x*5;
   buy=check_money(total);
   if(buy==false){
      cout<<"You do not have enough money!"<<endl;
      return;
   }
   else if(buy==true){
      for(int i=0; i<x; i++){
	 create_human();
      }
   }
}
/*********************************************************************
 ** Function: void create_human
 ** Description: creates a human and resizes the array
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::create_human(){

   if(h_array=NULL){
      num_humans=1;
      h_array= new Human [num_humans];
   }
   else{
      num_humans++;
      Human *temparray= h_array;
      delete [] h_array;
      h_array=new Human [num_humans];
      for(int i=0; i<num_humans-1; i++)
	 h_array[i]=temparray[i];
   }

}
/*********************************************************************
 ** Function: void buy_dwarf
 ** Description: asks user how many dwarves they want
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::buy_dwarf(){
   int x=0;
   bool buy;
   cout<<"How many Dwarves would you like to buy?"<<endl;
   cin>>x;
   int total= x*10;
   buy=check_money(total);
   if(buy==false){
      cout<<"You do not have enough money!"<<endl;
      return;
   }
   else if(buy==true){
      for(int i=0; i<x; i++){
	 create_dwarf();
      }
   }
}
/*********************************************************************
 ** Function: void create_dwarf
 ** Description: creates a dwarf and resizes the array
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::create_dwarf(){
   if(d_array=NULL){
      num_dwarves=1;
      d_array= new Dwarf [num_dwarves];
   }
   else{
      num_dwarves++;
      Dwarf *temparray= d_array;
      delete [] d_array;
      d_array=new Dwarf [num_dwarves];
      for(int i=0; i<num_humans-1; i++)
	 d_array[i]=temparray[i];
   }
}
/*********************************************************************
 ** Function: void get_types
 ** Description: grabs two creatures to battle
 ** Parameters: int &type1, int &type2
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::get_types(int &type1, int &type2){
   bool dead1, dead2;
   do{
      cout<<"Who will be your first contestant? 1)Human 2)Balrog 3)Dwarf 4)Elf 5)Cyberdemon?"<<endl;
      cin>>type1;
      cout<<"Who will be your second contestant? 1)Human 2)Balrog 3)Dwarf 4)Elf 5)Cyberdemon?"<<endl;
      cin>>type2;
      if(type1==type2){
	 cout<<"Those creatures are on the same team! Please reselect an opponent!"<<endl;
      }
   }while(type1==type2);

   //loop until they are dead
   while(dead1==false && dead2==false){
      battle(type1, type2);
      dead1=check_dead(type2);
      battle(type2, type1);
      dead2=check_dead(type1);
   }
   if(dead1==true){
      after_death(type2);
   }
   if(dead2==true){
      after_death(type1);
   }
}
/*********************************************************************
 ** Function: void after_death
 ** Description: prints out dead species, adds payoff to bank and deletes the dead animal
 ** Parameters: int type
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::after_death(int type){
   //print out which species died
   //add payoff to the bank
   //delete the dead species from the array
   int payoff=0;
   if(type==1){
      cout<<"Your Human died!"<<endl;
      payoff=h_array[0].get_payoff();
      delete_human();

   }
   else if(type==2){
      cout<<"Your Balrog died!"<<endl;
      payoff=b_array[0].get_payoff();
      delete_balrog();
   }
   else if(type==3){
      cout<<"Your Dwarf died!"<<endl;
      payoff=d_array[0].get_payoff();
      delete_dwarf();
   }
   else if(type==4){
      cout<<"Your Elf died!"<<endl;
      payoff=e_array[0].get_payoff();
      delete_elf();
   }
   else if(type==5){
      cout<<"Your Cyberdemon died!"<<endl;
      payoff=c_array[0].get_payoff();
      delete_cyberdemon();
   }
   money+=payoff;

}
/*********************************************************************
 ** Function: void delete_human
 ** Description: deletes a dead human
 ** Parameters: int type
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::delete_human(){

   Human *temp=new Human[num_humans-1];
   int index=1;
   for(int i=0; i<num_humans-1; i++){
      temp[i]=h_array[index];
      index++;
   }
   delete [] h_array;
   h_array=temp;
   set_num_humans(num_humans-1);
}
/*********************************************************************
 ** Function: void delete_cyberdemon
 ** Description: deletes a dead cyberdemon
 ** Parameters: int type
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::delete_cyberdemon(){
   Cyberdemon *temp=new Cyberdemon[num_cyberdemons-1];
   int index=1;
   for(int i=0; i<num_cyberdemons-1; i++){
      temp[i]=c_array[index];
      index++;
   }
   delete [] c_array;
   c_array=temp;
   set_num_cyberdemons(num_cyberdemons-1);
}
/*********************************************************************
 ** Function: void delete_balrog
 ** Description: deletes a dead balrog
 ** Parameters: int type
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::delete_balrog(){
   Balrog *temp=new Balrog[num_balrogs-1];
   int index=1;
   for(int i=0; i<num_balrogs-1; i++){
      temp[i]=b_array[index];
      index++;
   }
   delete [] b_array;
   b_array=temp;
   set_num_balrogs(num_balrogs-1);
}
/*********************************************************************
 ** Function: void delete_elf
 ** Description: deletes a dead elf
 ** Parameters: int type
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::delete_elf(){
   Elf *temp=new Elf[num_elves-1];
   int index=1;
   for(int i=0; i<num_elves-1; i++){
      temp[i]=e_array[index];
      index++;
   }
   delete [] e_array;
   e_array=temp;
   set_num_elves(num_elves-1);
}
/*********************************************************************
 ** Function: void delete_dwarf
 ** Description: deletes a dead dwarf
 ** Parameters: int type
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::delete_dwarf(){
   Dwarf *temp=new Dwarf[num_dwarves-1];
   int index=1;
   for(int i=0; i<num_dwarves-1; i++){
      temp[i]=d_array[index];
      index++;
   }
   delete [] d_array;
   d_array=temp;
   set_num_dwarves(num_dwarves-1);
}
/*********************************************************************
 ** Function: void check_dead
 ** Description: checks if the animal is dead
 ** Parameters: int type
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
bool World::check_dead(int type){
   int hitpoints=0;
   if(type==1){
      hitpoints=h_array[0].get_hitpoints();
   }
   else if(type==2){
      hitpoints=b_array[0].get_hitpoints();
   }
   else if(type==3){
      hitpoints=d_array[0].get_hitpoints();
   }
   else if(type==4){
      hitpoints=e_array[0].get_hitpoints();
   }
   else if(type==5){
      hitpoints=c_array[0].get_hitpoints();
   }

   if(hitpoints<=0){
      return true;
   }
   else{
      return false;
   }
}
/*********************************************************************
 ** Function: void matchup
 ** Description:  calls get damage and then battles
 ** Parameters: int &type1, int &type2
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::battle(int &type1, int &type2){
   int x=0;
   int y=0;
   int damage=0;

   if(type1==1){
      damage=h_array[0].getDamage();
   }
   else if(type1==2){
      damage=b_array[0].getDamage();
   }
   else if(type1==3){
      damage=d_array[0].getDamage();
   }
   else if(type1==4){
      damage=e_array[0].getDamage();
   }
   else if(type1==5){
      damage=c_array[0].getDamage();
   }
   if(type2==1){
      h_array[0].changehitpoints(damage);
   }
   else if(type2==2){
      b_array[0].changehitpoints(damage);
   }
   else if(type2==3){
      d_array[0].changehitpoints(damage);
   }
   else if(type2==4){
      e_array[0].changehitpoints(damage);
   }
   else if(type2==5){
      c_array[0].changehitpoints(damage);
   }

}

/*********************************************************************
 ** Function: void create_world
 ** Description: adds money to world
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: money is in bank
 *********************************************************************/
void World::create_world(){
   //ask how many of each crature they want to buy
   //in a for loop call create that Creature
   cout<<"How much money would you like?"<<endl;
   cin>>money;
}
/*********************************************************************
 ** Function: void view_bank
 ** Description: prints out money in bank
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::view_bank(){
   cout<<"You have $"<<money<<" in the bank"<<endl;
}
/*********************************************************************
 ** Function: void main_menu
 ** Description: asks user if they want to add money, battle, view bank, buy a creature or quit
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::main_menu(){
   int x=0;
   do{
      cout<<"Would you like to 1)Add Money 2)Battle 3)View Bank 4)Buy A Creature 5)Quit"<<endl;
      cin>>x;

      if(x==1){
	 create_world();
      }
      else if(x==2){
	 get_types(type1, type2);
      }
      else if(x==3){
	 view_bank();
      }
      else if(x==4){
	 buy_creatures();
      }
      else if(x==5){
	 return;
      }
      else{
	 cout<<"Invalid input!"<<endl;
      }
   }while(x!=5);

}
//GETTERS/ACCESSORS
/*********************************************************************
 ** Function: void get_money
 ** Description: access money
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int World::get_money(){

   return money;
}
/*********************************************************************
 ** Function: void get_money
 ** Description: access num_cyberdemons
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int World::get_num_cyberdemons(){

   return num_cyberdemons;
}
/*********************************************************************
 ** Function: void get_num_balrogs
 ** Description: access num_balrogs
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int World::get_num_balrogs(){

   return num_balrogs;
}
/*********************************************************************
 ** Function: void get_num_elves
 ** Description: access num_elves
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int World::get_num_elves(){

   return num_elves;
}
/*********************************************************************
 ** Function: void get_num_dwarves
 ** Description: access num_dwarves
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int World::get_num_dwarves(){

   return num_dwarves;
}
/*********************************************************************
 ** Function: void get_num_humans
 ** Description: access num_humans
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int World::get_num_humans(){

   return num_humans;
}
//SETTERS/MUTATORS
/*********************************************************************
 ** Function: void set_num_cyberdemons
 ** Description: sets num_cyberdemons
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::set_num_cyberdemons(int c){
   num_cyberdemons=c;
}
/*********************************************************************
 ** Function: void set_num_balrogs
 ** Description: sets num_balrogs
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::set_num_balrogs(int b){
   num_balrogs=b;
}
/*********************************************************************
 ** Function: void set_num_elves
 ** Description: sets num_elves
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::set_num_elves(int e){
   num_elves=e;
}
/*********************************************************************
 ** Function: void set_num_dwarves
 ** Description: sets num_dwarves
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::set_num_dwarves(int d){
   num_dwarves=d;
}
/*********************************************************************
 ** Function: void set_num_humans
 ** Description: sets num_humans
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::set_num_humans(int h){
   num_humans=h;
}
/*********************************************************************
 ** Function: void set_money
 ** Description: sets money
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::set_money(int m){
   money=m;
}
