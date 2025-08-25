#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int m, n;
    int query(vector<vector<int>>& mat, int i, int j){
        if (i >= m || j >= n) return 1e9;
        return mat[i][j];
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        vector<int> ans;
        ans.reserve(m * n);
        int round = 0;
        for (int i = 0; i < max(m, n); i++){
            vector<int> temp;
            for (int k = 0; k <= i; k++){
                int q = query(mat, i - k, k);
                if (q != 1e9) temp.push_back(q);
            }
            if (round++ % 2) reverse(temp.begin(), temp.end());
            for (int t : temp) ans.push_back(t);
        }
        for (int j = 1; j < max(m, n); j++){
            vector<int> temp;
            for (int k = 0; k < max(m, n) - j; k++){
                int q = query(mat, max(m, n) - 1 - k, j + k);
                if (q != 1e9) temp.push_back(q);
            }
            if (round++ % 2) reverse(temp.begin(), temp.end());
            for (int t : temp) ans.push_back(t);
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    // vector<vector<int>> mat = {{1,2},{3,4}};
    // vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Solution S;
    vector<int> ans = S.findDiagonalOrder(mat);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}