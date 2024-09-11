#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }
};

int main(){
    int start = 10;
    int goal = 7;
    // int start = 3;
    // int goal = 4;
    Solution S;
    cout << S.minBitFlips(start, goal) << endl;
    return 0;
}