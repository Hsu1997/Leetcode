#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;

        int ans = 0;
        uint dis = UINT_MAX;
        sort(nums.begin(), nums.end());
        for (int k = nums.size()-1; k >= 2; k--){
            int i = 0;
            int j = k-1;
            while(i < j){
                int temp = nums[i] + nums[j] + nums[k];
                uint dis_temp = abs(temp - target);
                if (dis_temp < dis) ans = temp, dis = abs(temp - target);
                if (temp > target) j--;
                else if (temp == target) return temp;
                else i++;
            }
        }
        return ans;   
    }
};

int main(){
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    // vector<int> nums = {1,1,1,0};
    // int target = 100;
    Solution S;
    cout << S.threeSumClosest(nums, target) << endl;
    return 0;
}