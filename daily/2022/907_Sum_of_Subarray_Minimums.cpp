#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7;
        int ans = 0;
        stack<pair<int,int>> s;
        vector<int> v(arr.size(), 0);

        for (int i = 0; i < arr.size(); i++){
            while(!s.empty() && s.top().first >= arr[i]) s.pop();
            if (s.empty()) v[i] = (arr[i] * (i+1)) % mod;
            else v[i] = ((arr[i] * (i - s.top().second)) % mod + v[s.top().second]) % mod;
            s.push(pair(arr[i], i));
        }
        for (auto i : v) ans = (ans + i) % mod;
        return ans;
    }
};

int main(){
    // vector<int> arr = {3,1,2,4};
    vector<int> arr = {11,81,94,43,3};
    Solution S;
    cout << S.sumSubarrayMins(arr) << endl;
    return 0;
}