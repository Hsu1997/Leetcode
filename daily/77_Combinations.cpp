#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;
    int k;
    vector<vector<int>> ans;

    void dfs(vector<int> &temp, int start, int pos){
        if (pos == k){
            // for (auto i : temp) cout << i << " ";
            // cout << endl;
            ans.push_back(temp);
        }
        else{
            for (int i = start; i <= n; i++){
                temp[pos] = i;
                dfs(temp, i+1, pos+1);
            }
        }

    }
    vector<vector<int>> combine(int _n, int _k) {
        n = _n;
        k = _k;
        vector<int> temp(k);
        dfs(temp, 1, 0);
        return ans;
    }
};

int main(){
    int n = 4;
    int k = 2;
    Solution S;
    vector<vector<int>> ans = S.combine(n, k);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}