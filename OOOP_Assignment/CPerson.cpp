#include <stdexcept>
#include <string>
#include <string.h>
#include <math.h>
#include "CPerson.h"

using namespace std;

CPerson::CPerson() {
	this->name = "undefined";
	this->gender = other;
	this->EGN = "0000000000";
}

CPerson::CPerson(string szName, GenderTypes szGender, string szEGN) {
	this->name = szName;
	this->gender = szGender;
	this->setEGN(szEGN);
}

bool CPerson::validateEGNLength(string egn) {
	return egn.length() == 10;
}

bool CPerson::validateEGNYear(string egn) {
	int year = stoi(egn.substr(0, 2));

	return year >= 0;
}

bool CPerson::validateEGNMonth(string egn) {
	int month = stoi(egn.substr(2, 2));

	return (month > 0 && month < 13) || (month > 20 && month < 33) || (month > 40 && month < 53);
}

bool CPerson::validateEGNDay(string egn) {
	int day = stoi(egn.substr(4, 2));

	return day > 0 && day < 32;
}

bool CPerson::validateEGNGender(string egn) {
	if (this->gender == other) {
		return true;
	}

	int genderSymbol = stoi(egn.substr(8, 1));

	if (genderSymbol % 2) {
		return this->gender == female;
	}
	else {
		return this->gender == male;
	}
}

bool CPerson::validateEGNControlNum(string egn) {
	int controlNumber = stoi(egn.substr(9, 1));
	int controlSum = 0;

	for (unsigned int i = 0; i < egn.length() - 1; ++i) {
		int numWeight = pow(2, i + 1);
		numWeight = numWeight % 11;
		int currentNumber = stoi(egn.substr(i, 1));
		controlSum += currentNumber * numWeight;
	}

	int calculatedControlNumber = controlSum % 11 > 10 ? 0 : controlSum % 11;

	return calculatedControlNumber == controlNumber;
}

GenderTypes CPerson::stringToGender(string gender) {
	if (gender == "m" || gender == "male") {
		return male;
	}

	if (gender == "f" || gender == "female") {
		return female;
	}

	return other;
}
string CPerson::genderToString(GenderTypes gender) {
	if (gender == male) {
		return "male";
	}

	if (gender == female) {
		return "female";
	}

	return "other";
}

bool CPerson::isEGNValid(const string newEGN) {
	return  this->validateEGNLength(newEGN) &&
		this->validateEGNYear(newEGN) &&
		this->validateEGNMonth(newEGN) &&
		this->validateEGNDay(newEGN) &&
		this->validateEGNGender(newEGN) &&
		this->validateEGNControlNum(newEGN);
}

void CPerson::SetName(string szName) {
	this->name = szName;
}

void CPerson::SetGender(GenderTypes gender) {
	this->gender = gender;
}

void CPerson::setEGN(string newEGN) noexcept (false) {
	bool validationResult = this->isEGNValid(newEGN);

	if (!validationResult) {
		throw std::runtime_error("EGN is not valid");
	}

	this->EGN = newEGN;
}

const string CPerson::GetName() {
	return name;
}

const GenderTypes CPerson::GetGender() {
	return this->gender;
}

const string CPerson::GetEGN() {
	return EGN;
}
