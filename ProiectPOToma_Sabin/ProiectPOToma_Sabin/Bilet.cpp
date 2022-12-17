#define _CRT_SECURE_NO_WARNINGS
#include "Bilet.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

Bilet::Bilet() :idBilet(0)
{
	nrTipPret = 0;
	nume = "";
	varsta = 0;
	tipZona = nullptr;
	pret = nullptr;
}

Bilet::Bilet(int idBilet, float* pret, int nrTipPret, string nume, char* tipZona, int varsta) :idBilet(idBilet)
{
	if (pret != nullptr && nrTipPret > 0)
	{
		this->pret = new float[nrTipPret];
		for (int i = 0; i < nrTipPret; i++)
		{
			this->pret[i] = pret[i];
		}
		this->nrTipPret = nrTipPret;
	}
	else
	{
		this->pret = nullptr;
		this->nrTipPret = 0;
	}
	this->varsta = varsta;
	this->nume = nume;
	if (tipZona != nullptr)
	{
		this->tipZona = new char[strlen(tipZona) + 1];
		strcpy_s(this->tipZona, strlen(tipZona) + 1, tipZona);
	}
	else
	{
		this->tipZona = nullptr;
	}
}
Bilet::Bilet(const Bilet & b) :idBilet(b.idBilet)
{
	if (b.pret != nullptr && b.nrTipPret > 0)
	{
		this->pret = new float[b.nrTipPret];
		for (int i = 0; i < b.nrTipPret; i++)
		{
			this->pret[i] = b.pret[i];
		}
		this->nrTipPret = b.nrTipPret;
	}
	else
	{
		this->pret = nullptr;
		this->nrTipPret = 0;
	}
	this->nume = b.nume;
	this->varsta = b.varsta;
	if (b.tipZona != nullptr)
	{
		this->tipZona = new char[strlen(b.tipZona) + 1];
		strcpy_s(this->tipZona, strlen(b.tipZona) + 1, b.tipZona);
	}
	else
	{
		this->tipZona = nullptr;
	}
}
Bilet::~Bilet()
{
	if (this->pret != nullptr)
	{
		delete[] this->pret;
		pret = nullptr;
	}

	if (tipZona != nullptr)
	{
		delete[] this->tipZona;
		tipZona = nullptr;
	}
}
Bilet& Bilet::operator=(const Bilet & b)
{
	if (this != &b)
	{
		if (b.tipZona != nullptr)
		{
			if (tipZona != nullptr)
			{
				delete[] tipZona;
			}
			this->tipZona = new char[strlen(b.tipZona) + 1];
			strcpy_s(this->tipZona, strlen(b.tipZona) + 1, b.tipZona);
		}
		if (b.pret != nullptr && b.nrTipPret > 0)
		{
			this->pret = new float[b.nrTipPret];
			for (int i = 0; i < b.nrTipPret; i++)
			{
				this->pret[i] = b.pret[i];
			}
			this->nrTipPret = b.nrTipPret;
		}
		else
		{
			this->pret = nullptr;
			this->nrTipPret = 0;
		}
		this->nume = b.nume;
		this->varsta = b.varsta;
	}
	return *this;
}
void Bilet::settipZona(const char* tipZona)
{
	if (tipZona != nullptr)
	{
		if (this->tipZona != nullptr)
		{
			delete[] tipZona;
			tipZona = nullptr;
		}
	}
	this->tipZona = new char[strlen(tipZona) + 1];
	strcpy_s(this->tipZona, strlen(tipZona) + 1, tipZona);
}

char* Bilet::gettipZona()
{
	if (tipZona != nullptr)
	{
		char* copy = new char[strlen(tipZona) + 1];
		strcpy_s(this->tipZona, strlen(tipZona) + 1, tipZona);
		return copy;
	}
	return nullptr;
}

Bilet& Bilet::operator++()
{
	if (this->pret != nullptr && this->nrTipPret > 0)
	{
		for (int i = 0; i < nrTipPret; i++)
			this->pret[i] = this->pret[i] + 0.1 * this->pret[i];
	}
	return *this;
}

float Bilet::operator[](int index)
{
	if (index >= 0 && index < this->nrTipPret)
		return this->pret[index];
}

float Bilet::profitBilete(char* tipZona, Bilet* preturi, int nrPreturi)
{
	float suma = 0;
	if (preturi != nullptr && nrPreturi > 0)
	{
		for (int i = 0; i < nrPreturi; i++)
		{
			suma = suma + preturi[i].nrTipPret;
		}
	}
	return suma;
}

void Bilet::setNume(string nume)
{
	this->nume = nume;
}

string Bilet::getNume()
{
	return nume;
}

void Bilet::setVarsta(int varsta)
{
	this->varsta = varsta;
}

int Bilet::getVarsta()
{
	return varsta;
}

int Bilet::getIdBilet()
{
	return idBilet;
}

float* Bilet::getPret()
{
	if (pret != nullptr)
	{
		float* copy = new float[nrTipPret];
		for (int i = 0; i < nrTipPret; i++)
		{
			copy[i] = pret[i];
		}
		return copy;
	}
	else return nullptr;
}
float Bilet::getPret(int index)
{
	if (index >= 0 && index < nrTipPret && pret != nullptr)
	{
		return pret[index];
	}
	else return -1;
}

int idBilet = 1 + (rand() % 1000) * 1000 + 4 + (rand() % 1000) * 1000 + 7 + (rand() % 1000) * 1000;

ostream& operator<<(ostream& out, Bilet b)
{
	out << "IDul biletului: " << b.idBilet << endl;
	out << "Numarul tipului de bilet: " << b.nrTipPret << endl;
	out << "Numele persoanei: " << b.nume << endl;
	out << "Varsta persoanei: " << b.varsta << endl;
	out << "Preturi: ";
	for (int i = 0; i < b.nrTipPret; i++)
	{
		out << b.pret[i] << " ";
	}
	out << endl;
	out << "Zona: ";
	if (b.tipZona != nullptr)
	{
		out << b.tipZona;
	}
	out << endl;
	return out;
}

istream& operator>>(istream& in, Bilet& b)
{
	cout << "Numarul tipului de bilet: ";
	in >> b.nrTipPret;

	cout << "Numele persoane: ";
	in >> b.nume;

	cout << "Varsta persoanei: ";
	in >> b.varsta;

	if (b.pret != nullptr)
	{
		delete[]b.pret;
		b.pret = nullptr;
	}
	b.pret = new float[b.nrTipPret];
	cout << "Preturi:";
	for (int i = 0; i < b.nrTipPret; i++)
	{
		in >> b.pret[i];
	}

	cout << "Zona:";
	string buffer;
	in >> buffer;
	b.settipZona(buffer.c_str());

	return in;
}