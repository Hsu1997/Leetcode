#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int slove(vector<int>& s1, vector<int>& d1, vector<int>& s2, vector<int>& d2){
        int m = s1.size();
        int n = s2.size();
        int f1 = INT_MAX;
        for (int i = 0; i < m; i++) f1 = min(f1, s1[i] + d1[i]);
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) ans = min(ans, max(f1, s2[i]) + d2[i]);
        return ans;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(slove(landStartTime, landDuration, waterStartTime, waterDuration), slove(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};

int main(){
    vector<int> landStartTime = {2,8};
    vector<int> landDuration = {4,1};
    vector<int> waterStartTime = {6};
    vector<int> waterDuration = {3};
    // vector<int> landStartTime = {5};
    // vector<int> landDuration = {3};
    // vector<int> waterStartTime = {1};
    // vector<int> waterDuration = {10};
    Solution S;
    cout << S.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration) << endl;
    return 0;
}