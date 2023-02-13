#include <iostream>

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        int range = (high - low + 1);
        if (range % 2 == 0) return range / 2;
        else{
            if (low % 2 && high % 2) return range / 2 + 1;
            else return range / 2;     
        }
        return -1;
    }
};

int main(){
    int low = 3;
    int high = 7;
    Solution S;
    cout << S.countOdds(low, high) << endl;
    return 0;
}