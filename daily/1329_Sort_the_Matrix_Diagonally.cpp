#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        if (m == 1 || n == 1) return mat;

        for (int k = m - 1; k >= 0; k--){
            vector<int> temp;
            int i = k;
            int j = 0;
            int c = 0;
            while(i < m && j < n){
                temp.push_back(mat[i][j]);
                i++,j++,c++;
            }
            sort(temp.begin(), temp.end());

            // for (auto q : temp) cout << q << " ";
            // cout << endl;

            i = k;
            j = 0;
            for (int l = 0; l < c; l++){
                mat[i][j] = temp[l];
                i++,j++;
            }
        }
        
        for (int k = 1; k < n; k++){
            vector<int> temp;
            int i = 0;
            int j = k;
            int c = 0;
            while(i < m && j < n){
                temp.push_back(mat[i][j]);
                i++,j++,c++;
            }
            sort(temp.begin(), temp.end());

            // for (auto q : temp) cout << q << " ";
            // cout << endl;
            
            i = 0;
            j = k;
            for (int l = 0; l < c; l++){
                mat[i][j] = temp[l];
                i++,j++;
            }
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