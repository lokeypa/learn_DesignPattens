// Learn_CreationDesignPatterns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

#pragma region Abstract factor design pattern

class Door {
public:
	Door(){}
	virtual void Open() = 0;
};

class GasCarDoor : public Door {
public :
	GasCarDoor() : Door() {
		cout << "Creating the dor for gas car!"<<endl;
	}

	void Open() {
		cout << "door sound click" << endl;
	}
};

class ElectricCarDoor : public Door {

public:
	ElectricCarDoor() {
		cout << "Creating the door for electric car! " << endl;
	}

	void Open() {
		cout << "door sound shhhhh!" << endl;
	}
};


/// for engien stuff

class Engine {

protected:
	char m_sound[15];

public :
	Engine(){
		strcpy_s(m_sound, "");
	}
	virtual void Run() = 0;
};


class GasCarEngine : public Engine {
public :
	GasCarEngine() {
		strcpy_s(m_sound, "vroom");
		cout << "making a gas car engine" << endl;
	}

	void Run() {
		cout << m_sound << endl;
	}

};


class ElectricCarEngine : public Engine {
public:
	ElectricCarEngine() {
		strcpy_s(m_sound, "whosshussh");
		cout << "making a Electric car engine" << endl;
	}

	void Run() {
		cout << m_sound << endl;
	}

};


// creating a factory class for abstract factory.

class CarFactory {
public:
	virtual Door* BuildDoor() = 0;
	virtual Engine* BuildEngine() = 0;
 };


class GasCarFactory : public CarFactory {
public:

	// Inherited via CarFactory
	virtual Door * BuildDoor() override
	{
		return new GasCarDoor();
	}
	virtual Engine * BuildEngine() override
	{
		return new GasCarEngine();
	}
};

class ElectricCarFactory : public CarFactory {
public:

	Door * BuildDoor() 
	{
		return new ElectricCarDoor();
	}

	Engine * BuildEngine() 
	{
		return new ElectricCarEngine();
	}

};

int main() {

	CarFactory* carPlant;

	// let user deside which car to build
	int choice = 1;
	cout << "Selecte a car to build \n";
	cout << "1 : Electric Car\n";
	cout << "2 : GAsoline car\n";
	cout << "Your Selection : ";
	cin >> choice;
	cout << endl;

	switch (choice) {
		case 1: {
			carPlant = new ElectricCarFactory();
		}
				break;
		case 2: {
			carPlant = new GasCarFactory();
		}
				break;
		default :{
			cout << "Dekh le lorya!!!!\n";
				carPlant = NULL;
		}
				 break;
	}


	if (carPlant != NULL) {
		Door* car1door =  carPlant->BuildDoor();
		Engine* car1Engine =  carPlant->BuildEngine();

		car1door->Open();
		car1Engine->Run();
	}



	return 0;
}

#pragma endregion


#pragma region Factor Method Concept



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





int mainFactoryMethodConcept()
{
	CoffeeMakerFactory* cmf = new CoffeeMakerFactory();
	Coffee* yourCoffee =  cmf->getCoffee();
	cout <<endl<<"Le daal le agnd mai "<< yourCoffee->getType();
	return 0;
}
#pragma endregion

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
