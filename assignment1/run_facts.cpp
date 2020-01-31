//Main file (run_facts.cpp)
#include "state_facts.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
/********************************************************************* 
 * ** Function: main
 * ** Description: calls functions
 * ** Parameters: int argc, char* [] argv
 * ** Pre-Conditions:
 * ** Post-Conditions:
 **********************************************************************/
int main(int argc, char* argv[]){
   ifstream input;
   ofstream output;
   char* file = new char[256];
   state* s;
   county* c;
   int num_counties=0;
   int largestatepop=0;
   int largecountypop=0;
   int* sort_snames_pop;

   is_valid_arguments(argv, argc);
   //store file name
   store_file_name(argv, argc, file);
   //check file exists
   check_file_exists(file, input);
   //find the number of states
   int num_states=find_num_states(argv, argc);
   //create state array
   s=create_states(num_states);
   //put data in state array
   for(int i=0; i<num_states; i++){
      get_state_data(s, i, input);
      num_counties= s[i].counties;
      s[i].c=create_counties(num_counties);
      get_county_data(s[i].c, num_counties, input);
      
   }
   state_largest_population(s, num_states, largestatepop) ;
   county_largest_population(s, num_states, largecountypop);
   avg_house_price(s, num_states);
   income_above(s, num_states);
   sort_state_name(s, num_states);
   sort_statename_pop(s, num_states);
   sort_county_name(s, num_states);
   sort_countyname_pop(s, num_states);
   //print_options(s, num_states, largestatepop, largecountypop, input, output);
   //check_print(s, num_states);
   delete_info(&s, num_states);
   return 0;

}
