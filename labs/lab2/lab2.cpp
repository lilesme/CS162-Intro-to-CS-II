#include <iostream>
#include <fstream>
#include <cstdlib>
std::ifstream input;
using namespace std;

void create_header(ifstream &, ofstream &);
void create_body(ifstream &, ofstream &);
void create_html(ifstream &);


int main(int argc, char * argv[]){

   char* file= new char[256];
   bool fail;
   ifstream input;

   cout<<"Please enter a filename: "<<endl;
   cin.getline(file, 256);
   input.open(file);
   if(input.fail()){
      cout<<"That file does not exist. Enter a file name: "<<endl;
      cin.getline(file, 256);
   }

create_html(input);


return 0;
}

