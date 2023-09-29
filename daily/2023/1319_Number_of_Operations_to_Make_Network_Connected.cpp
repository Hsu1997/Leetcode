#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;

class group{
public:    
    vector<int> u;
    vector<int> rank;

    group(int n){
        u.resize(n);
        iota(u.begin(), u.end(), 0);
        rank = vector<int>(n,0);
    }

    int find(int i){
        if (u[i] != i) return u[i] = find(u[i]);
        return u[i];
    }

    void union_group(int i, int j){
        int i_h = find(i);
        int j_h = find(j);
        if (i_h == j_h) return;
        if (rank[i_h] < rank[j_h]) u[i_h] = j_h;
        else if (rank[i_h] > rank[j_h]) u[j_h] = i_h;
        else{
            u[j_h] = i_h;
            rank[i_h]++;
        }
    }

    void print_group(){
        for (auto i : u) cout << i << " ";
        cout << endl;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n > connections.size() + 1) return -1;
        group u(n);
        for (auto i : connections){
            u.union_group(i[0],i[1]);
        }
        unordered_set<int> s;
        for (int i = 0; i < n; i++){
            if (!s.count(u.find(i))) s.insert(u.find(i));
        }
        // u.print_group();
        return s.size()-1;
    }
};

int main(){
    int n = 4;
    vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
    // int n = 6;
    // vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    // int n = 6;
    // vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2}};
    Solution S;
    cout << S.makeConnected(n, connections) << endl;
    return 0;
}