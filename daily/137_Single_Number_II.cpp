#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for (auto i : nums) m[i]++;
        for (auto i : m) if (i.second != 3) return i.first;
        return -1;
    }
};

int main(){
    // vector<int> nums = {2,2,3,2};
    vector<int> nums = {0,1,0,1,0,1,99};
    Solution S;
    cout << S.singleNumber(nums) << endl;
    return 0;
}