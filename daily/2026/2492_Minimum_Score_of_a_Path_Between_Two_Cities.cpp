#include <iostream>
#include <vector>

using namespace std;

class DisjointSet{
public:
    DisjointSet(int n){
        u = vector<int>(n);
        for (int i = 0; i < n; i++) u[i] = i;
    }
    int find(int i){
        if (u[i] != i) u[i] = find(u[i]);
        return u[i];
    }
    bool combine(int i, int j){
        int x = find(i);
        int y = find(j);
        if (x == y) return false;
        u[y] = x;
        return true;
    }
private:
    vector<int> u;
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet d(n);
        for (auto& road : roads){
            int u = road[0] - 1;
            int v = road[1] - 1;
            d.combine(u, v);
        }
        int ans = INT_MAX;
        for (auto& road : roads){
            int c = road[0] - 1;
            if (d.find(0) == d.find(c)) ans = min(ans, road[2]);
        }
        return ans;
    }
};

int main(){
    int n = 4;
    vector<vector<int>> roads = {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};
    // int n = 4;
    // vector<vector<int>> roads = {{1,2,2},{1,3,4},{3,4,7}};
    Solution S;
    cout << S.minScore(n, roads) << endl;
    return 0;
}