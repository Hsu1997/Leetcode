#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i = 0; i <= n; i++) if (ranges[i] > 0) pq.push({i-ranges[i], i+ranges[i]});
        // cout << pq.top().first << " " << pq.top().second << endl;
        int ans = 0;
        int now_search = 0;
        while(now_search < n && !pq.empty()){
            // cout << "now search " << now_search << endl;
            int last = -1;
            while(!pq.empty() && pq.top().first <= now_search){
                // cout << pq.top().first << " " << pq.top().second << endl;
                if (pq.top().second > now_search) last = max(last, pq.top().second);
                pq.pop();
            }
            // cout << "last = " << last << endl;
            if (last < 0) return -1;
            ans++;
            now_search = last;
        }
        return (now_search < n)? -1 : ans;
    }
};

int main(){
    // int n = 5;
    // vector<int> ranges = {3,4,1,1,0,0};
    // int n = 3;
    // vector<int> ranges = {0,0,0,0};
    int n = 35;
    vector<int> ranges = {1,0,4,0,4,1,4,3,1,1,1,2,1,4,0,3,0,3,0,3,0,5,3,0,0,1,2,1,2,4,3,0,1,0,5,2};
    Solution S;
    cout << S.minTaps(n, ranges) << endl;
    return 0;
}