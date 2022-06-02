#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> tmatrix(matrix[0].size(), vector<int>(matrix.size(), 0));
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                tmatrix[j][i] = matrix[i][j];
            }
        }
        return tmatrix;
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution S;
    vector<vector<int>> tmatrix = S.transpose(matrix);
    for (auto i : tmatrix){
        for (int j : i) cout << j << " ";
        cout << endl;
    }
}