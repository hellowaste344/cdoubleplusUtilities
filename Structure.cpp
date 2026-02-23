#include <iostream>
using namespace std;
// define inner structure
struct inner
{
    int a, b;
};
// define the outer structure that contains the inner structure
struct outer
{
    inner in;
    int x, y;

    /* 
    // Nested structure
    struct inner
    {
    int a, b;
    } in;
    int x, y;
    */
};

typedef struct itswhatits
{
    int x, y;

} IWI; //Alias is specified here 

struct GfG
{
    char c;
    int x, y;
    int count;
    void showCount(){cout << count << endl;}
};

struct Base{
    int x, y;
    // member function
    int sum() const{return x + y;}
};

struct Point
{
 private:
    int x, y;

 public:
    // constructors
    Point(int a, int b) : x(a), y(b) {}

    int getX() const{return x;}
    
    int getY() const{return y;}
    
    void setX(int value){x = value;}
    
    void show(){
        cout << x << " " << y << endl;
    }

    // destructor
    ~Point(){
        cout << "Destroyed Point Variable!" << endl;
    }
};

int main(){
    // struct keyword is not needed here
    Base b = {0, 1};
    // accessing members
    cout << b.x << " ";
    cout << b.y << " ";
    // updating members
    b.x = 99;

    cout << b.sum() << endl;

    Point p(0,1);

    cout << p.getX() << endl;
    cout << p.getY() << endl;

    p.setX(99);
    p.show();

    cout << sizeof(GfG) << endl;
    GfG gfg = {'A', 2,3,4};
    
    // creating pointer
    GfG *sptr = &gfg;

    // accessing using arrow operator
    sptr->showCount();

    outer obj = {{1,2}, 10,20};
    cout << "Inner: " << obj.in.a << "  " << obj.in.b << endl;
    cout << "Outer: " << obj.x << "  " << obj.y;
    return 0;
}