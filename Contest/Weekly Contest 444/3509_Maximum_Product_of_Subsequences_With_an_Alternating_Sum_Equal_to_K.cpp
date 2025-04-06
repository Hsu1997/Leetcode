#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ans = -1;
    int n;
    int k;
    int limit;
    // [index][sum][production][status]
    // [max150][-900~900][0~5000][0/1/-1]
    // In fact, numbers from [1, 12] can produce only 313 distinct products
    unordered_map<int,unordered_map<int,unordered_map<int,unordered_map<int,int>>>> memo;
    int maxProduct(vector<int>& nums, int _k, int _limit) {
        n = nums.size();
        k = _k;
        limit = _limit;
        int total = 0;
        for (int i : nums) total += i;
        if (k > total || k < -total) return -1;
        recursion(nums, 0, 0, 1, 0);
        return ans;
    }
    void recursion(vector<int>& nums, int index, int s, int p, int m){
        if (index == n){
            if (s == k && p <= limit && m != 0) ans = max(ans, p);
            return;
        }
        if (memo.count(index) && memo[index].count(s) && memo[index][s].count(p) && memo[index][s][p].count(m)) return;
        recursion(nums, index+1, s, p, m);
        if (m == 0 || m == 1){
            recursion(nums, index+1, s + nums[index], min(limit+1, p * nums[index]), 2);
        }
        else{
            recursion(nums, index+1, s - nums[index], min(limit+1, p * nums[index]), 1);
        }
        memo[index][s][p][m]= 1;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    int k = 2;
    int limit = 10;
    // vector<int> nums = {0,2,3};
    // int k = -5;
    // int limit = 12;
    // vector<int> nums = {2,2,3,3};
    // int k = 0;
    // int limit = 9;
    Solution S;
    cout << S.maxProduct(nums, k, limit) << endl;
    return 0;
}