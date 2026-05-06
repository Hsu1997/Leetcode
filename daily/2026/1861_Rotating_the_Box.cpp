#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        for (int i = 0; i < m; i++){
            int stone = 0;
            for (int j = 0; j < n; j++){
                if (boxGrid[i][j] == '*'){
                    ans[j][m-1-i] = '*';
                    int k = j - 1;
                    while(stone){
                        ans[k--][m-1-i] = '#';
                        stone--;
                    }
                }
                else if (boxGrid[i][j] == '#'){
                    stone++;
                }
                else continue;
            }
            int k = n - 1;
            while(stone){
                ans[k--][m-1-i] = '#';
                stone--;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<char>> boxGrid = {{'#','.','#'}};
    // vector<vector<char>> boxGrid = {{'#','.','*','.'},{'#','#','*','.'}};
    // vector<vector<char>> boxGrid = {{'#','#','*','.','*','.'},{'#','#','#','*','.','.'},{'#','#','#','.','#','.'}};
    Solution S;
    vector<vector<char>> ans = S.rotateTheBox(boxGrid);
    for (auto row : ans){
        for (auto col : row) cout << col << " ";
        cout << endl;
    }
    return 0;
}