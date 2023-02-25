#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 1) return 0;

        int temp_min = INT_MAX;
        int profit = 0;
        for (int i = 0; i < n; i++){
            temp_min = min(temp_min, prices[i]);
            profit = max(profit, prices[i] - temp_min);
        }
        return profit;
    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    // vector<int> prices = {7,6,4,3,1};
    Solution S;
    cout << S.maxProfit(prices) << endl;
    return 0;
}