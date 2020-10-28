#include <stdexcept>
#include <string>
#include <string.h>

using namespace std;

enum GenderTypes { male = 1, female = 2, other = 0 };

class CPerson {
private:
	string name;
	GenderTypes gender;
	string EGN;

	bool validateEGNLength(string);
	bool validateEGNYear(string);
	bool validateEGNMonth(string);
	bool validateEGNDay(string);
	bool validateEGNGender(string);
	bool validateEGNControlNum(string);

public:
	CPerson(string, GenderTypes, string);
	CPerson();

	void SetName(string);
	void SetGender(GenderTypes);
	void setEGN(string) noexcept (false);
	const string GetName();
	const GenderTypes GetGender();
	const string GetEGN();

	bool isEGNValid(const string);
	GenderTypes stringToGender(string);
	string genderToString(GenderTypes);
};