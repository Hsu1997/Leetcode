#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> transToGraph(vector<vector<int>>& edges){
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        for (auto edge : edges){
            int n1 = edge[0];
            int n2 = edge[1];
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }
        return graph;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int m = edges1.size() + 1;
        int n = edges2.size() + 1;
        vector<vector<int>> g1 = transToGraph(edges1);
        vector<vector<int>> g2 = transToGraph(edges2);
        vector<int> T1_p1;
        vector<int> T1_p2;

        queue<int> que;
        bool part = true;
        vector<bool> visited(m, false);
        visited[0] = true;
        que.push(0);
        while(!que.empty()){
            int k = que.size();
            while(k--){
                int curr = que.front();
                que.pop();
                if (part) T1_p1.push_back(curr);
                else T1_p2.push_back(curr);
                for (int neighbor : g1[curr]){
                    if (!visited[neighbor]){
                        que.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            part = !part;
        }
        // for (int i : T1_p1) cout << i << " ";
        // cout << endl;
        // for (int i : T1_p2) cout << i << " ";
        // cout << endl;
        vector<int> T2_p1;
        vector<int> T2_p2;
        part = true;
        visited = vector<bool>(n, false);
        visited[0] = true;
        que.push(0);
        while(!que.empty()){
            int k = que.size();
            while(k--){
                int curr = que.front();
                que.pop();
                if (part) T2_p1.push_back(curr);
                else T2_p2.push_back(curr);
                for (int neighbor : g2[curr]){
                    if (!visited[neighbor]){
                        que.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            part = !part;
        }
        int M = max(T2_p1.size(), T2_p2.size());
        vector<int> ans(m, M);
        for (int i : T1_p1) ans[i] += T1_p1.size();
        for (int i : T1_p2) ans[i] += T1_p2.size();
        // for (int i : T2_p1) cout << i << " ";
        // cout << endl;
        // for (int i : T2_p2) cout << i << " ";
        // cout << endl;
        return ans;
    }
};

int main(){
    // vector<vector<int>> edges1 = {{0,1},{0,2},{2,3},{2,4}};
    // vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{1,7},{1,4},{4,5},{4,6}};
    vector<vector<int>> edges1 = {{0,1},{0,2},{0,3},{0,4}};
    vector<vector<int>> edges2 = {{0,1},{1,2},{2,3}};
    Solution S;
    vector<int> ans = S.maxTargetNodes(edges1, edges2);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}