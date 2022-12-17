#pragma once
#include <iostream>
#include <string>
using namespace std;

class Bilet
{
private:
	float* pret;
	int nrTipPret;
	string nume;
	char* tipZona;
	int varsta;
	const int idBilet;
	static int idBiletCurent;
public:
	Bilet();
	Bilet(int idBilet, float* pret, int nrTipPret, string nume, char* tipZona, int varsta);
	Bilet(const Bilet& b);
	~Bilet();
	Bilet& operator=(const Bilet& b);
	void settipZona(const char* tipZona);
	char* gettipZona();
	Bilet& operator++();
	float operator[](int index);
	static float profitBilete(char* tipZona, Bilet* preturi, int nrPreturi);
	void setNume(string nume);
	string getNume();
	void setVarsta(int varsta);
	int getVarsta();
	int getIdBilet();
	float* getPret();
	float getPret(int index);
	friend ostream& operator<<(ostream&, Bilet);
	friend istream& operator>>(istream&, Bilet&);

};