#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> holding(n,-INT_MAX);
        vector<int> no_hold(n, 0);
        holding[0] = -prices[0];
        for (int i = 1; i < n; i++){
            holding[i] = max(holding[i-1], no_hold[i-1]-prices[i]);
            no_hold[i] = max(no_hold[i-1], holding[i-1]+prices[i]-fee);
        }
        return no_hold[n-1];
    }
};

int main(){
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    // vector<int> prices = {1,3,7,5,10,3};
    // int fee = 3;
    Solution S;
    cout << S.maxProfit(prices, fee) << endl;
    return 0;
}