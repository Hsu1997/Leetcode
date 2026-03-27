#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k %= n;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] != mat[i][(j + k) % n]) return false;
            }
        }
        return true;
    }
};

int main(){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 4;
    // vector<vector<int>> mat = {{1,2,1,2},{5,5,5,5},{6,3,6,3}};
    // int k = 2;
    // vector<vector<int>> mat = {{2,2},{2,2}};
    // int k = 3;
    Solution S;
    cout << S.areSimilar(mat, k) << endl;
    return 0;
}