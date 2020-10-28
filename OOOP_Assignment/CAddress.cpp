#include <iostream>
#include <string>
#include <string.h>
#include "CAddress.h"

using namespace std;

CAddress::CAddress() {
	this->street = "undefined";
	this->postCode = "undefined";
	this->town = "undefined";
}

CAddress::CAddress(string street, string postCode, string town) {
	this->street = street;
	this->postCode = postCode;
	this->town = town;
}

CAddress::CAddress(const CAddress& address) {
	this->street = address.street;
	this->postCode = address.postCode;
	this->town = address.town;
}

ostream& operator << (ostream& toStream, CAddress& address) {
	toStream << "   Street: " << address.street << endl;
	toStream << "   Post Code: " << address.postCode << endl;
	toStream << "   Town: " << address.town << endl;

	return toStream;
}

void CAddress::setStreet(string street) {
	this->street = street;
};

void CAddress::setPostCode(string postCode) {
	this->postCode = postCode;
};
void CAddress::setTown(string town) {
	this->town = town;
};

const string CAddress::getStreet() {
	return this->street;
};

const string CAddress::getPostCode() {
	return this->postCode;
};

const string CAddress::getTown() {
	return this->town;
};
