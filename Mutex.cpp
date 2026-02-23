#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

int counter = 0;
mutex mtx;

void increment(){
    for(float i = 0; i < 1e9; i+= 0.1){
        mtx.lock(); // prevents thread crush
        counter++;
        mtx.unlock(); // prevent thread crush
    }
}

int main(){
    thread t1(increment); // runs simultaneously
    thread t2(increment); // runs simultaneously

    t1.join();
    this_thread::sleep_for(chrono::milliseconds(1));
    if (t2.joinable()){
        t2.detach();
    }
    cout << counter << endl;
}
