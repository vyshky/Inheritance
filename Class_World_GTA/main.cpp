#include <iostream>
using namespace std;

class Human
{
	unsigned static int count_obj;
	short count_human;
	bool walk;
	bool alive_dead;
	short health_points;
	short stamina;
	bool voice;
	bool run;
	short human_skin;
public:
	void set_to_stand()
	{
		this->walk = 0;
	}
	void set_to_move()
	{
		this->walk++;
	}

	void set_alive()
	{
		this->alive_dead++;
	}
	void set_dead()
	{
		this->alive_dead = 0;
	}
	void set_health_point(short health_point)
	{
		this->health_points = health_point;
	}
	void set_stamina(short stamina)
	{
		this->stamina = stamina;
	}
	void set_voice()
	{
		this->voice++;
	}
	void set_mute_voice()
	{
		this->voice = 0;
	}
	void set_run_slow_down()
	{
		this->run = 0;
	}
	void set_run()
	{
		this->run++;
	}

	/// GET			
	bool get_walk()
	{
		return this->walk;
	}

	bool get_alive_dead()
	{
		return this->alive_dead;
	}

	short get_health_point()
	{
		return this->health_points;
	}
	short get_stamina()
	{
		return this->stamina;
	}
	bool get_voice()
	{
		return this->voice;
	}
	bool get_run()
	{
		return this->run;
	}

	Human(bool walk = 0, bool alive_dead = 1, short	 health_points = 100, short	stamina = 100, bool	voice = 0, bool run = 0, short human_skin = 0)
	{
		this->walk = walk;
		this->alive_dead = alive_dead;
		this->health_points = health_points;
		this->stamina = stamina;
		this->voice = voice;
		this->run = run;
		this->count_obj++;
		this->count_human = count_obj;
		cout << "HumanConstuct\t" << this << endl;
	}

	virtual ~Human()
	{
		cout << "HumanDestruct\t" << this << endl;
	}

	virtual void info()
	{
		cout << "Людей созданно\t" << count_obj << endl;
		cout << "--------------------------" << endl;
		cout << "Человек\t№" << count_human << endl;
		cout << "|" << (walk ? " Идет" : " Стоит") << endl;
		cout << "|" << (alive_dead ? " Жив" : (health_points > 0 ? " Жив" : " Мертв")) << endl;
		cout << "|" << " Жизней\t" << health_points << endl;
		cout << "|" << " Выносливость\t" << stamina << endl;
		cout << "|" << (voice ? " Кричит(Говорит)" : " Молчит") << endl;
		cout << "|" << (run ? " Убегает" : (walk ? " Идет" : " Стоит")) << endl;
	}

};

class Main_character :public Human
{
	bool uses_weapons;

	Main_character(bool walk = 0, bool alive_dead = 1, short health_points = 100, short	stamina = 100, bool	voice = 0, bool run = 0, short human_skin = 0, bool uses_weapons = 1)
		:Human(walk, alive_dead, health_points, stamina, voice, run, human_skin)
	{
		cout << "Main_characterConstuctor\t" << this;
	}
	~Main_character()
	{
		cout << "Main_characterDestructor\t" << this;
	}
};

class Fireman :public Human
{
	Fire_engine car;
	Fireman(/*bool walk = 0, bool alive_dead = 1, short health_points = 100, short stamina = 100, bool voice = 0, bool run = 0,*/  short fireman_skin = 1)
		:Human(/*walk, alive_dead, health_points, stamina, voice, run,*/ fireman_skin)
	{
		cout << "FiremanConstuctor\t" << this;
	}
	~Fireman()
	{
		cout << "FiremanDestructor\t" << this;
	}
};

class Medic :public Human
{
	Ambulance car;
	Medic(/*bool walk = 0, bool alive_dead = 1, short health_points = 100, short stamina = 100, bool voice = 0, bool run = 0,*/  short medic_skin = 2)
		:Human(/*walk, alive_dead, health_points, stamina, voice, run,*/ medic_skin)
	{
		cout << "MedicConstuctor\t" << this;
	}
	~Medic()
	{
		cout << "MedicDestructor\t" << this;
	}
};

class Car
{
	unsigned static int count_obj;
	short count_car;
	short health_points;
	bool open_door;
	bool drive;
	bool get_in_the_car;
	bool broken_car;
	short model_car;
public:

	void set_health_point(short health_points)
	{
		this->health_points = health_points;
	}
	void set_open_door()
	{
		this->open_door++;
	}
	void set_close_door()
	{
		this->open_door = 0;
	}
	void set_drive()
	{
		this->drive++;
	}
	void set_stop_driving()
	{
		this->drive = 0;
	}
	void set_get_out_of_the_car()
	{
		this->get_in_the_car = 0;
	}
	void set_get_in_the_car()
	{
		this->get_in_the_car++;
	}
	void set_broken_car()
	{
		this->broken_car = 0;
	}
	void set_refurbish_car()
	{
		this->broken_car++;
	}

	short get_health_point()
	{
		return health_points;
	}
	bool get_door()
	{
		return open_door;
	}
	bool get_drive()
	{
		return drive;
	}
	bool get_get_in_the_car()
	{
		return get_in_the_car;
	}
	bool get_broken_car()
	{
		return broken_car;
	}

	Car(short health_points = 100, bool open_door = 0, bool drive = 0, bool get_in_the_car = 0, bool broken_car = 100, short model_car = 0)
	{
		this->count_obj++;
		this->count_car = count_obj;
		this->health_points = health_points;
		this->open_door = open_door;
		this->drive = drive;
		this->get_in_the_car = get_in_the_car;
		this->broken_car = broken_car;
		cout << "CarConstructor\t" << this << endl;
	}
	virtual ~Car()
	{
		cout << "CarDestructor\t" << this << endl;
	}
	void info()
	{
		cout << "Транспортных средств созданно\t" << count_obj << endl;
		cout << "--------------------------" << endl;
		cout << "Транспортное средство\t№" << count_car << endl;
		cout << "Состояние трнспорта\t" << (health_points >= 50 ? "Хорошее" : (health_points > 0 ? "Двигатель дымится" : "Двигатель горит")) << endl;
		cout << "Дверь\t" << (open_door ? "Открыта" : "Закрыта") << endl;
		cout << "Транспорт\t" << (drive && health_points > 0 ? "Едет" : "Стоит") << endl;
		cout << "Сесть в машину\t";
		if (open_door && get_in_the_car == 0)
		{
			get_in_the_car++;//Сесть в машину
			cout << "Садимся в машину" << endl;
		}
		else if (get_in_the_car == 0)
		{
			open_door++;//Открыть дверь
			get_in_the_car++;//Сесть в машину
			cout << "Открываем дверь и садимся" << endl;
		}
		cout << "Машина\t" << (broken_car ? (health_points >= 50 ? "Машина не нуждается в ремонте" : "Требуется ремонт в ближайшем гараже") : "Машина не подлежит ремонту") << endl;
	}
};

class Fire_engine :public Car
{
	bool water_wash;
	Fire_engine(short health_points = 100, bool open_door = 0, bool drive = 0, bool get_in_the_car = 0, bool broken_car = 100, short model_car = 1, bool water_wash = 1)
		:Car(health_points, open_door, drive, get_in_the_car, broken_car, model_car)
	{
		cout << "CarConstructor\t" << this << endl;
	}
	~Fire_engine()
	{
		cout << "CarDestructor\t" << this << endl;
	}

	friend class Fireman;
};

class Ambulance :public Car
{
	Ambulance(short health_points = 100, bool open_door = 0, bool drive = 0, bool get_in_the_car = 0, bool broken_car = 100, short model_car = 2)
		:Car(health_points, open_door, drive, get_in_the_car, broken_car, model_car)
	{
		cout << "MedicConstructor\t" << this << endl;
	}
	~Ambulance()
	{
		cout << "MedicDestructor\t" << this << endl;
	}
	friend class Medic;
};


void main()
{

}