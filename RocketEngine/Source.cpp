#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <tchar.h>
#include <conio.h>
#include <strsafe.h>
#include "Source.h"
#include "RocketMain.cpp"
#include "FlightSimulation.cpp"


using namespace std;

int main() {

    TCHAR szOldTitle[MAX_PATH];
    TCHAR szNewTitle[MAX_PATH];


    if (GetConsoleTitle(szOldTitle, MAX_PATH))
    {
        // Build new console title string.

        StringCchPrintf(szNewTitle, MAX_PATH, TEXT("RocketEngine"), szOldTitle);

        // Set console title to new title
        if (!SetConsoleTitle(szNewTitle))
        {
            _tprintf(TEXT("SetConsoleTitle failed (%d)\n"), GetLastError());
            return 1;
        }
    }



    string request;
    RocketMain rocket;
    while(request != "close") {
        cout << "Enter one of those commands: setRocket, checkRocket or close" << endl;
        cin >> request;

        if (request == "setRocket"){
            while (request!="back")
            {
                cout << "Enter one of those commands: addStage or back" << endl;
                cin >> request;
                if(request == "addStage") {

                //Tank
                rocket.tankN = rocket.tankN + 1;

                rocket.tankHeight = rocket.setTankHeight();
                //Edit cout
                cout << "Your tank height is ";
                cout << rocket.tankHeight << endl;

                cout << "Enter an outer radius for the tank (m)" << endl;
                rocket.tankOuterRadius = rocket.setTankRadius();
                cout << "Your tank outer radius is ";
                cout << rocket.tankOuterRadius << endl;

                cout << "Enter an inner radius for the tank (m)" << endl;
                rocket.tankInnerRadius = rocket.setTankRadius();
                cout << "Your tank inner radius is ";
                cout << rocket.tankInnerRadius << endl;

                rocket.tankEmptyVolume = rocket.tankEmptyVolumeFunc(rocket.tankOuterRadius, rocket.tankInnerRadius, rocket.tankHeight);
                cout << "Your tank volume without fuel is: ";
                cout << rocket.tankEmptyVolume << endl;

                rocket.tankPropellantVolume = rocket.tankPropellantVolumeFunc(rocket.tankOuterRadius, rocket.tankInnerRadius, rocket.tankHeight);
                cout << "Your tank volume for propellant/oxidizer is: ";
                cout << rocket.tankPropellantVolume << endl;

                rocket.tankMat = rocket.setMat();
                cout << "Your tank material mass is: ";
                cout << rocket.tankMat << endl;

                rocket.tankWeight = rocket.tankWeightFunc(rocket.tankEmptyVolume, rocket.tankMat);
                cout << "Your tank weight is: ";
                cout << rocket.tankWeight << endl;

                rocket.tankFuelVolume = rocket.tankFuelVolumeFunc(rocket.tankPropellantVolume);
                cout << "Set" << endl;

                rocket.tankOxidizerVolume = rocket.tankOxidizerVolumeFunc(rocket.tankPropellantVolume, rocket.tankFuelVolume);
                cout << "Set" << endl;

                rocket.fuelChoice = rocket.fuelChoiceFunc();
                cout << "Set" << endl;

                rocket.oxidizerChoice = rocket.oxidizerChoiceFunc();
                cout << "Set" << endl;
                
                //Engine
                rocket.oradius = rocket.engineOuterChamberRadius();
                rocket.iradius = rocket.engineInnerChamberRadius();
                rocket.cheight = rocket.engineChamberHeight();
                rocket.ofradius = rocket.throatOuterFirstRadius();
                rocket.ifradius = rocket.throatInnerFirstRadius();
                rocket.isradius = rocket.throatInnerSecondRadius();
                rocket.osradius = rocket.throatOuterSecondRadius();
                rocket.nheight = rocket.nozzleHeight();
                rocket.theight = rocket.throatHeight();
                rocket.eMass = rocket.engineMass(rocket.oradius, rocket.iradius, rocket.ofradius, rocket.ifradius, rocket.osradius, rocket.isradius, rocket.nheight, rocket.cheight);
                rocket.eThrust = rocket.engineThrustFunc();
                rocket.massFlowRate = rocket.engineMassFlowRateFunc();


                //Saving data
                int i = rocket.tankN - 1;
                rocket.tankWeights[i] = rocket.tankWeight;
                rocket.tankHeights[i] = rocket.tankHeight;
                rocket.tankInnerRadiuses[i] = rocket.tankInnerRadius;
                rocket.tankOuterRadiuses[i] = rocket.tankOuterRadius;
                rocket.tankPropellantVolumes[i] = rocket.tankPropellantVolume;
                rocket.tankFuelVolumes[i] = rocket.tankFuelVolume;
                rocket.tankOxidizerVolumes[i] = rocket.tankOxidizerVolume;
                rocket.tankFuelChoices[i] = rocket.fuelChoice;
                rocket.tankOxidizerChoices[i] = rocket.oxidizerChoice;
                rocket.eMasses[i] = rocket.eMass;
                rocket.ethrusts[i] = rocket.eThrust;
                rocket.eRates[i] = rocket.massFlowRate;
                i = 0;

                
                }

            }
        }

        if (request == "checkRocket") {
                while(request != "back") {
                    cout << "Enter one of those commands or type back: getTankInfo, launch, save, load, writeStats" << endl;
                    cin >> request;
                    if(request == "getTankInfo") {
                        int tankCheck;
                        cout << "Enter the tank number, 1 to ";
                        cout << rocket.tankN << endl;
                        cin >> tankCheck;
                        int i = tankCheck - 1;
                        cout << "Tank weight without fuel of this tank is: ";
                        cout << rocket.tankWeights[i]<<endl;
                        cout << "Tank height of this tank is: ";
                        cout << rocket.tankHeights[i] << endl;
                        cout << "Tank inner radius of this tank is: ";
                        cout << rocket.tankInnerRadiuses[i] << endl;
                        cout << "Tank outer radius of this tank is: ";
                        cout << rocket.tankOuterRadiuses[i] << endl;
                        cout << "Tank volume for propellant of this tank is: ";
                        cout << rocket.tankPropellantVolumes[i]<<endl;
                    }

                    if(request == "launch") {
                        Simulation sim;
                        sim.launch(rocket.ethrusts[0], rocket.tankWeights[0], rocket.eMasses[0], rocket.tankFuelVolumes[0], rocket.tankOxidizerVolumes[0], rocket.tankFuelChoices[0], rocket.tankOxidizerChoices[0], rocket.eRates[0]);
                    }

                    if(request == "save") {
                        string filename;
                        cout << "Enter a filename" << endl;
                        cin >> filename;
                        filename = filename + "data.txt";
                        ofstream file_obj;

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
                        filename = filename + "data.txt";
                        ifstream file_obj;
                        file_obj.open(filename, ios::in);
                        if(file_obj.is_open()) {
                            while (!file_obj.eof()) {
                                cout << "Opened" << endl;
                                file_obj.read((char*)&rocket, sizeof(RocketMain));
                            }
                        }
                    
                    }

                    if (request == "writeStats") {
                        string filename;
                        cout << "Enter a filename" << endl;
                        cin >> filename;
                        filename = filename + "stats.txt";
                        ofstream file;

                        file.open(filename, ios::app);
                        int i = rocket.tankN - 1;
                        if (file.is_open()) {
                            file << "Tank weight: " << rocket.tankWeights[i] << endl;
                            file << "Tank height: " << rocket.tankHeights[i] << endl;
                            file << "Tank outer radius: " << rocket.tankOuterRadiuses[i] << endl;
                            file << "Stage thrust: " << rocket.ethrusts[i] << endl;
                            file.close();
                        }
                        else cout << "Can't open file!" << endl;

                    }
                }
            }

        }
        cout << "Closing safely" << endl;
        return 0;
    
}