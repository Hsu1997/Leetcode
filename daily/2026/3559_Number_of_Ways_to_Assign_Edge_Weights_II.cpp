#include <iostream>
#include <vector>

using namespace std;

class LCA{
public:
    LCA(vector<vector<int>>& edges, int root = 1){
        n = edges.size() + 1;
        m = 32 - __builtin_clz(n);
        d.resize(n + 1);
        e.resize(n + 1);
        t.resize(n + 1, vector<int>(m, 0));
        for (auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(root, 0);
        for (int i = 1; i < m; i++){
            for (int x = 1; x <= n; x++){
                t[x][i] = t[t[x][i-1]][i-1];
            }
        }
    }
    void dfs(int x, int father){
        t[x][0] = father;
        for (int child : e[x]){
            if (child == father) continue;
            d[child] = d[x] + 1;
            dfs(child, x);
        }
    }
    int lca(int x, int y){
        if (d[x] > d[y]) swap(x, y);
        for (int i = m - 1; i >= 0; i--){
            if (d[x] <= d[t[y][i]]) y = t[y][i];
        }
        if (x == y) return x;
        for (int i = m - 1; i >= 0; i--){
            if (t[x][i] != t[y][i]){
                x = t[x][i];
                y = t[y][i];
            }
        }
        return t[x][0];
    }
    int dis(int x, int y) {return d[x] + d[y] - d[lca(x, y)] * 2;}
private:
    int n, m;
    vector<int> d;
    vector<vector<int>> e;
    vector<vector<int>> t;
};

class Solution {
public:
    int powmod(long long base, int pow){
        long long mod = 1e9 + 7;
        long long res = 1;
        while(pow){
            if (pow & 1) res = res * base % mod;
            base = base * base % mod;
            pow /= 2;
        }
        return res;
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        LCA lca(edges);
        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++){
            int x = queries[i][0];
            int y = queries[i][1];
            ans[i] = (x == y)? 0 : powmod(2, lca.dis(x, y) - 1);
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> edges = {{1,2}};
    vector<vector<int>> queries = {{1,1},{1,2}};
    // vector<vector<int>> edges = {{1,2},{1,3},{3,4},{3,5}};
    // vector<vector<int>> queries = {{1,4},{3,4},{2,5}};
    Solution S;
    vector<int> ans = S.assignEdgeWeights(edges, queries);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}