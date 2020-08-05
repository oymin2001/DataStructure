#include <iostream>
#include<algorithm>
#include<array>
#define SOLAR_PLANETS 9
using namespace std;

struct planet {
	char name[10];
	double relativeMass;
	double distance;
};

void printplanet(struct planet solarSystem[], int num_planet);
void sortPlanetByRelativMass(struct planet solarSystem[], int num_planet);
void sortPlanetByName(struct planet solarSystem[], int num_planet);


int main()
{
	struct planet solarSystem[SOLAR_PLANETS] = { {"Mercury",0.0558,57.9},{"Venus",0.815,108},{"Earth",1.0,150},{"Mars",0.107,228},{"Jupiter",318,778},{"Saturn",95.1,1430},{"Uranos",14.5,2870},{"Neptune",17.2,4500},{"Pluto",0.11,5900} };
	printf("\nIntial State\n");
	printplanet(solarSystem, SOLAR_PLANETS);

	sortPlanetByRelativMass(solarSystem, SOLAR_PLANETS);
	printf("\n After sortByRelativeMass:\n");
	printplanet(solarSystem, SOLAR_PLANETS);

	sortPlanetByName(solarSystem, SOLAR_PLANETS);
	printf("\n After sortByName:\n");
	printplanet(solarSystem, SOLAR_PLANETS);
	cout << '\n';

}

void printplanet(struct planet solarSystem[], int num_planet) {
	for (int i = 0; i < num_planet; i++)
	{
		printf("%2d", i);
		printf(" Name: ");
		printf("%-8s", solarSystem[i].name);
		printf(" Relative Mass: ");
		printf("%7.3f", solarSystem[i].relativeMass);
		printf(" Distance: ");
		printf("%6.1f\n", solarSystem[i].distance);
	}
}

//BinarySearch

void sortPlanetByRelativMass(struct planet solarSystem[], int num_planet) {
	struct planet tmp;
	int m;
	double min_RelMass;
	for (int i = 0; i < num_planet - 1; i++)
	{
		m = i;
		min_RelMass = solarSystem[i].relativeMass;

		for (int j = i + 1; j < num_planet; j++)
		{
			if (min_RelMass > solarSystem[j].relativeMass) {
				m = j;
				min_RelMass = solarSystem[j].relativeMass;
			}
		}
		if (m != i) {
			tmp = solarSystem[i];
			solarSystem[i] = solarSystem[m];
			solarSystem[m] = tmp;
		}
	}

}

void sortPlanetByName(struct planet solarSystem[], int num_planet) {
	struct planet tmp;
	int m;
	char min_Name[10] = { };
	for (int i = 0; i < num_planet - 1; i++)
	{
		m = i;
		strcpy(min_Name, solarSystem[i].name);

		for (int j = i + 1; j < num_planet; j++)
		{
			if (strcmp(min_Name, solarSystem[j].name) > 0) {
				m = j;
				strcpy(min_Name, solarSystem[j].name);
			}
		}
		if (m != i) {
			tmp = solarSystem[i];
			solarSystem[i] = solarSystem[m];
			solarSystem[m] = tmp;
		}
	}

}