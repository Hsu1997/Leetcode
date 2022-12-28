#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int, vector<int>, less<int>> q(piles.begin(), piles.end());
        for (int i = 0; i < k; i++){
            int take = q.top();
            take -= take/2;
            q.pop(), q.push(take);
        }
        int ans = 0;
        while(!q.empty()){
            // cout << q.top() << " ";
            ans += q.top(), q.pop();
        }
        return ans;
    }
};

int main(){
    // vector<int> piles = {5,4,9};
    // int k = 2;
    vector<int> piles = {4,3,6,7};
    int k = 3;
    Solution S;
    cout << S.minStoneSum(piles, k) << endl;
    return 0;
}