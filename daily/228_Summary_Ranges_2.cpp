#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if (n == 0) return ans;
        int start = nums[0];
        bool started = true;
        for (int i = 1; i < n; i++){
            if (nums[i] == nums[i-1] + 1) continue;
            if (started){
                if (start == nums[i-1]) ans.push_back(to_string(start));
                else ans.push_back(to_string(start)+"->"+to_string(nums[i-1]));
                start = nums[i];
            }
        }
        if (start == nums[n-1]) ans.push_back(to_string(start));
        else ans.push_back(to_string(start)+"->"+to_string(nums[n-1]));
        return ans;
    }
};

int main(){
    // vector<int> nums = {0,1,2,4,5,7};
    vector<int> nums = {0,2,3,4,6,8,9};
    Solution S;
    vector<string> ans = S.summaryRanges(nums);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}