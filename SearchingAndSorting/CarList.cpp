#include "CarList.h"
#include <iostream> // get rid of this

CarList::CarList() {
	CarList::size = 0;
	CarList::head = nullptr;
	CarList::tail = nullptr;

}

CarList::~CarList() {

}

Car* CarList::getHead() {
	return this->head;
}

Car* CarList::getTail() {
	return this->tail;
}

int CarList::getSize() {
	return this->size;
}

void CarList::add(Car *newCar) {
	if (this->head == nullptr) {
		this->head = newCar;
		this->tail = newCar;
		//newCar->setNext(nullptr);// added
		//newCar->setPrevious(nullptr);// added
		size++;
		return;
	}

	this->tail->setNext(newCar);
	this->tail->getNext()->setPrevious(this->tail);
	this->tail = this->tail->getNext();
	//this->tail->setNext(nullptr);// added
	this->size++;
}

Car* CarList::pop() {
	if (size == 0) {
		return nullptr;
	}

	Car* result = this->tail;

	if (size == 1) {
		this->head = nullptr;
		this->tail = nullptr;
		this->size--;
		return result;
	}

	this->tail = this->tail->getPrevious();
	this->tail->setNext(nullptr);
	result->setPrevious(nullptr);
	return result;
}

void CarList::insert(Car* car, int index) {
	if (index >= size) {
		return;
	}
	int count = 0;
	Car* currentCar = this->getHead();
	while (count < index) {
		currentCar = currentCar->getNext();
		count++;
	}
	car->setPrevious(currentCar->getPrevious());
	car->setNext(currentCar->getNext());
	if (car->getPrevious() != nullptr) {
		car->getPrevious()->setNext(car);
	} else {
		this->head = car;
	}
	if (car->getNext() != nullptr) {
		car->getNext()->setPrevious(car);
	} else {
		this->tail = car;
	}
	return;
}

Car* CarList::get(int index) {
	Car* currentCar = this->getHead();
	int count = 0;
	while (count < index) {
		currentCar = currentCar->getNext();
		if (currentCar == nullptr) {
			return nullptr;
		}
		count++;
	}
	return currentCar;
}

std::ostream& operator<<(std::ostream& out, const CarList& cList) {
	Car* currentCar = cList.head;
	while (currentCar != nullptr) {
		out << currentCar->getName() << " has " << currentCar->getHp() << " hp!" << std::endl;
		currentCar = currentCar->getNext();
	}
	return out;
}


int CarList::search(double hp) {
	Car* currentNode = this->head;
	if (currentNode == nullptr) return -1;
	int indexCount = 0;
	while (currentNode != nullptr) {
		if (currentNode->getHp() == hp) {
			return indexCount;
		}
		currentNode = currentNode->getNext();
		indexCount++;
	}
	return -1;
}

CarList* CarList::mergeList(CarList* list1, CarList* list2) {
	if (!list1 || list1->getHead() == nullptr) {
		return list2;
	} else if (!list2 || list2->getHead() == nullptr) {
		return list1;
	}
	CarList* result = new CarList();
	Car* currentNode1 = list1->getHead();
	Car* currentNode2 = list2->getHead();
	while (currentNode1 != nullptr || currentNode2 != nullptr) {
		// if either list fully added already
		if (currentNode1 == nullptr) {
			result->add(currentNode2->copy());
			currentNode2 = currentNode2->getNext();
		} else if (currentNode2 == nullptr) {
			result->add(currentNode1->copy());
			currentNode1 = currentNode1->getNext();
			// if both lists have nodes to be iterated through
		} else {
			if (currentNode1->getHp() <= currentNode2->getHp()) {
				result->add(currentNode1->copy());
				currentNode1 = currentNode1->getNext();
			} else {
				result->add(currentNode2->copy());
				currentNode2 = currentNode2->getNext();
			}
		}
	}
	return result;
}


CarList* CarList::splitList(CarList* list) {
	// find half way point
	Car* creep = list->getHead();
	Car* speed = list->getHead();
	while (speed->getNext() && speed->getNext()->getNext()) {
		creep = creep->getNext();
		speed = speed->getNext()->getNext();
	}
	// split list
	Car* middle = creep->getNext();
	creep->setNext(nullptr);
	middle->setPrevious(nullptr);
	CarList* secondHalf = new CarList();
	secondHalf->add(middle);
	return secondHalf;
}


CarList* CarList::mergeSortList(CarList* list) {
	// handle null lists and lists with <= 1 cars
	if (!list || !list->getHead() || !list->getHead()->getNext()) {
		return list;
	}
	CarList* secondHalf = splitList(list);
	list = mergeSortList(list);
	secondHalf = mergeSortList(secondHalf);
	return mergeList(list, secondHalf);
}


CarList* CarList::mergeSortListDesc(CarList* list) {
	CarList* sortedList = mergeSortList(list);
	return sortedList->reverse();
}

CarList* CarList::reverse() {
	if (this->getSize() <= 1) {
		return this;
	}
	Car* currentCar = this->getHead();
	while (currentCar != nullptr) {
		Car* tempCar = currentCar->getPrevious();
		currentCar->setPrevious(currentCar->getNext());
		currentCar->setNext(tempCar);
		currentCar = currentCar->getPrevious();
	}
	Car* tempHead = this->getHead();
	this->head = this->getTail();
	this->tail = tempHead;
	return this;
}


