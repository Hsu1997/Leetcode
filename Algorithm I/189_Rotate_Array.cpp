#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverse(vector<int>& nums, int i, int j){
        while(i < j) swap(nums[i++], nums[j--]);
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
};

int main(){
    int n[7] = {1,2,3,4,5,6,7};
    int k = 3;
    vector<int> nums(n, n + 7);
    Solution A;
    A.rotate(nums, k);
    for (auto &it : nums) cout << it << " ";
}