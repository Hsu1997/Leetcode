#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    int ans = 0;
    vector<int> u;

    int find(int node){
        if (u[node] != node) return u[node] = find(u[node]);
        else return u[node];
    }

    void combine(int a, int b){
        u[find(a)] = find(b);
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        u = vector<int>(n);
        iota(u.begin(), u.end(), 0);
        map<int, vector<int>> m;
        for (int i = 0; i < n; i++){
            m[vals[i]].push_back(i);
        }
        vector<vector<int>> neighbors(n);
        for (auto i : edges){
            neighbors[i[0]].push_back(i[1]);
            neighbors[i[1]].push_back(i[0]);
        }

        for (auto& [val, nodes] : m){
            for (int node : nodes){
                for (int neighbor : neighbors[node]){
                    if (vals[neighbor] <= val) combine(node, neighbor);
                }
            }
            unordered_map<int,int> count;
            for (int node : nodes) count[find(node)]++;
            for (auto& [group, times] : count) ans += times * (times+1) / 2;
        }
        return ans;
    }
};

int main(){
    vector<int> vals = {1,3,2,1,3};
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{2,4}};
    // vector<int> vals = {1,1,2,2,3};
    // vector<vector<int>> edges = {{0,1},{1,2},{2,3},{2,4}};
    // vector<int> vals = {1};
    // vector<vector<int>> edges = {};
    Solution S;
    cout << S.numberOfGoodPaths(vals, edges) << endl;
    return 0;
}