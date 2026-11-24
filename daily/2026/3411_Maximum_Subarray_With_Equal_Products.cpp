#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void delfactor(int i, unordered_map<int,int>& cnt){
        if (i % 2 == 0) cnt[2]--;
        if (i % 3 == 0) cnt[3]--;
        if (i % 5 == 0) cnt[5]--;
        if (i % 7 == 0) cnt[7]--;
        return;
    }
    void addfactor(int i, unordered_map<int,int>& cnt){
        if (i % 2 == 0) cnt[2]++;
        if (i % 3 == 0) cnt[3]++;
        if (i % 5 == 0) cnt[5]++;
        if (i % 7 == 0) cnt[7]++;
        return;
    }
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;
        unordered_map<int,int> cnt;
        int left = 0;
        for (int right = 0; right < n; right++){
            int curr = nums[right];
            if (curr % 2 == 0 && cnt[2] != 0){
                while(cnt[2] != 0) delfactor(nums[left++], cnt);
            }
            if (curr % 3 == 0 && cnt[3] != 0){
                while (cnt[3] != 0) delfactor(nums[left++], cnt);
            }
            if (curr % 5 == 0 && cnt[5] != 0){
                while (cnt[5] != 0) delfactor(nums[left++], cnt);
            }
            if (curr % 7 == 0 && cnt[7] != 0){
                while (cnt[7] != 0) delfactor(nums[left++], cnt);
            }
            addfactor(curr, cnt);
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,1,2,1,1,1};
    // vector<int> nums = {2,3,4,5,6};
    // vector<int> nums = {1,2,3,1,4,5,1};
    // vector<int> nums = {2,6};
    Solution S;
    cout << S.maxLength(nums) << endl;
    return 0;
}