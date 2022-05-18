#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> adj;

    vector<int> disc;
    vector<int> low;
    vector<int> parent;
    int time;
    vector<vector<int>> critical;

    void subproblem(int start){
        disc[start] = low[start] = ++time;

        for (auto i : adj[start]){
            // Not visited yet
            if (disc[i] == 0){
                parent[i] = start;
                subproblem(i);

                low[start] = min(low[start], low[i]);

                if (low[i] > disc[start]) critical.push_back({start, i});
            }
            else if (i != parent[start]) low[start] = min(low[start], disc[i]);
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        for (auto i : connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        disc = vector<int>(n, 0);
        low = vector<int>(n, 0);
        parent = vector<int>(n, -1);
        time = 0;

        subproblem(0);

        return critical;
    }
};

int main(){
    int n = 4;
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    // vector<vector<int>> connections = {{0,1}};

    Solution S;

    for (auto i : S.criticalConnections(n, connections)) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}