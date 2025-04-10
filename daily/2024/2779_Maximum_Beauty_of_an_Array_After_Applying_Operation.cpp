#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int maxv = 0;
        for (int i : nums) maxv = max(i, maxv);
        vector<int> count(maxv+1, 0);
        for (int i : nums){
            count[max(0, i-k)]++;
            if (i+k+1 <= maxv) count[i+k+1]--;
        }
        int ans = 0;
        int curr = 0;
        for (int i : count){
            curr += i;
            ans = max(ans, curr);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {4,6,1,2};
    int k = 2;
    // vector<int> nums = {1,1,1,1};
    // int k = 10;
    Solution S;
    cout << S.maximumBeauty(nums, k) << endl;
    return 0;
}