#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int mod = 1e9+7;
        sort(arr.begin(), arr.end(), less<int>());
        vector<long> dp(n, 1);
        unordered_map<int,int> m;
        for (int i = 0; i < n; i++) m[arr[i]] = i;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if ((long)arr[j] * arr[j] > arr[i]) break;
                if ((long)arr[j] * arr[j] == arr[i] && m.find(arr[i]/arr[j]) != m.end())                    dp[i] = (dp[i] + 1 * dp[j] * dp[j]) % mod;
                else if (arr[i]  % arr[j] == 0 && m.find(arr[i]/arr[j]) != m.end()) dp[i] = (dp[i] + (1+((long)arr[j] * arr[j] != arr[i])) * dp[j] * dp[m[arr[i]/arr[j]]]) % mod;
            }
        }
        for (auto i : dp) ans = (ans + i) % mod;
        return ans;
    }
};

int main(){
    // vector<int> arr = {2,4};
    // vector<int> arr = {2,4,5,10};
    vector<int> arr = {45,42,2,18,23,1170,12,41,40,9,47,24,33,28,10,32,29,17,46,11,759,37,6,26,21,49,31,14,19,8,13,7,27,22,3,36,34,38,39,30,43,15,4,16,35,25,20,44,5,48};
    Solution S;
    cout << S.numFactoredBinaryTrees(arr) << endl;
    return 0;
}