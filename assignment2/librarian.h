//librarian.h
#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include <string>
#include <iostream>
#include <cstdlib>
//#include "library.h"
#include "cart.h"
using namespace std;

class librarian{
   private:
      string name;
      int id;
   public:
   //constructors 
   librarian(); //set  name to null and id to zero
   //mutators
   void set_name(const string &);//name index to set name
   void set_id(const int);
   //accessors
   string get_name() const; //returns name
   int get_id() const; //returns id
   //other functions
   void change_library_hours(hours week[7]);
   void add_new_books();
   void remove_old_books();
   void view_all_books_checked_out();
   void librarian_menu(hours week[7]);
   
};

#endif
