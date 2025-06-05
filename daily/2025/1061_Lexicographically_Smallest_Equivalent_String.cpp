#include <iostream>
#include <vector>
#include <string>

using namespace std;

class UnionFind{
public:
    vector<int> group;
    UnionFind(int n){
        group = vector<int>(n, 0);
        for (int i = 0; i < n; i++) group[i] = i;
    }
    int find(int i){
        return (group[i] == i)? i : group[i] = find(group[i]);
    }
    void combine(int i, int j){
        int x = find(i);
        int y = find(j);
        if (x > y) swap(x, y);
        group[y] = x;
        return;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind U(26);
        int n = s1.length();
        for (int i = 0; i < n; i++){
            int c1 = s1[i] - 'a';
            int c2 = s2[i] - 'a';
            U.combine(c1, c2);
        }
        int m = baseStr.length();
        string ans(m, ' ');
        for (int i = 0; i < m; i++){
            ans[i] = 'a' + U.find(baseStr[i] - 'a');
        }
        return ans;
    }
};

int main(){
    string s1 = "parker";
    string s2 = "morris";
    string baseStr = "parser";
    // string s1 = "hello";
    // string s2 = "world";
    // string baseStr = "hold";
    // string s1 = "leetcode";
    // string s2 = "programs";
    // string baseStr = "sourcecode";
    Solution S;
    cout << S.smallestEquivalentString(s1, s2, baseStr) << endl;
    return 0;
}