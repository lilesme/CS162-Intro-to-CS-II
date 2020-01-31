//library.h
#ifndef LIBRARY_H
#define LIBRARY_H
#include "patron.h"
#include "librarian.h"
#include "cart.h"
#include "structs.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class library {
   private:
      hours week[7];
      int num_books;
      book *books;
      cart c;
      librarian l;
      patron p;
   public:
      //You need constructors, accessors, mutators and any other functions (use const where necessary)
      //constructors
      library();
      //Mutators/setters
      void set_num_books(const int n);
      //Accessors/getters
      void get_books(const int i, const book &b);
      int get_num_books() const ;
      //other functions
      void display_daily_hours();
      void display_weekly_hours();
      void view_hours();
      void librarian_menu();
      void patron_menu();
      //BIG THREE
      library(const library &); //copy constructor to do deep copy
      ~library(); //destructor to delete book array
      //assignment operator overload, same object was already constructed but with deleting memmory, since object was already constructed
      void operator=(const library &);
      void go_to_patron_menu();
      void go_to_librarian_menu();

};

#endif 
