#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        int ans = 0;
        sort(events.begin(), events.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> waiting_que;
        int curr_max = 0;
        for (auto& event : events){
            int start = event[0];
            int end = event[1];
            int value = event[2];
            while(!waiting_que.empty() && start > waiting_que.top().first){
                curr_max = max(curr_max, waiting_que.top().second);
                waiting_que.pop();
            }
            ans = max(ans, value + curr_max);
            waiting_que.push({end, value});
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> events = {{1,3,2},{4,5,2},{2,4,3}};
    // vector<vector<int>> events = {{1,3,2},{4,5,2},{1,5,5}};
    // vector<vector<int>> events = {{1,5,3},{1,5,1},{6,6,5}};
    Solution S;
    cout << S.maxTwoEvents(events) << endl;
    return 0;
}