#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_set<int> s;
        for (int num : nums){
            if (num < k) return -1;
            else if (num > k){
                if (s.find(num) == s.end()){
                    s.insert(num);
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {5,2,5,4,5};
    int k = 2;
    // vector<int> nums = {2,1,2};
    // int k = 2;
    // vector<int> nums = {9,7,5,3};
    // int k = 1;
    Solution S;
    cout << S.minOperations(nums, k) << endl;
    return 0;
}