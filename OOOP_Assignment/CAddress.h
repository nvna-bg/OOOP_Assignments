#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class CAddress {
private:
	string street;
	string postCode;
	string town;

public:
	CAddress();
	CAddress(const CAddress&);
	CAddress(const string, const string, const string);

	void setStreet(const string);
	void setPostCode(const string);
	void setTown(const string);

	const string getStreet();
	const string getPostCode();
	const string getTown();

	friend ostream& operator << (ostream&, CAddress&);
};