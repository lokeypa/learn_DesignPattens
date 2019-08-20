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
		strcpy_s(m_type, "Latte the coffee!");
		cout << "Making you fucking latte " << endl;
		cout << "this is the latte coffee for you !";
	}

};



//Second type of coffee i.e. Espresso .// concreate class.
class Latte : public Coffee {

public:
	Latte() : Coffee() {
		strcpy_s(m_type, "Espresso the coffee!");
		cout << "Making you fucking Espresso " << endl;
		cout << "this is the Espresso coffee for you !";
	}

};


// finally the concrete creattor class to create the required object of required component.












int main()
{
    
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
