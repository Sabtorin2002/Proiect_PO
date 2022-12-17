#define _CRT_SECURE_NO_WARNINGS
#include "Locatie.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

Locatie::Locatie()
{
	zone = nullptr;
	rand = 0;
	loc = 0;
	numeLocatie = "";
	numeZona = "";
}

Locatie::Locatie(int** zone, int rand, int loc, string numeLocatie)
{
	this->numeZona = numeZona;
	this->numeLocatie = numeLocatie;
	if (zone != nullptr && rand > 0 && loc > 0)
	{
		this->zone = new int* [rand];
		for (int i = 0; i < rand; i++)
		{
			this->zone[i] = new int[loc];
		}
		this->rand = rand;
		this->loc = loc;
	}
	else
	{
		this->zone = nullptr;
		this->rand = 0;
		this->loc = 0;
	}
}

Locatie::Locatie(const Locatie& l)
{
	this->numeZona = l.numeZona;
	this->numeLocatie = l.numeLocatie;
	if (l.zone != nullptr && l.rand > 0 && l.loc > 0)
	{
		this->zone = new int* [l.rand];
		for (int i = 0; i < l.rand; i++)
		{
			this->zone[i] = new int[l.loc];
		}
		this->rand = rand;
		this->loc = loc;
	}
	else
	{
		this->zone = nullptr;
		this->rand = 0;
		this->loc = 0;
	}
}

Locatie::~Locatie()
{
	if (zone != nullptr)
	{
		for (int i = 0; i < rand; i++)
		{
			delete[]zone[i];
		}
		delete[]zone;
		zone = nullptr;
	}
}

Locatie& Locatie::operator=(const Locatie& l)
{
	if (this != &l)
	{
		if (this->zone != nullptr)
		{
			delete[]this->zone;
		}
		this->numeZona = l.numeZona;
		this->numeLocatie = l.numeLocatie;
		if (l.zone != nullptr && l.rand > 0 && l.loc > 0)
		{
			this->zone = new int* [l.rand];
			for (int i = 0; i < l.rand; i++)
			{
				this->zone[i] = new int[l.loc];
			}
			this->rand = rand;
			this->loc = loc;
		}
		else
		{
			this->zone = nullptr;
			this->rand = 0;
			this->loc = 0;
		}
	}
	return *this;
}

void Locatie::setNumeZona(string numeZona)
{
	this->numeZona = numeZona;
}

void Locatie::setNumeLocatie(string numeLocatie)
{
	this->numeLocatie = numeLocatie;
}

string Locatie::getNumeLocatie()
{
	return numeLocatie;
}

void Locatie::setLoc(int loc)
{
	this->loc = loc;
}

int Locatie::getLoc()
{
	return loc;
}

void Locatie::setRand(int rand)
{
	this->rand = rand;
}

int Locatie::getRand()
{
	return rand;
}

void Locatie::setZone(int** zone, int rand, int loc)
{
	if (zone != nullptr && rand > 0 && loc > 0)
	{
		delete[] zone;
		this->zone = new int* [rand];
		for (int i = 0; i < rand; i++)
		{
			this->zone[i] = new int[loc];
		}
		this->rand = rand;
		this->loc = loc;
	}
}

int** Locatie::getZone()
{
	if (zone != nullptr)
	{
		int** copy = new int* [rand];
		for (int i = 0; i < rand; i++)
		{
			copy[i] = new int[loc];
		}
		return copy;
	}
	else return nullptr;
}

int Locatie::getZone(int index1, int index2)
{
	if (index1 >= 0 && index1 < rand && index2 >= 0 && index2 <= loc && zone != nullptr)
	{
		return zone[index1][index2];
	}
	else return -1;
}

int Locatie::nrMaximDeBilete(string numeZona, Locatie * zone, int nrZone)
{
	int maxim = 0;
	if (zone != nullptr && nrZone > 0)
	{
		for (int i = 0; i < nrZone; i++)
		{
			maxim = maxim + zone[i].rand * zone[i].loc;
		}
	}
	return maxim;
}

Locatie::operator string()
{
	return numeZona;
}
string mesajInvalid = "Locul nu este valid";

ostream& operator<<(ostream& out, Locatie l)
{
	out << "Rand:" << l.rand << endl;
	out << "Locul:" << l.loc << endl;
	out << l.numeLocatie;
	out << l.numeZona;
	for (int i = 0; i < l.rand; i++)
	{
		for (int j = 0; j < l.loc; j++)
			cout << l.zone[i][j] << endl;
	}
	out << endl;
	return out;
}

istream& operator>>(istream& in, Locatie& l)
{
	cout << "Rand: ";
	in >> l.rand;

	cout << "Locul: ";
	in >> l.loc;

	cout << "Numele locatiei: ";
	in >> l.numeLocatie;

	cout << "Numele zonei: ";
	in >> l.numeZona;

	if (l.zone != nullptr)
	{
		for (int i = 0; i < l.rand; i++)
		{
			delete[]l.zone[i];
		}
		delete[]l.zone;
		l.zone = nullptr;
	}

	l.zone = new int* [l.rand];
	for (int i = 0; i < l.rand; i++)
	{
		l.zone[i] = new int[l.loc];
	}
	cout << "Locuri disponibile:";
	for (int i = 0; i < l.rand; i++)
		for (int j = 0; j < l.loc; j++)
		{
			in >> l.zone[i][j];
		}
	return in;

}