#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> m;
        m[0]++;
        int acc = 0;
        for (auto i : nums){
            int temp = (i%k);
            if (temp < 0) temp += k;
            acc = (acc + temp) % k;
            ans += m[acc];
            m[acc]++;
        }
        
        return ans;
    }
};

int main(){
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;
    // vector<int> nums = {5};
    // int k = 9;

    Solution S;
    cout << S.subarraysDivByK(nums, k) << endl;
    return 0;
}