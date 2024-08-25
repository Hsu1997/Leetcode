#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

#define ll long long

class Solution {
public:
    const ll mod = 1000000007;
    ll power_and_mod(ll base, ll exp){
        if (exp == 0) return 1;
        ll ans = 1;
        while(exp > 1){
            if (exp % 2) ans = (ans * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return (ans * base) % mod;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) return nums;
        int n = nums.size();
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        for (int i = 0; i < n; i++) pq.push({nums[i], i});
        unordered_set<ll> s;
        while(k && s.size() < n){
            auto [val, index] = pq.top();
            pq.pop();
            val *= multiplier;
            k--;
            s.insert(index);
            pq.push({val, index});
        }
        vector<int> v(n);
        int rep = k / n;
        int plus_one = k % n;
        while(!pq.empty()){
            auto [val, index] = pq.top();
            pq.pop();
            val = ((val % mod) * power_and_mod(multiplier, rep + ((plus_one-- > 0)? 1 : 0))) % mod;
            v[index] = val;
        }
        return v;
    }
};

int main(){
    // vector<int> nums = {2,1,3,5,6};
    // int k = 5;
    // int multiplier = 2;
    // vector<int> nums = {1,2};
    // int k = 3;
    // int multiplier = 4;
    // vector<int> nums = {100000,2000};
    // int k = 2;
    // int multiplier = 1000000;
    vector<int> nums = {161209470};
    int k = 56851412;
    int multiplier = 39846;
    Solution S;
    vector<int> ans = S.getFinalState(nums, k, multiplier);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}