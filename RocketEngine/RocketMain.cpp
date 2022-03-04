#include <iostream>
using namespace std;
#include <math.h>

class RocketMain{
public:
	string name= "";
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


	string setName() {
		string rname;
		cout << "Enter a name for the Rocket" << endl;
		cin >> rname;
		return rname;
	}

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
		cout << "Enter a material volumetric weight for the rocket: Type 1 for aluminium" << endl;
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

};
