#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <fstream>

using namespace std;

/*struct TopNote
{
	short ID;
	float nota;
};*/

struct Scholar
{
	string Nume;
	float medie;
};


class Student
{
private:
	string Nume;
	vector<float> note;
	short ID;
	float Medie;
public:
	Student() {}
	Student(string Nume, short ID)
	{
		this->Nume = Nume;
		this->ID = ID;
	}
	void adaugare_nota(float nota)
	{
		if (note.empty())
			note.push_back(nota);
		else if (note[0] < nota)
			note.insert(note.begin(), nota);
		else
			note.push_back(nota);      
	}
	void calcul_Medie()
	{
		short p=0;
		for(float n: note)
		{
			Medie += n;
			p++;
		}
		this->Medie = Medie / p;
	}
	void afisare()
	{
		cout << Nume << " ";
	}
	float GetMedie()
	{
		return Medie;
	}
	string GetNume()
	{
		return Nume;
	}
	short GetID()
	{
		return ID;
	}
	vector<float> GetNote()
	{
		return note;
	}
};

class Universitate
{
private:
	bool valid;
	string Nume;
	list<Student> Studenti;
	float Media;
	vector<float> ScholarShip;
public:
	Universitate() {}
	Universitate(string Nume)
	{
		this->Nume = Nume;
		ScholarShip = vector<float>(2, 0);
		valid = false;
	}
	void adaugare_student(Student S)
	{
		bool gasit = true;
		if (Studenti.empty())
		{
			Studenti.push_back(S);
			gasit = false;
		}
		else if (true)
			for (auto i = Studenti.begin(); i != Studenti.end(); ++i)
			{
				if ((*i).GetNume()[0] >= S.GetNume()[0])
				{
					Studenti.insert(i, S);
					gasit = false;
					break;
				}
			}
		    if(gasit)
			Studenti.push_back(S);

	}
	void calcul_medieUniv()
	{
		Media = 0;
		short p=0;
		for (auto i = Studenti.begin(); i != Studenti.end(); i++)
		{
			Media += (*i).GetMedie();
			p++;
		}
		Media = Media / p;
	}
	void stegere_student(float nota)
	{
		vector<float>Note;
		for (auto i = Studenti.begin(); i != Studenti.end(); i++)
		{
			Note = (*i).GetNote();
			if (Note[0] = nota)
			{
				i = Studenti.erase(i);
				break;
			}
		}
	}
	void calcul_medieStud()
	{
		for (auto i = Studenti.begin(); i != Studenti.end(); i++)
		{
			(*i).calcul_Medie();
			for (short j=0;j<2;j++)
			{
				if (ScholarShip[j] < (*i).GetMedie() && j==0)
				{
					ScholarShip[j + 1] = ScholarShip[j];
					ScholarShip[j] = (*i).GetMedie();
					break;
				}
				else if (ScholarShip[j] < (*i).GetMedie())
				{
					ScholarShip[j] = (*i).GetMedie();
					break;
				}
			}
		}
	}
	void Afisare_stud()
	{
		for (auto i = Studenti.begin(); i != Studenti.end(); i++)
		{
			(*i).afisare();
		}
	}
	string GetNume()
	{
		return Nume;
	}
	list<Student> GetStudenti()
	{
		return Studenti;
	}
	float GetMedie()
	{
		return Media;
	}
	void SetStudenti(list<Student> S)
	{
		Studenti = S;
	}
	vector<float> GetScholar()
	{
		return ScholarShip;
	}
	void SetValid(bool va)
	{
		this->valid = va;
	}
	bool GetValid()
	{
		return valid;
	}
};

list<float> citire_date(list<Universitate>& U)
{
	ifstream fin("DateIntrare.txt");
	short nr_univ=0;
	short n; fin >> n;
	string Nume;
	string NumeUni;
	short ID;
	float nota;
	bool gasit = false;
	for (short i = 0; i < n; i++)
	{
		fin >> ID;
		fin >> Nume;
		fin >> NumeUni;
		for (auto Univ=U.begin();Univ!=U.end();Univ++)
		{
			if ((*Univ).GetNume() == NumeUni)
			{
				(*Univ).adaugare_student(Student(Nume,ID));
				gasit = true;
			}
		}
		if (!gasit)
		{
			U.push_back(Universitate(NumeUni));
			(*(U.rbegin())).adaugare_student(Student(Nume, ID));
			nr_univ++;
		}
		gasit = false;
	}
	short m; fin >> m;
	list<float> TopNot(nr_univ,0);
	for (short i = 0; i < m; i++)
	{
		fin >> nota;
		fin >> ID;
		for (auto v=TopNot.begin();v!=TopNot.end();v++)
		{
			if (nota > (*v))
			{
				TopNot.insert(v, nota);
				auto a = TopNot.erase(--TopNot.end());
				break;
			}
		}
		for (auto i = U.begin(); i != U.end(); i++)
		{
			list<Student> Stu = (*i).GetStudenti();
			for (auto j = Stu.begin(); j != Stu.end(); j++)
			{
				if ((*j).GetID() == ID)
					(*j).adaugare_nota(nota);
			}
			(*i).SetStudenti(Stu);
		}
	}
	return TopNot;
}

void afisare_task1(list<Universitate>& U)
{
	for (auto i = U.begin(); i != U.end(); i++)
	{
		(*i).calcul_medieStud();
		(*i).calcul_medieUniv();
	}
	U.sort([](Universitate& U1, Universitate U2) {return U1.GetMedie() > U2.GetMedie(); });
	cout << "-----Task1-----" << endl;
	for (auto i = U.begin(); i != U.end(); i++)
	{
		cout << (*i).GetNume() << " ";
		(*i).Afisare_stud();
		cout << endl;
	}
}

void afisare_task2(list<Universitate>& U)
{
	list<Student> Stud;
	vector<float> Sch;
	cout << "------Task2-------" << endl;
	for (auto i = U.begin(); i != U.end(); i++)
	{ 
		cout << (*i).GetNume() << ": ";
		Stud = (*i).GetStudenti();
		Sch = (*i).GetScholar();
		for (auto j = Stud.begin(); j != Stud.end(); j++)
		{
			for (short g=0;g<2;g++)
			{
				if ((Sch[g]) == (*j).GetMedie())
				{
					(*j).afisare();
				}
			}
		}
		cout << endl;
	}
}

void afisare_task3(list<Universitate>& U,list<float> TopNot)
{
	list<Student> Stu,Stu1;
	for (auto i = TopNot.begin(); i != TopNot.end(); i++)
	{
		for (auto j = U.begin(); j != U.end(); j++)
		{
			Stu = (*j).GetStudenti();
			for(auto g=Stu.begin();g!=Stu.end();g++)
				if ((*i) == (*g).GetNote()[0] )
				{
					if (!(*j).GetValid())
					{
						(*j).SetValid(true);
						break;
					}
					else
					{
						for (auto u = U.begin(); u != U.end(); u++)
						{
							Stu1 = (*u).GetStudenti();
							for (auto w = Stu1.begin(); w != Stu1.end(); w++)
								if ((*u).GetValid() )
									break;
								else
								{
									(*u).adaugare_student((*g));
									(*j).stegere_student((*g).GetNote()[0]);
									(*u).SetValid(true);
								}
						}
					}
				}
		}
	}
}


int main()
{
	list<Universitate> Universitati;
	short opt = 0;
	list<float> Top;
	do {
		cout << "------Meniu------" << endl;
		cout << "1. Citire date" << endl;
		cout << "2. Afisare universitati sortate dupa GPA(Subtask1)" << endl;
		cout << "3. Afisarea studentilor care au primit scholarship(Substak 2)" << endl;
		cout << "4. Afisare repartizarea studenti dupa echilibarea GPA-ului(Subtask 3)" << endl;
		cout << "0. IESIRE" << endl;
		cout << "Selectati optiunea: " << endl;
		cin >> opt;
		switch (opt)
		{
		case 1:
		{
			Top=citire_date(Universitati);
			break;
		}
		case 2:
		{
			afisare_task1(Universitati);
			break;
		}
		case 3:
		{
			afisare_task2(Universitati);
			break;
		}
		case 4:
		{
			afisare_task3(Universitati, Top);
			break;
		}
		case 0:
			break;
		}
	} while (opt != 0);
	return 0;
}
