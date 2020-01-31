//driver.cpp
/********************************************************************* 
 ** Program Filename: driver
 ** Author:Megan Liles
 ** Date:5/2/17
 ** Description: library with patrons and librarians and carts
 ** Input: keys
 ** Output: words
 *********************************************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <string.h>
#include "driver.h"
#include "library.h"
#include "patron.h"
#include "librarian.h"
#include "cart.h"
using namespace std;


/********************************************************************* 
 ** Function: login
 ** Description:main menu login
 ** Parameters: library a
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void login(library a){
   bool patron;
   bool librarian;
   int x=0;
   cout<<"Are you a patron(1) or a librarian(2)?"<<endl;
   cin>>x;
   if(x==1){
      patron=patron_login();

      if(patron==false){
	 cout<<"I'm sorry. Your patron ID was not found."<<endl;
	 return;
      }
      else{
	 a.go_to_patron_menu();
      }
   }
   else if(x==2){
      librarian=librarian_login();
      if(librarian==false){
	 cout<<"I'm sorry. Your librarian ID was not found."<<endl;
	 return;
      }
      else{
	 a.go_to_librarian_menu();
      }
   }
}
/********************************************************************* 
 ** Function: patron_login
 ** Description: main menu for patron to login
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
bool patron_login(){
   ifstream input; 
   int id=0;
   int temp=0;
   cout<<"Please enter your id: "<<endl;
   cin>>id;

   //open patron file and find id
   input.open("patronfile.txt");
   if(input.fail()){
      cout<<"The file failed to open!"<<endl;
   }  
   while(!input.eof()){
      input>>temp;
      if(id==temp){
	 return true;
      }  
   }     
   input.close();
}
/********************************************************************* 
 ** Function: librarian_login
 ** Description: main menu for librarian to login
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
bool librarian_login(){
   ifstream input;
   int id=0;
   int temp=0;
   cout<<"Please enter your id: "<<endl;
   cin>>id;
   //open librarian file and find id
   input.open("librarianfile.txt");
   if(input.fail()){
      cout<<"The file failed to open!"<<endl;
   }
   while(!input.eof()){
      input>>temp;
      if(id==temp){
	 return true;
      }

   }
   input.close();
}

/********************************************************************* 
 ** Function: main_menu
 ** Description: main menu to choose what to do
 ** Parameters: library a
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void main_menu(library a){

   int x=0;
   while(x!=3){
      cout<<"Hello. Would you like to 1) Login 2) View Hours 3) Quit ?"<<endl;
      cin>>x;
      if(x==1){
	 login(a);
      }
      else if(x==2){
	 a.view_hours();
      }
      else if(x==3){
	 return ;
      }
   }
}

/********************************************************************* 
 ** Function: main
 ** Description: calls main_menu
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
int main(){
   library a;

   //a.display_weekly_hours();

   main_menu(a);



   return 0;



}
