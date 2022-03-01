#include <iostream>
#include "Source.h"
#include "RocketMain.cpp"
#include "RocketEngine.cpp"
using namespace std;

int main() {
    string request;
    RocketMain rocket;
    while(request != "close") {
        cout << "Enter command one of those commands: setRocket, checkRocket or close" << endl;
        cin >> request;

        if (request == "setRocket"){
                    
                    rocket.name = rocket.setName();
                    cout << "Your rocket's name is " + rocket.name << endl;

                    rocket.tankHeight = rocket.setTankHeight();
                    cout << "Your tank height is ";
                    cout << rocket.tankHeight << endl;

                    cout << "Enter an outer radius for the tank" << endl;
                    rocket.tankOuterRadius = rocket.setTankRadius();
                    cout << "Your tank outer radius is ";
                    cout << rocket.tankOuterRadius << endl;

                    cout << "Enter an inner radius for the tank" << endl;
                    rocket.tankInnerRadius = rocket.setTankRadius();
                    cout << "Your tank inner radius is ";
                    cout << rocket.tankInnerRadius << endl;

                    rocket.tankEmptyVolume = rocket.tankEmptyVolumeFunc(rocket.tankOuterRadius, rocket.tankInnerRadius, rocket.tankHeight);
                    cout << "Your tank volume without fuel is: ";
                    cout << rocket.tankEmptyVolume<< endl;

                    rocket.tankFuelVolume = rocket.tankFuelVolumeFunc(rocket.tankOuterRadius, rocket.tankInnerRadius, rocket.tankHeight);
                    cout << "Your tank volume for fuel is: ";
                    cout << rocket.tankFuelVolume << endl;

                    rocket.tankMat = rocket.setMat();
                    cout << "Your tank material mass is: ";
                    cout << rocket.tankMat << endl;

                    rocket.tankWeight = rocket.tankWeightFunc(rocket.tankEmptyVolume, rocket.tankMat);
                    cout << "Your tank weight is: ";
                    cout << rocket.tankWeight << endl;
                
        }

        if (request == "checkRocket") {
            if(rocket.name != "") {
                cout << rocket.name << endl;
                cout << "Tank Height is: ";
                cout << rocket.tankHeight << endl;
                cout << "Tank Fuel Volume is: ";
                cout << rocket.tankFuelVolume << endl;
                cout << "Your tank weight without fuel is: ";
                cout << rocket.tankWeight << endl;
            }
            else
            {
                cout << "Any rocket is setup" << endl;
            }
            

        }
    }
}