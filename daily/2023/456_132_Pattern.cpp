#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int mid = INT_MIN;
        stack<int> s;
        for (int i = n-1; i >= 0; i--){
            if (nums[i] < mid) return true;
            if (!s.empty() && nums[i] == s.top()) continue;
            while(!s.empty() && nums[i] > s.top()) mid = s.top(), s.pop();
            s.push(nums[i]);
        }
        return false;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    // vector<int> nums = {3,1,4,2};
    // vector<int> nums = {-1,3,2,0};
    // vector<int> nums = {1,4,0,-1,-2,-3,-1,-2};
    Solution S;
    cout << S.find132pattern(nums) << endl;
    return 0;
}