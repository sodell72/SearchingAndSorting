#pragma once
#include <string>

class Car{

private:
	std::string name;
	double hp;
	Car* next;
	Car* previous;

public:
	Car(std::string, double);
	~Car();

	void setNext(Car*);
	void setPrevious(Car*);

	Car* getNext();
	Car* getPrevious();

	Car* copy();


	std::string getName();
	double getHp();


};