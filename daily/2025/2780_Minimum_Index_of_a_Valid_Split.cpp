#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> count;
        for (int i : nums) count[i]++;
        int dominant = -1;
        for (auto& [key, val] : count) if (val > n / 2) dominant = key;
        int left = 0;
        int right = count[dominant];
        for (int i = 0; i < n; i++){
            if (nums[i] == dominant){
                left++;
                right--;
                if (left * 2 > i + 1 && right * 2 > n - 1 - i) return i;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {1,2,2,2};
    // vector<int> nums = {2,1,3,1,1,1,7,1,2,1};
    // vector<int> nums = {3,3,3,3,7,2,2};
    Solution S;
    cout << S.minimumIndex(nums) << endl;
    return 0;
}