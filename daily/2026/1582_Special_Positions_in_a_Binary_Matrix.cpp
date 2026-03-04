#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowsum(m, 0);
        vector<int> colsum(n, 0);
        for (int i = 0; i < m; i++){
            int acc = 0;
            for (int j = 0; j < n; j++){
                acc += mat[i][j];
            }
            rowsum[i] = acc;
        }
        for (int j = 0; j < n; j++){
            int acc = 0;
            for (int i = 0; i < m; i++){
                acc += mat[i][j];
            }
            colsum[j] = acc;
        }
        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 1 && rowsum[i] == 1 && colsum[j] == 1) ans++;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> mat = {{1,0,0},{0,0,1},{1,0,0}};
    // vector<vector<int>> mat = {{1,0,0},{0,1,0},{0,0,1}};
    Solution S;
    cout << S.numSpecial(mat) << endl;
    return 0;
}