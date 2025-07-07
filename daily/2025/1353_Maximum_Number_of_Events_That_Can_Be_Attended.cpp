#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int ans = 0;
        auto cmp = [](vector<int>& a, vector<int>& b){
            if (a[0] != b[0]) return a[0] < b[0];
            else return a[1] < b[1];
        };
        sort(events.begin(), events.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = events.size();
        int idx = 0;
        int t = events[0][0];
        while(idx < n || !pq.empty()){
            while(idx < n && events[idx][0] <= t){
                pq.push(events[idx++][1]);
            }
            while (!pq.empty() && pq.top() < t){
                pq.pop();
            }
            if (!pq.empty() && pq.top() >= t){
                pq.pop();
                ans++;
            }
            t++;
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> events = {{1,2},{2,3},{3,4}};
    // vector<vector<int>> events = {{1,2},{2,3},{3,4},{1,2}};
    Solution S;
    cout << S.maxEvents(events) << endl;
    return 0;
}