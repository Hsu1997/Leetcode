#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> u;
    int find(int i){
        while(u[i] != i){
            u[i] = u[u[i]];
            i = u[i];
        }
        return i;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        u = vector<int>(n);
        for (int i = 0; i < n; i++) u[i] = i;
        for (auto i : edges) u[find(u[i[0]])] = find(u[i[1]]);

        // for (auto i : u) cout << i << " ";
        // cout << endl;
        
        return find(u[source]) == find(u[destination]);
    }
};

int main(){
    // int n = 3;
    // vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    // int source = 0;
    // int destination = 2;
    // int n = 6;
    // vector<vector<int>> edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    // int source = 0;
    // int destination = 5;
    int n = 10;
    vector<vector<int>> edges = {{0,7},{0,8},{6,1},{2,0},{0,4},{5,8},{4,7},{1,3},{3,5},{6,5}};
    int source = 7;
    int destination = 5;

    Solution S;
    cout << S.validPath(n, edges, source, destination) << endl;
    return 0;
}