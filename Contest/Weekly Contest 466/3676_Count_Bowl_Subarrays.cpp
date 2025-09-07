#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> bigger_R(n, -1);
        vector<int> bigger_L(n, -1);
        stack<int> s;
        for (int i = 0; i < n; i++){
            while(!s.empty() && nums[s.top()] < nums[i]){
                bigger_R[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; i--){
            while(!s.empty() && nums[i] > nums[s.top()]){
                bigger_L[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (bigger_R[i] != -1 && bigger_R[i] - i >= 2) ans++;
            if (bigger_L[i] != -1 && i - bigger_L[i] >= 2) ans++;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,5,3,1,4};
    // vector<int> nums = {5,1,2,3,4};
    // vector<int> nums = {1000000000,999999999,999999998};
    Solution S;
    cout << S.bowlSubarrays(nums) << endl;
    return 0;
}