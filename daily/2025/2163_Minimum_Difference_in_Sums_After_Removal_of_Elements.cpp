#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int k = n / 3;
        vector<long long> left(n);
        vector<long long> right(n);
        priority_queue<int, vector<int>, less<int>> pq_left;
        priority_queue<int, vector<int>, greater<int>> pq_right;
        long long acc_left = 0;
        long long acc_right = 0;
        for (int i = 0; i < n; i++){
            acc_left += nums[i];
            pq_left.push(nums[i]);
            if (i >= k){
                acc_left -= pq_left.top();
                pq_left.pop();
            }
            left[i] = acc_left;
        }
        // for (int i : left) cout << i << " ";
        // cout << endl;
        for (int i = n-1; i >= 0; i--){
            acc_right += nums[i];
            pq_right.push(nums[i]);
            if (n - i > k){
                acc_right -= pq_right.top();
                pq_right.pop();
            }
            right[i] = acc_right;
        }
        // for (int i : right) cout << i << " ";
        // cout << endl;
        long long ans = LLONG_MAX;
        for (int i = k - 1; i < n - k; i++){
            ans = min(ans, left[i] - right[i+1]);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {3,1,2};
    // vector<int> nums = {7,9,5,8,1,3};
    // vector<int> nums = {16,46,43,41,42,14,36,49,50,28,38,25,17,5,18,11,14,21,23,39,23};
    Solution S;
    cout << S.minimumDifference(nums) << endl;
    return 0;
}