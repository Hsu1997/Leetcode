#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

class UnionFind {
public:
    UnionFind(int n){
        parents = vector<int>(n);
        iota(parents.begin(), parents.end(), 0);
        rank = vector<int>(n, 0);
    }

    int find(int i){
        if (parents[i] == i) return i;
        return parents[i] = find(parents[i]);
    }

    void union_set(int x, int y){
        int i = find(x);
        int j = find(y);
        if (i == j) return;
        if (rank[i] < rank[j]) parents[i] = j;
        else if (rank[i] > rank[j]) parents[j] = i;
        else{
            parents[j] = i;
            rank[i]++;
        }
    }

    void print_all(){
        for (auto i : parents) cout << i << " ";
        cout << endl;
    }

private:
    vector<int> parents;
    vector<int> rank;
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        UnionFind u(n);
        for (auto i : edges){
            u.union_set(i[0], i[1]);
        }
        // u.print_all();
        unordered_map<int,long> m;
        for (int i = 0; i < n; i++){
            m[u.find(i)]++;
        }
        for (auto i : m){
            // cout << i.first << " : " << i.second << endl;
            ans += ((long long)n - i.second) * i.second;
        }
        return ans/2;
    }
};

int main(){
    // int n = 3;
    // vector<vector<int>> edges = {{0,1},{0,2},{1,2}};
    // int n = 7;
    // vector<vector<int>> edges = {{0,2},{0,5},{2,4},{1,6},{5,4}};
    int n = 20;
    vector<vector<int>> edges = {{0,1},{0,2},{3,0},{4,0},{0,5},{6,0},{0,7},{0,8},{9,0},{10,0},{0,11},{0,12},{0,13},{0,14},{0,15},{0,16},{0,17},{18,0},{0,19},{2,1},{3,1},{4,1},{1,5},{1,6},{1,7},{8,1},{9,1},{1,10},{1,11},{12,1},{13,1},{14,1},{15,1},{16,1},{17,1},{1,18},{19,1},{2,3},{4,2},{2,5},{2,6},{2,7},{2,8},{2,9},{2,10},{2,11},{12,2},{13,2},{14,2},{15,2},{16,2},{17,2},{2,18},{2,19},{3,4},{3,5},{3,6},{7,3},{8,3},{3,9},{3,10},{3,11},{3,12},{13,3},{14,3},{15,3},{16,3},{17,3},{3,18},{3,19},{5,4},{4,6},{7,4},{8,4},{4,9},{10,4},{4,11},{4,12},{4,13},{14,4},{4,15},{4,16},{4,17},{18,4},{19,4},{5,6},{7,5},{8,5},{9,5},{5,10},{5,11},{12,5},{5,13},{5,14},{15,5},{16,5},{17,5},{5,18},{19,5},{7,6},{6,8},{6,9},{10,6},{11,6},{6,12},{13,6},{6,14},{15,6},{6,16},{17,6},{18,6},{19,6},{7,8},{9,7},{10,7},{11,7},{7,12},{7,13},{14,7},{15,7},{7,16},{7,17},{18,7},{19,7},{8,9},{10,8},{11,8},{8,12},{8,13},{8,14},{15,8},{8,16},{17,8},{18,8},{8,19},{9,10},{9,11},{12,9},{9,13},{14,9},{15,9},{9,16},{9,17},{9,18},{9,19},{10,11},{12,10},{13,10},{14,10},{10,15},{16,10},{17,10},{10,18},{19,10},{12,11},{13,11},{11,14},{15,11},{11,16},{11,17},{18,11},{11,19},{12,13},{12,14},{12,15},{12,16},{12,17},{18,12},{12,19},{14,13},{15,13},{16,13},{17,13},{13,18},{13,19},{15,14},{14,16},{14,17},{14,18},{14,19},{15,16},{17,15},{15,18},{15,19},{16,17},{16,18},{16,19},{18,17},{19,17},{18,19}};
    Solution S;
    cout << S.countPairs(n, edges) << endl;
    return 0;
}