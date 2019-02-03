#pragma once
#include "Car.h"

class CarList {


private:
	Car* head;
	Car* tail;
	int size;


	
public:

	CarList();
	~CarList();


	Car* getHead();
	Car* getTail();
	int getSize();

	void add(Car*);
	Car* pop();
	void insert(Car*, int);
	Car* get(int);

	

	friend std::ostream& operator<<(std::ostream &out, const CarList& data);


	// returns -1 if value not found, otherwise returns index node with matched hp
	// this function is O(n)
	int search(double);

	// this function is 0(n)
	static CarList* mergeList(CarList*, CarList*);

	// this function is O(n)
	static CarList* splitList(CarList*);

	// this function is O n(log(n))
	static CarList* mergeSortList(CarList*);

	// this function is O n(log(n))
	static CarList* mergeSortListDesc(CarList*);

	// this function is O(n)
	CarList* reverse();

};