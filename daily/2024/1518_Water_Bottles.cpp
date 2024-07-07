#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int full = numBottles;
        int empty = 0;
        int ans = 0;
        while(full || empty >= numExchange){
            ans += full;
            empty += full;
            full = empty / numExchange;
            empty %= numExchange;
            // cout << "ans = " << ans << ", full = " << full << ", empty = " << empty << endl;
        }
        return ans;
    }
};

int main(){
    int numBottles = 9;
    int numExchange = 3;
    // int numBottles = 15;
    // int numExchange = 4;
    Solution S;
    cout << S.numWaterBottles(numBottles, numExchange) << endl;
    return 0;
}