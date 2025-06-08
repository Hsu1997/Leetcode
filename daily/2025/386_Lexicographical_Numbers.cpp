#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int i, int limit, vector<int>& ans){
        if (i > limit) return;
        ans.push_back(i);
        for (int d = 0; d < 10; d++){
            dfs(i * 10 + d, limit, ans);
        }
        return;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int curr = 1;
        for (int i = 1; i < 10; i++){
            dfs(i, n, ans);
        }
        return ans;
    }
};

int main(){
    int n = 13;
    // int n = 2;
    Solution S;
    vector<int> ans = S.lexicalOrder(n);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}