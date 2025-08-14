#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> cnt;
        for (int v : basket1) cnt[v]++;
        for (int v : basket2) cnt[v]--;
        vector<int> m;
        int cost = INT_MAX;
        for (auto& [v, c] : cnt){
            if (c % 2) return -1;
            cost = min(cost, v);
            for (int i = 0; i < abs(c) / 2; i++) m.push_back(v);
        }
        sort(m.begin(), m.end());
        long long ans = 0;
        for (int i = 0; i < m.size() / 2; i++){
            ans += min(cost * 2, m[i]);
        }
        return ans;
    }
};

int main(){
    vector<int> basket1 = {4,2,2,2};
    vector<int> basket2 = {1,4,1,2};
    // vector<int> basket1 = {2,3,4,1};
    // vector<int> basket2 = {3,2,5,1};
    // vector<int> basket1 = {84,80,43,8,80,88,43,14,100,88};
    // vector<int> basket2 = {32,32,42,68,68,100,42,84,14,8};
    Solution S;
    cout << S.minCost(basket1, basket2) << endl;
    return 0;
}