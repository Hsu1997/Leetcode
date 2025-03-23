#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        int m = properties[0].size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++){
            unordered_set<int> s;
            for (int j = 0; j < m; j++) s.insert(properties[i][j]);
            for (int x = i + 1; x < n; x++){
                unordered_set<int> sub_s;
                for (int l = 0; l < m; l++) sub_s.insert(properties[x][l]); 
                int common_amount = 0;
                for (auto num : sub_s) if (s.find(num) != s.end()) common_amount++;
                if (common_amount >= k){
                    graph[i].push_back(x);
                    graph[x].push_back(i);
                }
            }
        }
        return components(graph);
    }
    int components(vector<vector<int>>& graph){
        int n = graph.size();
        int ans = 0;
        vector<bool> visited(n, false);
        queue<int> que;
        for (int i = 0; i < n; i++){
            if (!visited[i]){
                que.push(i);
                visited[i] = true;
                while(!que.empty()){
                    int curr = que.front();
                    que.pop();
                    for (int neighbor : graph[curr]){
                        if (!visited[neighbor]){
                            visited[neighbor] = true;
                            que.push(neighbor);
                        }
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> properties = {{1,2},{1,1},{3,4},{4,5},{5,6},{7,7}};
    int k = 1;
    // vector<vector<int>> properties = {{1,2,3},{2,3,4},{4,3,5}};
    // int k = 2;
    // vector<vector<int>> properties = {{1,1},{1,1}};
    // int k = 2;
    Solution S;
    cout << S.numberOfComponents(properties, k) << endl;
    return 0;
}