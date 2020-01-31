//implementation file (state_facts.cpp)
/********************************************************************* * ** Program Filename:state_facts.cpp
 * ** Author: Megan Liles
 * ** Date:4/8/17
 * ** Description:
 * ** Input:file containing info about states and thier counties
 * ** Output:info aout states vs counties
 **********************************************************************/
#include "state_facts.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;


/********************************************************************* 
 * ** Function: bool is_valid_arguments
 * ** Description: error checks if command line arguments are valid
 * ** Parameters:int argc, char* [] argv
 * ** Pre-Conditions:none
 * ** Post-Conditions:none
 **********************************************************************/
bool is_valid_arguments(char * argv[], int argc){
   //check number of arguments
   if(argc != 5){
      cout<<"You do not have the correct number of arguments!"<<endl;
      return false;
   }
   //check for "-s" and "-f"
   if(strcmp(argv[1], "-s")!=0){
      if(strcmp(argv[1], "-f")!=0){ 
         cout<<"You did not enter a valid argument!"<<endl;
	 return false;
      }
   }
   else if(strcmp(argv[3], "-s")!=0){
      if(strcmp(argv[3], "-f")!=0){
	 cout<<"You did not enter a valid argument!"<<endl;
	 return false;
      }
   }
}
/********************************************************************* 
 * ** Function: void store_file_name
 * ** Description: stores file name
 * ** Parameters:int 
 * ** Pre-Conditions:none
 * ** Post-Conditions:none
 **********************************************************************/
void store_file_name(char * argv[], int argc, char* file){
   for(int i=0; i<argc; i++){
      if(strcmp(argv[i], "-f")==0){
	 strcpy(file, argv[i+1]);
      }
   }
}

/********************************************************************* 
 * ** Function: void check_file_exists
 * ** Description: error checks if file exists
 * ** Parameters:char* file, ifstream &input
 * ** Pre-Conditions:none
 * ** Post-Conditions:none
 **********************************************************************/
void check_file_exists(char* file, ifstream &input){
        
	input.open(file);
	while(input.fail()==true){
           cout<<"That file does not exist. Enter a file name: "<<endl;
           cin.getline(file, 256);
           input.close();
	   input.open(file);
	}
}	

/********************************************************************* 
 * ** Function: void find_num_states
 * ** Description: error checksfor correct number of states
 * ** Parameters:int argc, char* [] argv
 * ** Pre-Conditions:none
 * ** Post-Conditions:none
 **********************************************************************/
int find_num_states(char* argv[], int argc){

 int num_states;   
 //check for positive, non-zero integer for #states and RECOVER
for(int i=0; i<argc; i++){
      if(strcmp(argv[i], "-s")==0){
	 num_states= atoi(argv[i+1]);
      }
}
 while(num_states <1){
    cout<<"You did not enter a valid number of states. Please enter a correct number of states: "<<endl;
    cin>>num_states;
 }
 return num_states;
}
/********************************************************************* 
 * ** Function: state* create_states
 * ** Description: creates and array of states
 * ** Parameters:int num_states
 * ** Pre-Conditions:none
 * ** Post-Conditions:none
 **********************************************************************/
state* create_states(int num_states){
   
   state* s= new state[num_states];
  
 return s;
 }
/********************************************************************* 
 * ** Function: void get_state_data
 * ** Description: reads data from file and puts in states array
 * ** Parameters:state* s, int i, ifstream &input
 * ** Pre-Conditions:none
 * ** Post-Conditions:none
 **********************************************************************/
void get_state_data(state* s, int i, ifstream &input){

   input>>s[i].name;
   input>>s[i].population;
   input>>s[i].counties; 
   
}
/********************************************************************* 
 * ** Function:county* create_counties 
 * ** Description: creates county array
 * ** Parameters:int num_counties
 * ** Pre-Conditions:none
 * ** Post-Conditions:none
 **********************************************************************/
county* create_counties(int num_counties){
   county* c= new county[num_counties];
   return c;
}

/********************************************************************* 
 * ** Function: void get_county_data
 * ** Description: reads data from file and puts in county array
 * ** Parameters:county* c, int num_counties, ifstream &input
 * ** Pre-Conditions:none
 * ** Post-Conditions:none
 **********************************************************************/
void get_county_data(county* c, int num_counties, ifstream &input){
   for(int i=0; i<num_counties; i++){
      input>>c[i].name;
      input>>c[i].population;
      input>>c[i].avg_income;
      input>>c[i].avg_house;
      input>>c[i].cities;
      int cities=c[i].cities;
      //Create city array
      c[i].city= new string[cities];
      for(int j=0; j<cities; j++){
	 input>>c[i].city[j];
      }
   }
   
}
/********************************************************************* 
 * ** Function: void print_options
 * ** Description: prints info to screen or a file
 * ** Parameters:sttae* s. int num_states, int &largestatepop, int &largecountypop, ifstream &input, ofstream &output
 * ** Pre-Conditions:none
 * ** Post-Conditions:none
 *********************************************************************/
/*void print_options(state* s, int num_states, int &largestatepop, int &largecountypop, ifstream &input, ofstream &output){
 int choice;
 string ofile;
 ofstream output;

 do{
   cout<<"Would you like to print this information to the screen(1) or to a file(2)?"<<endl;
   cin>>choice;
   
   if(choice==1){
   //print to screen
   state_largest_population(s, num_states, largestatepop);
   county_largest_population(s, num_states, largecountypop);
   income_above(s, num_states);
   avg_house_price(s, num_states);
   sort_state_name(s, num_states);
   sort_statename_pop(s, num_states);
   //sort_county_name(s, num_states);
   //sort_countyname_pop(s, num_states);
   }
   else if(choice==2){
   //print to file
   cout<<"Please enter a filename: "<<endl;
   getline(cin, ofile);

   output.open(ofile.c_str());

   output<<state_largest_population(s, num_states, largestatepop)<<endl;
   output<<county_largest_population(s, num_states, largecountypop)<<endl;
   output<<income_above(s, num_states)<<endl;
   output<<avg_house_price(s, num_states)<<endl;
   output<<sort_state_name(s, num_states)<<endl;
   output<<sort_statename_pop(s, num_states)<<endl;
   //output<<sort_county_name(s, num_states)<<endl;
   //output<<sort_countyname_pop(s, num_states)<<endl;


   }
   else{
   cout<<"You did not enter a correct choice."<<endl;
   }

   }while(choice!=1 && choice!=2);

}*/
/********************************************************************* 
 * ** Function: void state_largest_population
 * ** Description: finds the state with the largest population
 * ** Parameters: state* s int num_states, int &largstatepop
 * ** Pre-Conditions:none
 * ** Post-Conditions:none
 *********************************************************************/
void state_largest_population(state* s, int num_states, int &largestatepop){
   int x=0;
   string name=s[0].name;

   for(int i=0; i<num_states; i++){
      if(s[i].population>largestatepop){
	 largestatepop = s[i].population;
	 name=s[i].name;
      }
   }
   cout<<"State with Largest Population: "<<name<<endl;
  
}

/********************************************************************* 
 * ** Function: void county_largest_population
 * ** Description: finds the ocunty with th largest population
 * ** Parameters:state* s, int num_states, int &largecountypop
 * ** Pre-Conditions:none
 * ** Post-Conditions:none
 *********************************************************************/
void county_largest_population(state* s, int num_states, int &largecountypop){
   string name;
   
   for(int i=0; i<num_states; i++){
      for(int j=0; j<(s[i].counties); j++){	 
	 if(s[i].c[j].population > largecountypop){
	    largecountypop = s[i].c[j].population;
	    name= s[i].c[j].name;  
	 }
      }
   }

   cout<<"County with Largest Population: "<<name<<endl;
}

/********************************************************************* 
 * ** Function: void income_above(state* s, int num_states
 * ** Description: finds a county with an income above a number
 * ** Parameters:state* s, int num_states
 * ** Pre-Conditions:none
 * ** Post-Conditions:none
 *********************************************************************/
void income_above(state* s, int num_states){
   int size=0;
   int x;
   int k=0;
   cout<<"Please enter an minimum income: "<<endl;
   cin>>x;

   for(int i=0; i<num_states; i++){
      for(int j=0; j<s[i].counties; j++){
	 if(s[i].c[j].avg_income> x){
	    size++;
	 }
      }
   }

   string* income=new string[size];
   for(int i=0; i<num_states; i++){
      for(int j=0; j<s[i].counties; j++){
         if(s[i].c[j].avg_income>x){	 
	    income[k]= s[i].c[j].name;
            k++;
	 }
      }
   }
cout<<"Counties above that income: "<<endl;
for(int i=0; i<size; i++){
   cout<<income[i]<<endl;
}
}
/********************************************************************* 
 * ** Function: void avg_house_price
 * ** Description: finds the avg house price in a county
 * ** Parameters:state* s, int num_states
 * ** Pre-Conditions:none
 * ** Post-Conditions:none
 *********************************************************************/
void avg_house_price(state* s, int num_states){
   int total=0;
   int average=0;

   for(int i=0; i<num_states; i++){
      for(int j=0; j<s[i].counties; j++){
	 total+=s[i].c[j].avg_house;
      }
      average= total/s[i].counties;
      cout<<"Average house prices of the counties in "<<s[i].name<<": "<<average<<endl;
   }

}
/********************************************************************* 
 * ** Function: void sort_state_name
 * ** Description: sorts the states alphabetically
 * ** Parameters: state* s, int num_states
 * ** Pre-Conditions: none
 * ** Post-Conditions:none
 *********************************************************************/
void sort_state_name(state* s, int num_states){
  string* sname_sort= new string[num_states];
   for(int i=0; i<num_states; i++){
     if(i<num_states-1){
	if(s[i].name>s[i+1].name){
           sname_sort[i]=s[i+1].name;
        }
        else{
           sname_sort[i]=s[i].name;
        }
     }
     else{
	sname_sort[i]=s[i].name;
     }
   }
   cout<<"State Names in order by alphabet: "<<endl;
   for(int i=0; i<num_states; i++){
      cout<<sname_sort[i]<<endl;
   }
}
/********************************************************************* 
 * ** Function:sort_name_pop 
 * ** Description: sorts the states by population
 * ** Parameters:state* s, int num_states
 * ** Pre-Conditions:none
 * ** Post-Conditions:none
 *********************************************************************/
void sort_statename_pop(state* s, int num_states){
   string* spop_sort= new string[num_states];
   for(int i=0; i<num_states; i++){
      if(i<num_states-1){
	 if(s[i].population>s[i+1].population){
	    spop_sort[i]=s[i+1].name;
	 }
	 else{
	    spop_sort[i]=s[i].name;
	 }
      }
      else{
         spop_sort[i]=s[i].name;
      }
    }
    cout<<"State Names in order by population: "<<endl;
    for(int i=0; i<num_states; i++){
      cout<<spop_sort[i]<<endl;
    }
}

/********************************************************************* 
 * ** Function:void sort_county_name(state* s, int num_states
 * ** Description: sorts the counties alphabetically
 * ** Parameters: state* s, int num_states
 * ** Pre-Conditions:none
 * ** Post-Conditions:none
 *********************************************************************/
void sort_county_name(state* s, int num_states){
   for(int i=0; i<num_states; i++){
      string* cname_sort=new string[s[i].counties];
      for(int j=0; j<s[i].counties; j++){
         if(i<s[i].counties-1){
	    if(s[i].c[j].name>s[i].c[j+1].name){
	       cname_sort[i]=s[i].c[j+1].name;
	    }
	    else{
	       cname_sort[i]=s[i].c[i].name;
	    }
         }
         else{
	    cname_sort[i]=s[i].c[i].name;
         }
      }
      cout<<"County Names in order by alphabet in the state "<<s[i].name<<": "<<endl;
      for(int i=0; i<s[i].counties; i++){
	 cout<<cname_sort[i]<<endl;
      }
   }
}
/********************************************************************* 
 * ** Function: void sort_countyname_pop
 * ** Description: sorts the counties in each state by population
 * ** Parameters: state* s, int num_states
 * ** Pre-Conditions:none
 * ** Post-Conditions:none
 *********************************************************************/
void sort_countyname_pop(state* s, int num_states){
   for(int i=0; i<num_states; i++){
      string* cpop_sort=new string[s[i].counties];
      for(int j=0; j<s[i].counties; j++){
      if(i<s[i].counties-1){
	 if(s[i].c[j].population>s[i].c[j+1].population){
	    cpop_sort[i]=s[i].c[j+1].name;
	 }
	 else{
	    cpop_sort[i]=s[i].c[i].name;
	 }
      }
      else{
	 cpop_sort[i]=s[i].c[i].name;
      }
      }
      cout<<"County Names in order by population in the state "<<s[i].name<<": "<<endl;
      for(int i=0; i<s[i].counties; i++){
	 cout<<cpop_sort[i]<<endl;
      }
   }
}

/********************************************************************* 
 * ** Function:void check_print
 * ** Description: checks to see if the info in the file is stored correctly
 * ** Parameters: sttae* s, int num_states
 * ** Pre-Conditions: none
 * ** Post-Conditions:none
 *********************************************************************/
void check_print(state* s, int num_states){
   for(int i=0; i<num_states; i++){
      cout<<"State Name: "<<s[i].name<<endl;
      cout<<"State Population: "<<s[i].population<<endl;
      cout<<"State Counties: "<<s[i].counties<<endl;
      for(int j=0; j<s[i].counties; j++){
	 cout<<"County Name: "<<s[i].c[j].name<<endl;
	 cout<<"County Pop: "<<s[i].c[j].population<<endl;
	 cout<<"Avg. Income: "<<s[i].c[j].avg_income<<endl;
	 cout<<"Number of cities: "<<s[i].c[i].cities<<endl;
	 cout<<"House price: "<<s[i].c[j].avg_house<<endl;
	 for(int k=0; k<s[i].c[j].cities; k++){
	    cout<<"City Name: "<<s[i].c[j].city[k]<<endl;
	 }
      }
   }
}
/********************************************************************* 
 * ** Function:delete_info 
 * ** Description: deletes the dynamic arrays 
 * ** Parameters:state** s, int num_states
 * ** Pre-Conditions:none
 * ** Post-Conditions:none
 *********************************************************************/	    
void delete_info(state** s, int num_states){
   for(int i=0; i<num_states; i++){
      for(int j=0; j<(*s)[i].counties; j++){
	    delete [] (*s)[i].c[j].city;
	    (*s)[i].c[j].city=NULL;
	 }
	 delete [] s[i]->c;
	 (*s)[i].c=NULL;
      }
   
      delete [] *s;
      *s = NULL;
}

