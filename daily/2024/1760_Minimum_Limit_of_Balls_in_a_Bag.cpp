#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool distributable(vector<int>& nums, int num, int maxOperations){
        int operation = 0;
        for (int i : nums){
            operation += ((i + num - 1) / num) - 1;
            if (operation > maxOperations) return false;
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int ans = right;
        while(left < right){
            int mid = left + (right - left) / 2;
            if (distributable(nums, mid, maxOperations)){
                ans = mid;
                right = mid;
            }
            else left = mid + 1;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {9};
    int maxOperations = 2;
    // vector<int> nums = {2,4,8,2};
    // int maxOperations = 4;
    Solution S;
    cout << S.minimumSize(nums, maxOperations) << endl;
    return 0;
}