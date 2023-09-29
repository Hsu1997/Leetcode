#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    UnionFind(int n){
        for (int i = 0; i < n; i++) parent.push_back(i);
        rank = vector<int>(n, 0);
    }
    int find(int i){
        return (parent[i] == i)? i : parent[i] = find(parent[i]);
    }
    void combine(int i, int j){
        int x = find(i);
        int y = find(j);
        if (x == y) return;
        if (rank[x] < rank[y]) parent[x] = y;
        else if (rank[x] > rank[y]) parent[y] = x;
        else{
            parent[x] = y;
            rank[y]++;
        }
    }
    bool same_group(int i, int j){
        return find(i) == find(j);
    }
    void print_group(){
        for (auto i : parent) cout << find(i) << " ";
        cout << endl;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans = 0;
        UnionFind g1(n+1);
        UnionFind g2(n+1);
        for (auto i : edges){
            if (i[0] == 3){
                if (g1.same_group(i[1],i[2]) && g2.same_group(i[1],i[2])) ans++;
                else{
                    g1.combine(i[1],i[2]);
                    g2.combine(i[1],i[2]);
                }
            }
        }
        // g1.print_group();
        // g2.print_group();
        // cout << "ans = " << ans << endl;
        for (auto i : edges){
            if (i[0] == 1){
                if (g1.same_group(i[1],i[2])) ans++;
                else g1.combine(i[1],i[2]);
            }
            else if (i[0] == 2){
                if (g2.same_group(i[1],i[2])) ans++;
                else g2.combine(i[1],i[2]);
            }
        }
        // g1.print_group();
        // g2.print_group();
        // cout << "ans = " << ans << endl;
        for (int i = 2; i < n+1; i++){
            if (!g1.same_group(1,i)) return -1;
            if (!g2.same_group(1,i)) return -1;
        }
        return ans;
    }
};

int main(){
    // int n = 4;
    // vector<vector<int>> edges = {{3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}};
    int n = 2;
    vector<vector<int>> edges = {{2,1,2}};
    Solution S;
    cout << S.maxNumEdgesToRemove(n, edges) << endl;
    return 0;
}