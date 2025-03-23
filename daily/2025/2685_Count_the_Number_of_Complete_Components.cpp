#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);
        for (auto edge : edges){
            int n1 = edge[0];
            int n2 = edge[1];
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }
        for (int i = 0; i < n; i++){
            if (!visited[i]){
                vector<int> curr_component;
                queue<int> que;
                que.push(i);
                visited[i] = true;
                curr_component.push_back(i);
                while(!que.empty()){
                    int temp = que.front();
                    que.pop();
                    for (int neighbor : graph[temp]){
                        if (!visited[neighbor]){
                            visited[neighbor] = true;
                            curr_component.push_back(neighbor);
                            que.push(neighbor);
                        }
                    }
                }
                bool complete_component = true;
                for (int node : curr_component){
                    if (graph[node].size() != curr_component.size()-1){
                        complete_component = false;
                        break;
                    }
                }
                if (complete_component) ans++;
            }
        }
        return ans;
    }
};

int main(){
    int n = 6;
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4}};
    // int n = 6;
    // vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4},{3,5}};
    Solution S;
    cout << S.countCompleteComponents(n, edges) << endl;
    return 0;
}