#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream> 
using namespace std;

const string INPUT_FILE = "demo_in.dat";

class Fraction {
public:

	Fraction();
	Fraction(int newWholeNumber);
	Fraction(int newNumerator, int newDenominator);
	Fraction(int newWholeNumber, int newNumerator, int newDenominator);
	Fraction(const Fraction& copyFromThisFraction);

	~Fraction();

	void setFraction(int newWholeNumber);
	void setFraction(int newNumerator, int newDenominator);
	void setFraction(int newWholeNumber, int newNumerator, int newDenominator);

	string toString();
	void printToConsole() {

		cout << right << setw(6) << toString() << " ";
	}
	int returnFractionObjects() {
		return fractionCount;
	}

	bool operator==(const Fraction& otherFraction) const;
	Fraction& operator=(const Fraction& otherFraction);
	friend ostream& operator<<(ostream& os, const Fraction& fractionObj);
	friend istream& operator>>(istream& is, Fraction& fractionObj);


private:

	static const int DEFAULT_NUMERATOR = 1;
	static const int DEFAULT_DENOMINATOR = 1;

	int numerator = DEFAULT_NUMERATOR;
	int denominator = DEFAULT_DENOMINATOR;

	static int fractionCount;

};
class FractionExeption {

public:
	FractionExeption() {
		message = "Unknown Error";
	}
	FractionExeption(int value) {
		message = value;
	}
	string what() {
		return message;
	}
private:

	string message = "";

};

void defaultMenuOption();

void assignLists(Fraction**& array, int size);
void deAllocateMemory(Fraction**& array, int size);
void printArray(Fraction**& array, int size);

void createAndPrintArray(Fraction**& array);
void overloadDemo();

Fraction** ppFractions = nullptr;

int main()
{
	int userInput = 0;
	enum {

		DEMO = 1,
		QUIT

	};

	while (userInput != QUIT) {

		cout << "\n\nMenu:\n"
			<< "1. Print table based off input\n"
			<< "2. Exit\n"
			<< "\nInput: ";

		cin >> userInput;

		switch (userInput) {
		case DEMO:
			overloadDemo();
			break;
		case QUIT:
			break;
		default:
			defaultMenuOption();
			break;
		}
	}

	return 0;
}

Fraction::Fraction() {

	setFraction(0, DEFAULT_NUMERATOR, DEFAULT_DENOMINATOR);

}
Fraction::Fraction(int newWholeNumber) {

	setFraction(0, newWholeNumber, 1);

}
Fraction::Fraction::Fraction(int newNumerator, int newDenominator) {

	setFraction(0, newNumerator, newDenominator);

}
Fraction::Fraction(int newWholeNumber, int newNumerator, int newDenominator) {

	setFraction(newWholeNumber, newNumerator, newDenominator);

}
Fraction::Fraction(const Fraction& copyFromThisFraction) {

	setFraction(0, copyFromThisFraction.numerator, copyFromThisFraction.denominator);

}
Fraction::~Fraction() {

	setFraction(0, 0, 1);

}

void Fraction::setFraction(int newWholeNumber) {

	setFraction(0, newWholeNumber, 1);
}
void Fraction::setFraction(int newNumerator, int newDenominator) {

	setFraction(0, newNumerator, newDenominator);
}
void Fraction::setFraction(int newWholeNumber, int newNumerator, int newDenominator) {
	try {

		int errorNumber = 0;

		if (newNumerator > newDenominator && newWholeNumber !=0) {

			cout << "ERROR: NUMERATOR IS LARGER THAN DENOMINATOR\n ERROR HERE: ";
			errorNumber = newNumerator;
			throw(FractionExeption(errorNumber));

		}
		if (newNumerator < 0) {

			cout << "ERROR: NUMERATOR IS LESS THAN OR EQUAL TO 0\n ERROR HERE: ";
			errorNumber = newNumerator;
			throw(FractionExeption(errorNumber));

		}
		if (newDenominator < 0) {

			cout << "ERROR: DENOMINATOR IS LESS THAN OR EQUAL TO 0\n ERROR HERE: ";
			errorNumber = newDenominator;
			throw(FractionExeption(errorNumber));

		}
		if (newWholeNumber < 0) {

			cout << "ERROR: FRACTION IS LESS THAN OR EQUAL TO 0\n ERROR HERE: ";
			errorNumber = newWholeNumber;
			throw(FractionExeption(errorNumber));

		}

		numerator = newWholeNumber * newDenominator + newNumerator;
		denominator = newDenominator;
	}
	catch (FractionExeption ex) {

		cout << ex.what() << endl;

	}
	catch (...) {

		cout << "UNKNOWN ERROR!\n";

	}

}

string Fraction::toString() {

	return (to_string(numerator)) + "/" + (to_string(denominator));

}

int Fraction::fractionCount = 0;

bool Fraction::operator==(const Fraction& otherFraction) const {

	return ((numerator == otherFraction.numerator) && (denominator == otherFraction.denominator));
}
Fraction& Fraction::operator=(const Fraction& rightFraction) {

	if (this != &rightFraction) {

		this->setFraction(rightFraction.numerator, rightFraction.denominator);

	}

	return *this;
}

ostream& operator<<(ostream& os, const Fraction& fractionObj) {


	int whole = 0;
	int numerator = fractionObj.numerator;

	while (numerator > fractionObj.denominator) {

		numerator = numerator - 1;
		whole++;
	}

	if (whole > 0) {

		os << whole << " ";

	}

	os << numerator << "/" << fractionObj.denominator;
	
	return os;
}
istream& operator>>(istream& is, Fraction& fractionObj) {

	cout << "\nInput numerator: ";
	is >> fractionObj.numerator;

	cout << "\nInput denominator: ";
	is >> fractionObj.denominator;

	return is;

}

void defaultMenuOption() {

	cout << "Invalid choice, try again\n";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void assignLists(Fraction**& array, int size) {

	try {
		// Makes the rows
		array = new Fraction * [size] {nullptr};

		// makes the columns
		for (int i = 0; i < size; ++i) {
			array[i] = new Fraction[size];
		}

		for (int rows = 0; rows < size; ++rows) {

			for (int columns = 0; columns < size; ++columns) {
				if (rows == 0 && columns == 0) {

				}
				else if (rows == 0) {

					array[rows][columns].setFraction(columns, size);

				}
				else if (columns == 0) {

					array[rows][columns].setFraction(rows, size);

				}
				else {

					array[rows][columns].setFraction(columns * rows, size * size);

				}

			}
		}


	}
	catch (bad_alloc& ex)
	{

		deAllocateMemory(array, size);

	}

}
void deAllocateMemory(Fraction**& array, int size) {

	if (array != nullptr)
	{
		for (int i = 0; i < size; ++i) {

			delete[] array[i];
			array[i] = nullptr;

		}

		delete[] array;
		array = nullptr;
	}

}
void printArray(Fraction**& array, int size) {

	if (array) {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {

				array[i][j].printToConsole();
			}

			cout << endl;
		}

	}
	else {

	}

}

void createAndPrintArray(Fraction**& array) {

	int denominator = 0;

	while (denominator <= 0)
	{
		cout << "\nInput denominator: ";
		cin >> denominator;

		if (denominator <= 0) {

			cout << "ERROR: " << denominator << " IS INVALID, INPUT AN INTEGER LARGER THAN 0";
			defaultMenuOption();
		}

	}

	assignLists(array, denominator);
	printArray(array, denominator);

}
void overloadDemo() {


	Fraction fr1;
	Fraction fr2(5, 2);

	cout << "\n1. >> operator Demo: \n"
		<< "Before >> fr1: " << fr1;

	ifstream infile;
	infile.open(INPUT_FILE);
	if (!infile) {
		cout << "Cannot open file" << endl;
		exit(EXIT_FAILURE);
	}
	infile >> fr1;

	cout << "\nAfter >> fr1: " << fr1
		<< "\n==============================================================\n"

		<< "2. << operator Demo: \n"
		<< "Cout << fr2 [5/2]: " << fr2
		<< "\n==============================================================\n"

		<< "3. = operator Demo: \n"
		<< "Befre fr1 = fr2: \n"
		<< "fr1: " << fr1 << "; fr2: " << fr2;
	fr1 = fr2;
	cout << "\n\nAfter fr1 = fr2: \n"
		<< "fr1: " << fr1 << "; fr2: " << fr2

		<< "\n==============================================================\n"
		<< "4. == Operator Demo: \n"
		<< "fr1 == fr2: ";

	if (fr1 == fr2) {

		cout << "true";

	}
	else {

		cout << "false";

	}
	cout << "\n==============================================================\n";


}
/*
TEST RUN:



Menu:
1. Print table based off input
2. Exit

Input: 1

1. >> operator Demo:
Before >> fr1: 1/1
Input numerator:
Input denominator:
After >> fr1: 2/3
==============================================================
2. << operator Demo:
Cout << fr2 [5/2]: 3 2/2
==============================================================
3. = operator Demo:
Befre fr1 = fr2:
fr1: 2/3; fr2: 3 2/2

After fr1 = fr2:
fr1: 3 2/2; fr2: 3 2/2
==============================================================
4. == Operator Demo:
fr1 == fr2: true
==============================================================


Menu:
1. Print table based off input
2. Exit

Input: 2

C:\Users\Matteo\source\repos\Fraction2\x64\Debug\Fraction2.exe (process 25528) exited with code 0.
Press any key to close this window . . .

*/
