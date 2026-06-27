#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> cnt;
        for (long long num : nums) cnt[num]++;
        int ans = (cnt[1] > 0)? (cnt[1] - 1) / 2 * 2 + 1 : 0;
        for (long long num : nums){
            if (num == 1) continue;
            int curr = 1;
            while (cnt[num] >= 2 && cnt[num * num] >= 1){
                num = num * num;
                curr += 2;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {5,4,1,2,2};
    // vector<int> nums = {1,3,2,4};
    // vector<int> nums = {1,1};
    // vector<int> nums = {1,1,1,1,1,1,1,1,1,1,2,4,8,16,32,64,128,256,512,1024};
    Solution S;
    cout << S.maximumLength(nums) << endl;
    return 0;
}