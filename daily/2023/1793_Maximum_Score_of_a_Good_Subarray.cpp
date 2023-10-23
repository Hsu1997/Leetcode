#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i = k;
        int j = k;
        long ans = nums[k];
        long temp = nums[k];
        while(i > 0 || j < n-1){
            while(i > 0 && nums[i-1] >= temp) i--;
            while(j < n-1 && nums[j+1] >= temp) j++;
            // cout << i << " " << j << " : " << temp * (j-i+1) << endl;
            ans = max(ans, temp * (j-i+1));
            if (i == 0 && j == n-1) break;
            if ((j == n-1) || (i > 0 && nums[i-1] >= nums[j+1])) temp = nums[--i];
            else temp = nums[++j];
        }
        return ans;
    }
};

int main(){
    // vector<int> nums = {1,4,3,7,4,5};
    // int k = 3;
    vector<int> nums = {5,5,4,5,4,1,1,1};
    int k = 0;
    Solution S;
    cout << S.maximumScore(nums, k) << endl;
    return 0;
}