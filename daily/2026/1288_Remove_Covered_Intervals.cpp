#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0;
        int currMax = 0;
        for (auto& interval : intervals){
            if (interval[1] <= currMax) ans++;
            currMax = max(currMax, interval[1]);
        }
        return intervals.size() - ans;
    }
};

int main(){
    vector<vector<int>> intervals = {{1,4},{3,6},{2,8}};
    // vector<vector<int>> intervals = {{1,4},{2,3}};
    Solution S;
    cout << S.removeCoveredIntervals(intervals) << endl;
    return 0;
}