#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        auto compare = [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        };
        sort(events.begin(), events.end(), compare);
        int ans = 0;
        vector<int> after_max(n+1, 0);
        vector<int> begining(n, 0);
        for (int i = n-1; i >= 0; i--){
            begining[i] = events[i][0];
            after_max[i] = max(events[i][2], after_max[i+1]);
        }
        for (int i = 0; i < n; i++){
            int end = events[i][1];
            int idx = upper_bound(begining.begin(), begining.end(), end) - begining.begin();
            ans = max(ans, events[i][2] + after_max[idx]);
        }
        return ans;
    }
};

int main(){
    // vector<vector<int>> events = {{1,3,2},{4,5,2},{2,4,3}};
    vector<vector<int>> events = {{1,3,2},{4,5,2},{1,5,5}};
    // vector<vector<int>> events = {{1,5,3},{1,5,1},{6,6,5}};
    Solution S;
    cout << S.maxTwoEvents(events) << endl;
    return 0;
}