#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        priority_queue<pair<long,int>, vector<pair<long,int>>, greater<pair<long,int>>> pq;
        int n = nums.size();
        long acc = 0;
        int ans = n + 1;
        for (int i = 0; i < n; i++){
            acc += nums[i];
            if (acc >= k) ans = min(ans, i+1);
            while(!pq.empty() && acc - pq.top().first >= k){
                ans = min(ans, i - pq.top().second);
                pq.pop();
            }
            pq.push({acc, i});
        }
        return (ans == n + 1)? -1 : ans;
    }
};

int main(){
    vector<int> nums = {1};
    int k = 1;
    // vector<int> nums = {1,2};
    // int k = 4;
    // vector<int> nums = {2,-1,2};
    // int k = 3;
    Solution S;
    cout << S.shortestSubarray(nums, k) << endl;
    return 0;
}