#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = INT_MAX;
        int landfirst = INT_MAX;
        for (int i = 0; i < n; i++){
            landfirst = min(landfirst, landStartTime[i] + landDuration[i]);
        }
        for (int i = 0; i < m; i++){
            ans = min(ans, ((landfirst >= waterStartTime[i])? landfirst : waterStartTime[i]) + waterDuration[i]);
        }
        int waterfirst = INT_MAX;
        for (int i = 0; i < m; i++){
            waterfirst = min(waterfirst, waterStartTime[i] + waterDuration[i]);
        }
        for (int i = 0; i < n; i++){
            ans = min(ans, ((waterfirst >= landStartTime[i])? waterfirst : landStartTime[i]) + landDuration[i]);
        }
        return ans;
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