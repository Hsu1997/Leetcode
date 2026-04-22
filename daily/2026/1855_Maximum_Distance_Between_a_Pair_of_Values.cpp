#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int ans = -1;
        int ptr = 0;
        for (int i = 0; i < n1; i++){
            int curr = nums1[i];
            while(ptr < n2 - 1 && nums2[ptr + 1] >= curr) ptr++;
            ans = max(ans, ptr - i);
        }
        return ans == -1? 0 : ans;
    }
};

int main(){
    vector<int> nums1 = {55,30,5,4,2};
    vector<int> nums2 = {100,20,10,10,5};
    // vector<int> nums1 = {2,2,2};
    // vector<int> nums2 = {10,10,1};
    // vector<int> nums1 = {30,29,19,5};
    // vector<int> nums2 = {25,25,25,25,25};
    Solution S;
    cout << S.maxDistance(nums1, nums2) << endl;
    return 0;
}