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


	void launch(double thrust, double tankMass, double engineMass, double fuelVolume, double oxidizerVolume, int fuelChoice, int oxidizerChoice) {
		double weight = weightFunc(tankMass, engineMass, fuelVolume, oxidizerVolume, fuelChoice, oxidizerChoice);
		
		double accy = 9.8 * ((thrust/weight)-1);
		cout << "Acceleration on Y for thrust part of the flight is: " << accy << endl;
	}

};