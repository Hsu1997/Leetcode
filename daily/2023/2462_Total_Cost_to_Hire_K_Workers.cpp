#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        if (candidates * 2 >= costs.size()){
            sort(costs.begin(), costs.end());
            long long ans = 0;
            for (int i = 0; i < k; i++) ans += costs[i];
            return ans;
        }

        priority_queue<int, vector<int>, greater<int>> pql;
        priority_queue<int, vector<int>, greater<int>> pqr;
        int left = 0;
        int right = costs.size()-1;
        while(pql.size() < candidates) pql.push(costs[left++]);
        while(pqr.size() < candidates) pqr.push(costs[right--]);
        long long ans = 0;
        int taken = 0;
        while(left <= right && taken < k){
            // cout << "ans = " << ans << ", taken = " << taken << endl;
            if (pqr.top() < pql.top()){
                // cout << "take " << pqr.top() << " and push " << costs[right] << " to right" << endl;
                ans += pqr.top();
                pqr.pop();
                pqr.push(costs[right--]);
            }
            else{
                // cout << "take " << pql.top() << " and push " << costs[left] << " to left" << endl;
                ans += pql.top();
                pql.pop();
                pql.push(costs[left++]);
            }
            taken++;
        }
        if (taken == k) return ans;
        while(!pqr.empty()){
            pql.push(pqr.top());
            pqr.pop();
        }
        while(taken < k){
            ans += pql.top();
            pql.pop();
            taken++;
        }
        return ans;
    }
};

int main(){
    vector<int> costs = {17,12,10,2,7,2,11,20,8};
    int k = 3;
    int candidates = 4;
    // vector<int> costs = {1,2,4,1};
    // int k = 3;
    // int candidates = 3;
    // vector<int> costs = {31,25,72,79,74,65,84,91,18,59,27,9,81,33,17,58};
    // int k = 11;
    // int candidates = 2;
    Solution S;
    cout << S.totalCost(costs, k, candidates) << endl;
    return 0;
}