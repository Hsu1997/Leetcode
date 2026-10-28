#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));
        for (int i = 0; i < m; i++) ans[i][0] = '.';
        for (int j = 0; j < n; j++) ans[m-1][j] = '.';
        return ans;
    }
};

int main(){
    int m = 2;
    int n = 3;
    // int m = 3;
    // int n = 3;
    // int m = 1;
    // int n = 4;
    Solution S;
    vector<string> ans = S.createGrid(m, n);
    for (string s : ans) cout << s << endl;
    cout << endl;
    return 0;
}