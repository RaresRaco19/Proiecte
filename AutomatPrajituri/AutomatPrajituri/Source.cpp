#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

class Cake
{
private:
	string Name;
public:
	Cake(string Name)
	{
		this->Name = Name;
	}
	string GetName()
	{
		return Name;
	}
};

class RecipeCake
{
private:
	string Name;
	int Time;
public:
	RecipeCake() {};
	RecipeCake(string Name, int Time)
	{
		this->Name = Name;
		this->Time = Time;
	}
	string GetName()
	{
		return Name;
	}
	int GetTime()
	{
		return Time;
	}
};

class CakeMaker
{
public:
	CakeMaker() {}
	Cake TakeCommand(RecipeCake Recipe)
	{
		Cake Cke(Recipe.GetName());
		std::this_thread::sleep_for(std::chrono::seconds(Recipe.GetTime()));
		return Cke;
	}
};


class CarouselOfCakes
{
private:
	vector<Cake> Array;
	unsigned int MaxCap = 10, MinCap = 3;
public:
	CarouselOfCakes() {}
	bool AddCake(Cake C)
	{
		bool Check;
		if (Array.size() < 10)
		{
			Array.push_back(C);
			Check = true;
		}
		else
			Check = false;
		return Check;
	}
	Cake GetCake(string Name)
	{
		Cake Cke(Name);
		bool Gasit = false;
		for (auto i = Array.begin(); i != Array.end() && Gasit==false; i++)
		{
			if ((*i).GetName() == Name)
			{
				Gasit = true;
				Array.erase(i);
				break;
			}
		}
		return Cke;
	}
	int GetCurrentCap()
	{
		int Cap;
		Cap=Array.size();
		return Cap;
	}
	friend class CommandTaker;
};

class CommandTaker
{
private:
	vector<RecipeCake> CarouselRecipe;
	CakeMaker CakeM;
	CarouselOfCakes Carousel;
	bool CheckCarousel()
	{
		bool Check=false;
		int Cap = Carousel.GetCurrentCap();
		if (Cap < 3)
			Check = true;
		return Check;
		
	}
	bool RefillCarousel()
	{
		string Name;
		int Time=0;
		if (CommandTaker::CheckCarousel())
		{
			auto i = CarouselRecipe.begin();
			cout << "----Asteptam se se umple Vitrina----" << endl;
			while (Carousel.GetCurrentCap() < 10)
			{
				if (i == CarouselRecipe.end())
					i = CarouselRecipe.begin();
				Name = (*i).GetName();
				Cake Cke(Name);
				Carousel.AddCake(Cke);
				Time = Time + (*i).GetTime();
				i++;
			}
			
		}
		std::this_thread::sleep_for(std::chrono::seconds(20));
		return true;
	}
public:
	CommandTaker() 
	{
		RecipeCake R1("Lava Cake", 5);
		CarouselRecipe.push_back(R1);
		RecipeCake R2("Tiramisu", 7);
		CarouselRecipe.push_back(R2);
		RecipeCake R3("Turta cu lamaie", 10);
		CarouselRecipe.push_back(R3);
		RecipeCake R4("Diplomat", 5);
		CarouselRecipe.push_back(R4);
		RecipeCake R5("Pancete", 6);
		CarouselRecipe.push_back(R5);
	}
	Cake TakeCommandRecipe(RecipeCake Recipe)
	{
		bool FoundInCarousel = false;
		vector<Cake> CarouselList;
		if (CheckCarousel())
			RefillCarousel();
		CarouselList = Get_Cake_From_Carousel();
		
		for (auto i = CarouselList.begin(); i != CarouselList.end(); i++)
		{
			if (Recipe.GetName() == (*i).GetName())
			{
				FoundInCarousel = true;
				return Carousel.GetCake((*i).GetName());
			}
		}
		if (!FoundInCarousel)
		{
			return CakeM.TakeCommand(Recipe);
		}
	}
	vector<Cake> TakeCommandArray(RecipeCake Recipe, int NrofC)
	{
		Cake Cke(Recipe.GetName());
		vector<Cake> ReturnCakes;
		int Number = 0;
		for (Number = 0; Number <= NrofC; Number++)
		{
			Cke = CakeM.TakeCommand(Recipe);
			ReturnCakes.push_back(Cke);
		}
		return ReturnCakes;
	}
	Cake TakeCommandName(string NameofCake)
	{

	}
	vector<Cake> Get_Cake_From_Carousel()
	{
		vector<Cake> CarouselList;
		CarouselList = Carousel.Array;
		return CarouselList;
	}
};

class CommandPanel
{
private:
	list<RecipeCake> Menu;
	CommandTaker Command;
public:
	CommandPanel() 
	{
		RecipeCake R1("Lava Cake", 5);
		Menu.push_back(R1);
		RecipeCake R2("Tiramisu", 7);
		Menu.push_back(R2);
		RecipeCake R3("Turta cu lamaie", 10);
		Menu.push_back(R3);
		RecipeCake R4("Diplomat", 5);
		Menu.push_back(R4);
		RecipeCake R5("Pancete", 6);
		Menu.push_back(R5);
	}
	void ShowProducts()
	{
	    	
		RecipeCake Reci;
		cout << "----Lista de Produse----" << endl;
		for (auto i = Menu.begin(); i != Menu.end(); i++)
		{
			string Name = (*i).GetName();
			int Time = (*i).GetTime();
			cout << "Nume:" << Name << " timp de preparare:" << Time << endl;
		}
	}
	void SelectProduct(string Name)
	{
		Cake Cke(Name);
		for (auto i = Menu.begin(); i != Menu.end(); i++)
		{
			if (Name == (*i).GetName())
				Cke = Command.TakeCommandRecipe((*i));
		}
		cout << "Multumim ca ati ales produsul nostru: '" << Cke.GetName() << "'" << endl;
	}
	void SelectProducts(string Name, int NrofC)
	{
		vector<Cake> Cakes;
		for (auto i = Menu.begin(); i != Menu.end(); i++)
		{
			if (Name == (*i).GetName())
				Cakes = Command.TakeCommandArray((*i), NrofC);
		}
		cout << "Multumim ca ati ales produsele noastre: ";
		for (auto i = Cakes.begin(); i != Cakes.end(); i++)
		{
			cout << "'" << (*i).GetName() << "'/";
		}
		cout << endl;
	}
	void ShowProductsInCarousel()
	{
		string Name;
		vector<Cake> CarouselList;
		CarouselList = Command.Get_Cake_From_Carousel();
		cout << "----Lista Produselor din vitrina----" << endl;
		for (auto i = CarouselList.begin(); i != CarouselList.end(); i++)
		{
			Name = (*i).GetName();
			cout << "Name:" << Name << endl;
		}
	}
};

void menu()
{
	CommandPanel CommandP;
	int opt1=1;
	while (opt1 != 0)
	{
		cout << "----Meniu----" << endl;
		cout << "1.Lista Produselor disponibile" << endl;
		cout << "2.Lista Produselor din vitrina" << endl;
		cout << "3.Selecteaza Produs" << endl;
		cout << "0.Iesire Program" << endl;
		cout << "Introduceti optiunea:"; cin >> opt1;
		switch (opt1)
		{
		case 1:
		{
			CommandP.ShowProducts();
			cout << endl;
			break;
		}
		case 2:
		{
			CommandP.ShowProductsInCarousel();
			cout << endl;
			break;
		}
		case 3:
		{
			int opt2=0;
			int opt3;
			cout << "Produse:" << endl << "1.Lava Cake" << endl << "2.Tiramisu" << endl << "3.Turta de lamaie" << endl << "4.Diplomat" << endl << "5.Pancete" << endl<<"Alegeti produsul:";
			cin >> opt3;
			cout << "Cantitatea de produse:"; cin >> opt2;
			if (opt2 == 1)
			{
				switch (opt3)
				{
				case 1:
				{
					CommandP.SelectProduct("Lava Cake");
					break;
				}
				case 2:
				{
					CommandP.SelectProduct("Tiramisu");
					break;
				}
				case 3:
				{
					CommandP.SelectProduct("Turta cu lamaie");
					break;
				}
				case 4:
				{
					CommandP.SelectProduct("Diplomat");
					break;
				}
				case 5:
				{
					CommandP.SelectProduct("Pancete");
					break;
				}
				}
			}
			else
			{
				switch (opt3)
				{
				case 1:
				{
					CommandP.SelectProducts("Lava Cake", opt2-1);
					break;
				}
				case 2:
				{
					CommandP.SelectProducts("Tiramisu", opt2-1);
					break;
				}
				case 3:
				{
					CommandP.SelectProducts("Turta cu lamaie", opt2-1);
					break;
				}
				case 4:
				{
					CommandP.SelectProducts("Diplomat", opt2-1);
					break;
				}
				case 5:
				{
					CommandP.SelectProducts("Pancete", opt2-1);
					break;
				}
				}
			}
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
	menu();
	return 0;
}