#include <iostream>
#include <cctype>
#include <string>
using namespace std;
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int dir = 0; // 0=N, 1=E, 2=S, 3=W
        for (char c : instructions)
        {
			c = toupper(c);
            if (c == 'G') {
                if (dir == 0) y++;
                else if (dir == 1) x++;
                else if (dir == 2) y--;
                else if (dir == 3) x--;
            }
            else if (c == 'L') {
                dir = (dir + 3) % 4; // turn left
            }
            else if (c == 'R') {
                dir = (dir + 1) % 4; // turn right
            }
        }
        return (x == 0 && y == 0) || (dir != 0);
    }
};

int main(){
    Solution sol;
	string instructions;
    cout << "Enter the instructions!" << "\n";
    cin >> instructions;
    if (sol.isRobotBounded(instructions)) {
        cout << "The robot is bounded in a circle." << endl;
    } else {
        cout << "The robot is not bounded in a circle." << endl;
    }
    return 0;
}