#include <iostream>
using namespace std;
#include "RocketMain.h"
#include <math.h>

class RocketMain {
public:
	string name;
	float tankHeight;
	float tankRadius;
	float tankVolume;


	string setName(string rname) {
		cout << "Enter a name for the Rocket" << endl;
		cin >> rname;
		return rname;
	}

	float setTankHeight(int theight) {
		cout << "Enter a height for the tank" << endl;
		cin >> theight;
		return theight;
	}

	float setTankRadius(int tradius) {
		cout << "Enter a radius for the tank" << endl;
		cin >> tradius;
		return tradius;
	}

	float tankVolumeFunc(float tradius, float theight, float tankVolume) {
		double pi = 2 * acos(0.0);
		tankVolume = pi * pow(tradius, 2) * theight;
		return tankVolume;
	}
};
