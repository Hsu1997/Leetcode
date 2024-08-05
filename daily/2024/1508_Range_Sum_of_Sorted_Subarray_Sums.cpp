#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i = 0; i < n; i++) pq.push({nums[i], i});
        int round = 1;
        int ans = 0;
        int mod = 1e9+7;
        while(round <= right){
            auto temp = pq.top();
            pq.pop();
            int num = temp.first;
            int index = temp.second;
            if (round >= left) ans = (ans + num) % mod;
            if (index+1 < n) pq.push({num + nums[index+1], index+1});
            round++;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    int n = 4;
    int left = 1;
    int right = 5;
    // vector<int> nums = {1,2,3,4};
    // int n = 4;
    // int left = 3;
    // int right = 4;
    // vector<int> nums = {1,2,3,4};
    // int n = 4;
    // int left = 1;
    // int right = 10;
    Solution S;
    cout << S.rangeSum(nums, n, left, right) << endl;
    return 0;
}