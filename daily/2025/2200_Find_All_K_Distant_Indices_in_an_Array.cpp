#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < min(k, n); i++){
            if (nums[i] == key) count++;
        }
        for (int i = 0; i < n; i++){
            if (i - k - 1 >= 0 && nums[i - k - 1] == key) count--;
            if (i + k < n && nums[i + k] == key) count++;
            if (count > 0) ans.push_back(i);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {3,4,9,1,3,9,5};
    int key = 9;
    int k = 1;
    // vector<int> nums = {2,2,2,2,2};
    // int key = 2;
    // int k = 2;
    Solution S;
    vector<int> ans = S.findKDistantIndices(nums, key, k);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}