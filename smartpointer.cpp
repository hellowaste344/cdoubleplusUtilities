#include <iostream>
#include <memory>
using namespace std;

class Rectangle{
private:
    int length;
    int breadth;
public:
    Rectangle(int l, int b) : length(l), breadth(b) {}
    int area() {return length * breadth;}
};

int main(){
    // infinite loop
    while(1)
    {   
        // normal pointer
        // memory leak occurse
        int* ptr = new int;
        break;
    }
    
    // unique_ptr stores one pointer at a time
    unique_ptr<Rectangle> p1(new Rectangle(10,5));
    cout << p1->area() << endl;

    unique_ptr<Rectangle> p2;

    // copy the addres of p1 into p2
    p2 = move(p1);
    cout << p2->area() << endl;
    
    // shared_ptr more than one pointer can point to same object at a time
    shared_ptr<Rectangle> p3(new Rectangle(10,10));

    shared_ptr<Rectangle> p4;
    
    // p4 and p3 are pointing to same object
    p4 = p3;
    cout << p4->area() << endl;
    cout << p3->area() << endl;
    cout << p3.use_count() << endl;

    // create shared_ptr smart pointer
    shared_ptr<Rectangle> p5(new Rectangle(20,30));
    
    // create weak_ptr smart pointer
    weak_ptr<Rectangle> p6(p5);
    cout << p5->area() << endl;

    // returns the number of shared_ptr
    // doesn't count weak_ptr
    cout << p6.use_count(); 
    return 0;
}