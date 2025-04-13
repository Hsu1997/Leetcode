#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        if (abs(x-z) == abs(y-z)) return 0;
        else if (abs(x-z) < abs(y-z)) return 1;
        else return 2;
    }
};

int main(){
    int x = 2;
    int y = 7;
    int z = 4;
    // int x = 2;
    // int y = 5;
    // int z = 6;
    // int x = 1;
    // int y = 5;
    // int z = 3;
    Solution S;
    cout << S.findClosest(x, y, z) << endl;
    return 0;
}