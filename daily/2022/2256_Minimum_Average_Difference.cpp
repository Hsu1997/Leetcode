#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        vector<long> acc(n, 0);
        acc[0] = nums[0];
        for (int i = 1; i < n; i++) acc[i] = acc[i-1] + nums[i];

        int min_ans = INT_MAX;
        int ans = -1;

        for (int i = 0; i < n-1; i++){
            int temp = abs(acc[i]/(i+1) - (acc[n-1]-acc[i])/(n-i-1));
            // cout << temp << endl;
            if (temp < min_ans){
                min_ans = temp;
                ans = i;
            }
        }
        if (acc[n-1]/n < min_ans) ans = n-1; 

        return ans;
    }
};

int main(){
    vector<int> nums = {2,5,3,9,5,3};
    // vector<int> nums = {1};
    // vector<int> nums = {0,0,0,0};
    Solution S;
    cout << S.minimumAverageDifference(nums) << endl;
    return 0;
}