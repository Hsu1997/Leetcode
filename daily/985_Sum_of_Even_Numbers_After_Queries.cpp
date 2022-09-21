#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int even_accumulate = 0;
        for (auto i : nums) if (i % 2 == 0) even_accumulate += i;
        for (auto i : queries){
            if (nums[i[1]] % 2 == 0) even_accumulate -= nums[i[1]];
            nums[i[1]] += i[0];
            if (nums[i[1]] % 2 == 0) even_accumulate += nums[i[1]];
            ans.push_back(even_accumulate);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> queries = {{1,0},{-3,1},{-4,0},{2,3}};
    // vector<int> nums = {1};
    // vector<vector<int>> queries = {{4,0}};
    Solution S;
    vector<int> ans = S.sumEvenAfterQueries(nums, queries);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}