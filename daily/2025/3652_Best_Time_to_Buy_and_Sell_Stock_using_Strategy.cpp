#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> accProfit(n, 0);
        vector<long long> accPrices(n, 0);
        long long Profit = 0;
        long long Prices = 0;
        for (int i = 0; i < n; i++){
            Profit += 1LL * prices[i] * strategy[i];
            Prices += prices[i];
            accProfit[i] = Profit;
            accPrices[i] = Prices;
        }
        long long ans = max(Profit, accPrices[k - 1] - accPrices[k / 2 - 1] + accProfit[n - 1] - accProfit[k - 1]);
        for (int strategyStart = 1; strategyStart + k - 1 < n; strategyStart++){
            long long prev = accProfit[strategyStart - 1];
            long long strategyGain = accPrices[strategyStart + k - 1] - accPrices[strategyStart + k / 2 - 1];
            long long after = accProfit[n - 1] - accProfit[strategyStart + k - 1];
            ans = max(ans, prev + strategyGain + after);
        }
        return ans;
    }
};

int main(){
    vector<int> prices = {4,2,8};
    vector<int> strategy = {-1,0,1};
    int k = 2;
    // vector<int> prices = {5,4,3};
    // vector<int> strategy = {1,1,0};
    // int k = 2;
    Solution S;
    cout << S.maxProfit(prices, strategy, k) << endl;
    return 0;
}