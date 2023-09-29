#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        sort(intervals.begin(), intervals.end(), compare);
        // for (auto i : intervals) cout << i[0] << "," << i[1] << endl;
        int now = INT_MIN;
        for(int i = 0; i < n; i++){
            int x = intervals[i][0];
            int y = intervals[i][1];
            if (x >= now) now = y;
            else ans++;
        }
        return ans;
    }
};

int main(){
    // vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    vector<vector<int>> intervals = {{0,2},{1,3},{2,4},{3,5},{4,6}};
    Solution S;
    cout << S.eraseOverlapIntervals(intervals) << endl;
    return 0;
}