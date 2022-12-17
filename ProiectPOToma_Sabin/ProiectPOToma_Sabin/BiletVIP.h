#pragma once
#include <iostream>
#include <string>
#include "Bilet.h"
using namespace std;

class BiletVIP : public Bilet
{
private:
	float* pretVIP;
	int nrTipBiletVIP;
	string numeBiletVIP;
public:
	BiletVIP();
	BiletVIP(int idBilet, float* pret, int nrTipPret, string nume, char* tipZona, int varsta,
		float* pretVIP, int nrTipBiletVIP, string numeBiletVIP);
	BiletVIP(const BiletVIP& bv);
	~BiletVIP();
	BiletVIP& operator=(const BiletVIP& bv);
	string getNumeBiletVIP();
	int getNrTipBiletVIP();
	float* getPretVIP();
	float getPretVIP(int index);
	Bilet& operator--();
	float operator[](int index);
	static float nrBileteVanduteVIP(string numeBiletVIP, BiletVIP* preturiVIP, int nrBileteVIP);
	friend ostream& operator<<(ostream&, BiletVIP);
	friend istream& operator>>(istream&, BiletVIP&);
	
};