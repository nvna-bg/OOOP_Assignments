#include <cstdlib>
#include <iostream>
#include "CStudent.h"

using namespace std;

int main(int argsNum, char** argsList) {
	CAddress address("Temenujka 5", "8000", "Burgas");
	CStudent firstStudent("Todor", address, "9612010662", "895-3211");
	cout << firstStudent;

	cout << endl << "Bye" << endl << endl;

	return 0;
}