#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> v;
        for (int i = 0; i < nums.size(); i++){
            string temp = to_string(nums[i]);
            string trans = "";
            for (int j = 0; j < temp.length(); j++){
                trans += to_string(mapping[temp[j]-'0']);
            }
            v.push_back({stoi(trans), i});
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for (auto i : v) ans.push_back(nums[i.second]);
        return ans;
    }
};

int main(){
    vector<int> mapping = {8,9,4,0,2,1,3,5,7,6};
    vector<int> nums = {991,338,38};
    // vector<int> mapping = {0,1,2,3,4,5,6,7,8,9};
    // vector<int> nums = {789,456,123};
    Solution S;
    vector<int> ans = S.sortJumbled(mapping, nums);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}