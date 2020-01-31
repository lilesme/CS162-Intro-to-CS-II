#include "vehicle.h"
#include "skateboard.h"
#include "motorcycle.h"
#include "bike.h"
#include "racecar.h"
#include <string>
#include <iostream>

using namespace std;

int main(){

   Skateboard s;
   Motorcycle m;
   Bike b;
   Racecar r;

   /*int rdistance = r.getDistance();
   int mdistance = m.getDistance();

   if(rdistance > mdistance){
      cout << "Racecar wins!" << endl;
   }
   else{
      cout << "Motorcycle wins!" << endl;
   }*/

   if(m > r){
      cout << "Motorcycle wins!" << endl;
   }
   else{
      cout << "Racecar wins!" << endl;
   
   }

   return 0;
}
