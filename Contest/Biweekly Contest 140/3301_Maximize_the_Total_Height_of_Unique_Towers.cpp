#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());
        long long ans = 0;
        long long cand = 1e9+7;
        for (int i = 0; i < maximumHeight.size(); i++){
            ans += min((long long)maximumHeight[i], cand);
            cand = min((long long)maximumHeight[i], cand) - 1;
            if (cand < 0) return -1;
        }
        return ans;
    }
};

int main(){
    vector<int> maximumHeight = {2,3,4,3};
    // vector<int> maximumHeight = {15,10};
    // vector<int> maximumHeight = {2,2,1};
    Solution S;
    cout << S.maximumTotalSum(maximumHeight) << endl;
    return 0;
}