#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n/2; j++){
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n-1-i; j++){
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
            }
        }
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution S;
    S.rotate(matrix);
    for (auto i : matrix){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}