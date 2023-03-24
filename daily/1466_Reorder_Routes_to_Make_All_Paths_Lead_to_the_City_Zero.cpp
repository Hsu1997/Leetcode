#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n,false);
        int ans = 0;
        vector<vector<int>> edge(n);
        vector<vector<int>> reverse_edge(n);
        for (auto i : connections){
            edge[i[0]].push_back(i[1]);
            reverse_edge[i[1]].push_back(i[0]);
        }
        queue<int> que;
        visited[0] = true;
        que.push(0);
        while(!que.empty()){
            int temp = que.front();
            que.pop();
            for (auto i : reverse_edge[temp]){
                if (!visited[i]){
                    visited[i] = true;
                    que.push(i);
                }
            }
            for (auto i : edge[temp]){
                if (!visited[i]){
                    visited[i] = true;
                    que.push(i);
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(){
    int n = 6;
    vector<vector<int>> connections = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    // int n = 5;
    // vector<vector<int>> connections = {{1,0},{1,2},{3,2},{3,4}};
    // int n = 3;
    // vector<vector<int>> connections = {{1,0},{2,0}};
    Solution S;
    cout << S.minReorder(n, connections) << endl;
    return 0;
}