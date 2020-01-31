//cart.cpp
#include "cart.h"
#include <fstream>
/********************************************************************* 
 ** Function:cart
 ** Description:constructor
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
//constructors
cart::cart(){
   books=NULL;
   num_books=0;
}
/********************************************************************* 
 ** Function:get_num_books
 ** Description:returns num_books
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

//getters/accessors
int cart::get_num_books() const {
   return num_books;
}

/********************************************************************* 
 ** Function:get_books
 ** Description:returns book array
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
book* cart::get_books() const {

   return books;
}

/********************************************************************* 
 ** Function:set_books
 ** Description:mutator for set_books
 ** Parameters:const int i, const book &b
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
//setters/mutators

void cart::set_books(const int i, const book &b){
  if(i>=num_books){
     resize_books(i);
  }
  else if(i<0){
     return;
  }
  books[i]=b;
  
}
/********************************************************************* 
 ** Function:set_num_books
 ** Description:sets num_books
 ** Parameters:const int n
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void cart::set_num_books(const int n){
   if(n>num_books){
      resize_books(n);
   }
   num_books=n;
}
//other functions


/********************************************************************* 
 ** Function:cart
 ** Description:copy constructor for cart
 ** Parameters:const cart &other
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
//BIG THREE
//Copy Constructor
cart::cart(const cart &other){
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
 ** Function:~cart
 ** Description:destructor for cart
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

//Destructor
cart::~cart(){
   for(int i=0; i<num_books; i++){
      delete [] books[i].authors;
   }
   delete [] books;
}
/********************************************************************* 
 ** Function:operator=
 ** Description:assignment overload operator
 ** Parameters:const cart &other
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
//Assignment Operator
void cart::operator=(const cart &other){
   int num_authors;
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
 ** Function:copy_to_bookfile
 ** Description:deletes a book from bookfile
 ** Parameters:string title, string author, string year
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void cart::copy_to_bookfile(string title, string author, string year){
   ifstream input;
   ofstream output;
   string temp;
   int found=0;
   input.open("bookfile.txt");
   output.open("tempbookfile.txt");
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
 ** Function:copy_to_bookscheckedoutfile
 ** Description:deletes a book from bookscheckedout file
 ** Parameters:string title, sting author, stirng year
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void cart::copy_to_bookscheckedoutfile(string title, string author, string year){
   ifstream input;
   ofstream output;
   string temp;
   int found=0;
   input.open("bookscheckedout.txt");
   output.open("tempbookscheckedout.txt");
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
   remove("bookscheckedout.txt");
   rename("tempbookscheckedout.txt", "bookscheckedout.txt");
}
//other functions
/********************************************************************* 
 ** Function: add_to_cart
 ** Description:checks out books or returns books
 ** Parameters:string title, stirng author, string year, bool checkout
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void cart::add_to_cart(string title, string author, string year, bool checkout){
   ifstream input;
   ofstream output;
   string temp;


   if(checkout==true){
   //add books to books checked out
   output.open("bookscheckedout.txt", ios::app);//append to file
      if(output.fail()){
      cout<<"The file failed to open!"<<endl;
      }
      output<<title<<" "<<author<<" "<<year<<endl;
      output.close();
   
   //delete from book file
   copy_to_bookfile(title, author, year);

   }
   else if(checkout==false){
   //add books back to book file and delete from books checked out file
   output.open("bookfile.txt", ios::app);//append to file
   //output books wanting to return
   output<<title<<" "<<author<<" "<<year<<endl;
   output.close();
   
   //delete from books checked out
   copy_to_bookscheckedoutfile(title, author, year);
   }
}

/********************************************************************* 
 ** Function:resize_books
 ** Description:resizes the book arary
 ** Parameters:int b
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void cart::resize_books(int b){
   
   book* array= new book[b];
   
   if(b<0){
      cout<<"You do not have enough books!"<<endl;
   }
   else{
      num_books=b;
   }
   for(int i=0; i<num_books-1; i++){
      array[i]=books[i];
   }
  delete [] books;

  books=array;

  delete array;

}
/********************************************************************* 
 ** Function:empty_cart
 ** Description:deletes contents in cart
 ** Parameters: 
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void cart::empty_cart(){
   books=NULL;
}

