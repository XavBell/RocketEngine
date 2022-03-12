#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <tchar.h>
#include <conio.h>
#include <strsafe.h>
#include "Source.h"
#include "RocketMain.cpp"
#include <math.h>


using namespace std;

class Simulation{
public:

	double totalWeight = 0;



	double weightFunc(double tankMass, double engineMass, double fuelVolume, double oxidizerVolume, int fuelChoice, int oxidizerChoice) {
		double fuelWeight = 0;
		double oxidizerWeight = 0;
		if(fuelChoice == 1) {
			fuelWeight = fuelVolume * 800;
		}

		if (oxidizerChoice == 1) {
			oxidizerWeight = oxidizerVolume * 1141;
		}

		double weight = tankMass + engineMass + fuelWeight + oxidizerWeight;
		return weight;
	}


	void launch(double thrust, double tankMass, double engineMass, double fuelVolume, double oxidizerVolume, int fuelChoice, int oxidizerChoice, double massFlowRate) {
		double weight = weightFunc(tankMass, engineMass, fuelVolume, oxidizerVolume, fuelChoice, oxidizerChoice);
		double oxidizerFuelRatio = 0;
		double usableFuel = 0;
		double usableOxidizer = 0;
		double burnTime = 0;
		double specificImpulse = 0;
		double weightAfterFlight = 0;

		if(oxidizerChoice == 1 and fuelChoice == 1) {
			oxidizerFuelRatio = 2.56;
		}

		double fuelWeight = 0;
		double oxidizerWeight = 0;
		if (fuelChoice == 1) {
			fuelWeight = fuelVolume * 800;
		}

		if (oxidizerChoice == 1) {
			oxidizerWeight = oxidizerVolume * 1141;
		}

		usableFuel = oxidizerWeight / oxidizerFuelRatio;

		if (usableFuel  > fuelWeight) {
			usableOxidizer = fuelWeight * oxidizerFuelRatio;
			burnTime = (fuelWeight+usableOxidizer) / massFlowRate;
			specificImpulse = (thrust * burnTime) /(fuelWeight+usableOxidizer);
			weightAfterFlight = weight - (fuelWeight+usableOxidizer);

		} else if (usableFuel < fuelWeight) {
			burnTime = (usableFuel+oxidizerWeight) / massFlowRate;
			specificImpulse = (thrust * burnTime) /(usableFuel+oxidizerWeight);
			weightAfterFlight = weight - (usableFuel + oxidizerWeight);
		}

		cout << burnTime << " s"<< endl;

		double accy = 9.8 * ((thrust/weight)-1);
		cout << "Acceleration on Y for thrust part of the flight is: " << accy << "m/s^2" << endl;


		double vy = 9.8 *specificImpulse*log(weight/weightAfterFlight)-(9.8*burnTime);
		cout << vy << " m/s" << endl;

		double apogee = 0.5 * pow(vy, 2) / 9.8;
		cout << apogee << " m" << endl;
	}

};