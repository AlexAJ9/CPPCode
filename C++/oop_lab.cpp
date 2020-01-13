#include <iostream>
#include <afxdisp.h>
#include <string>
#include <fstream>
using namespace std;

enum Gender
{
	Undefined,
	Male,
	Female
};
class CPerson
{
	COleDateTime birthDate;
	string name;
	Gender gender;
	string egn;

#pragma region Validation and birthdate build
	bool isValid(const string &egn)
	{

		if (egn.length() < 10 || egn.length() > 10)
			return false;

		bool result = checkAndBuildBirthDate(egn.substr(0, 6));

		if (result)
		{

			if (ctoi(egn[8]) % 2 != 0 && gender != Female)
				gender = Female;
			if (ctoi(egn[8]) % 2 == 0 && gender != Male)
				gender = Male;

			int controlNumber = 0;
			int weight[]{2, 4, 8, 5, 10, 9, 7, 3, 6};
			int sum = 0;

			for (int i = 0; i < egn.length() - 1; i++)
			{
				int t = ctoi(egn[i]) * weight[i];
				sum += t;
			}

			int dev = sum % 11;

			if (dev < 10)
				controlNumber = dev;

			if (ctoi(egn[9]) == controlNumber)
				return true;
		}

		return false;
	}
	int ctoi(const char &ch)
	{
		return (int)ch - 48;
	}
	bool checkAndBuildBirthDate(string egnDateSubString)
	{
		string year = egnDateSubString.substr(0, 2);
		string month = egnDateSubString.substr(2, 2);
		string day = egnDateSubString.substr(4, 2);

		int y = atoi(year.c_str());
		int m = atoi(month.c_str());
		int d = atoi(day.c_str());

		if (d < 1 || d > 31)
			return false;

		if (m > 12)
		{
			m = m - 20;
			if (m > 12)
			{
				m = m - 20;

				if (m > 12)
					return false;

				y += 2000;
			}
			else
			{
				y += 1800;
			}
		}
		else
		{
			y += 1900;
		}

		COleDateTime now(COleDateTime::GetTickCount());
		COleDateTime tbirthDate(y, m, d, 0, 0, 0);

		if (now.m_status != now.invalid && tbirthDate.m_status != tbirthDate.invalid)
		{
			if (now < tbirthDate)
				return false;
		}
		else
			return false;

		this->birthDate = tbirthDate;
		return true;
	}
#pragma endregion

	friend ostream &operator<<(ostream &os, const CPerson &pers)
	{
		return pers.Output(os);
	}

protected:
	void GetYMD(const string &egn, int &year, int &month, int &day)
	{
		if (birthDate.m_status == birthDate.null)
		{
			SetEGN(egn);
		}
		year = birthDate.GetYear();
		month = birthDate.GetMonth();
		day = birthDate.GetDay();
	}
	COleDateTime GetAgeAsDateTimeObject()
	{
		return birthDate;
	}
	ostream &Output(ostream &stream) const
	{
		stream << "Name: " << name << endl;
		stream << "Gender: " << GenderToString(gender) << endl;
		stream << "EGN: " << egn << endl;

		return stream;
	}

public:
	CPerson(const string &name, Gender gender)
	{
		this->name = name;
		this->gender = gender;
		this->egn = "";
		this->birthDate;
		this->birthDate.m_status = birthDate.null;
	}
	CPerson()
	{
		this->name = "Unnamed";
		this->gender = Undefined;
		this->egn = "";
		this->birthDate;
		this->birthDate.m_status = birthDate.null;
	}

#pragma region Setters
	void SetName(const string &name)
	{
		this->name = name;
	}
	void SetGender(Gender gender)
	{
		this->gender = gender;
	}
	bool SetEGN(const string &egn)
	{
		if (isValid(egn))
		{
			this->egn = egn;
			return true;
		}
		this->egn = "invalid";
		return false;
	}
#pragma endregion
#pragma region Getters
	string GetName() const
	{
		return this->name;
	}
	Gender GetGender() const
	{
		return this->gender;
	}
	string GetEGN() const
	{
		if (this->egn == "")
			return "undefined";

		return this->egn;
	}
#pragma endregion

	string GenderToString(Gender gender) const
	{
		switch (gender)
		{
		case Male:
			return "Male";
		case Female:
			return "Female";
		case Undefined:
			return "Undefined";
		}
	}
	Gender stringToGender(const string &str) const
	{
		if (str == "Male")
			return Male;
		else if (str == "Female")
			return Female;
		else
			return Undefined;
	}
};
class CAddress
{
	string m_cStreetName;
	int m_cPostCode;
	string m_cCity;

	ostream &Output(ostream &stream) const
	{
		stream << m_cCity << " / " << m_cPostCode << " / " << m_cStreetName << endl;
		return stream;
	}
	friend ostream &operator<<(ostream &os, const CAddress &addr)
	{
		return addr.Output(os);
	}

public:
	CAddress()
	{
		m_cStreetName = "unnamed";
		m_cPostCode = 0;
		m_cCity = "unnamed";
	}
	CAddress(string streetName, int postCode, string cityName)
	{
		m_cStreetName = streetName;
		m_cPostCode = postCode;
		m_cCity = cityName;
	}
	CAddress(const CAddress &other)
	{
		this->m_cCity = other.m_cCity;
		this->m_cPostCode = other.m_cPostCode;
		this->m_cStreetName = other.m_cStreetName;
	}
};
class CStudent : public CPerson
{
	string m_cFn;
	CAddress m_CAddress;

#pragma region Friend functions

	friend void ConsoleInputEGN(CStudent &stud)
	{
		string egn;
		cin >> egn;
		stud.SetEGN(egn);
	}
	friend ostream &operator<<(ostream &os, const CStudent &stud)
	{
		return stud.output(os);
	}
	friend bool operator==(CStudent &stud1, CStudent &stud2)
	{
		return stud1.GetAgeAsDateTimeObject() == stud2.GetAgeAsDateTimeObject();
	}
	friend bool operator!=(CStudent &stud1, CStudent &stud2)
	{
		return stud1.GetAgeAsDateTimeObject() != stud2.GetAgeAsDateTimeObject();
	}
	friend bool operator<(CStudent &stud1, CStudent &stud2)
	{
		return stud1.GetAgeAsDateTimeObject() < stud2.GetAgeAsDateTimeObject();
	}
	friend bool operator>(CStudent &stud1, CStudent &stud2)
	{
		return stud1.GetAgeAsDateTimeObject() > stud2.GetAgeAsDateTimeObject();
	}
	friend bool operator>=(CStudent &stud1, CStudent &stud2)
	{
		return stud1.GetAgeAsDateTimeObject() >= stud2.GetAgeAsDateTimeObject();
	}

#pragma endregion

	ostream &output(ostream &stream) const
	{
		this->Output(stream);
		stream << "Fak. N: " << m_cFn << endl;
		stream << "Address: " << m_CAddress << endl;
		return stream;
	}

public:
#pragma region Constructors
	CStudent()
	{
		this->SetName("Unnamed");
		this->SetGender(Undefined);
		this->SetEGN("");
		this->SetFN("");
		this->m_CAddress;
	}
	CStudent(string name, string egn)
	{
		this->SetName(name);
		this->SetEGN(egn);
		this->SetFN("");
		this->m_CAddress;
	}
	CStudent(string name, string egn, CAddress address, string f_n)
	{
		this->SetName(name);
		this->SetEGN(egn);
		this->m_CAddress = address;
		this->SetFN(f_n);
	}
	CStudent(CStudent &const copy)
	{
		this->SetName(copy.GetName());
		this->SetGender(copy.GetGender());
		this->SetEGN(copy.GetEGN());
		this->SetFN(copy.GetFN());
		this->m_CAddress = copy.m_CAddress;
	}
#pragma endregion

	void SetFN(string fn)
	{
		m_cFn = fn;
	}
	string GetFN()
	{
		return m_cFn;
	}
	CAddress GetAddress()
	{
		return m_CAddress;
	}
};

void main()
{

	CAddress address("Gotce Delchev 5", 9090, "Varna");

	CStudent student("Viktor", "9702040961", address, "61660176");
	CStudent student1("James", "9702040961", address, "542132456"); // valid date, invalid egn
	CStudent student2("Peter", "0204050967", address, "543132456"); // valid date, invalid egn

	if (student == student1)
		cout << student.GetName() << " is as old as " << student1.GetName() << endl;
	if (student2 != student1)
		cout << student2.GetName() << " isnt as old as " << student1.GetName() << endl;

	if (student2 < student)
		cout << student.GetName() << " is older than " << student2.GetName() << endl;

	fstream stream("D:\\Tema03.txt", ios::app); // path for the file D:\\Tema03.txt;
	stream << student << endl
		   << endl
		   << student1 << endl
		   << endl
		   << student2 << endl;

	cout << student1;
	system("pause");
}
