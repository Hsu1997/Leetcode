#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> cnt(100001);
        for (int i : costs) cnt[i]++;
        int ans = 0;
        int ptr = 1;
        for (int ptr = 1; ptr <= 100000 && coins >= ptr; ptr++){
            int curr = min(cnt[ptr], coins / ptr);
            ans += curr;
            coins -= ptr * curr;
        }
        return ans;
    }
};

int main(){
    vector<int> costs = {1,3,2,4,1};
    int coins = 7;
    // vector<int> costs = {10,6,8,7,7,8};
    // int coins = 5;
    // vector<int> costs = {1,6,3,1,2,5};
    // int coins = 20;
    Solution S;
    cout << S.maxIceCream(costs, coins) << endl;
    return 0;
}