#include <iostream>
#include <string>
using namespace std;

enum class OS{
    Mac,
    Windows,
    Linux,
    Unknown
};

template<typename T>

OS getOs(const T& os){
    if(os == "MacOs") return OS::Mac;
    if(os == "Windows")return OS::Windows;
    if(os == "Linux")return OS::Linux;
    return OS::Unknown;
}


class OperatingSystem{
public:
    template<typename T>
    static void Switch_Case(const T& os){
        switch (getOs(os))
        {
        case OS::Mac:
             cout << "You use apple's operating system: " << os << endl;
            break;
        case OS::Windows:
             cout << "You use Windows's operating system: " << os << endl;
            break;
        case OS::Linux:
            cout << "You use Linux operating system: " << os << endl;
            break;
        default:
            cout << "You likely use Unix based operating system" << endl;
            break;
        }
    }
};

int main(){
    OperatingSystem::Switch_Case("MacOs");
    OperatingSystem::Switch_Case("Windows");
    OperatingSystem::Switch_Case("Linux");
    OperatingSystem::Switch_Case("Android");
    return 0;
}
