#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (hour % 12) + ((double)minutes / 60);
        double m = (double)minutes / 5;
        double delta = abs(h - m) * 30;
        delta = min(delta, 360 - delta);
        return delta;
    }
};

int main(){
    int hour = 12;
    int minutes = 30;
    // int hour = 3;
    // int minutes = 30;
    // int hour = 3;
    // int minutes = 15;
    Solution S;
    cout << S.angleClock(hour, minutes) << endl;
    return 0;
}