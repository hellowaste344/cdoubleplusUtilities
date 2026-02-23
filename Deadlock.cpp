#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

mutex m1;
mutex m2;

void taskA(){
    cout << "Task A: Trying to lock m1...\n";
    lock_guard<mutex> lock1(m1);
    cout << "Task A: Locked m1.\n";

    this_thread::sleep_for(chrono::seconds(3));
    
    cout << "Task A: Trying to lock m2...\n";
    lock_guard<mutex> lock2(m2); // waiting for m2
    cout << "Task A: locked m2.\n";

    cout << "Task A finished\n";
}

void taskB(){
    cout << "Task B: Trying to lock m2...\n";
    lock_guard<std::mutex> lock2(m2);
    cout << "Task B: Locked m2.\n";

    this_thread::sleep_for(std::chrono::seconds(3));

    cout << "Task B: Trying to lock m1...\n";
    lock_guard<std::mutex> lock1(m1);
    cout << "Task B: Locked m1.\n";

    cout << "Task B finished\n"; // waiting for m1
}

int main(){
    thread t1(taskA);
    thread t2(taskB);

    t1.join();
    t2.join();

    cout << "Done\n";
    return 0;
}