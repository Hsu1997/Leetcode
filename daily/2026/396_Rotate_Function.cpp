#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int total = 0;
        for (int i = 0; i < n; i++){
            sum += i * nums[i];
            total += nums[i];
        }
        int ans = sum;
        for (int i = 0; i < n; i++){
            sum += n * nums[i] - total;
            ans = max(ans, sum);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {4,3,2,6};
    // vector<int> nums = {100};
    Solution S;
    cout << S.maxRotateFunction(nums) << endl;
    return 0;
}