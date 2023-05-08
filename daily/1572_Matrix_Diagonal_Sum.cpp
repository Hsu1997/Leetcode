#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = 0;
        for (int i = 0; i < n; i++) ans += mat[i][i] + mat[i][n-i-1];
        if (n % 2 == 1) ans -= mat[n/2][n/2];
        return ans;
    }
};

int main(){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    Solution S;
    cout << S.diagonalSum(mat) << endl;
    return 0;
}