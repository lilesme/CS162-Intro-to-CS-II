//library.cpp
#include "library.h"
#include <fstream>
/********************************************************************* 
 ** Function:library
 ** Description:constructor
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
//constructors
library::library(){
   for(int i=0; i<7; i++){
      week[i].begin_time="10:00AM";
      week[i].end_time="10:00PM";
   }
   
   num_books=0;
   books=NULL;
}

/********************************************************************* 
 ** Function:library
 ** Description:copy constructor
 ** Parameters:const library &other
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
//BIG THREE
//Copy Constructor
library::library(const library &other){	   
   
   for(int i=0; i<7; i++){
      week[i].begin_time=other.week[i].begin_time;
      week[i].end_time=other.week[i].end_time;
   }

   int num_authors;
   if(num_books==0){
      books=NULL;
      num_books=0;
   }
   else{
      books=new book[other.num_books];
      num_books=other.num_books;
      for(int i=0; i<num_books; i++){
	 num_authors=other.books[i].num_authors;
	 books[i]=other.books[i];
	 for(int j=0; j<num_authors; j++){
	    books[i].authors[j]=other.books[i].authors[j];
	 }
      }
      }
}
/********************************************************************* 
 ** Function:~library
 ** Description:destructor
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
//Destructor
library::~library(){
   for(int i=0; i<num_books; i++){
      delete [] books[i].authors;
   }
   delete [] books;

}
/********************************************************************* 
 ** Function:operator=
 ** Description:assignment operator overload (deep copy)
 ** Parameters:const library &other
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
//Assignment Operator Overload
void library::operator=(const library &other){
 int num_authors;
 c=other.c;
 l=other.l;
 p=other.p;
 for(int i=0; i<7; i++){
    week[i]=other.week[i];
 }
   if(books!=NULL){
      delete [] books;
   }
 for(int i=0; i<num_books; i++){
    delete books[i].authors;
 }
    delete [] books;

    if(num_books==0){
       books=NULL;
       num_books=0;
    }
    else{
       books=new book[other.num_books];
       num_books=other.num_books;
       for(int i=0; i<num_books; i++){
	 num_authors=other.books[i].num_authors;
	  books[i]=other.books[i];
	  for(int j=0; j<num_authors; j++){
	     books[i].authors[j]=other.books[i].authors[j];
          }
       }
    }
}
/********************************************************************* 
 ** Function:get_books
 ** Description:access the get_books
 ** Parameters:const int i, const book &b
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

//Accessors/getters
void library::get_books(const int i, const book &b){
   if(i>=num_books){
   }
   else if(i<0){
      return;
   }
   //books[i]=books;

}
/********************************************************************* 
 ** Function:get_num_books
 ** Description:returns num_books
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
int library::get_num_books() const {
   return num_books;
}
/********************************************************************* 
 ** Function:set_num_books
 ** Description:sets num_books to n
 ** Parameters:const int n
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
//Mutators/setters
void library::set_num_books(const int n){
   if(n>num_books){
   }
   num_books=n;
}
/********************************************************************* 
 ** Function:display_weekly_hours
 ** Description:displays the weekly hours
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void library::display_weekly_hours(){

for(int i=0; i<7; i++){
   cout<<"OPEN: "<<week[i].begin_time<<endl;
   cout<<"CLOSE: "<<week[i].end_time<<endl;
}   
   
}
/********************************************************************* 
 ** Function: display_daily_hours
 ** Description: displays the daily hours
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void library::display_daily_hours(){
   int i=0;
   cout<<"Would you like to view Sunday(0), Monday(1), Tuesday(2), Wednesday(3), Thursday(4), Friday(5), Saturday(6). "<<endl;
   cin>>i;
   cout<<"OPEN: "<<week[i].begin_time<<endl;
   cout<<"CLOSE: "<<week[i].end_time<<endl;

}
/********************************************************************* 
 ** Function: view_hours
 ** Description:presents menu for how to see hours
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void library::view_hours(){
   int x=0;
   int weekday=0;

   cout<<"Would you like to view hours by 1)entire week 2)day ?"<<endl;
   cin>>x;
   if(x==1){
      display_weekly_hours();
   }
   else if(x==2){
      display_daily_hours();
   }
}
/********************************************************************* 
 ** Function:go_to_patron_menu
 ** Description:sends user to patron menu
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void library::go_to_patron_menu(){
   p.patron_menu();
}
/********************************************************************* 
 ** Function:go_to_librarian_menu
 ** Description:sends user to librarian_menu
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void library::go_to_librarian_menu(){
   l.librarian_menu(week);
}
