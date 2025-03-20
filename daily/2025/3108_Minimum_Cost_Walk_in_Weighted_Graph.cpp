#include <iostream>
#include <vector>

using namespace std;

class UnionFind{
public:
    vector<int> parents;
    vector<int> ranks;
    vector<int> cost;
    UnionFind(int n){
        parents = vector<int>(n);
        for (int i = 0; i < n; i++) parents[i] = i;
        ranks = vector<int>(n, 1);
        cost = vector<int>(n, (1 << 30) - 1);
    }
    int find(int i){
        if (parents[i] != i) return parents[i] = find(parents[i]);
        else return i;
    }
    bool combine(int i, int j, int w){
        int rootA = find(i);
        int rootB = find(j);
        cost[rootA] &= w;
        cost[rootB] &= w;
        if (rootA == rootB) return false;
        if (ranks[rootA] < ranks[rootB]) swap(rootA, rootB);
        parents[rootB] = rootA;
        cost[rootA] &= cost[rootB];
        if (ranks[rootA] == ranks[rootB]) ranks[rootA]++;
        return true;
    }
    int query_cost(int i, int j){
        if (find(i) != find(j)) return -1;
        return cost[find(i)];
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        UnionFind G(n);
        for (auto edge : edges){
            int n1 = edge[0];
            int n2 = edge[1];
            int weight = edge[2];
            G.combine(n1, n2, weight);
        }
        int q = query.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++) ans[i] = G.query_cost(query[i][0], query[i][1]);
        return ans;
    }
};

int main(){
    int n = 5;
    vector<vector<int>> edges = {{0,1,7},{1,3,7},{1,2,1}};
    vector<vector<int>> query = {{0,3},{3,4}};
    // int n = 3;
    // vector<vector<int>> edges = {{0,2,7},{0,1,15},{1,2,6},{1,2,1}};
    // vector<vector<int>> query = {{1,2}};
    // int n = 7;
    // vector<vector<int>> edges = {{3,0,2},{5,4,12},{6,3,7},{4,2,2},{6,2,2}};
    // vector<vector<int>> query = {{6,0}};
    Solution S;
    vector<int> ans = S.minimumCost(n, edges, query);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}