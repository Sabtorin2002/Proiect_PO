#define _CRT_SECURE_NO_WARNINGS
#include "BiletVIP.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

BiletVIP::BiletVIP()
{
	nrTipBiletVIP = 0;
	numeBiletVIP = "";
	pretVIP = nullptr;
}

BiletVIP::BiletVIP(int idBilet, float* pret, int nrTipPret, string nume, char* tipZona, int varsta,
	float* pretVIP, int nrTipBiletVIP, string numeBiletVIP) : Bilet(idBilet, pret, nrTipPret, nume, tipZona, varsta)
{
	this->numeBiletVIP = numeBiletVIP;
	if (pretVIP != nullptr && nrTipBiletVIP > 0)
	{
		this->pretVIP = new float[nrTipBiletVIP];
		for (int i = 0; i < nrTipBiletVIP; i++)
		{
			this->pretVIP[i] = pretVIP[i];
		}
		this->nrTipBiletVIP = nrTipBiletVIP;
	}
	else
	{
		this->pretVIP = nullptr;
		this->nrTipBiletVIP = 0;
	}
}

BiletVIP::BiletVIP(const BiletVIP & bv) : Bilet(bv)
{
	this->numeBiletVIP = bv.numeBiletVIP;
	if (bv.pretVIP != nullptr && bv.nrTipBiletVIP > 0)
	{
		this->pretVIP = new float[bv.nrTipBiletVIP];
		for (int i = 0; i < bv.nrTipBiletVIP; i++)
		{
			this->pretVIP[i] = bv.pretVIP[i];
		}
		this->nrTipBiletVIP = bv.nrTipBiletVIP;
	}
	else
	{
		this->pretVIP = nullptr;
		this->nrTipBiletVIP = 0;
	}
}

BiletVIP::~BiletVIP()
{
	if (pretVIP != nullptr)
	{
		delete[]pretVIP;
		pretVIP = nullptr;
	}
}

BiletVIP& BiletVIP::operator=(const BiletVIP& bv)
{
	if (this != &bv)
	{
		Bilet::operator=(bv);
		if (pretVIP != nullptr)
		{
			delete[]pretVIP;
			pretVIP = nullptr;
		}
		this->numeBiletVIP = bv.numeBiletVIP;
		if (bv.pretVIP != nullptr && bv.nrTipBiletVIP > 0)
		{
			this->pretVIP = new float[bv.nrTipBiletVIP];
			for (int i = 0; i < bv.nrTipBiletVIP; i++)
			{
				this->pretVIP[i] = bv.pretVIP[i];
			}
			this->nrTipBiletVIP = bv.nrTipBiletVIP;
		}
		else
		{
			this->pretVIP = nullptr;
			this->nrTipBiletVIP = 0;
		}
	}
	return *this;
}

string BiletVIP::getNumeBiletVIP()
{
	return numeBiletVIP;
}

int BiletVIP::getNrTipBiletVIP()
{
	return nrTipBiletVIP;
}

float* BiletVIP::getPretVIP()
{
	if (pretVIP != nullptr)
	{
		float* copy = new float[nrTipBiletVIP];
		for (int i = 0; i < nrTipBiletVIP; i++)
		{
			copy[i] = pretVIP[i];
		}
		return copy;
	}
	else return nullptr;
}
float BiletVIP::getPretVIP(int index)
{
	if (index >= 0 && index < nrTipBiletVIP && pretVIP != nullptr)
	{
		return pretVIP[index];
	}
	else return -1;
}

Bilet& BiletVIP::operator--()
{
	if (this->pretVIP != nullptr && this->nrTipBiletVIP > 0)
	{
		for (int i = 0; i < nrTipBiletVIP; i++)
			this->pretVIP[i] = this->pretVIP[i] - 0.1 * this->pretVIP[i];
	}
	return *this;
}

float BiletVIP::operator[](int index)
{
	if (index >= 0 && index < this->nrTipBiletVIP)
		return this->pretVIP[index];
}

float BiletVIP::nrBileteVanduteVIP(string numeBiletVIP, BiletVIP* preturiVIP, int nrBileteVIP)
{
	float suma = 0;
	int nrBileteVIPVandute = 0;
	if (preturiVIP != nullptr && nrBileteVIP > 0)
	{
		for (int i = 0; i < nrBileteVIP; i++)
		{
			suma = suma + preturiVIP[i].nrTipBiletVIP;
		}
		nrBileteVIPVandute = suma / nrBileteVIP;
	}
	return nrBileteVIPVandute;
}

ostream& operator<<(ostream& out, BiletVIP b)
{
	out << (Bilet)b << endl;
	out << "Tipul de bilete VIP: " << b.nrTipBiletVIP << endl;
	out << "Numele tipului biletului VIP: " << b.numeBiletVIP << endl;
	for (int i = 0; i < b.nrTipBiletVIP; i++)
	{
		out << b.pretVIP[i] << " ";
	}
	return out;
}

istream& operator>>(istream& in, BiletVIP& b)
{
	in >> (Bilet&)b;
	if (b.pretVIP != nullptr)
	{
		delete[]b.pretVIP;
	}
	b.pretVIP = new float[b.nrTipBiletVIP];
	cout << "Preturi:";
	for (int i = 0; i < b.nrTipBiletVIP; i++)
	{
		in >> b.pretVIP[i];
	}
	cout << "Numele tipului biletului VIP: ";
	in >> b.numeBiletVIP;

	cout << "Tipul de bilete VIP: ";
	in >> b.nrTipBiletVIP;

	return in;
}