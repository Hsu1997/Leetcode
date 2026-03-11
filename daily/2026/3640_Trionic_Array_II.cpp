#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long ans = LLONG_MIN;
        int n = nums.size();
        int ptr1 = 1;
        int ptr2 = 1;
        while(ptr1 < n){
            bool flag = true;
            while(ptr1 + 1 < n && !(nums[ptr1 - 1] < nums[ptr1] && nums[ptr1] > nums[ptr1 + 1])){
                if (nums[ptr1 - 1] == nums[ptr1]){
                    ptr1 = ptr1 + 1;
                    flag = false;
                    break;
                }
                ptr1++;
            }
            if (ptr1 + 2 >= n) return ans;
            if (!flag) continue;
            ptr2 = ptr1 + 1;
            while(ptr2 + 1 < n && !(nums[ptr2 - 1] > nums[ptr2] && nums[ptr2] < nums[ptr2 + 1])){
                if (nums[ptr2 - 1] == nums[ptr2]){
                    ptr1 = ptr2 + 1;
                    flag = false;
                    break;
                }
                ptr2++;
            }
            if (ptr2 + 1 >= n) return ans;
            if (!flag) continue;
            long long currAcc = 0;
            for (int i = ptr1; i <= ptr2; i++) currAcc += nums[i];
            long long prevAcc = 0;
            long long prevMax = LLONG_MIN;
            int tempptr = ptr1 - 1;
            while(tempptr >= 0 && nums[tempptr] < nums[tempptr + 1]){
                prevAcc += nums[tempptr];
                prevMax = max(prevMax, prevAcc);
                tempptr--;
            }
            long long nextAcc = 0;
            long long nextMax = LLONG_MIN;
            tempptr = ptr2 + 1;
            while(tempptr < n && nums[tempptr] > nums[tempptr - 1]){
                nextAcc += nums[tempptr];
                nextMax = max(nextMax, nextAcc);
                tempptr++;
            }
            ans = max(ans, prevMax + currAcc + nextMax);
            ptr1 = tempptr - 1;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {0,-2,-1,-3,0,2,-1};
    // vector<int> nums = {1,4,2,7};
    // vector<int> nums = {1,4,2,2,3,1,2};
    Solution S;
    cout << S.maxSumTrionic(nums) << endl;
    return 0;
}