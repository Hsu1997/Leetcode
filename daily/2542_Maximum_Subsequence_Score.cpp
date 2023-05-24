#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    static bool compare(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> nums;
        for (int i = 0; i < n; i++) nums.push_back({nums1[i], nums2[i]});
        sort(nums.begin(), nums.end(), compare);
        // for (auto i : nums) cout << i.first << " " << i.second << endl;
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0;
        long long acc = 0;
        int mul = nums[0].second;
        for (int i = 0; i < k; i++){
            pq.push(nums[i].first);
            acc += nums[i].first;
            mul = min(mul, nums[i].second);
        }
        ans = acc * mul;
        for (int i = k; i < n; i++){
            if (nums[i].first < pq.top()) continue;
            else{
                acc = acc - pq.top() + nums[i].first;
                pq.pop();
                pq.push(nums[i].first);
                mul = min(mul, nums[i].second);
                ans = max(ans, acc * mul);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums1 = {1,3,3,2};
    vector<int> nums2 = {2,1,3,4};
    int k = 3;
    Solution S;
    cout << S.maxScore(nums1, nums2, k) << endl;
    return 0;
}