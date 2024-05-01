#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     bool isToeplitzMatrix(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         for (int k = m-1; k >= 0; k--){
//             int i = k;
//             int j = 0;
//             int con = matrix[i][j];
//             while(i < m && j < n){
//                 if (matrix[i][j] != con) return false;
//                 i++;
//                 j++;
//             }
//         }
//         for (int k = 1; k < n; k++){
//             int i = 0;
//             int j = k;
//             int con = matrix[i][j];
//             while(i < m && j < n){
//                 if (matrix[i][j] != con) return false;
//                 i++;
//                 j++;
//             }
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (i > 0 && j > 0 && matrix[i-1][j-1] != matrix[i][j]) return false;
            }
        }
        return true;
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    // vector<vector<int>> matrix = {{1,2},{2,2}};
    Solution S;
    cout << S.isToeplitzMatrix(matrix) << endl;
    return 0;
}