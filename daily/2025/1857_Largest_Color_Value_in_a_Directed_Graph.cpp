#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        for (auto edge : edges){
            int from = edge[0];
            int to = edge[1];
            if (from == to) return -1;
            graph[from].push_back(to);
            indegree[to]++;
        }
        queue<int> que;
        vector<vector<int>> count(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) if (indegree[i] == 0) que.push(i);
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            count[curr][colors[curr] - 'a'] += 1;
            for (int neighbor : graph[curr]){
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) que.push(neighbor);
                for (int c = 0; c < 26; c++){
                    count[neighbor][c] = max(count[neighbor][c], count[curr][c]);
                }
            }
        }
        for (int i = 0; i < n; i++) if (indegree[i] != 0) return -1;
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int c = 0; c < 26; c++){
                ans = max(ans, count[i][c]);
            }
        }
        return ans;
    }
};

int main(){
    string colors = "abaca";
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{3,4}};
    // string colors = "a";
    // vector<vector<int>> edges = {{0,0}};
    Solution S;
    cout << S.largestPathValue(colors, edges) << endl;
    return 0;
}