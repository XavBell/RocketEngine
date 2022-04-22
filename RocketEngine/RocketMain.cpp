#include <iostream>
using namespace std;
#include <math.h>

#pragma once
class RocketMain{
public:

	//Tanks variables
	double tankHeight = 0.0;
	double tankInnerRadius = 0.0;
	double tankOuterRadius = 0.0;
	double tankEmptyVolume = 0.0;
	double tankPropellantVolume = 0.0;
	double tankMat = 0.0;
	double tankWeight = 0.0;
	double tankFuelVolume = 0.0;
	double tankOxidizerVolume = 0.0;
	int fuelChoice = 0;
	int oxidizerChoice = 0;
	int tankN = 0;

	string fuelName;
	string oxidizerName;

	double tankWeights[10];
	double tankHeights[10];
	double tankInnerRadiuses[10];
	double tankOuterRadiuses[10];
	double tankPropellantVolumes[10];
	double tankFuelVolumes[10];
	double tankOxidizerVolumes[10];
	int tankFuelChoices[10];
	int tankOxidizerChoices[10];

	//Engine variables
	double eMass = 0;
	double eThrust = 0;
	double massFlowRate = 0;

	//Chamber variables
	double oradius = 0;
	double iradius = 0;
	double cheight = 0;

	//Throat variables
	double ofradius = 0;
	double ifradius = 0;
	double osradius = 0;
	double isradius = 0;
	double theight = 0;
	double nheight = 0;

	double eMasses[10];
	double ethrusts[10];
	double eRates[10];


	//Functions for tanks
	double setTankHeight() {
		double theight;
		cout << "Enter a height for the tank (m)" << endl;
		cin >> theight;
		return theight;
	}

	double setTankRadius() {
		double tradius;
		cin >> tradius;
		return tradius;
	}

	double tankEmptyVolumeFunc(float tOradius, float tIradius, float theight) {
		double tankEmptyVolume;
		double pi = 2 * acos(0.0);
		float outerVolume = pi * pow(tOradius, 2) * theight;
		float innerVolume = pi * pow(tIradius, 2) * theight;
		tankEmptyVolume = outerVolume-innerVolume;
		return tankEmptyVolume;
	}

	double tankPropellantVolumeFunc(float tOradius, float tIradius, float theight) {
		double tankVolume;
		double pi = 2 * acos(0.0);
		tankPropellantVolume = pi * pow(tIradius, 2) * theight;
		return tankPropellantVolume;
	}

	double setMat() {
		string a;
		double choice;
		cout << "Enter a material volumetric weight for the tank: Type 1 for aluminium" << endl;
		cin>>a;
		if (a == "1") {
			choice = 2699;
			return choice;
		}
	}

	double tankWeightFunc(double tVolume, double tMaterial) {
		double tWeight;
		tWeight = tVolume * tMaterial;
		return tWeight;
	}

	double tankFuelVolumeFunc(double tVolume) {
		double tankFuelVolume;
		cout << "Enter volume designed to propellant, max: " << tVolume << endl;
		cin >> tankFuelVolume;
		return tankFuelVolume;
	}

	double tankOxidizerVolumeFunc(double tVolume, double fVolume) {
		double tankFuelVolume = fVolume;
		double tankOxidizerVolume;
		cout << "Enter a volume designed to oxidizer max: " << tVolume - tankFuelVolume << endl;
		cin >> tankOxidizerVolume;
		return tankOxidizerVolume;
	}

	float fuelChoiceFunc() {
		int a;
		cout << "Enter one of the following number to select your propellant: 1. RP-1" << endl;
		cin >> a;
		return a;
	}

	float oxidizerChoiceFunc() {
		int a;
		cout << "Enter one of the following number to select your oxidizer: 1. LOX" << endl;
		cin >> a;
		return a;
	}

	//Functions for engines
	
	double engineOuterChamberRadius() {
		double oradius;
		cout << "Enter outer radius of chamber (m)" << endl;
		cin >> oradius;
		return oradius;
	}

	double engineInnerChamberRadius() {
		double iradius;
		cout << "Enter inner radius of chamber (m)" << endl;
		cin >> iradius;
		return iradius;
	}

	double engineChamberHeight() {
		double cheight;
		cout << "Enter height of chamber (m)" << endl;
		cin >> cheight;
		return cheight;
	}

	double throatOuterFirstRadius() {
		double ofradius;
		cout << "Enter outer radius between chamber and nozzle (m)" << endl;
		cin >> ofradius;
		return ofradius;
	}

	double throatInnerFirstRadius() {
		double ifradius;
		cout << "Enter inner radius between chamber and nozzle (m)" << endl;
		cin >> ifradius;
		return ifradius;
	}

	double throatInnerSecondRadius() {
		double isradius;
		cout << "Enter inner radius between exterior and nozzle (m)" << endl;
		cin >> isradius;
		return isradius;
	}

	double throatOuterSecondRadius() {
		double osradius;
		cout << "Enter outer radius between exterior and nozzle (m)" << endl;
		cin >> osradius;
		return osradius;
	}

	double nozzleHeight() {
		double nheight;
		cout << "Enter nozzle's height (m)" << endl;
		cin >> nheight;
		return nheight;

	}

	double throatHeight() {
		double theight;
		cout << "Enter throat's height (m)" << endl;
		cin >> theight;
		return theight;

	}

	double engineMass(double oradius, double iradius, double ofradius, double ifradius, double osradius, double isradius,double nheight, double cheight) {

		string a;
		double choice = 0;
		cout << "Enter a material volumetric weight for the engine: Type 1 for aluminium" << endl;
		cin >> a;
		if (a == "1") {
			choice = 2699;
		}


		double chamberVolume;

		double pi = 2 * acos(0.0);
		double outerVolume = pi * pow(oradius, 2) * cheight;
		double innerVolume = pi * pow(iradius, 2) * cheight;
		chamberVolume = outerVolume - innerVolume;

		double nozzleVolume;

		double OuterVolume = nheight*(pi/3)*(pow(osradius, 2)+pow(ofradius, 2)+(osradius*ofradius));
		cout << "Nozzle outer Volume: " << OuterVolume << "m^3" << endl;
		double InnerVolume = nheight * (pi / 3) * (pow(isradius, 2) + pow(ifradius, 2) + (isradius * ifradius));
		cout << "Nozzle inner Volume: " << InnerVolume << "m^3" << endl;
		nozzleVolume = OuterVolume - InnerVolume;


		double mass;

		mass = (chamberVolume + nozzleVolume)*choice;

		return mass;
	}

	double engineThrustFunc() {
		double thrust;
		cout << "Enter engine thrust (N)" << endl;
		cin >> thrust;
		return thrust;

	}

	double engineMassFlowRateFunc() {
		double rate;
		cout << "Enter engine mass flow rate (kg/s)" << endl;
		cin >> rate;
		return rate;

	}
};
