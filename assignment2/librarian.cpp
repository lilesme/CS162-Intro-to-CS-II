#include "librarian.h"
#include <string>
#include <fstream>
#include <iostream>
#include "library.h"
#include <cstdlib>

using namespace std;

/********************************************************************* 
 ** Function: librarian
 ** Description: constuctor
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
//constructors
librarian::librarian(){
   name="";
   id=0;

}

/********************************************************************* 
 ** Function: get_name
 ** Description: accessor to get the name
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
//getters/accessors

string librarian::get_name() const{

   return name;

}

/********************************************************************* 
 ** Function:get_id
 ** Description: accessor to get id
 ** Parameters: 
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
int librarian::get_id() const{

   return id;
}

/********************************************************************* 
 ** Function: set_name
 ** Description: mutator to set name
 ** Parameters:const string &n
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
//setters/mutators

void librarian::set_name(const string &n){
   name=n;

}

/********************************************************************* 
 ** Function: set_id
 ** Description:mutator to set id
 ** Parameters:const int i
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void librarian::set_id(const int i){
   id=i;

}

//other functions
/********************************************************************* 
 ** Function: change_library_hours
 ** Description: changes the hours
 ** Parameters:hours week[7]
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void librarian::change_library_hours(hours week[7]){
   int x=0;
   string begin;
   string end;
   cout<<"What day of the week would you like to change hours for? Sunday(0), Monday(1), Tuesday(2), Wedenesday(3), Thursday(4), Friday(5), Saturday(6)?"<<endl;
   cin>>x;
   cout<<"What would you like the begin time to be? "<<endl;
   cin>>begin;
   cout<<"What would you like the end time to be? "<<endl;
   cin>>end;
   week[x].begin_time=begin;
   week[x].end_time=end;
}
/********************************************************************* 
 ** Function: add_new_books
 ** Description:allows librarian to add new books
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void librarian::add_new_books(){
   int num_books=0;
   ofstream output;

   cout<<"How many books would you like to add? "<<endl;
   cin>>num_books;
   if(num_books>0){
      for(int i=0; i<num_books; i++){
	 string title;
	 string author;
	 string year;
	 cout<<"Title: "<<endl;
	 cin>>title;
	 cout<<"Author: "<<endl;
	 cin.ignore();
	 cin>>author;
	 cout<<"Year: "<<endl;
	 cin>>year;
	 //open book file and add to the end of file
	 output.open("bookfile.txt", ios::app);//append to file
	 output<<title<<" "<<author<<" "<<year<<endl;

      }
   }
}
/********************************************************************* 
 ** Function: remove_old_books
 ** Description:allows librarian to remove books
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void librarian::remove_old_books(){
   string title;
   string author;
   string year;
   string temp;
   int found;
   ifstream input;
   ofstream output;
   cout<<"Please enter the following information about the book you want to remove."<<endl;
   cout<<"Title: "<<endl;
   cin>>title;
   cout<<"Author: "<<endl;
   cin>>author;
   cout<<"Year: "<<endl;
   cin>>year;
   input.open("bookfile.txt");
   output.open("tempbookfile.txt");
   if(input.fail()){
      cout<<"File failed to open!"<<endl;
   }
   while(!input.eof()){
      getline(input, temp);
      found=temp.find(title);
      if(found==string::npos){
	 found=temp.find(author);
	 if(found==string::npos){
	    found=temp.find(year);
	    if(found==string::npos){
	       output<<temp<<endl;
	    }
	 }
      }
   }
   input.close();
   output.close();
   remove("bookfile.txt");
   rename("tempbookfile.txt", "bookfile.txt");
}
/********************************************************************* 
 ** Function:view_all_books_checked_out
 ** Description: allows librarian to view books checked out
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void librarian::view_all_books_checked_out(){
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
      cout<<" "<<"Author: "<<temp;
      input>>temp;
      cout<<" "<<"Year: "<<temp<<endl;
   }
   input.close();
}
/********************************************************************* 
 ** Function: librarian_menu
 ** Description:menu for librarian to choose what to do
 ** Parameters:hours week[7]
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void librarian::librarian_menu(hours week[7]){
   int x=0;
   cout<<"You have successfully logged in as a librarian. Would you like to: 1)Change hours 2)Add new books 3)Remove old books 4) View books checked out"<<endl;
   cin>>x;

   if(x==1){
      change_library_hours(week);
   }
   else if(x==2){
      add_new_books();
   }
   else if(x==3){
      remove_old_books();
   }
   else if(x==4){
      view_all_books_checked_out();
   }

} 
