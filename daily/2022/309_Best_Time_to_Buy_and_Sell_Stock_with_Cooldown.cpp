#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        // int ans = 0;
        // vector<int> buy(prices.size(), 0);
        // vector<int> sell(prices.size(), 0);
        // buy[0] = -1 * prices[0];
        // buy[1] = min(prices[0], prices[1]) * -1;
        // sell[1] = max(prices[1]-prices[0], 0);
        // ans = max(ans, sell[1]);
        // for (int i = 2; i < prices.size(); i++){
        //     buy[i] = max(buy[i-1], sell[i-2] - prices[i]);
        //     sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
        //     ans = max({ans, buy[i], sell[i]});
        // }
        // for (auto i : buy) cout << i << " ";
        // cout << endl;
        // for (auto i : sell) cout << i << " ";
        // cout << endl;

        int pre_buy = -min(prices[0], prices[1]);
        int pre_sell = max(prices[1]-prices[0], 0);
        int pre_pre_sell = 0;
        int ans = max(0, pre_sell);
        for (int i = 2; i < prices.size(); i++){
            int temp = pre_sell;
            pre_sell = max(pre_sell, pre_buy + prices[i]);
            pre_buy = max(pre_buy, pre_pre_sell - prices[i]);
            pre_pre_sell = temp;
            ans = max(ans, pre_sell);
        }

        return ans;
    }
};

int main(){
    // vector<int> prices = {1,2,3,0,2};
    // vector<int> prices = {1};
    // vector<int> prices = {1,2};
    vector<int> prices = {2,4,1,7};
    Solution S;
    cout << S.maxProfit(prices) << endl;
    return 0;
}