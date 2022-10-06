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

		double pi = M_PI;

		double angleofLaunch;

		cout << "Enter angle of launch" << endl;
		cin >> angleofLaunch;

		double radAngle = angleofLaunch * (pi / 180);

		double sinAngle = sin(radAngle) * (180/pi);
		double cosAngle = cos(radAngle) * (180/pi);
		
		double accy = 9.8 * ((thrust/weight)*sinAngle - 1);
		cout << "Acceleration on Y for thrust part of the flight is: " << accy << "m/s^2" << endl;


		double accx = 9.8 * ((thrust / weight) * cosAngle);
		cout << "Acceleration on X for thrust part of the flight is: " << accx << "m/s^2" << endl;


		double vy = (9.8 *specificImpulse*log(weight/weightAfterFlight)*sinAngle) - (9.8 * burnTime);
		cout << vy << " m/s on Y axis" << endl;

		double vx = 9.8 * specificImpulse * log(weight / weightAfterFlight)*cosAngle;
		cout << vx << " m/s on X axis" << endl;


		//Position at burnout
		double yp = (9.8 * specificImpulse * (1 - (log(weight / weightAfterFlight) / (weight / weightAfterFlight - 1))) * sinAngle) - (0.5*9.8*sqrt(burnTime));
		double xp = 9.8 * specificImpulse * (1 - (log(weight / weightAfterFlight) / (weight / weightAfterFlight - 1))) * cosAngle;

		//Apogee
		double ypu = 0.5 * sqrt(vy) / 9.8;
		double apogee = yp + ypu;
		cout << "Apogee (m): " << apogee << endl;
		
	}

};