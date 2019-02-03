#include "Car.h"
#include "CarList.h"
#include <iostream>
#include <time.h>

using namespace std;

// search is O(n)
// mergeSort is O(n log(n)) in the best, average, and worst cases and uses a space complexity of O(n)
int main(int argc, char * argv[]) {

	// data placed in nodes
	double horses[10] = {776, 100.0, 345, 222.22, 10.456, 99.1, 12, 2, 900.224, 187};
	string names[10] = {"(8)", "(4)", "(7)", "(6)", "(1)", "(3)", "(2)", "sm(0)", "lg(9)", "(6)"};
	
	// creates list and nodes
	CarList myCarList;
	for (int i = 0; i < 10; i++) {
		Car* nextCar = new Car(names[i], horses[i]);
		myCarList.add(nextCar);
	}

	// creating initial clock time
	clock_t t;
	clock_t t2;
	t = clock();
	int g = clock();
	cout << g << endl;
	cout << "initial clock time: " << t << endl << endl;
	
	// test for overloaded <<, also tests add
	cout << myCarList << endl;

	// getting final clock time (testing time for << myCarList)
	t2 = clock();
	t = t2 - t;
	cout << "final clock time: " << t2 << endl;
	cout << "clock time difference: " << t << endl << endl;

	// test doubly linked by getting node from tail
	cout << myCarList.getTail()->getPrevious()->getName() << endl;
	cout << endl;

	// test pop
	myCarList.pop();
	cout << myCarList << endl;

	// add 10th car back in
	myCarList.add(new Car(names[9], horses[9]));
	cout << myCarList << endl;

	// tests for search, this search functionality is big O(n)
	cout << "hp of 776 should be at index 0: " << myCarList.search(776) << endl;
	cout << "hp of 187 should be at index 9: " << myCarList.search(187) << endl;
	cout << "hp of 10.456 should be at index 4: " << myCarList.search(10.456) << endl;
	cout << "hp of 22222 should not be at any index and will return -1: " << myCarList.search(22222) << endl << endl;

	// test get method
	cout << "hp of car in index 2 is 345: " << myCarList.get(2)->getHp() << endl << endl;

	//myCarList.mergeSort(&myCarList, 0, myCarList.getSize() - 2);

	//cout << myCarList << endl;

	//cout << "hi" << endl;

	CarList* list1 = new CarList();
	list1->add(new Car("l1 car1", 20));
	list1->add(new Car("l1 car2", 10));
	list1->add(new Car("l1 car3", 30));
	CarList* list2 = new CarList();
	list2->add(new Car("l2 car1", 2));
	list2->add(new Car("l2 car2", 45));
	list2->add(new Car("l2 car3", 15));

	
	// test mergeList
	CarList* mergedList = CarList::mergeList(list1, list2);
	cout << "here is the merged small list: " << endl << *mergedList << endl;

	// test mergeSortList on small list
	CarList* sorted = CarList::mergeSortList(mergedList);
	cout << "here is the sorted small list: " << endl << *sorted << endl;

	// test mergeSortList on large list
	CarList* sortedBig = CarList::mergeSortList(&myCarList);
	cout << "here is the sorted large list: " << endl << *sortedBig << endl;

	// test mergeSortListDesc with previously sorted list
	CarList* reversed = CarList::mergeSortListDesc(sortedBig);
	cout << "here is the reversed sorted large list: " << endl << *reversed << endl;


	// create another car list
	CarList myCarList2;
	for (int i = 0; i < 10; i++) {
		Car* nextCar = new Car(names[i], horses[i]);
		myCarList2.add(nextCar);
	}

	// test mergeSortListDesc with previously sorted list
	CarList* reversed2 = CarList::mergeSortListDesc(&myCarList2);
	cout << "here is the reversed sorted list 2: " << endl << *reversed2 << endl;

	cin.get();
}