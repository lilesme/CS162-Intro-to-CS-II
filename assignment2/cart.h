#ifndef CART_H
#define CART_H //include in .h files incase redeclared
#include <iostream>
#include <string>
#include <cstdlib>
#include "structs.h"

class cart {
   private:
      book *books;
      int num_books;
      void resize_books(int);
   public: 
      //You need constructors, accessors, mutators and any other funcitons (use const when necessary)
   
   cart(); //set books to NULL and num_books to zero
   void set_books (const int, const book &); //book index to set & book
   book* get_books() const; //return address of array of books
   void set_num_books(const int); // set num_books and make book array
   int get_num_books () const; //return number of books in cart
   void add_to_cart(string, string, string, bool);
   void display_books();
   void empty_cart();
   void copy_to_bookfile(string, string, string);
   void copy_to_bookscheckedoutfile(string, string, string);
   //BIG THREE
   cart(const cart &); //copy constructor to do deep copy
   ~cart(); //destructor to delete book array
   //assignment operator overload, same contents as copy construcot but with deleting memory, cince object was already constructed
   void operator=(const cart &);


};

#endif
