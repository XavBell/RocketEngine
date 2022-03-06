#include <iostream>
using namespace std;
#include <math.h>

class RocketMain{
public:

	//Tanks variables
	float tankHeight = 0.0f;
	float tankInnerRadius = 0.0f;
	float tankOuterRadius = 0.0f;
	float tankEmptyVolume = 0.0f;
	float tankPropellantVolume = 0.0f;
	float tankMat = 0.0f;
	float tankWeight = 0.0f;
	float tankFuelVolume = 0.0f;
	float tankOxidizerVolume = 0.0f;
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
	double ethrust = 0;

	double eMasses[10];
	double ethrusts[10];


	//Functions for tanks
	float setTankHeight() {
		double theight;
		cout << "Enter a height for the tank" << endl;
		cin >> theight;
		return theight;
	}

	float setTankRadius() {
		double tradius;
		cin >> tradius;
		return tradius;
	}

	float tankEmptyVolumeFunc(float tOradius, float tIradius, float theight) {
		double tankEmptyVolume;
		double pi = 2 * acos(0.0);
		float outerVolume = pi * pow(tOradius, 2) * theight;
		float innerVolume = pi * pow(tIradius, 2) * theight;
		tankEmptyVolume = outerVolume-innerVolume;
		return tankEmptyVolume;
	}

	float tankPropellantVolumeFunc(float tOradius, float tIradius, float theight) {
		double tankVolume;
		double pi = 2 * acos(0.0);
		tankPropellantVolume = pi * pow(tIradius, 2) * theight;
		return tankPropellantVolume;
	}

	float setMat() {
		string a;
		double choice;
		cout << "Enter a material volumetric weight for the tank: Type 1 for aluminium" << endl;
		cin>>a;
		if (a == "1") {
			choice = 2699;
			return choice;
		}
	}

	float tankWeightFunc(float tVolume, float tMaterial) {
		double tWeight;
		tWeight = tVolume * tMaterial;
		return tWeight;
	}

	float tankFuelVolumeFunc(float tVolume) {
		double tankFuelVolume;
		cout << "Enter volume designed to propellant, max: " << tVolume << endl;
		cin >> tankFuelVolume;
		return tankFuelVolume;
	}

	float tankOxidizerVolumeFunc(float tVolume, float fVolume) {
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

	double engineMass() {

		string a;
		double choice = 0;
		cout << "Enter a material volumetric weight for the engine: Type 1 for aluminium" << endl;
		cin >> a;
		if (a == "1") {
			choice = 2699;
		}

		double oradius;
		cout << "Enter outer radius of chamber" << endl;
		cin >> oradius;

		double iradius;
		cout << "Enter inner radius of chamber" << endl;
		cin >> iradius;

		double cheight;
		cout << "Enter height of chamber" << endl;
		cin >> cheight;

		double ofradius;
		cout << "Enter outer radius between chamber and nozzle" << endl;
		cin >> ofradius;

		double ifradius;
		cout << "Enter inner radius between chamber and nozzle" << endl;
		cin >> ifradius;

		double isradius;
		cout << "Enter inner radius between exterior and nozzle" << endl;
		cin >> isradius;

		double osradius;
		cout << "Enter outer radius between exterior and nozzle" << endl;
		cin >> osradius;

		double nheight;
		cout << "Enter nozzle's height" << endl;
		cin >> nheight;


		double chamberVolume;

		double pi = 2 * acos(0.0);
		double outerVolume = pi * pow(oradius, 2) * cheight;
		double innerVolume = pi * pow(iradius, 2) * cheight;
		chamberVolume = outerVolume - innerVolume;

		double nozzleVolume;

		double OuterVolume = nheight*(pi/3)*(pow(osradius, 2)+pow(ofradius, 2)+(osradius*ofradius));
		double InnerVolume = nheight * (pi / 3) * (pow(isradius, 2) + pow(ifradius, 2) + (isradius * ifradius));
		nozzleVolume = OuterVolume - InnerVolume;


		double mass;

		mass = (chamberVolume + nozzleVolume)*choice;

		return mass;
	}

	double engineThrust() {
		double thrust;
		cout << "Enter thrust (N)" << endl;
		cin >> thrust;
		return thrust;
	}

};
