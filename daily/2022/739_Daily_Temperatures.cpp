#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        ans[n-1] = 0;
        for (int i = n-2; i >= 0; i--){
            int j = i+1;
            while(temperatures[i] >= temperatures[j] && ans[j] != 0 && j < n){
                j += ans[j];
            }
            if (temperatures[i] < temperatures[j]) ans[i] = j-i;
            else ans[i] = 0;
        }
        return ans;
    }
};

int main(){
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    // vector<int> temperatures = {30,40,50,60};
    // vector<int> temperatures = {30,60,90};
    Solution S;
    vector<int> ans = S.dailyTemperatures(temperatures);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}