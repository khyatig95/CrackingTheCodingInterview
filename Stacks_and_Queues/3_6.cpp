//Algorithm :   Maintain 2 different queues of cat and dog. Maintain a
//              global pointer of the oldest animal so far.

using namespace std;
#include <iostream>
#include "Queue.h"
#include "LinkedList.h"
#include <string>

class AnimalInfo {
    public : 
        string name;
        int timestamp;
};

class Animal {
    private :
        Queue<AnimalInfo*> cat, dog;
        int oldest = 0;
    public :
        void Enqueue(bool isDog, string val);
        void DequeueOldest();
        void DequeueDog();
        void DequeueCat();
        void print();
};

void Animal :: Enqueue(bool isDog, string val) {
    AnimalInfo* ani = new AnimalInfo();
    ani->name = val;
    ani->timestamp = oldest;

    if (isDog) {
        cout << "Enqueue dog " << ani->name << " with timestamp " << ani->timestamp << endl;
        dog.push(ani);
    } else { 
        cout << "Enqueue cat " << ani->name << " with timestamp " << ani->timestamp << endl;
        cat.push(ani);
    }
    oldest++;
    
}

void Animal :: DequeueDog() {
    cout << "Dequeuing Dog : " << dog.peek()->name << " with timestamp " << dog.peek()->timestamp << endl;
    dog.pop();
}

void Animal :: DequeueCat() {
    cout << "Dequeuing Cat : " << cat.peek()->name << " with timestamp " << cat.peek()->timestamp << endl;
    cat.pop();
}

void Animal :: DequeueOldest() {
    if (cat.isEmpty()) {
        DequeueDog();
        return;
    } else if (dog.isEmpty()) {
        DequeueCat();
        return;
    }
    
    AnimalInfo* cat_temp = cat.peek();
    AnimalInfo* dog_temp = dog.peek();
    AnimalInfo* var;

    cout << "The cat timestamp for " << cat_temp->name << " is " << cat_temp->timestamp << " and dog timestamp for " << dog_temp->name << " is " << dog_temp->timestamp << endl;
    if (cat_temp->timestamp < dog_temp->timestamp) {
        DequeueCat();
        cout << "Dequeued Cat " << var->name << endl;
     } else {
        DequeueDog();
        cout << "Dequeued Dog " << var->name << endl;
     }
}

void Animal :: print() {
    cout << "Cat List is " << endl;
    cat.printQueue();
    cout << "Dog List is " << endl;
    dog.printQueue();
}

int main() {
    Animal obj;
    obj.Enqueue(true, "dog0");
    obj.Enqueue(true, "dog1");
    obj.Enqueue(false, "cat0");
    obj.Enqueue(true, "dog2");
    obj.Enqueue(false, "cat1");
    obj.Enqueue(true, "dog3");

    obj.DequeueCat();
    obj.DequeueDog();
    obj.DequeueCat();
    obj.DequeueOldest();

}
