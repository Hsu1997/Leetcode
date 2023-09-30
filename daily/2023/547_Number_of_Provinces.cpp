#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class UnionFind {
public:
    vector<int> parent;

    UnionFind(int n){
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int i){
        if (parent[i] != i) return parent[i] = find(parent[i]);
        else return parent[i];
    }

    void combine(int i, int j){
        int a = find(i);
        int b = find(j);
        parent[a] = b;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind u(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (isConnected[i][j]) u.combine(i,j);
            }
        }
        unordered_set<int> s;
        for (int i = 0; i < n; i++) s.insert(u.find(i));
        return s.size();
    }
};

int main(){
    // vector<vector<int>> isConnected = {{1,1,0},{1,1,0,},{0,0,1}};
    vector<vector<int>> isConnected = {{1,0,0},{0,1,0,},{0,0,1}};
    Solution S;
    cout << S.findCircleNum(isConnected) << endl;
    return 0;
}