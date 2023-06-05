#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if (coordinates[0][0] == coordinates[1][0]){
            for (int i = 0; i < n-1; i++) if (coordinates[i][0] != coordinates[i+1][0]) return false;
            return true;
        }
        else{
            double slope = (double)(coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
            // cout << "slope = " << slope << endl;
            for (int i = 0; i < n-1; i++){
                if (coordinates[i][0] == coordinates[i+1][0]) return false;
                if ((double)(coordinates[i+1][1] - coordinates[i][1]) / (coordinates[i+1][0] - coordinates[i][0]) != slope) return false;
                // cout << (double)(coordinates[i+1][1] - coordinates[i][1]) / (coordinates[i+1][0] - coordinates[i][0]) << endl;
            }
            return true;
        }
        return false;
    }
};

int main(){
    // vector<vector<int>> coordinates = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    // vector<vector<int>> coordinates = {{0,0},{0,5},{5,5},{5,0}};
    vector<vector<int>> coordinates = {{-4,-3},{1,0},{3,-1},{0,-1},{-5,2}};
    Solution S;
    cout << S.checkStraightLine(coordinates) << endl;
    return 0;
}