#include <iostream>
#include "rocket.h"
#include "RocketMain.h"
#include "Source.h"
#include "RocketMain.cpp"
using namespace std;

int main() {
    string request;
    RocketMain rocket;
    while(request != "close") {
        cout << "Enter command one of those commands: setRocket or close" << endl;
        cin >> request;

        if (request == "setRocket"){

                    rocket.name = rocket.setName(rocket.name);
                    cout << "Your rocket's name is " + rocket.name << endl;

                    rocket.tankHeight = rocket.setTankHeight(rocket.tankHeight);
                    cout << "Your tank height is ";
                    cout << rocket.tankHeight << endl;

                    rocket.tankRadius = rocket.setTankRadius(rocket.tankRadius);
                    cout << "Your tank radius is ";
                    cout << rocket.tankRadius << endl;

                    rocket.tankVolume = rocket.tankVolumeFunc(rocket.tankRadius, rocket.tankHeight, rocket.tankVolume);
                    cout << "Your tank volume is: ";
                    cout << rocket.tankVolume<< endl;
                
        }

        if (request == "checkRocket") {
            cout << rocket.name << endl;
            cout << "Tank Height is: ";
            cout << rocket.tankHeight << endl;
            cout << "Tank Radius is: ";
            cout << rocket.tankRadius << endl;
            cout << "Tank Volume is: ";
            cout << rocket.tankVolume << endl;

        }
    }
}