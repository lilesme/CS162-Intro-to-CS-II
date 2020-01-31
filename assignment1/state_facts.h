//Header (.h file)
//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include <cstring>
#include <string>
using namespace std;
struct county{
   string name; //name of county
   string* city; //name of cities in county
   int cities; //number of cities in county
   int population; //total population of county
   float avg_income; //average household income
   float avg_house; //average household price
};

struct state{
   string name; //name of state
   struct county *c; //name of counties
   int counties; //number of counties in state
   int population; //total population of state

};

bool is_valid_arguments(char*[], int);
void check_file_exists(char*, ifstream &);
void store_file_name(char* [], int, char*);
int find_num_states(char* [], int);
state* create_states(int);
void get_state_data(state *, int, ifstream &);
county* create_counties(int);
void get_county_data(county *, int, ifstream &);
void delete_info(state **, int);
void print_options(state*, int, int&, int&, ifstream &, ofstream &);
void state_largest_population(state*, int, int &);
void county_largest_population(state*, int, int &);
void avg_house_price(state*, int);
void income_above(state*, int);
void sort_state_name(state*, int);
void check_print(state*, int);
void sort_state_name(state*, int);
void sort_statename_pop(state*, int);
void sort_county_name(state*, int);
void sort_countyname_pop(state*, int);
