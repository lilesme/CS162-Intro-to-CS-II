#include "patron.h"
#include "library.h"
#include <fstream>
#include "cart.h"

/********************************************************************* 
 ** Function:patron
 ** Description:constructor
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
//constructors
patron::patron(){
   
   name="";
   id=0;
   books_checked_out=0;

}
/********************************************************************* 
 ** Function: get_id
 ** Description:returns id
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

//getters/accessors
int patron::get_id () const {
   
   return id;
}

/********************************************************************* 
 ** Function:get_name
 ** Description:returns name
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
string patron::get_name() const{
    

   return name;

}
/********************************************************************* 
 ** Function:get_books_checked_out
 ** Description:returns books_checked_out
 ** Parameters:const int b
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

int patron::get_books_checked_out (const int b) const{

   return books_checked_out;
}

/********************************************************************* 
 ** Function: set_name
 ** Description:sets name
 ** Parameters:const string &n
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
//setters/accessors

void patron::set_name(const string &n){
  name=n; 

}
/********************************************************************* 
 ** Function: set_id
 ** Description: sets id
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void patron::set_id(const int i){
   id=i;
}

/********************************************************************* 
 ** Function:set_books_checked_out
 ** Description:sets books checked out to c
 ** Parameters:const int c
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void patron::set_books_checked_out(const int c){

   books_checked_out=c;
}
/********************************************************************* 
 ** Function:check_out_books
 ** Description:allows patron to check out books
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void patron::check_out_books(){
   ifstream input;
   string title;
   string author;
   string year;
   string temp;
   cart c;
   bool checkout=true;

   cout<<"Please enter the title of the book you want to check out: "<<endl;
   cin>>title;
   //open book file and find book
   input.open("bookfile.txt");
   if(input.fail()){
      cout<<"The file failed to open!"<<endl;
   }
   while(!input.eof()){
      input>>temp;
      if(title==temp){
	 title=temp;
	 input>>temp;
	 author=temp;
	 year=temp;
      }
   }
      c.add_to_cart(title, author, year, checkout);
   }

/********************************************************************* 
 ** Function:check_in_books()
 ** Description:allows patron to check in books
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void patron::check_in_books(){
   ifstream input;
   string title;
   string author;
   string year;
   string temp;
   cart c;
   
   bool checkout=false;

   cout<<"Please enter the title of the book you want to check in: "<<endl;
   cin>>title;
   //open bookscheckedoutfile and find book
   
   input.open("bookscheckedout.txt");
   if(input.fail()){
      cout<<"The file failed to open!"<<endl;
   }
   while(!input.eof()){
      input>>temp;
      if(title==temp){
	 title=temp;
	 input>>temp;
	 author=temp;
	 year=temp;
      }
   }
      c.add_to_cart(title, author, year, checkout);
   }
 

/********************************************************************* 
 ** Function:view_my_books_out
 ** Description:allows patron to view books checked out
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void patron::view_my_books_out(){
   //open books checked out file
   ifstream input;
   string temp;   
   
   input.open("bookscheckedout.txt");
      if(input.fail()){
	 cout<<"The file failed to open!"<<endl;
      }
      while(!input.eof()){
	 input>>temp;
	 cout<<"Title: "<<temp;
	 input>>temp;
	 cout<<" Author: "<<temp;
	 input>>temp;
	 cout<<" Year: "<<temp<<endl;
      }
      input.close();
}
/********************************************************************* 
 ** Function: patron_menu
 ** Description:menu of options for patron
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void patron::patron_menu(){
   ifstream input;
   string temp;
   int x=0;
   cout<<"You successfully logged in as a patron. Would you like to: 1) view all books 2)Search for a Book 3) Return a book 4)Check out a book 5)View Books Checked out? "<<endl;
   
   cin>>x;
   

   if(x==1){
      view_all_books();
   }
   else if(x==2){
      find_book();
   }
   else if(x==3){
      check_in_books();
   }
   else if(x==4){
      check_out_books();
   }
   else if(x==5){
      view_my_books_out();
   }
}
/********************************************************************* 
 ** Function:view_all_books
 ** Description:allows patron to view all books
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void patron::view_all_books(){
   ifstream input;
   string temp;   
   
   input.open("bookfile.txt");
      if(input.fail()){
	 cout<<"The file failed to open!"<<endl;
      }
      while(!input.eof()){
	 input>>temp;
	 cout<<"Title: "<<temp;
	 input>>temp;
	 cout<<" Author: "<<temp;
	 input>>temp;
	 cout<<" Year: "<<temp<<endl;
      }
      input.close();
}
/********************************************************************* 
 ** Function:find_by_title
 ** Description:allows patron to search for book by title
 ** Parameters:string title
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void patron::find_by_title(string title){
   ifstream input;
   string temp;

   input.open("bookfile.txt");
   if(input.fail()){
      cout<<"the file failed to open!"<<endl;
   }
   while(!input.eof()){
      input>>temp;
      if(title==temp){
	 cout<<"The book was found!"<<endl;
	 cout<<"Title: "<<temp<<endl;
	 input>>temp;
	 cout<<"Author: "<<temp<<endl;
	 input>>temp;
	 cout<<"Year: "<<temp<<endl;
      }
	
   }
   input.close();
}
/********************************************************************* 
 ** Function:find_by_author
 ** Description:allows patron to search for book by author
 ** Parameters:string author
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void patron::find_by_author(string author){
   ifstream input;
   string temp;

   input.open("bookfile.txt");
   if(input.fail()){
      cout<<"the file failed to open!"<<endl;
   }
   while(!input.eof()){
      input>>temp;
      if(author==temp){
	 cout<<"The author was found!"<<endl;
	 cout<<"Author: "<<temp<<endl;
	 input>>temp;
	 cout<<"Year: "<<temp<<endl;
      }
   }
   input.close();
}
/********************************************************************* 
 ** Function:find_by_year
 ** Description:allows patron to search for book by year
 ** Parameters:string year
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void patron::find_by_year(string year){
   ifstream input;
   string temp;

   input.open("bookfile.txt");
   if(input.fail()){
      cout<<"the file failed to open!"<<endl;
   }
   while(!input.eof()){
      input>>temp;
      if(year==temp){
	 cout<<"The year was found!"<<endl;
	 cout<<"Year: "<<temp<<endl;
      }
   }
   input.close();
}
/********************************************************************* 
 ** Function: find_books
 ** Description: gives menu of how to find a book to patron
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void patron::find_book(){
   int y=0;
   string title;
   string author;
   string year;

   cout<<"Would you like to search by 1)Title 2)Author 3)Year ?"<<endl;
   cin>>y;
   if(y==1){
	 cout<<"Please enter a title with underscores as spaces"<<endl;
	 cin>>title;
	 find_by_title(title);
   }
   else if(y==2){
      cout<<"Please enter a author with underscores as spaces"<<endl;
      cin>>author;
      find_by_author(author);
   }
   else if(y==3){
      cout<<"Please enter a 4 digit year"<<endl;
      cin>>year;
      find_by_year(year);
   }
}
