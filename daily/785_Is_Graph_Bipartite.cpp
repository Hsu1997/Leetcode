#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> group;

    bool isBipartite(vector<vector<int>>& graph) {
        group = vector<int>(graph.size(), 0);
        queue<int> que;
        for (int i = 0; i < graph.size(); i++){
            if (group[i] == 0){
                group[i] = 1;
                que.push(i);
                while(!que.empty()){
                    int temp = que.front();
                    que.pop();
                    for (int adj : graph[temp]){
                        if (group[adj] == 0){
                            group[adj] = -group[temp];
                            que.push(adj);
                        }
                        else if (group[adj] == group[temp]) return false;
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    // vector<vector<int>> graph = {{1},{0,3},{3},{1,2}};
    vector<vector<int>> graph = {{3},{2,4},{1},{0,4},{1,3}};
    Solution S;
    cout << S.isBipartite(graph) << endl;
    // for (int i : S.group) cout << i << " ";
    return 0;
}