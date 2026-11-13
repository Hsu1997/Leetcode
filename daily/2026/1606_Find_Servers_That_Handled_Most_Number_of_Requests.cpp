#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        vector<int> cnt(k, 0);
        set<int> available;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i = 0; i < k; i++) available.insert(i);
        for (int i = 0; i < n; i++){
            int t = arrival[i];
            while(!pq.empty() && t >= pq.top().first){
                int idx = pq.top().second;
                pq.pop();
                available.insert(idx);
            }
            if (available.empty()) continue;
            auto it = available.lower_bound(i % k);
            if (it == available.end()) it = available.begin();
            int idx = *it;
            cnt[idx]++;
            pq.push({t + load[i], idx});
            available.erase(it);
        }
        vector<int> ans;
        int max_cnt = -1;
        for (int i = 0; i < k; i++){
            if (cnt[i] >= max_cnt){
                if (cnt[i] > max_cnt){
                    max_cnt = cnt[i];
                    ans.clear();
                }
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main(){
    int k = 3;
    vector<int> arrival = {1,2,3,4,5};
    vector<int> load = {5,2,3,3,3};
    // int k = 3;
    // vector<int> arrival = {1,2,3,4};
    // vector<int> load = {1,2,1,2};
    // int k = 3;
    // vector<int> arrival = {1,2,3};
    // vector<int> load = {10,12,11};
    Solution S;
    vector<int> ans = S.busiestServers(k, arrival, load);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}