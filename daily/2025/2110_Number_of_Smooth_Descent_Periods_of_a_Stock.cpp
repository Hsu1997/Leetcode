#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 1;
        int n = prices.size();
        int c = 1;
        for (int i = 1; i < n; i++){
            if (prices[i] + 1 == prices[i-1]){
                c++;
            }
            else c = 1;
            ans += c;
        }
        return ans;
    }
};

int main(){
    vector<int> prices = {3,2,1,4};
    // vector<int> prices = {8,6,7,7};
    // vector<int> prices = {1};
    Solution S;
    cout << S.getDescentPeriods(prices) << endl;
    return 0;
}