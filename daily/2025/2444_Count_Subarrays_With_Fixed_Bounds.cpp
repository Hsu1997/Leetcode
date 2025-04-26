#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        int min_pos = -1;
        int max_pos = -1;
        int break_pos = -1;
        for (int end = 0; end < n; end++){
            if (nums[end] > maxK || nums[end] < minK){
                break_pos = end;
                min_pos = -1;
                max_pos = -1;
            }
            else{
                if (nums[end] == minK) min_pos = end;
                if (nums[end] == maxK) max_pos = end;
                if (min_pos != -1 && max_pos != -1){
                    ans += min(min_pos, max_pos) - break_pos;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,5,2,7,5};;
    int minK = 1;
    int maxK = 5;
    // vector<int> nums = {1,1,1,1};
    // int minK = 1;
    // int maxK = 1;
    Solution S;
    cout << S.countSubarrays(nums, minK, maxK) << endl;
    return 0;
}