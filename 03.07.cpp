#include "careercup.h"
using namespace std;

class Animal
{
public:
    Animal(string s) : name(s) {};
    virtual void setOrder(int od) {order = od;}
    virtual void setType(string tp) {type = tp;}
    virtual string getType() {return type;}
    virtual int getOrder() {return order;}
    virtual string getName() {return name;}
    bool operator> (const Animal &a) const
	{
	    return order > a.order;
	}
private:
    int order;
    string name;
    string type;
};

class Cat: public Animal
{
public:
    Cat(string str) : Animal(str)
	{
	    Animal::setType("Cat");
	}
};

class Dog: public Animal
{
public:
    Dog(string str) : Animal(str)
	{
	    Animal::setType("Dog");
	}
};

class Shelter
{
public:
    Shelter() : order(0) {};
    void enqueue(Animal a)
	{
	    a.setOrder(order);
	    ++order;
	    if(a.getType() == "Dog")
		dogs.push_back(*(Dog*) &a);
	    if(a.getType() == "Cat")
		cats.push_back(*(Cat*) &a);
	    cout << a.getType() << " named " <<  a.getName() << " arrives at order : " << a.getOrder() << endl;
	}
    Animal dequeueAny()
	{
	    if(dogs.empty() && cats.empty())
		cerr << "Empty Shelter!" << endl;
	    if(dogs.empty() && !cats.empty())
	    {
		cout << "No dogs now!" << endl;
		return dequeueCat();
	    }
	    else if(cats.empty() && !dogs.empty())
	    {
		cout << "No cats now!" << endl;
		return dequeueDog();
	    }
	    if(cats.front() > dogs.front())
		return dequeueDog();
	    else
		return dequeueCat();
	}
    Dog dequeueDog()
	{
	    Dog dog = dogs.front();
	    dogs.pop_front();
	    return dog;
	}
    Cat dequeueCat()
	{
	    Cat cat = cats.front();
	    cats.pop_front();
	    return cat;
	}
private:
    list<Dog> dogs;
    list<Cat> cats;
    int order;
};

int main()
{
    Shelter aq;
    Cat c1("Cat1");
    Cat c2("Cat2");
    Cat c3("Cat3");
    Dog d1("Dog1");
    Dog d2("Dog2");
    Dog d3("Dog3");

    aq.enqueue(d1);
    aq.enqueue(c1);
    aq.enqueue(c2);
    aq.enqueue(c3);
    aq.enqueue(d2);
    aq.enqueue(d3);

    Animal a = aq.dequeueAny();
    cout << "Get your pet: " << a.getName() << endl;
    Cat c = aq.dequeueCat();
    cout << "Get your cat: " << c.getName() << endl;
    Dog d = aq.dequeueDog();
    cout << "Get your dog: " << d.getName() << endl;
    return 0;
}
