//Patron.h
#ifndef PATRON_H
#define PATRON_H
#include <string>
#include <iostream>
#include "cart.h"


using namespace std;

class patron {
   private:
      string name;
      int id;
      int books_checked_out;
   public:
   //constructor
      patron();
   //mutator/setters
      void set_name(const string &name);
      void set_id(const int i);
      void set_books_checked_out(const int c);
   //accessors/getters
      int get_id() const;
      string get_name() const;
      int get_books_checked_out (const int b) const;
   //other functions
      void check_out_books ();
      void check_in_books();
      void view_my_books_out();
      void patron_menu(); 
      void view_all_books();
      void find_book();
      void find_by_title(string);
      void find_by_year(string);
      void find_by_author(string);
};

#endif
