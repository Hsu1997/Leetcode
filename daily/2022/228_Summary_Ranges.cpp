#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 1){
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        vector<int>::iterator i = nums.begin();
        vector<int>::iterator j;
        vector<int>::iterator temp;
        temp = j = i;
        while (i != nums.end()){
            j++;
            while(j != nums.end() && *j == *temp + 1){
                temp++;
                j++;
                if (j == nums.end()) break;
            }
            if (i == temp) ans.push_back(to_string(*i));
            else ans.push_back(to_string(*i) + "->" + to_string(*temp));
            i = temp = j;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3};
    Solution S;
    vector<string> ans = S.summaryRanges(nums);
    for (auto i : ans) cout << i << " ";
    return 0;
}