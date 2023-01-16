#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if (n == 0) return {{newInterval[0], newInterval[1]}};
        if (newInterval[1] < intervals[0][0]){
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        int start = 0;
        while(start < n && newInterval[0] > intervals[start][0]) start++;
        start = max(0, start-1);
        intervals[start][0] = min(intervals[start][0], newInterval[0]);
        if (newInterval[0] <= intervals[start][1]) intervals[start][1] = max(intervals[start][1], newInterval[1]);
        else intervals.insert(intervals.begin()+start+1, newInterval), start++, n++;
        // cout << "start = " << start << endl;
        int i = start+1;
        // cout << "while position " << i <<  " : " << intervals[i][0] << "," << intervals[i][1] << " <= " << intervals[start][1] << endl;
        while(i < intervals.size() && intervals[i][0] <= intervals[start][1]){
            // cout << "while position " << i <<  " : " << intervals[i][0] << "," << intervals[i][1] << " <= " << intervals[start][1] << endl;
            // cout << intervals[start][1] << " " << intervals[i][1] << endl;
            intervals[start][1] = max(intervals[start][1], intervals[i][1]);
            intervals.erase(intervals.begin()+i);
        }

        return intervals;
    }
};

int main(){
    // vector<vector<int>> intervals = {{1,3},{6,9}};
    // vector<int> newInterval = {2,5};
    // vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    // vector<int> newInterval = {4,8};
    // vector<vector<int>> intervals = {};
    // vector<int> newInterval = {5,7};
    vector<vector<int>> intervals = {{2,5}};
    vector<int> newInterval = {0,0};
    
    Solution S;
    vector<vector<int>> ans = S.insert(intervals, newInterval);
    for (auto i : ans) cout << i[0] << ", " << i[1] << endl;
    return 0;
}