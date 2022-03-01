#include <iostream>
using namespace std;
#include <math.h>

class RocketMain {
public:
	string name= "";
	float tankHeight = 0.0f;
	float tankInnerRadius = 0.0f;
	float tankOuterRadius = 0.0f;
	float tankEmptyVolume = 0.0f;
	float tankFuelVolume = 0.0f;
	float tankMat = 0.0f;
	float tankWeight = 0.0f;
	int tankN = 0;

	double tankWeights[10];
	double tankFuelVolumes[10];


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

	float tankFuelVolumeFunc(float tOradius, float tIradius, float theight) {
		double tankVolume;
		double pi = 2 * acos(0.0);
		tankFuelVolume = pi * pow(tIradius, 2) * theight;
		return tankFuelVolume;
	}

	float setMat() {
		double a;
		cout << "Enter a material volumetric weight for the rocket: Type 2699 for aluminium" << endl;
		cin>>a;
		return a;
	}

	float tankWeightFunc(float tVolume, float tMaterial) {
		double tWeight;
		tWeight = tVolume * tMaterial;
		return tWeight;
	}

};
