#include "skateboard.h"

Skateboard::Skateboard(){

   motorized = false;
   wheels = 4;
   speed = 20;

}

const string Skateboard::type = "Skateboard";

void Skateboard::setMotorized(bool m){
   motorized = m;
}

void Skateboard::setWheels(int w){
   wheels = w;
}

void Skateboard::setSpeed(int s){
   speed = s;
}

bool Skateboard::getMotorized(){
   return motorized;
}

int Skateboard::getWheels(){
   return wheels;
}

const string Skateboard::getType(){
   return type;
}

int Skateboard::getSpeed(){
   return speed;
}

int Skateboard::getDistance(){

   int distance = Vehicle::getDistance();

   return distance;
}
