#include <iostream>
#include <vector>
#include <map>

using namespace std;

class SegmentTree{
public:
    SegmentTree(vector<int>& nums){
        n = 1;
        while(n < nums.size()) n <<= 1;
        tMax.reserve(n * 2);
        tMin.reserve(n * 2);
        for (int i = 0; i < nums.size(); i++){
            tMax[n + i] = nums[i];
            tMin[n + i] = nums[i];
        }
        for (int i = n - 1; i > 0; i--){
            tMin[i] = min(tMin[i * 2], tMin[i * 2 + 1]);
            tMax[i] = max(tMax[i * 2], tMax[i * 2 + 1]);
        }
    }
    int query(int l, int r){
        int M = -1;
        int m = 1e9 + 7;
        l += n;
        r += n;
        while(l <= r){
            m = min(m, tMin[l]);
            M = max(M, tMax[l]);
            l = (l + 1) / 2;
            m = min(m, tMin[r]);
            M = max(M, tMax[r]);
            r = (r - 1) / 2;
        }
        return M - m;
    }
private:
    int n;
    vector<int> tMax;
    vector<int> tMin;
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree T(nums);
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, less<pair<int,pair<int,int>>>> pq;
        for (int l = 0; l < n; l++){
            pq.push({T.query(l, n - 1), {l, n - 1}});
        }
        long long ans = 0;
        for (int i = 0; i < k; i++){
            auto [v, p] = pq.top();
            pq.pop();
            auto [l, r] = p;
            ans += v;
            if (r > l) pq.push({T.query(l, r - 1), {l, r - 1}});
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,2};
    int k = 2;
    // vector<int> nums = {4,2,5,1};
    // int k = 3;
    Solution S;
    cout << S.maxTotalValue(nums, k) << endl;
    return 0;
}