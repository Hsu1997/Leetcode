#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findPrime(int maxelement){
        vector<bool> isPrime(maxelement + 1, true);
        for (int i = 2; i * i <= maxelement; i++){
            if (isPrime[i]){
                for (int j = i * i; j <= maxelement; j += i) isPrime[j] = false;
            }
        }
        vector<int> prime;
        for (int i = 2; i <= maxelement; i++) if (isPrime[i]) prime.push_back(i);
        // for (int i : prime) cout << i << " ";
        // cout << endl;
        return prime;
    }
    long long longPow(long long base, long long exponent){
        int mod = 1e9 + 7;
        long long ans = 1;
        while(exponent > 0){
            if (exponent % 2) ans = (ans * base) % mod;
            base = (base * base) % mod;
            exponent /= 2;
        }
        return ans;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        long long mod = 1e9 + 7;
        int maxelement = *max_element(nums.begin(), nums.end());
        vector<int> prime = findPrime(sqrt(maxelement));
        vector<int> score(n, 0);
        for (int i = 0; i < n; i++){
            int curr = nums[i];
            int s = 0;
            for (int p : prime){
                if (p > curr) break;
                if (curr % p == 0) s++;
                while(curr % p == 0) curr /= p;
            }
            score[i] = s + (curr > 1);
        }
        // for (int i : score) cout << i << " ";
        // cout << endl;
        vector<int> nextDominant(n, n);
        vector<int> prevDominant(n, -1);
        stack<int> sta;
        for (int i = 0; i < n; i++){
            while (!sta.empty() && score[sta.top()] < score[i]){
                nextDominant[sta.top()] = i;
                sta.pop();
            }
            if (!sta.empty()) prevDominant[i] = sta.top();
            sta.push(i);
        }
        vector<long long> numOfSubbary(n, 0);
        for (int i = 0; i < n; i++){
            numOfSubbary[i] = (long long)(nextDominant[i] - i) * (long long)(i - prevDominant[i]);
        }
        priority_queue<pair<long long,long long>> que;
        for (int i = 0; i < n; i++) que.push({nums[i], numOfSubbary[i]});
        long long ans = 1;
        while(k){
            auto [num, count] = que.top();
            que.pop();
            long long op = min((long long)k, count);
            ans = (ans * longPow(num, op)) % mod;
            k -= op;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {8,3,9,3,8};
    int k = 2;
    // vector<int> nums = {19,12,14,6,10,18};
    // int k = 3;
    Solution S;
    cout << S.maximumScore(nums, k) << endl;
    return 0;
}