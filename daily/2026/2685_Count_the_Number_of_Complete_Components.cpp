#include <iostream>
#include <vector>

using namespace std;

class DisjointSet{
public:
    DisjointSet(int _n){
        n = _n;
        d = vector<int>(n);
        for (int i = 0; i < n; i++) d[i] = i;
        nodecnt = vector<int>(n, 1);
        edgecnt = vector<int>(n, 0);
    }
    int find(int i){
        if (d[i] != i) d[i] = find(d[i]);
        return d[i];
    }
    void combine(int i, int j){
        int x = find(i);
        int y = find(j);
        if (x == y) edgecnt[x]++;
        else{
            d[y] = d[x];
            nodecnt[x] += nodecnt[y];
            edgecnt[x] += edgecnt[y] + 1;
        }
        return;
    }
    int completeComponent(){
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (d[i] == i){
                if (nodecnt[i] * (nodecnt[i] - 1) / 2 == edgecnt[i]) ans++;
            }
        }
        return ans;
    }
private:
    int n;
    vector<int> d;
    vector<int> nodecnt;
    vector<int> edgecnt;
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet s(n);
        for (auto& edge : edges){
            s.combine(edge[0], edge[1]);
        }
        return s.completeComponent();
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