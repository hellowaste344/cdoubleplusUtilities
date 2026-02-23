// Classes/Methods	Description
// join()	It ensures that the calling thread waits for the specified thread to complete its execution.
// detach()	Allows the thread to run independently of the main thread, meaning the main thread does not need to wait.
// mutex	A mutex is used to protect shared data between threads to prevent data races and ensure synchronization.
// lock_guard	A wrapper for mutexes that automatically locks and unlocks the mutex in a scoped block.
// condition_variable	Used to synchronize threads, allowing one thread to wait for a condition before proceeding.
// atomic	Manages shared variables between threads in a thread-safe manner without using locks.
// sleep_for()	Pauses the execution of the current thread for a specified duration.
// sleep_until()	Pauses the execution of the current thread until a specified time point is reached.
// hardware_concurrency()	Returns the number of hardware threads available for use, allowing you to optimize the use of system resources.
// get_id	Retrieves the unique ID of the current thread, useful for logging or debugging purposes.
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class MyClass{
public:
    // non-static member function
    void f1(int num){
        cout << "f1 func: " << num << endl;
    }

    // static member function that takes one parameter
    static void f2(int num){
        cout << "f2 func: " << num << endl;
    }
};

class SumFunctor{
    int* n;
public:
    SumFunctor(int a) : n(new int(a)) {} // int* n = a;
            // (int& a) : n(&a) better memory control 
            // no destructor needed
    // destructor
    ~SumFunctor(){
        delete n;
    }
    // overload the operator() to
    // make it callable
    void operator()() const{
        cout << *n << "\n";
    };

};


void task1(){
    cout << "Thread 1 is running. ID: " << this_thread::get_id() << "\n";
}

void task2(){
    cout << "Thread 2 is running. ID: " << this_thread::get_id() << "\n";
}

void func(int n){
    cout << n << endl;
}

int main(){
    // Member functions
    // requires an object
    MyClass obj;

    // passing object and parameter
    thread t5(&MyClass::f1, &obj, 3);

    t5.join();

    // static member function can
    // be called without an object
    thread t6(&MyClass::f2, 7);

    t6.join();

    thread t1(task1);
    thread t2(task2);

   // join t1 if joinable
    if(t1.joinable()){
        t1.join();
        cout << "t1 joined";
    }

    // detach t2
    if(t2.joinable()){
        t2.detach();
        cout << "t2 detached";
    }

    // get thread ids
    cout << "t1 ID: " << t1.get_id() << "\n";
    cout << "t2 ID: " << t2.get_id() << "\n";

 

    cout << "Main thread sleeping for a while>..\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Main thread awoke>..\n";

    thread t(func, 3); // t(func, param1, param2);

    t.join();
    
    int n;
    cout << "n:?\n";
    cin >> n;

    thread t3([&](const int n){
        cout << n*n << "\n";
    }, n);

    t3.join();

    thread t4(SumFunctor(5));

    // wait for the thread  
    // to complete
    t4.join();
    return 0;
}

// Problems with Multithreading
// Multithreading improves the performance and utilization of CPU, but it also introduces various problems:

// Deadlock
// Race Condition
// Starvation