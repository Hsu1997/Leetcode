#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int count_neighbor(unordered_map<int,int>& m, int num){
        return m[num-2] + m[num-1] + m[num] + m[num+1] + m[num+2];
    }
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int,int> m;
        int n = nums.size();
        int start = 0;
        for (int i = 0; i < n; i++){
            m[nums[i]]++;
            while(start < i && (i - start + 1) > count_neighbor(m, nums[i])){
                m[nums[start++]]--;
            }
            ans += (i - start + 1);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {5,4,2,4};
    // vector<int> nums = {1,2,3};
    Solution S;
    cout << S.continuousSubarrays(nums) << endl;
    return 0;
}