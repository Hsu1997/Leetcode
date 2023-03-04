#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        int break_point = -1;
        int min_pos = -1;
        int max_pos = -1;
        for (int i = 0; i < n; i++){
            if (nums[i] > maxK || nums[i] < minK){
                break_point = i;
                min_pos = -1;
                max_pos = -1;
            }
            else{
                if (nums[i] == minK) min_pos = i;
                if (nums[i] == maxK) max_pos = i;
                if (min_pos > -1 && max_pos > -1){
                    ans += min(min_pos, max_pos) - break_point;
                }
            }
        }
        return ans;
    }
};

int main(){
    // vector<int> nums = {1,3,5,2,7,5};
    // int minK = 1;
    // int maxK = 5;
    // vector<int> nums = {1,1,1,1};
    // int minK = 1;
    // int maxK = 1;
    // vector<int> nums = {35054,398719,945315,945315,820417,945315,35054,945315,171832,945315,35054,109750,790964,441974,552913};
    // int minK = 35054;
    // int maxK = 945315;
    vector<int> nums = {934372,927845,479424,49441,17167,17167,65553,927845,17167,927845,17167,425106,17167,927845,17167,927845,251338,17167};
    //                           M                   m     m          M       m    M       m            m     M      m    M              m
    int minK = 17167;
    int maxK = 927845;
    // 118
    Solution S;
    cout << S.countSubarrays(nums, minK, maxK) << endl;
    return 0;
}