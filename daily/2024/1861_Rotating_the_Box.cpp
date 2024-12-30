#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotate(vector<vector<char>>& g){
        int m = g.size();
        int n = g[0].size();
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                // cout << "(" << i << "," << j << ") => (" << m-1-j << "," << i << ")"  << endl;
                ans[i][j] = g[m-1-j][i];
            }
        }
        return ans;
    }
    
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        for (int i = 0; i < m; i++){
            int stone = 0;
            for (int j = 0; j < n; j++){
                if (boxGrid[i][j] == '#'){
                    stone++;
                    boxGrid[i][j] = '.';
                }
                else if (boxGrid[i][j] == '*'){
                    int pos = j-1;
                    while(stone > 0){
                        boxGrid[i][pos] = '#';
                        pos--, stone--;
                    }
                }
                else continue;
            }
            int pos = n-1;
            while(stone > 0) boxGrid[i][pos] = '#', stone--, pos--; 
        }
        return rotate(boxGrid);
    }
};

int main(){
    // vector<vector<char>> boxGrid = {{'#','.','#'}};
    // vector<vector<char>> boxGrid = {{'#','.','*','.'},{'#','#','*','.'}};
    vector<vector<char>> boxGrid = {{'#','#','*','.','*','.'},{'#','#','#','*','.','.'},{'#','#','#','.','#','.'}};
    Solution S;
    vector<vector<char>> ans = S.rotateTheBox(boxGrid);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}