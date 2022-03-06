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
	double fuelMolecularMass = 0;
	double throatPressure = 0;
	double flowRate = 0;
	double thrust = 0;

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
	double nheight;

	const double primeR = 8.314;

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
	
	double engineOuterChamberRadius() {
		double oradius;
		cout << "Enter outer radius of chamber" << endl;
		cin >> oradius;
		return oradius;
	}

	double engineInnerChamberRadius() {
		double iradius;
		cout << "Enter outer radius of chamber" << endl;
		cin >> iradius;
		return iradius;
	}

	double engineChamberHeight() {
		double cheight;
		cout << "Enter height of chamber" << endl;
		cin >> cheight;
		return cheight;
	}

	double throatOuterFirstRadius() {
		double ofradius;
		cout << "Enter outer radius between chamber and nozzle" << endl;
		cin >> ofradius;
		return ofradius;
	}

	double throatInnerFirstRadius() {
		double ifradius;
		cout << "Enter inner radius between chamber and nozzle" << endl;
		cin >> ifradius;
		return ifradius;
	}

	double throatInnerSecondRadius() {
		double isradius;
		cout << "Enter inner radius between exterior and nozzle" << endl;
		cin >> isradius;
		return isradius;
	}

	double throatOuterSecondRadius() {
		double osradius;
		cout << "Enter outer radius between exterior and nozzle" << endl;
		cin >> osradius;
		return osradius;
	}

	double nozzleHeight() {
		double nheight;
		cout << "Enter nozzle's height" << endl;
		cin >> nheight;
		return nheight;

	}

	double throatHeight() {
		double theight;
		cout << "Enter nozzle's height" << endl;
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
		double InnerVolume = nheight * (pi / 3) * (pow(isradius, 2) + pow(ifradius, 2) + (isradius * ifradius));
		nozzleVolume = OuterVolume - InnerVolume;


		double mass;

		mass = (chamberVolume + nozzleVolume)*choice;

		return mass;
	}

	double flowRateFunc(double ifradius, double iradius, double theight, int propellantChoice) {
		double flowRate;
		double throatArea;
		double throatVolume;
		double HeatConst = 0;
		double chamberTemp = 0;
		double molarMass = 0;
		double throatSpeed;
		double usedMass = 0;

		if (propellantChoice == 1) {
			HeatConst = 1.24;
			chamberTemp = 3670;
			molarMass = 23.30;
			usedMass = 23.30 / 8314.3;

		}

		double pi = 2 * acos(0.0);
		throatVolume = theight * (pi / 3) * (pow(ifradius, 2) + pow(iradius, 2) + (ifradius * iradius));
		throatArea = ((2 * iradius + 2 * ifradius) * theight) / 2;
		throatSpeed = pow(((2*HeatConst)/HeatConst+1)*usedMass*chamberTemp,(1/2));


		flowRate = (throatArea*throatSpeed)/throatVolume;
		return flowRate;
	}


	double ThrustFunc(int propellantChoice, double iradius, double cheight, double flowRate) {
		double HeatConst = 0;
		double chamberTemp = 0;
		double molarMass = 0;
		double usedMass = 0;
		double exhaustVelocity = 0;
		double chamberPressure = 0;
		double thrust = 0;

		if (propellantChoice == 1) {
			HeatConst = 1.24;
			chamberTemp = 3670;
			molarMass = 23.30;
			usedMass = 23.30 / 8314.3;
		}

		double pi = 2 * acos(0.0);
		chamberPressure = (usedMass*chamberTemp)/(pi * pow(iradius, 2) * cheight);

		exhaustVelocity = pow(((2*HeatConst)/HeatConst-1)*usedMass*chamberTemp*(1-pow(101.3/chamberPressure, (HeatConst-1)/HeatConst)), (1^2));
		thrust = flowRate * exhaustVelocity;

		return thrust;
		
	}

};
