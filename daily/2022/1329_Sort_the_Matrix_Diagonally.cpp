#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> temp;

        if (m == 1 || n == 1) return mat;

        for (int r = 0; r < m; r++){
            temp.clear();
            for (int i = r, j = 0; i < m && j < n; i++, j++) temp.push_back(mat[i][j]);
            sort(temp.begin(), temp.end());
            for (int i = r, j = 0; i < m && j < n; i++, j++) mat[i][j] = temp[j];
        }
        for (int c = 1; c < n; c++){
            temp.clear();
            for (int i = 0, j = c; i < m && j < n; i++, j++) temp.push_back(mat[i][j]);
            sort(temp.begin(), temp.end());
            for (int i = 0, j = c; i < m && j < n; i++, j++) mat[i][j] = temp[i];
        }
        return mat;
    }
};

int main(){
    // vector<vector<int>> mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};
    // vector<vector<int>> mat = {{11,25,66,1,69,7},{23,55,17,45,15,52},{75,31,36,44,58,8},{22,27,33,25,68,4},{84,28,14,11,5,50}};
    // vector<vector<int>> mat = {{75,21,13,24,8},{24,100,40,49,62}};
    vector<vector<int>> mat = {{3,9},
                               {2,4},
                               {1,2},
                               {9,8},
                               {7,3}};

    Solution S;
    vector<vector<int>> ans = S.diagonalSort(mat);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}