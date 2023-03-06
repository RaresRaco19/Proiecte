#include <iostream>
#include <list>
#include <conio.h>

using namespace std;

class Articol
{
public:
	string Brand;
	int Pret;
	Articol() {};
	Articol(string Brand, int Pret)
	{
		this->Brand = Brand;
		this->Pret = Pret;
	}
	void afisare()
	{
		cout << "-----------"<<endl;
		cout << "Brand:" << Brand<<endl;
		cout << "Pret:" << Pret << endl;
	}
};

class Laptop :public Articol
{
public:
	bool Placa;
	int Ram;
	Laptop() {};
	Laptop(string Brand, int Pret, bool Placa, int Ram) :Articol(Brand, Pret)
	{
		this->Placa = Placa;
		this->Ram = Ram;
	}
		void afisare()
		{
			Articol::afisare();
			if (Placa)
			{
				cout << "Avem placa video dedicata" << endl;
			}
			else
			{
				cout << "Nu avem placa video dedicata" << endl;
			}
			cout << "RAM:" << Ram << endl;

		}
};

class PC :public Articol
{
public:
	int Hdd;
	PC() {};
	PC(string Brand, int Pret, int Hdd) :Articol(Brand, Pret)
	{
		this->Hdd = Hdd;
	}
	void afisare()
	{
		Articol::afisare();
		cout << "HDD:" << Hdd;
	}
};

ostream& operator <<(ostream& out, Laptop L)
{
	L.afisare();
	return out;
}

ostream& operator <<(ostream& out, PC P)
{
	P.afisare();
	return out;
}

istream& operator >>(istream& in, Laptop& L)
{
	string Brand;
	int Pret, Ram;
	bool Placa;
	cout << "Brand:"; cin >> Brand;
	cout << "Pret:"; cin >> Pret;
	cout << "Placa video dedicata(1.Da/0.Nu):";
	cin >> Placa;
	cout << "Ram:"; cin >> Ram;
	L=Laptop(Brand, Pret, Placa, Ram);
	return in;
}

istream& operator >>(istream& in, PC& P)
{
	string Brand;
	int Pret, Hdd;
	cout << "Brand:"; cin >> Brand;
	cout << "Pret:"; cin >> Pret;
	cout << "HDD:"; cin >> Hdd;
	P=PC(Brand, Pret, Hdd);
	return in;
}

void adaugare_laptop(list<Laptop>& Laptopuri)
{
	Laptop L;
	cin >> L;
	Laptopuri.push_back(L);
}

void adaugare_Pc(list<PC>& Calculatoare)
{
	PC P;
	cin >> P;
	Calculatoare.push_back(P);
}

void afisare_laptop(list<Laptop> Laptopuri)
{
	Laptop L;
	for (auto i = Laptopuri.begin(); i != Laptopuri.end(); i++)
	{
		L = *i;
		cout << L;
	}
}
void afisare_Pc(list<PC> Calculatoare)
{
	PC Cal;
	for (auto i = Calculatoare.begin(); i != Calculatoare.end(); i++)
	{
		Cal = *i;
		cout << Cal;
	}
}

void afisare_placa(list<Laptop> Laptopuri)
{
	for (auto i = Laptopuri.begin(); i != Laptopuri.end(); i++)
	{
		if ((*i).Placa)
			cout << (*i);
	}
}

void afisare_hdd(list<PC> Calculatoare)
{
	int aux=0;
	PC Cal;
	for (auto i = Calculatoare.begin(); i != Calculatoare.end(); i++)
	{
		if ((*i).Hdd > aux)
		{
			aux = (*i).Hdd;
			Cal = (*i);
		}
    }
	cout << Cal;
}

void afisare_meniu()
{
	list<Laptop> Laptopuri;
	list<PC> Calculatoare;
	int opt=1;
	while (opt != 0)
	{
		cout << "1.Adaugare Laptop" << endl;
		cout << "2.Adaugare PC" << endl;
		cout << "3.Afisare Laptopuri" << endl;
		cout << "4.Afisare Pc-uri" << endl;
		cout << "5.Afisare laptopuri placa dedicata" << endl;
		cout << "6.Cautare hdd max" << endl;
		cout << "0.Iesire"<<endl;
		cout << "Introduceti optiunea:"; cin >> opt;
		switch (opt)
		{
		case 1:
		{
			adaugare_laptop(Laptopuri);
			break;
		}
		case 2:
		{
			adaugare_Pc(Calculatoare);
			break;
		}
		case 3:
		{
			afisare_laptop(Laptopuri);
			break;
		}
		case 4:
		{
			afisare_Pc(Calculatoare);
			break;
		}
		case 5:
		{
			afisare_placa(Laptopuri);
			break;
		}
		case 6:
		{
			afisare_hdd(Calculatoare);
			break;
		}
		case 0:
		{
			break;
		}
		}
	}
	
}

int main()
{
	afisare_meniu();
	return 0;
}