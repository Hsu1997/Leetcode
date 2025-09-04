#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a = abs(x - z);
        int b = abs(y - z);
        if (a == b) return 0;
        else return (a < b)? 1 : 2;
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