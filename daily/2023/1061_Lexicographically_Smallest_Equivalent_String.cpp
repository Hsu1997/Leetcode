#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> m;

    int find(char a){
        int x = a - 'a';
        while(m[x] != x) x = m[x];
        return x;
    }

    void conbine(char a, char b){
        int temp1 = find(a);
        int temp2 = find(b);
        if (temp1 < temp2) m[find(b)] = temp1;
        else m[find(a)] = temp2;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i = 0; i < 26; i++) m.push_back(i);
        for (int i = 0; i < s1.length(); i++) conbine(s1[i], s2[i]);
        for (int i = 0; i < baseStr.length(); i++) baseStr[i] = 'a'+find(baseStr[i]);
        return baseStr;
    }
};

int main(){
    // string s1 = "parker";
    // string s2 = "morris";
    // string baseStr = "parser";
    // string s1 = "hello";
    // string s2 = "world";
    // string baseStr = "hold";
    string s1 = "leetcode";
    string s2 = "programs";
    string baseStr = "sourcecode";
    Solution S;
    cout << S.smallestEquivalentString(s1, s2, baseStr) << endl;
    return 0;
}