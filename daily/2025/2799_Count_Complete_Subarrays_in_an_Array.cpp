#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> count;
        unordered_set<int> s(nums.begin(), nums.end());
        int elements_size = s.size();
        int curr_size = 0;
        int ans = 0;
        int end = 0;
        for (int start = 0; start < n; start++){
            while(end < n && curr_size < elements_size){
                count[nums[end]]++;
                if (count[nums[end]] == 1) curr_size++;
                end++;
            }
            if (curr_size < elements_size) return ans;
            ans += (n - end + 1);
            count[nums[start]]--;
            if (count[nums[start]] == 0) curr_size--;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,1,2,2};
    // vector<int> nums = {5,5,5,5};
    Solution S;
    cout << S.countCompleteSubarrays(nums) << endl;
    return 0;
}