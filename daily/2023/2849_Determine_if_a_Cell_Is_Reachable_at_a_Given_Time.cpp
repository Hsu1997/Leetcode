#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        return max(abs(fx-sx), abs(fy-sy)) <= t;
    }
};

int main(){
    int sx = 2;
    int sy = 4;
    int fx = 7;
    int fy = 7;
    int t = 6;
    // int sx = 3;
    // int sy = 1;
    // int fx = 7;
    // int fy = 3;
    // int t = 3;
    Solution S;
    cout << S.isReachableAtTime(sx, sy, fx, fy, t) << endl;
    return 0;
}