#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0;
        long long s2 = 0;
        bool nums1_contain_zero = false;
        bool nums2_contain_zero = false;
        for (int i : nums1){
            if (i == 0){
                nums1_contain_zero = true;
                s1++;
            }
            else s1 += i;
        }
        for (int i : nums2){
            if (i == 0){
                nums2_contain_zero = true;
                s2++;
            }
            else s2 += i;
        }
        if ((!nums1_contain_zero && s1 < s2) || (!nums2_contain_zero && s2 < s1)) return -1;
        return max(s1, s2);
    }
};

int main(){
    vector<int> nums1 = {3,2,0,1,0};
    vector<int> nums2 = {6,5,0};
    // vector<int> nums1 = {2,0,2,0};
    // vector<int> nums2 = {1,4};
    // vector<int> nums1 = {1,2,3,2};
    // vector<int> nums2 = {1,4,3};
    Solution S;
    cout << S.minSum(nums1, nums2) << endl;
    return 0;
}