#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> img1_boundary;

    int dot(int _i, int _j, vector<vector<int>>& img){
        int ans = 0;
        for (int i = _i; i < _i+n; i++){
            for (int j = _j; j < _j+n; j++){
                ans += img1_boundary[i][j] * img[i-_i][j-_j];
            }
        }
        return ans;
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        if (img1.size() == 1) return img1[0][0] * img2[0][0];

        n = img1.size();
        int ans = 0;
        img1_boundary = vector<vector<int>>(3*n-2, vector<int>(3*n-2, 0));

        for (int i = n-1; i < 2*n-1; i++){
            for (int j = n-1; j < 2*n-1; j++){
                img1_boundary[i][j] = img1[i-n+1][j-n+1];
            }
        }

        // for (auto i : img1_boundary){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }

        for (int i = 0; i < 2*n-1; i++){
            for (int j = 0; j < 2*n-1; j++){
                ans = max(ans, dot(i, j, img2));
            }
        }

        return ans;
    }
};

int main(){
    vector<vector<int>> img1 = {{1,1,0},{0,1,0},{0,1,0}};
    vector<vector<int>> img2 = {{0,0,0},{0,1,1},{0,0,1}};
    // vector<vector<int>> img1 = {{1}};
    // vector<vector<int>> img2 = {{1}};
    // vector<vector<int>> img1 = {{0}};
    // vector<vector<int>> img2 = {{0}};
    // vector<vector<int>> img1 = {{0,0,0,0,1},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    // vector<vector<int>> img2 = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{1,0,0,0,0}};

    Solution S;
    cout << S.largestOverlap(img1, img2) << endl;
    return 0;
}