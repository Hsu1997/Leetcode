#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int ans = 0;
    vector<vector<int>> e;

    int helper(vector<vector<int>>& edge, int node){
        int count = 1;
        if (edge[node].empty()){
            ans++;
            return count;
        }
        int sub_count = -1;
        bool balance = true;
        for (int child : edge[node]){
            int temp = helper(edge, child);
            if (sub_count == -1) sub_count = temp;
            else balance = balance && (temp == sub_count);
            count += temp;
        }
        // cout << "node " << node << " : " << balance << endl;
        ans += balance;
        return count;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        e.resize(n);
        for (auto i : edges){
            int from = i[0];
            int to = i[1];
            e[from].push_back(to);
            e[to].push_back(from);
        }
        vector<bool> visited(n, false);
        vector<vector<int>> edge(n);
        visited[0] = true;
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            int s = que.size();
            for (int r = 0; r < s; r++){
                int temp = que.front();
                que.pop();
                for (int i : e[temp]){
                    if (!visited[i]){
                        visited[i] = true;
                        edge[temp].push_back(i);
                        que.push(i);
                    }
                }
            }
        }
        // int index = 0;
        // for (auto i : edge){
        //     cout << index++ << " : ";
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        helper(edge, 0);
        return ans;
    }
};

int main(){
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
    // vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,4},{0,5},{1,6},{2,7},{3,8}};
    Solution S;
    cout << S.countGoodNodes(edges) << endl;
    return 0;
}