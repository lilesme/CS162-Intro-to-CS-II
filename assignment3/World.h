#ifndef WORLD_H
#define WORLD_H
#include <cstdlib>
#include <iostream>
#include <string>
#include "Balrog.h"
#include "Creature.h"
#include "Cyberdemon.h"
#include "Demon.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Human.h"

using namespace std;

class World{
   private:
     Cyberdemon *c_array;
     Balrog *b_array;
     Human *h_array;
     Elf *e_array;
     Dwarf *d_array;
     int money;
     int num_cyberdemons;
     int num_balrogs;
     int num_elves;
     int num_humans;
     int num_dwarves;
     int type1;
     int type2;
   public:
     //getters/setters
     int get_money();
     int get_num_cyberdemons();
     int get_num_balrogs();
     int get_num_elves();
     int get_num_dwarves();
     int get_num_humans();
     void set_num_cyberdemons(int);
     void set_num_balrogs(int);
     void set_num_elves(int);
     void set_num_dwarves(int);
     void set_num_humans(int);
     void set_money(int);
     //other functions
     void buy_creatures();
     void after_death(int);
     void battle(int &, int &);
     bool check_dead(int);
     void get_types(int &, int &);
     void create_world();
     void main_menu();
     void view_bank();
     void buy_human();
     void buy_cyberdemon();
     void buy_elf();
     void buy_dwarf();
     void buy_balrog();
     void create_human();
     void create_cyberdemon();
     void create_dwarf();
     void create_elf();
     void create_balrog();
     bool check_money(int);
     void delete_elf();
     void delete_human();
     void delete_dwarf();
     void delete_balrog();
     void delete_cyberdemon();
     //constructors/BIG THREE
     World();//Constructor
     ~World();//Destructor
     void operator=(const World &);//Assignment Opperator Overload
     World(const World &);//Copy Constructor
};

#endif
