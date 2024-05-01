#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    int n;
    int m;
    vector<vector<int>> acc;

    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        acc = vector<vector<int>>(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++){
            int temp = 0;
            for (int j = 0; j < m; j++){
                temp += matrix[i][j];
                acc[i][j] = temp;
            }
        }
        for (int j = 0; j < m; j++){
            int temp = 0;
            for (int i = 0; i < n; i++){
                temp += acc[i][j];
                acc[i][j] = temp;
            }
        }
    }
    
    bool in_matrix(int i, int j){
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = acc[row2][col2];
        if (in_matrix(row2, col1-1)) ans -= acc[row2][col1-1];
        if (in_matrix(row1-1, col2)) ans -= acc[row1-1][col2];
        if (in_matrix(row1-1, col1-1)) ans += acc[row1-1][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(){
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    vector<vector<int>> point = {{2, 1, 4, 3}, {1, 1, 2, 2}, {1, 2, 2, 4}};
    NumMatrix *M = new NumMatrix(matrix);
    for (auto i : point){
        cout << M->sumRegion(i[0],i[1],i[2],i[3]) << endl;
    }
    return 0;
}