#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        vector<bool> visited(m, 0);
        for (int j = 0; j < n; j++){
            for (int i = 0; i < m; i++){
                if (!visited[i] && mat[i][j] == 0){
                    ans.push_back(i);
                    visited[i] = true;
                }
                if (ans.size() == k) return ans;
            }
        }
        for (int i = 0; i < m; i++) if (!visited[i] && ans.size() < k) ans.push_back(i);
        return ans;
    }
};

int main(){
    // vector<vector<int>> mat = {{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
    // int k = 3;
    // vector<vector<int>> mat = {{1,0,0,0},{1,1,1,1},{1,0,0,0},{1,0,0,0}};
    // int k = 2;
    vector<vector<int>> mat = {{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1}};
    int k = 3;
    Solution S;
    vector<int> ans = S.kWeakestRows(mat, k);
    for (auto& i : ans) cout << i << " ";
    cout << endl;
    return 0;
}