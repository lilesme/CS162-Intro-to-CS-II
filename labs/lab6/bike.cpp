#include "bike.h"

using namespace std;

Bike::Bike(){

   motorized = false;
   wheels = 2;
   speed = 10;
}

const string Bike::type = "Bike";

void Bike::setMotorized(bool m){
   motorized = m;
}

void Bike::setWheels(int w){
   wheels = w;
}

void Bike::setSpeed(int s){
   speed = s;
}

bool Bike::getMotorized(){
   return motorized;
}

int Bike::getWheels(){
   return wheels;
}
const string Bike::getType(){
   return type;
}

int Bike::getSpeed(){
   return speed;
}

int Bike::getDistance(){

   int distance = Vehicle::getDistance();

   return distance;
}
