#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        if (nums2.size() % 2){
            for (int i : nums1){
                ans ^= i;
            }
        }
        if (nums1.size() % 2){
            for (int i : nums2){
                ans ^= i;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums1 = {2,1,3};
    vector<int> nums2 = {10,2,5,0};
    // vector<int> nums1 = {1,2};
    // vector<int> nums2 = {3,4};
    Solution S;
    cout << S.xorAllNums(nums1, nums2) << endl;
    return 0;
}