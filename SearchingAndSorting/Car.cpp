#include "Car.h"

Car::Car(std::string name, double hp) {
	this->name = name;
	this->hp = hp;
	this->next = nullptr;
	this->previous = nullptr;
}

Car::~Car() {

}

void Car::setNext(Car* next) {
	this->next = next;
}

void Car::setPrevious(Car* previous) {
	this->previous = previous;
}

Car* Car::getNext() {
	return this->next;
}

Car* Car::getPrevious() {
	return this->previous;
}

Car* Car::copy() {
	return new Car(this->getName(), this->getHp());
}

std::string Car::getName() {
	return this->name;
}

double Car::getHp() {
	return this->hp;
}
