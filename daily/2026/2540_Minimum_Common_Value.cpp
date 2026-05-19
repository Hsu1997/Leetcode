#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr1 < n1 && ptr2 < n2){
            if (nums1[ptr1] == nums2[ptr2]) return nums1[ptr1];
            if (nums1[ptr1] < nums2[ptr2]) ptr1++;
            else ptr2++;
        }
        return -1;
    }
};

int main(){
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,4};
    // vector<int> nums1 = {1,2,3,6};
    // vector<int> nums2 = {2,3,4,5};
    Solution S;
    cout << S.getCommon(nums1, nums2) << endl;
    return 0;
}