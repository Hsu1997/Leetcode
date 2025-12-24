#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int,int> m;
        vector<int> next_pos(n, -1);
        for (int i = n - 1; i >= 0; i--){
            if (rains[i] == 0) continue;
            if (m.find(rains[i]) != m.end()) next_pos[i] = m[rains[i]];
            m[rains[i]] = i;
        }
        // {next_pos, lake idx}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // queue<int> que;
        vector<int> ans(n);
        vector<bool> full(n, 0);
        for (int i = 0; i < n; i++){
            if (rains[i] == 0){
                if (!pq.empty()){
                    ans[i] = pq.top().second;
                    full[ans[i]] = false;
                    pq.pop();
                }
                else{
                    ans[i] = 0;
                }
            }
            else{
                ans[i] = -1;
                int curr_lake = rains[i];
                if (full[curr_lake]) return {};
                full[curr_lake] = true;
                pq.push({next_pos[i], curr_lake});
            }
        }
        return ans;
    }
};

int main(){
    vector<int> rains = {1,2,3,4};
    // vector<int> rains = {1,2,0,0,2,1};
    // vector<int> rains = {1,2,0,1,2};
    Solution S;
    vector<int> ans = S.avoidFlood(rains);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}