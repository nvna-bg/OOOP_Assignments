#include <stdexcept>
#include <string>
#include <string.h>
#include <math.h>
#include "CPerson.h"
#include "CAddress.h"

using namespace std;

class CStudent : public CPerson {
private:
	string facultyNumber;
	CAddress address;

	GenderTypes EGNToGender(const string& EGN);

public:
	CStudent();
	CStudent(CStudent&);
	CStudent(string, CAddress, string);
	CStudent(string, CAddress, string, string);

	void setFacultyNumber(string);
	void setAddress(CAddress);

	const string getFacultyNumber();
	CAddress getAddress();

	friend ostream& operator << (ostream&, CStudent&);
};

