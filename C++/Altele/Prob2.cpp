#include<iostream>

using namespace std;

template<typename T>
class Cerc
{
public:
	T Raza;
	T Perimetru, Aria;
	Cerc() {};
	Cerc(T Raza)
	{
		this->Raza = Raza;
	}
	void calcul()
	{
		Perimetru = Raza*2*3.14;
		Aria = Raza*Raza*3.14;
	}
};

template <typename T>
class Dreptunghi
{
public:
	T a, b;
	T Perimetru,Aria;
	Dreptunghi() {};
	Dreptunghi(T a,T b)
	{
		this->a = a;
		this->b = b;
	}
	void calcul()
	{
		Perimetru = a * 2 + b * 2;
		Aria = a * b;
	}
};


template<typename T>
class Valoare
{
public:
	T get_aria(Cerc<T> obj)
	{
		return obj.Aria;
	}
	T get_aria(Dreptunghi<T> obj)
	{
		return obj.Aria;
	}
	
	T get_perimetru(Cerc<T> obj)
	{
		return obj.Perimetru;
	}
	T get_perimetru(Dreptunghi<T> obj)
	{
		return obj.Perimetru;
	}
};

void Rezolvare()
{
	Cerc<int> C1(10);
	Cerc<float> C2(7.54);
	Dreptunghi<int> D1(3, 7);
	Dreptunghi<float> D2(4.5, 12.5);
	Valoare<int> calculator1;
	Valoare<float> calculator2;

	C1.calcul();
	C2.calcul();
	D1.calcul();
	D2.calcul();

	auto P1 = calculator1.get_perimetru(C1);
	auto A1 = calculator1.get_aria(C1);
	auto P2 = calculator2.get_perimetru(C2);
	auto A2 = calculator2.get_aria(C2);
	auto P3 = calculator1.get_perimetru(D1);
	auto A3 = calculator1.get_aria(D1);
	auto P4 = calculator2.get_perimetru(D2);
	auto A4 = calculator2.get_aria(D2);

	cout << "Pentru cercul de raza " << C1.Raza << ": Perimetrul " << P1 << " si aria " << A1<<endl;
	cout << "Pentru cercul de raza " << C2.Raza << ": Perimetrul " << P2 << " si aria " << A2 << endl;
	cout << "Pentru dreptunghiul de laturi " << D1.a<<" si "<<D1.b << ": Perimetrul " << P3 << " si aria " << A3 << endl;
	cout << "Pentru dreptunghiul de laturi " << D2.a << " si " << D2.b << ": Perimetrul " << P4 << " si aria " << A4 << endl;
}

int main()
{
	Rezolvare();
	return 0;
}