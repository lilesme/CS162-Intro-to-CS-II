#include "motorcycle.h"

Motorcycle::Motorcycle(){

   motorized = true;
   wheels = 2;
   speed = 80;
}

const string Motorcycle::type = "Motorcycle";

void Motorcycle::setMotorized(bool m){
   motorized = m;
}

void Motorcycle::setWheels(int w){
   wheels = w;
}

void Motorcycle::setSpeed(int s){
   speed = s;
}

bool Motorcycle::getMotorized(){
   return motorized;
}

int Motorcycle::getWheels(){
   return wheels;
}

const string Motorcycle::getType(){
   return type;
}

int Motorcycle::getSpeed(){
   return speed;
}

int Motorcycle::getDistance(){

   int time = 0;
   cout << "Time for motorcycle? : " << endl;
   cin >> time;
   int distance = Vehicle::getDistance();


   return distance;
}
