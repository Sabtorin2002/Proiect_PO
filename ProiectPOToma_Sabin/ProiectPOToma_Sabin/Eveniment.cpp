#define _CRT_SECURE_NO_WARNINGS
#include "Eveniment.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
Eveniment::Eveniment() :idEveniment(0)
{
	numeEveniment = nullptr;
	dataEveniment = "";
	ora = "";
}

Eveniment::Eveniment(int idEveniment, char* numeEveniment, string data, string ora) :idEveniment(idEveniment)
{
	this->idEvenimentCurent++;
	this->dataEveniment = dataEveniment;
	this->ora = ora;
	if (numeEveniment != nullptr)
	{
		this->numeEveniment = new char[strlen(numeEveniment) + 1];
		strcpy_s(this->numeEveniment, strlen(numeEveniment) + 1, numeEveniment);
	}
	else
	{
		this->numeEveniment = nullptr;
	}
}
Eveniment::Eveniment(const Eveniment& e) :idEveniment(e.idEveniment)
{
	this->dataEveniment = e.dataEveniment;
	this->ora = e.ora;
	if (e.numeEveniment != nullptr)
	{
		this->numeEveniment = new char[strlen(e.numeEveniment) + 1];
		strcpy_s(this->numeEveniment, strlen(e.numeEveniment) + 1, e.numeEveniment);
	}
	else
	{
		this->numeEveniment = nullptr;
	}
}
Eveniment::~Eveniment()
{
	if (numeEveniment != nullptr)
	{
		delete[]numeEveniment;
		numeEveniment = nullptr;
	}
}
Eveniment& Eveniment::operator=(const Eveniment& e)
{
	if (this != &e)
	{
		this->dataEveniment = e.numeEveniment;
		this->ora = e.ora;
		if (e.numeEveniment != nullptr)
		{
			if (numeEveniment != nullptr)
			{
				delete[]numeEveniment;
			}
			this->numeEveniment = new char[strlen(e.numeEveniment) + 1];
			strcpy_s(this->numeEveniment, strlen(e.numeEveniment) + 1, e.numeEveniment);
		}
	}
	return *this;
}
void Eveniment::setNumeEveniment(const char* numeEveniment)
{
	if (numeEveniment != nullptr)
	{
		if (this->numeEveniment != nullptr)
		{
			delete[]this->numeEveniment;
		}
		this->numeEveniment = new char[strlen(numeEveniment) + 1];
		strcpy_s(this->numeEveniment, strlen(numeEveniment), numeEveniment);
	}
}

char* Eveniment::getNumeEveniment()
{
	if (numeEveniment != nullptr)
	{
		char* copy = new char[strlen(numeEveniment) + 1];
		strcpy_s(this->numeEveniment, strlen(numeEveniment) + 1, numeEveniment);
		return copy;
	}
	return nullptr;
}

int Eveniment::getidEvenimentCurent()
{
	return idEvenimentCurent;
}

string Eveniment::getOra()
{
	return ora;
}

string Eveniment::getDataEveniment()
{
	return dataEveniment;
}

string Eveniment::getOras()
{
	return oras;
}

bool Eveniment::operator!()
{
	if (this->oras == "Bucuresti")
		return true;
	return false;
}

char& Eveniment::operator[](int index)
{
	if (numeEveniment != nullptr && index >= 0 && index < strlen(numeEveniment))
	{
		return numeEveniment[index];
	}
	return charInvalid;
}
int Eveniment::getidEveniment()
{
	return idEveniment;
}


ostream& operator<<(ostream& out, Eveniment e)
{
	out << "Data Evenimentului: " << e.dataEveniment;
	out << "Ora Evenimentului: " << e.ora;
	out << "IDul Evenimentului: " << e.idEveniment;
	out << "Nume evenimentului: ";
	if (e.numeEveniment != nullptr)
	{
		out << e.numeEveniment;
	}
	return out;
}

istream& operator>>(istream& in, Eveniment& e)
{
	cout << "Data Evenimentului: ";
	in >> e.dataEveniment;

	cout << "Ora Evenimentului: ";
	in >> e.ora;

	cout << "Nume Evenimentului: ";
	string buffer;
	in >> buffer;
	e.setNumeEveniment(buffer.c_str());
	return in;
}

string Eveniment::oras = "Bucuresti";
int Eveniment::idEvenimentCurent = 1 + (rand() % 1000) * 1000 + 4 + (rand() % 1000) * 1000 + 7 + (rand() % 1000) * 1000;
char Eveniment::charInvalid = -1;