#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n / 2; j++){
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
        return;
    }
};

// 1 2 3
// 4 5 6
// 7 8 9
// [reflection]
// 1 4 7
// 2 5 8
// 3 6 9
// [rotation vertical]
// 7 4 1
// 8 5 2
// 9 6 3

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    // vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution S;
    S.rotate(matrix);
    for (auto& row : matrix){
        for (auto& col : row){
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}