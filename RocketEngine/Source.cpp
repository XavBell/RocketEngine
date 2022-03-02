#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Source.h"
#include "RocketMain.cpp"
#include "RocketEngine.cpp"


using namespace std;

int main() {

    string request;
    RocketMain rocket;
    while(request != "close") {
        cout << "Enter one of those commands: setRocket, checkRocket or close" << endl;
        cin >> request;

        if (request == "setRocket"){
            while (request!="back")
            {
                cout << "Enter one of those commands: addTank or back" << endl;
                cin >> request;
                if(request == "addTank") {

                //First tank
                rocket.tankN = rocket.tankN + 1;

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
                cout << rocket.tankEmptyVolume << endl;

                rocket.tankFuelVolume = rocket.tankFuelVolumeFunc(rocket.tankOuterRadius, rocket.tankInnerRadius, rocket.tankHeight);
                cout << "Your tank volume for fuel is: ";
                cout << rocket.tankFuelVolume << endl;

                rocket.tankMat = rocket.setMat();
                cout << "Your tank material mass is: ";
                cout << rocket.tankMat << endl;

                rocket.tankWeight = rocket.tankWeightFunc(rocket.tankEmptyVolume, rocket.tankMat);
                cout << "Your tank weight is: ";
                cout << rocket.tankWeight << endl;

                int i = rocket.tankN - 1;
                rocket.tankWeights[i] = rocket.tankWeight;
                rocket.tankFuelVolumes[i] = rocket.tankFuelVolume;
                i = 0;
                }

            }
        }

        if (request == "checkRocket") {
                while(request != "back") {
                    cout << "Enter one of those commands or type back: getTankInfo, save" << endl;
                    cin >> request;
                    if(request == "getTankInfo") {
                        int tankCheck;
                        cout << "Enter the tank number, 1 to ";
                        cout << rocket.tankN << endl;
                        cin >> tankCheck;
                        int i = tankCheck - 1;
                        cout << "Tank weight without fuel of this tank is: ";
                        cout << rocket.tankWeights[i]<<endl;
                        cout << "Tank volume for fuel of this tank is: ";
                        cout << rocket.tankFuelVolumes[i]<<endl;
                    }

                    if(request == "save") {
                        string filename;
                        cout << "Enter a filename" << endl;
                        cin >> filename;
                        filename = filename + ".txt";
                        ofstream file_obj;

                        // Opening file in append mode
                        file_obj.open(filename, ios::app);
                       
                        if(file_obj.is_open()) {
                           file_obj.write((char*)&rocket, sizeof(RocketMain));
                           cout << "File writed successfully" << endl;
                           file_obj.close();
                        }
                        else cout << "Can't open file!" << endl;

                    }

                    if(request == "load") {
                        string filename;
                        cout << "Enter a filename" << endl;
                        cin >> filename;
                        filename = filename + ".txt";
                        ifstream file_obj;
                        file_obj.open(filename, ios::in);
                        if(file_obj.is_open()) {
                            while (!file_obj.eof()) {
                                cout << "Opened" << endl;
                                file_obj.read((char*)&rocket, sizeof(RocketMain));
                            }
                        }
                    
                    }
                }
            }

        }
    
}