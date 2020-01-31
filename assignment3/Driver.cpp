#include <iostream>
#include <cstdlib>
#include <string>
#include "World.h"

using namespace std;
/*********************************************************************
 ** Function: int Main
 ** Description: calls main menu
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/

int main(){

   //initialize random seed
   srand (time(NULL));
   World w;
   w.main_menu();



   return 0;
}
