#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int x = 0;
        int y = n-1;
        while(x < m && y >= 0){
            if (matrix[x][y] == target) return true;
            if (matrix[x][y] > target) y--;
            else x++;
        }
        return false;
    }
};

int main(){
    // vector<vector<int>> matrix = {{1,4},{2,5}};
    // int target = 5;
    vector<vector<int>> matrix = {{5,6}};
    int target = 6;
    // vector<vector<int>> matrix = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    // int target = 15;
    // vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    // int target = 5;
    // vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    // int target = 20;
    // vector<vector<int>> matrix = {{48,65,70,113,133,163,170,216,298,389},
    //                               {89,169,215,222,250,348,379,426,469,554},
    //                               {178,202,253,294,367,392,428,434,499,651},
    //                               {257,276,284,332,380,470,516,561,657,698},
    //                               {275,331,391,432,500,595,602,673,758,783},
    //                               {357,365,412,450,556,642,690,752,801,887},
    //                               {359,451,534,609,654,662,693,766,803,964},
    //                               {390,484,614,669,684,711,767,804,857,1055},
    //                               {400,515,683,732,812,834,880,930,1012,1130},
    //                               {480,538,695,751,864,939,966,1027,1089,1224}};
    // int target = 642;
    Solution S;
    cout << S.searchMatrix(matrix, target) << endl;
    return 0;
}