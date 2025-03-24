#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        auto compare = [](vector<int>& a, vector<int>& b){
            if (a[0] != b[0]) return a[0] < b[0];
            else return a[1] < b[1];
        };
        sort(meetings.begin(), meetings.end(), compare);
        // for (auto i : meetings) cout << i[0] << " " << i[1] << endl;
        int n = meetings.size();
        int end = 0;
        int ans = 0;
        for (int i = 0; i < n; i++){
            int curr_start = meetings[i][0];
            int curr_end = meetings[i][1];
            if (curr_start > end) ans += curr_start - end - 1;
            end = max(end, curr_end);
        }
        if (days > end) ans += days - end;
        return ans;
    }
};

int main(){
    int n = 10;
    vector<vector<int>> meetings = {{5,7},{1,3},{9,10}};
    // int n = 5;
    // vector<vector<int>> meetings = {{2,4},{1,3}};
    // int n = 6;
    // vector<vector<int>> meetings = {{1,6}};
    // int n = 57;
    // vector<vector<int>> meetings = {{3,49},{23,44},{21,56},{26,55},{23,52},{2,9},{1,48},{3,31}};
    Solution S;
    cout << S.countDays(n, meetings) << endl;
    return 0;
}