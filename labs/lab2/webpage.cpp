#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void create_header(ifstream &input, ofstream &output){

string title;

getline(input,title);
output<<"<head>"<<endl;
output<<"<title>"<<title<<"</title>"<<endl;
output<<"</head>"<<endl;

}
void create_body(ifstream &input, ofstream &output){

string bgcolor;
string fcolor;
string fsize;
string face;
string line1;
string line2;

getline(input, bgcolor);
output<<"<body bgcolor="<<bgcolor<<">"<<endl;
input>>fcolor;
output<<"<font color= "<<fcolor<<" ";
input>>fsize;
output<<"size="<<fsize<<" ";
getline(input, face);
output<<"face="<<face<<">"<<endl;
getline(input, line1);
output<<line1<<"<br>"<<endl;
output<<"<br>"<<endl;
getline(input, line2);
output<<line2<<"<br>"<<endl;
output<<"<br>"<<endl;
output<<"</font>"<<endl;
output<<"</body>"<<endl;
output<<"</html>"<<endl;

}


void create_html(ifstream &input){
   string ofile;
   ofstream output;

   cout<<"Enter a file name for the output file"<<endl;
   getline(cin, ofile);

   output.open(ofile.c_str());

   output<<"<html>"<<endl;
   create_header(input, output);
   create_body(input, output);
   output<<"</html>"<<endl;

}



