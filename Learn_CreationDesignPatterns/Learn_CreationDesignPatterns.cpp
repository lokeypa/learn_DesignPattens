// Learn_CreationDesignPatterns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

//for factor method concept 
//creating coffe maker for different types of coffee.
// interface class kide of abstract class cause it has a method and prototype.
class Coffee {
	
protected:
	char m_type[15];

public:
	Coffee(){}
	char* getType() {
		return m_type;
	}
};




//First type of coffee i.e. latte.// concreate class.
class Latte : public Coffee {

public :
	Latte() : Coffee() {
		strcpy_s(m_type, "Latte!");
		cout << "Making you fucking latte " << endl;
		cout << "this is the latte coffee for you !";
	}

};



//Second type of coffee i.e. Espresso .// concreate class.
class Espresso : public Coffee {

public:
	Espresso() : Coffee() {
		strcpy_s(m_type, "Espresso!");
		cout << "Making you fucking Espresso " << endl;
		cout << "this is the Espresso coffee for you !";
	}

};

// third adding a new coffie i.e. cuppuccino 

class Cuppuccino : public Coffee {

public:
	Cuppuccino() : Coffee() {
		strcpy_s(m_type, "Cuppuccino!");
		cout << "Making you fucking Cuppuccino " << endl;
		cout << "this is the Cuppuccino coffee for you !";
	}

};


// finally the concrete creattor class to create the required object of required component.
class CoffeeMakerFactory {
private:
	Coffee *coffee;

public :
	Coffee* getCoffee() {

		int choice = 1;

		cout << "Select the type of coffee you want :" << endl;
		cout << " 1 : : Latte  " << endl;
		cout << " 2 : : Espresso  " << endl;
		cout << " 3 : : Cuppuccino  " << endl;
		cout<< " Selection. ";
		
		cin >> choice;

		switch (choice) {

		case 1: {
			return new Latte();
		}
				break;

		case 2: {
			return new Espresso();
		}
				break;

		case 3: {
			return new Cuppuccino();
		}
				break;

		default: {
			cout << "chutiye dekh ke tyoe krr.";
			return NULL;
		}
				 break;

		}
	}
};





int main()
{
	CoffeeMakerFactory* cmf = new CoffeeMakerFactory();
	Coffee* yourCoffee =  cmf->getCoffee();
	cout <<endl<<"Le daal le agnd mai "<< yourCoffee->getType();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
