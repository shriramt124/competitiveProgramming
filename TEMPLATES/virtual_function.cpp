#include <iostream>
using namespace std;
#include <string>

class Animal
{
public:
    virtual void makeSound() const
    {
        cout << "Someone is making sound " << endl;
    }
    void sleep() const
    {
        cout << "Animal is sleeping " << endl;
    }
};

class Dog : public Animal
{
public:
    void makeSound() const override
    {
        cout << "Dog is making sound " << endl;
    }
};

void petSound(const Animal &obj)
{
    obj.makeSound();
}

class Cat : public Animal
{
public:
    void makeSound() const override
    {
        cout << "Meo meo" << endl;
    }
};

int main(int argc, char const *argv[])
{
    Dog dog;
    Cat cat;
    petSound(dog);
    petSound(cat);

    return 0;
}
