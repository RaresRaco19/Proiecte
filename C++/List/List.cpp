#include <iostream>
#include <list>
#include <fstream>
using namespace std;

class Cadou
{
public:
	string Denumire, Magazin_a;
	int Pret;
	int Deo;
	Cadou() {};
	Cadou(string Denumire, string Magazin, int Pret,int Deo)
	{
		this->Deo = Deo;
		this->Denumire = Denumire;
		this->Magazin_a = Magazin;
		this->Pret = Pret;
	}
	virtual void afisare()
	{
		cout << "---" << endl;
		cout << "Denumire:" << Denumire<<endl;
		cout << "Magazin achizitionat:" << Magazin_a << endl;
		cout << "Pret:" << Pret<<endl;
	}
};

class Jucarie :public Cadou
{
public:
	string Culoarea;
	Jucarie() {};
	Jucarie(string Denumire, string Magazin, int Pret,int Deo ,string Culoare) :Cadou(Denumire, Magazin, Pret,Deo)
	{
		this->Culoarea = Culoare;
	}
	void afisare()
	{
	Cadou::afisare();
	cout << "Culoare:" << Culoarea << endl;
	}
};
class Dulciuri :public Cadou
{
public:
	string Indice;
	Dulciuri() {};
	Dulciuri(string Denumire, string Magazin, int Pret,int Deo ,string Indice) :Cadou(Denumire, Magazin, Pret,Deo)
	{
		this->Indice = Indice;
	}
	void afisare()
	{
		Cadou::afisare();
		cout << "Indice glicemic:" << Indice << endl;
	}
};

void adaugare(list<Cadou*>&Cadouri)
{
	Dulciuri* D=new Dulciuri();
	Jucarie* J=new Jucarie();
	int tip;
	ifstream fis("Fisier.txt");
	if (fis.is_open())
	{
		while (fis >> tip)
			switch (tip)
			{
			case 1:
			{
				Jucarie* J = new Jucarie();
				J->Deo = tip;
				fis >> J->Denumire >> J->Magazin_a >> J->Pret >> J->Culoarea;
				Cadouri.push_back(J);
				break;
			}
			case 2:
			{
				D->Deo = tip;
				fis >> D->Denumire >> D->Magazin_a >> D->Pret >> D->Indice;
				Cadouri.push_back(D);
				break;
			}
			}
	}
}

void afisare_tot(list<Cadou*>Cadouri)
{
	Cadou* C = new Cadou();

	for (auto i = Cadouri.begin(); i != Cadouri.end(); i++)
	{
		C = *i;
		C->afisare();
	}
}
ostream& operator <<(ostream& out, Jucarie* J)
{
	J->afisare();
	return out;
}
void afisare_culoare(list<Cadou*>& Cadouri)
{
	Cadou* C = new Cadou();
	string Culoare;
	cout << "Introduceti culoarea cautata:"; cin >> Culoare;
	for (auto i = Cadouri.begin(); i != Cadouri.end(); i++)
	{
		if ((*i)->Deo == 1)
		{
			C = *i;
			Jucarie* J = (Jucarie*)C;
			if (J->Culoarea == Culoare)
			{
				cout << J;
			}
		}
	}
}

void meniu()
{
	int opt=1;
	list<Cadou*>Cadouri;
	while (opt != 0)
	{
		cout << "1.Adaugare" << endl;
		cout << "2.Afisare" << endl;
			cout << "3.Ordonare" << endl;
			cout << "4.Afisare ordonata" << endl;
			cout << "0.Iesire" << endl;
			cout << "Introduceti optiunea:"; cin >> opt;
			switch (opt)
			{
			case 1:
			{
				adaugare(Cadouri);
				break;
			}
			case 2:
			{
				afisare_tot(Cadouri);
				break;
			}
			case 3:
			{
				break;
			}
			case 4:
			{
				afisare_culoare(Cadouri);
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
	meniu();
	return 0;
}