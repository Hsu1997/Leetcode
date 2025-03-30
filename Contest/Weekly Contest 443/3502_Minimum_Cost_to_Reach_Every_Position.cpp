#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n = cost.size();
        vector<int> ans(n);
        int m = INT_MAX;
        for (int i = 0; i < n; i++){
            m = min(m, cost[i]);
            ans[i] = m;
        }
        return ans;
    }
};

int main(){
    vector<int> cost = {5,3,4,1,3,2};
    // vector<int> cost = {1,2,4,6,7};
    Solution S;
    vector<int> ans = S.minCosts(cost);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}