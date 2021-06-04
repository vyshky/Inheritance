#include<iostream>
#include <cstdlib>;
#include <windows.h>;
#include<string.h>
#include<regex>
using namespace std;
using std::cout;
using std::cin;
using std::endl;



class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_fisrt_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_first_name(const string& first_name)
	{
		this->is_firstname(first_name);
	}
	void set_last_name(const string& last_name)
	{
		this->is_lastname(last_name);
	}
	void set_age(unsigned int age)
	{
		if (age < 100)
		{
			this->age = age;
		}
		else
		{
			age = 0;
		}
	}

	void is_firstname(const string& firstname);
	void is_lastname(const string& lastname);
	//Constructor
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor\t" << this << endl;
	}
	//method
	virtual void info()const
	{
		cout << last_name << " " << first_name << " " << age << " лет" << endl;
	}

};

class Student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(const double rating)
	{
		this->rating = rating;
	}
	//Constructors;
	Student(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating) :Human(last_name, first_name, age)
	{
		this->speciality = speciality;
		this->group = group;
		this->rating = rating;
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	void info() const
	{
		Human::info();
		cout << "Специальность:\t" << speciality << ",\tгрупп\t" << group << ",\tуспеваемость\t" << rating << "\n";
	}
};

class	Graduate :public Student
{
	string diploma_theme;
public:
	const string& get_diploma_theme()
	{
		return diploma_theme;
	}
	void set_diploma_theme(const string& diploma_theme)
	{
		this->diploma_theme = diploma_theme;
	}
	Graduate(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating, const string& diploma_theme
	) :Student(last_name, first_name, age, speciality, group, rating)
	{
		this->diploma_theme = diploma_theme;
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	void info() const
	{
		Student::info();
		cout << "Тема дипломного проэкта:\t" << diploma_theme << endl;
	}
};

class Teacher :public Human
{
	string speciality;
	float experience;

public:
	Teacher(const string& last_name, const string& first_name, int age, const string& speciality, float experience)
		:Human(last_name, first_name, age)
	{
		this->speciality = speciality;
		this->experience = experience;
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	const string& get_speciality()
	{
		return this->speciality;
	}

	float get_experience()
	{
		return this->experience;
	}

	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}

	void set_experience(float expirience)
	{
		if (expirience < 50)
		{
			this->experience = expirience;
		}
		else { this->experience = 0; }

	}
	void info() const
	{
		Human::info();
		cout << "Специальность:\t" << speciality << ",\tСтаж работы:\t" << experience << endl;
	}
};

void Human::is_firstname(const string& firstname)
{
	regex template_first_name("[A-ZА-Я][a-zа-я]{1,15}");
	cout << "Имя\t" << regex_match(firstname.c_str(), template_first_name, std::regex_constants::match_any) << endl;

	if (regex_match(firstname.c_str(), template_first_name, std::regex_constants::match_any))
	{
		this->first_name = firstname;
	}
	else
	{
		cout << "Введите имя" << endl;
		do
		{
			getline(cin, this->first_name);
		} while (!(regex_match(first_name.c_str(), template_first_name, std::regex_constants::match_any)));
	}
}

void Human::is_lastname(const string& lastname)
{
	regex template_last_name("[A-ZА-Я][a-zа-я]{1,15}");
	cout << "Фамилия\t" << regex_match(lastname.c_str(), template_last_name, std::regex_constants::match_any) << endl;

	if (regex_match(lastname.c_str(), template_last_name, std::regex_constants::match_any))
	{
		this->last_name = lastname;
	}
	else
	{
		cout << "Введите фамилию" << endl;
		do
		{
			getline(cin, this->last_name);
		} while (!(regex_match(last_name.c_str(), template_last_name, std::regex_constants::match_any)));
	}
}

ostream& operator<<(ostream& os, const Human& group) //значение по адресс
{
	group.info();
	os << endl;
	return os;
}

//ostream& operator<<(ostream& os, const Human group[]) //Указатель на значение
//{
//	group->info(); // Разименовываем указатель
//	os << endl;
//	return os;
//}

//#define TEST_INFO

void main()
{
	setlocale(LC_ALL, "rus");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//system("chcp 1251");

#ifdef TEST_INFO
	Human human("Jmishenko", "Valera", 70);
	cout << endl << endl;
	human.info();
	cout << endl << endl;

	Student student("Владимирович", "Влад234имир", 15, "Китайская философия", "OST_01", 4.9);
	cout << endl << endl;
	student.info();
	cout << endl << endl;

	Graduate graduate("jessi", "pincman", 25, "Metamthetamin manufactyring", "WithWaolter", 4.5, "Metamthetamin destribution");
	cout << endl << endl;
	graduate.info();
	cout << endl << endl;

	Teacher teacher("Иванова", "Мария", 45, "Химия", 20.5);
	cout << endl << endl;
	teacher.info();
	cout << endl << endl;
#endif // TEST_INFO

	Human* group[] =
	{
		new Human("Jmishenko", "Valera", 70),
		new Student("Владимирович", "Владимир", 15, "Китайская философия", "OST_01", 4.9),
		new Graduate("Jessi", "Pincman", 25, "Metamthetamin manufactyring", "WithWaolter", 4.5, "Metamthetamin destribution"),
		new Teacher("Иванова", "Мария", 45, "Химия", 20.5)
	};
		
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << *group[i] << endl;
	}

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}


	//regex name_template("[A-Z][a-z]{1,30}");
	//string name;
	//cout << "Введите имя: "; cin >> name;
	////regex_match(строка_для_проверки,регулярное_выражение,шаблон_проверки)
	//cout << regex_match(name.c_str(), name_template, std::regex_constants::match_any) << endl;
}