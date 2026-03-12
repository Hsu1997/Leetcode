#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class UnionFind{
public:
    UnionFind(int _n){
        n = _n;
        u = vector<int>(n);
        s = vector<int>(n, 1);
        for (int i = 0; i < n; i++){
            u[i] = i;
        }
    }
    int find(int i){
        return (u[i] == i)? i : u[i] = find(u[i]);
    }
    bool combine(int i, int j){
        int a = find(i);
        int b = find(j);
        if (a == b) return 0;
        if (s[a] < s[b]){
            s[b] += s[a];
            u[a] = b;
        }
        else{
            s[a] += s[b];
            u[b] = a;
        }
        return 1;
    }
    int group(){
        unordered_set<int> g;
        for (int i = 0; i < n; i++) g.insert(find(i));
        return g.size();
    }
private:
    int n;
    vector<int> u;
    vector<int> s;
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        UnionFind u(n);
        int ans = INT_MAX;
        int connect = 1;
        auto cmp = [&](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (auto e : edges){
            if (e[3] == 1){
                ans = min(ans, e[2]);
                if (!u.combine(e[0], e[1])) return -1;
                connect++;
            }
            else{
                pq.push(e);
            }
        }
        while(!pq.empty()){
            if (connect == n) return ans;
            auto curr = pq.top();
            pq.pop();
            if (u.combine(curr[0], curr[1])){
                if (connect + k >= n){
                    ans = min(ans, curr[2] * 2);
                }
                else ans = min(ans, curr[2]);
                connect++;
            }
            else{
                continue;
            }
        }
        return (connect == n)? ans : -1;
    }
};

int main(){
    int n = 3;
    vector<vector<int>> edges = {{0,1,2,1},{1,2,3,0}};
    int k = 1;
    // int n = 3;
    // vector<vector<int>> edges = {{0,1,4,0},{1,2,3,0},{0,2,1,0}};
    // int k = 2;
    // int n = 3;
    // vector<vector<int>> edges = {{0,1,1,1},{1,2,1,1},{2,0,1,1}};
    // int k = 0;
    Solution S;
    cout << S.maxStability(n, edges, k) << endl;
    return 0;
}