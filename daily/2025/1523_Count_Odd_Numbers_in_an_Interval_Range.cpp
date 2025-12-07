#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        return (high - low + 1) / 2 + (low & 1 & high);
    }
};

int main(){
    int low = 3;
    int high = 7;
    // int low = 8;
    // int high = 10;
    // int low = 21;
    // int high = 22;
    Solution S;
    cout << S.countOdds(low, high) << endl;
    return 0;
}