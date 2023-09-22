#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        int i = 0;
        int j = 0;
        double ans;
        for (int c = 0; c < (n1 + n2 + 1) / 2; c++){
            if (nums1[i] < nums2[j]) ans = nums1[i++];
            else ans = nums2[j++];
        }
        if ((n1 + n2) % 2 == 0){
            if (nums1[i] < nums2[j]) ans += nums1[i];
            else ans += nums2[j];
            ans /= 2;
        }
        return ans;
    }
};

int main(){
    // vector<int> nums1 = {1,3};
    // vector<int> nums2 = {2};
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    Solution S;
    cout << S.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}