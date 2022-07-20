//Algorithm : 	Number all chopsticks. You first pick up the lower numbered chopstick. If the higher numbered
//				chopstick exists, pick up and eat. Else release the lowered chopstick as well.
//
//				Avoids deadlock as all philosophers will first pick up left and then right except for the last.
//				This breaks the chain. With this solution, a philosopher can never hold the larger chopstick
// 				without holding the smaller one. This prevents the ability to have a cycle,
// 				since a cycle means that a higher chopstick would "point"to a lower one.

#include <mutex>
#include <thread>
#include <unistd.h>
#include <iostream>
#include <vector>
using namespace std;
//even
//odd
#define numPhilosophers 5


class Chopstick {
private :
	int id;
	mutex avail;

public :
	Chopstick(int val) {
		id = val;
		avail.unlock();
	}
	bool pickUp() {
		return(avail.try_lock()); //Returns true if it is able to lock
	}
	void putDown() { //Only call putDown if it was able to pick up.
		avail.unlock();
	}
	int getID() {
		return(id);
	}
};

class Philosopher {
private :
	Chopstick* smaller;
	Chopstick* larger;
	int numBites;
	int id;

	bool doneEating;
	bool pickUp();
	void putDown();
	void chew();

public :
	Philosopher(Chopstick* left, Chopstick* right, int id);
	void eat();
	int getID() {
		return(id);
	}
};

Philosopher :: Philosopher(Chopstick* left, Chopstick* right, int index) {
	id = index;
	if (left->getID() < right->getID()) {
		smaller = left;
		larger = right;
	} else {
		larger = left;
		smaller = right;
	}
	doneEating = false;
	numBites = 10;
	cout << "Create Philospher " << id << " with smaller chopstick=" << smaller->getID() << " and larger chopstick=" << larger->getID() << endl;
}

bool Philosopher :: pickUp() {
	//Try to pickup lower chopstick first
	if (smaller->pickUp()) {
		if (larger->pickUp()) {
			return true;
		} else {
			smaller->putDown();
			return false;
		}
	} else {
		return false;
	}
}

void Philosopher :: putDown() {
	//Put Down the larger chopstick first
	larger->putDown();
	smaller->putDown();
}

void Philosopher :: chew() {
	for (int i=0; i<numBites; i++)
		usleep(1000);
}

void Philosopher :: eat() {
	while(!doneEating) {
		if (pickUp()) {
			chew();
			putDown();
			doneEating = true;
			cout << "Finished eating for Philosopher " << id << " with smaller chopstick " << smaller->getID() << " and larger chopstick " << larger->getID() << endl;
		} else {
			doneEating = false;
		}
	}
}

int main() {
	vector<thread> threads;

	Philosopher* p[numPhilosophers];
	Chopstick*	c[numPhilosophers];

	for (int i=0; i<numPhilosophers; i++) {
		c[i] = new Chopstick(i);
	}
	for (int i=0; i<numPhilosophers; i++) {
		int left_id = i;
		int right_id = (i-1 < 0) ? (numPhilosophers-1) : i-1;
		p[i] = new Philosopher(c[left_id], c[right_id], i);
	}
	
	for (int i=0; i<numPhilosophers; i++) {
		thread t(&Philosopher::eat, p[i]);
		threads.push_back(move(t));
	}

	for (int i=0; i<numPhilosophers; i++) {
		threads[i].join();
	}
	return 0;
}
