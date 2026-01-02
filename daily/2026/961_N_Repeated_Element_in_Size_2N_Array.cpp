#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;
        for (int i : nums){
            if (s.find(i) != s.end()) return i;
            s.insert(i);
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {1,2,3,3};
    // vector<int> nums = {2,1,2,5,3,2};
    // vector<int> nums = {5,1,5,2,5,3,5,4};
    Solution S;
    cout << S.repeatedNTimes(nums) << endl;
    return 0;
}