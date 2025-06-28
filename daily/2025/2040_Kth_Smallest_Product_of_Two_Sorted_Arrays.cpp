#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int pos1 = 0;
        int pos2 = 0;
        // pos1 / pos2 is the position of first number not negative
        while(pos1 < n1 && nums1[pos1] < 0) pos1++;
        while(pos2 < n2 && nums2[pos2] < 0) pos2++;
        auto count = [&](long long threshold){
            long long cnt = 0;
            // - -
            for (int i = 0, j = pos2 - 1; i < pos1 && j >= 0; ){
                if (1LL * nums1[i] * nums2[j] > threshold) i++;
                else{
                    cnt += pos1 - i;
                    j--;
                }
            }
            // + +
            for (int i = pos1, j = n2 - 1; i < n1 && j >= pos2; ){
                if (1LL * nums1[i] * nums2[j] > threshold) j--;
                else{
                    cnt += j - pos2 + 1;
                    i++;
                }
            }
            // - +
            for (int i = 0, j = pos2; i < pos1 && j < n2; ){
                if (1LL * nums1[i] * nums2[j] > threshold) j++;
                else{
                    cnt += n2 - j;
                    i++;
                }
            }
            // + -
            for (int i = pos1, j = 0; i < n1 && j < pos2; ){
                if (1LL * nums1[i] * nums2[j] > threshold) i++;
                else{
                    cnt += n1 - i;
                    j++;
                }
            }
            return cnt;
        };
        long long left = min({1LL * nums1[0] * nums2[0], 1LL * nums1[0] * nums2.back(), 1LL * nums1.back() * nums2[0], 1LL * nums1.back() * nums2.back()});
        long long right = max({1LL * nums1[0] * nums2[0], 1LL * nums1[0] * nums2.back(), 1LL * nums1.back() * nums2[0], 1LL * nums1.back() * nums2.back()});
        long long ans = right;
        while(left <= right){
            long long mid = (left + right) / 2;
            if (count(mid) < k) left = mid + 1;
            else{
                ans = min(ans, mid);
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums1 = {2,5};
    vector<int> nums2 = {3,4};
    int k = 2;
    // vector<int> nums1 = {-4,-2,0,3};
    // vector<int> nums2 = {2,4};
    // int k = 6;
    // vector<int> nums1 = {-2,-1,0,1,2};
    // vector<int> nums2 = {-3,-1,2,4,5};
    // int k = 3;
    // vector<int> nums1 = {-100000,100000};
    // vector<int> nums2 = {-100000,100000};
    // int k = 1;
    Solution S;
    cout << S.kthSmallestProduct(nums1, nums2, k) << endl;
    return 0;
}