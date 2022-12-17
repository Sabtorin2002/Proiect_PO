#pragma once
#include <iostream>
#include <string>
using namespace std;

class Locatie
{
private:
	int** zone;
	int rand;
	int loc;
	string numeLocatie;
	string numeZona;
	static string mesajInvalid;
public:
	Locatie();
	Locatie(int** zone, int rand, int loc, string numeLocatie);
	Locatie(const Locatie& l);
	~Locatie();
	Locatie& operator=(const Locatie& l);
	void setNumeZona(string numeZona);
	void setNumeLocatie(string numeLocatie);
	string getNumeLocatie();
	void setLoc(int loc);
	int getLoc();
	void setRand(int rand);
	int getRand();
	void setZone(int** zone, int rand, int loc);
	int** getZone();
	int getZone(int index1, int index2);
	static int nrMaximDeBilete(string numeZona, Locatie* zone, int nrZone);
	explicit operator string();
	friend ostream& operator<<(ostream&, Locatie);
	friend istream& operator>>(istream&, Locatie&);

};
string Locatie::mesajInvalid = "Locul nu este valid";

