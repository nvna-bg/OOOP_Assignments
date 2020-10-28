#include <iostream>
#include <string>
#include <string.h>
#include "CStudent.h"

using namespace std;

CStudent::CStudent() {
	CAddress address("undefined", "0000", "undefined");
	this->SetName("undefined");
	this->address = address;
	this->setEGN("0000000000");
};

CStudent::CStudent(string name, CAddress address, string EGN) {
	this->SetName(name);
	this->address = address;
	this->setEGN(EGN);
	this->SetGender(this->EGNToGender(EGN));
};

CStudent::CStudent(string name, CAddress address, string EGN, string facultyNumber) {
	this->facultyNumber = facultyNumber;
	this->SetName(name);
	this->address = address;
	this->setEGN(EGN);
	this->SetGender(this->EGNToGender(EGN));
};

CStudent::CStudent(CStudent& student) {
	this->SetName(student.GetName());
	this->setEGN(student.GetEGN());
	this->SetGender(student.GetGender());
	this->SetGender(student.GetGender());
}

GenderTypes CStudent::EGNToGender(const string& EGN) {
	int genderSymbol = stoi(EGN.substr(8, 1));
	return genderSymbol % 2 ? female : male;
}

void CStudent::setFacultyNumber(string facultyNumber) {
	this->facultyNumber = facultyNumber;
}

void CStudent::setAddress(CAddress address) {
	this->address = address;
}

const string CStudent::getFacultyNumber() {
	return this->facultyNumber;
}

CAddress CStudent::getAddress() {
	return this->address;
}

ostream& operator << (ostream& toStream, CStudent& student) {
	toStream << "Student`s name: " << student.GetName() << endl;
	toStream << "Student`s gender: " << student.genderToString(student.GetGender()) << endl;
	toStream << "Student`s EGN: " << student.GetEGN() << endl;
	toStream << "Student`s faculty number: " << student.getFacultyNumber() << endl;
	toStream << "Student`s address: " << endl << student.address << endl;

	return toStream;
}