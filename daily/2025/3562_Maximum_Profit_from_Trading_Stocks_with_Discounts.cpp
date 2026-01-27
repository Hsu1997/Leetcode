#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int neg = -1e8;
    int budget;
    vector<int> present;
    vector<int> future;
    vector<vector<int>> child;
    vector<vector<vector<int>>> dp;

    void dfs(int u){
        for (int v : child[u]) dfs(v);
        for (int parentBought = 0; parentBought <= 1; parentBought++){
            int price = parentBought? present[u] / 2 : present[u];
            int profit = future[u] - price;
            vector<int> skipCurr(budget + 1, neg);
            skipCurr[0] = 0;
            for (int v : child[u]){
                for (int totalCost = budget; totalCost >= 0; totalCost--){
                    for (int childCost = 0; childCost <= totalCost; childCost++){
                        skipCurr[totalCost] = max(skipCurr[totalCost], skipCurr[totalCost - childCost] + dp[v][childCost][0]);
                    }
                }
            }
            vector<int> takeCurr(budget + 1, neg);
            if (budget >= price) takeCurr[price] = 0;
            for (int v : child[u]){
                for (int totalCost = budget; totalCost >= price; totalCost--){
                    for (int childCost = 0; childCost <= totalCost - price; childCost++){
                        takeCurr[totalCost] = max(takeCurr[totalCost], takeCurr[totalCost - childCost] + dp[v][childCost][1]);
                    }
                }
            }
            for (int p = price; p <= budget; p++) takeCurr[p] += profit;
            for (int b = 0; b <= budget; b++){
                dp[u][b][parentBought] = max(skipCurr[b], takeCurr[b]);
            }
        }
    }

    int maxProfit(int n, vector<int>& _present, vector<int>& _future, vector<vector<int>>& hierarchy, int _budget) {
        budget = _budget;
        present = _present;
        future = _future;
        child = vector<vector<int>>(n);
        for (auto& e : hierarchy) child[e[0]-1].push_back(e[1]-1);
        // [node][budget][state]
        // state 0 : no discount, state 1 : discount
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(budget + 1, vector<int>(2, neg)));
        dfs(0);
        int ans = 0;
        for (int b = 0; b <= budget; b++) ans = max(ans, dp[0][b][0]);
        return ans;
    }
};

int main(){
    int n = 2;
    vector<int> present = {1,2};
    vector<int> future = {4,3};
    vector<vector<int>> hierarchy = {{1,2}};
    int budget = 3;
    // int n = 2;
    // vector<int> present = {3,4};
    // vector<int> future = {5,8};
    // vector<vector<int>> hierarchy = {{1,2}};
    // int budget = 4;
    // int n = 3;
    // vector<int> present = {4,6,8};
    // vector<int> future = {7,9,11};
    // vector<vector<int>> hierarchy = {{1,2},{1,3}};
    // int budget = 10;
    // int n = 3;
    // vector<int> present = {5,2,3};
    // vector<int> future = {8,5,6};
    // vector<vector<int>> hierarchy = {{1,2},{2,3}};
    // int budget = 7;
    // int n = 1;
    // vector<int> present = {28};
    // vector<int> future = {6};
    // vector<vector<int>> hierarchy = {};
    // int budget = 2;
    Solution S;
    cout << S.maxProfit(n, present, future, hierarchy, budget) << endl;
    return 0;
}