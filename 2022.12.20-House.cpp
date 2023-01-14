#include <iostream>
using namespace std;

class House {
	//поля
	const char* city;
	const char* street;
	int number;
	int amountOfFloors;
	int amountOfEntrances;
public:
	// конструктор по умолчанию
	House() {
		city = nullptr;
		street = nullptr;
		number = 1;
		amountOfFloors = 1;
		amountOfEntrances = 1;
	}

	// конструктор копирования
	House(House& h) {
		this->city = h.city;
		this->street = h.street;
		this->number = h.number;
		this->amountOfFloors = h.amountOfFloors;
		this->amountOfEntrances = h.amountOfEntrances;
	}

	// сеттеры
	void setcity(const char* city) {
		this->city = city;
	}
	void setstreet(const char* street) {
		this->street = street;
	}
	void setnumber(int number) {
		this->number = number;
	}
	void setamountOfFloors(int amountOfFloors) {
		this->amountOfFloors = amountOfFloors;
	}
	void setamountOfEntrances(int amountOfEntrances) {
		this->amountOfEntrances = amountOfEntrances;
	}

	// геттеры
	const char* getcity() {
		return this->city;
	}
	const char* getstreet() {
		return this->street;
	}
	int getnumber() {
		return this->number;
	}
	int getamountOfFloors() {
		return this->amountOfFloors;
	}
	int getamountOfEntrances() {
		return this->amountOfEntrances;
	}
};

class Apartment {
	//поля
	int number;
	int entrance;
	int floor;
	House house;
public:
	// конструктор по умолчанию
	Apartment() {
		number = 1;
		entrance = 1;
		floor = 1;
		house = House();
	}

	// конструктор копирования
	Apartment(Apartment& a) {
		this->number = a.number;
		this->entrance = a.entrance;
		this->floor = a.floor;
		this->house = House(a.house);
	}

	// сеттеры
	void setnumber(int number) {
		this->number = number;
	}
	void setentrance(int entrance) {
		this->entrance = entrance;
	}
	void setfloor(int floor) {
		this->floor = floor;
	}
	void sethouse(House house) {
		this->house = house;
	}

	// геттеры
	int getnumber() {
		return this->number;
	}
	int getentrance() {
		return this->entrance;
	}
	int getfloor() {
		return this->floor;
	}
	House gethouse() {
		return this->house;
	}

};

class Person {
	//поля
	const char* name;
	int age;
	Apartment apartment;
public:
	// конструктор по умолчанию
	Person() {
		name = nullptr;
		age = 0;
		apartment = Apartment();
	}

	// конструктор копирования
	Person(Person& p) {
		this->name = p.name;
		this->age = p.age;
		this->apartment = Apartment(p.apartment);
	}

	// сеттеры
	void setname(const char* name) {
		this->name = name;
	}
	void setage(int age) {
		this->age = age;
	}
	void setapartment(Apartment apartment) {
		this->apartment = apartment;
	}

	// геттеры
	const char* getname() {
		return this->name;
	}
	int getage() {
		return this->age;
	}
	Apartment getapartment() {
		return this->apartment;
	}
};

int main()
{
	House myHouse;
	myHouse.setcity("Stavropol");
	myHouse.setstreet("Kulakova");
	myHouse.setnumber(16);
	myHouse.setamountOfEntrances(2);
	myHouse.setamountOfFloors(6);
	Apartment myApartment;
	myApartment.setnumber(601);
	myApartment.setentrance(2);
	myApartment.setfloor(6);
	myApartment.sethouse(myHouse);
	Person myPerson;
	myPerson.setname("John Doe");
	myPerson.setage(28);
	myPerson.setapartment(myApartment);


	cout << "Person:"
		<< "\n\tname - " << myPerson.getname()
		<< "\n\tage - " << myPerson.getage()
		<< "\n\tapartment:"
		<< "\n\t\tnumber - " << myApartment.getnumber()
		<< "\n\t\tentrance - " << myApartment.getentrance()
		<< "\n\t\tfloor - " << myApartment.getfloor()
		<< "\n\t\thouse: "
		<< "\n\t\t\tcity - " << myApartment.gethouse().getcity()
		<< "\n\t\t\tstreet - " << myApartment.gethouse().getstreet()
		<< "\n\t\t\tnumber - " << myApartment.gethouse().getnumber()
		<< "\n\t\t\tamount of floors - " << myApartment.gethouse().getamountOfFloors()
		<< "\n\t\t\tamount of entrances - " << myApartment.gethouse().getamountOfEntrances();

}