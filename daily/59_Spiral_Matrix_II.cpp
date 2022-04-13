#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        // -> down <- up
        int x_shift[] = {0,1,0,-1};
        int y_shift[] = {1,0,-1,0};
        int size = n;
        int dir = 0;
        int times = 1;
        int x = 0;
        int y = -1;
        int now = 1;
        while(size > 0){
            while(times < 2){
                for (int i = 0; i < size; i++){
                    x += x_shift[dir];
                    y += y_shift[dir];
                    ans[x][y] = now;
                    // cout << "(" << x << "," << y << ") = " << now << endl; 
                    now++;
                }
                times += 1;
                dir = (dir + 1) % 4;
            }
            times = 0;
            size--;
        }
        return ans;
    }
};

int main(){
    int n = 9;
    Solution S;
    vector<vector<int>> ans = S.generateMatrix(n);
    for (auto i : ans){
        for (auto j : i){
            cout << setw(2) << j << " ";
        }
        cout << endl;
    }
    return 0;
}