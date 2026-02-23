#include <iostream>
using namespace std;

class Animal{
public:
    virtual void speak(){
        cout << "Animal sound\n";
    }
};

class Dog : public Animal{
public:
    void speak() override {
        cout << "Bark\n";
    }
};

class Cat : public Animal{
public: 
    void speak() override {
        cout << "Meow\n:";
    }
};

int main(){
    Animal* animals[] = { new Dog(), new Cat()};
    for(Animal* a : animals){
        a->speak();
    }
    
    /*
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->speak();
    a2->speak();
    */
}