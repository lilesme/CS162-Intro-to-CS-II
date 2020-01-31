#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include <string>
#include "vehicle.h"

using namespace std;

class Motorcycle : public Vehicle {

   private:
      bool motorized;
      int wheels;
      static const string type;
      int speed;

   public:

      Motorcycle();

      void setMotorized(bool);
      void setWheels(int);
      void setSpeed(int);

      bool getMotorized();
      int getWheels();
      const string getType();
      int getSpeed();

      int getDistance();
};

#endif
