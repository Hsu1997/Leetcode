#include <iostream>
#include <vector>
#include <string>

using namespace std;

class UnionFind{
public:
    vector<int> group;
    vector<int> rank;

    UnionFind(int size){
        group = vector<int>(size, 0);
        rank = vector<int>(size, 0);
        for (int i = 0; i < size; i++) group[i] = i;
    }

    int find(int node){
        if (node != group[node]){
            group[node] = find(group[node]);
        }
        return group[node];
    }

    bool join(int node1, int node2){
        int group1 = find(node1);
        int group2 = find(node2);
        if (group1 == group2) return false;
        if (rank[group1] < rank[group2]) group[group1] = group2;
        else if (rank[group1] > rank[group2]) group[group2] = group1;
        else{
            group[group2] = group1;
            rank[group1]++;
        }
        return true;
    }
};


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind set(s.size());
        for (auto i : pairs){
            set.join(i[0], i[1]);
        }
        for (int i = 0; i < s.size(); i++) set.find(i);

        // for (auto i : set.group) cout << i << " ";
        // cout << endl;

        vector<vector<char>> record_s(s.size(), vector<char>());
        vector<vector<int>> record_p(s.size(), vector<int>());
        for (int i = 0; i < s.size(); i++){
            record_s[set.find(i)].push_back(s[i]);
            record_p[set.find(i)].push_back(i);
        }
        for (int i = 0; i < s.size(); i++){
            sort(record_s[i].begin(), record_s[i].end());
            sort(record_p[i].begin(), record_p[i].end());
        }
        for (int i = 0; i < s.size(); i++){
            for (int j = 0; j < record_s[i].size(); j++){
                s[record_p[i][j]] = record_s[i][j];
            }
        }
        return s;
    }
};

int main(){
    // string s = "dcab";
    // vector<vector<int>> pairs = {{0,3},{1,2},{0,2}};
    string s = "pwqlmqm";
    vector<vector<int>> pairs = {{5,3},{3,0},{5,1},{1,1},{1,5},{3,0},{0,2}};
    Solution S;
    cout << S.smallestStringWithSwaps(s, pairs) << endl;
    return 0;
}