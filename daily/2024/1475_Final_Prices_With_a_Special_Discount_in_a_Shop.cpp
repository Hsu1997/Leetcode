#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        int n = prices.size();
        for (int i = n-1; i >= 0; i--){
            int curr = prices[i];
            while(!s.empty() && curr < s.top()) s.pop();
            if (!s.empty()) prices[i] -= s.top();
            s.push(curr);
        }
        return prices;
    }
};

int main(){
    vector<int> prices = {8,4,6,2,3};
    // vector<int> prices = {1,2,3,4,5};
    // vector<int> prices = {10,1,1,6};
    Solution S;
    vector<int> ans = S.finalPrices(prices);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}