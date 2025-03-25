#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        auto cut_vertical = [](vector<int>& a, vector<int>& b){return a[0] < b[0];};
        auto cut_horizontal = [](vector<int>& a, vector<int>& b){return a[1] < b[1];};
        int cut = 0;
        int r = rectangles.size();
        int end = 0;
        sort(rectangles.begin(), rectangles.end(), cut_vertical);
        for (int i = 0; i < r; i++){
            if (rectangles[i][0] >= end) cut++;
            if (cut == 3) return true;
            end = max(end, rectangles[i][2]);
        }
        sort(rectangles.begin(), rectangles.end(), cut_horizontal);
        cut = 0;
        end = 0;
        for (int i = 0; i < r; i++){
            if (rectangles[i][1] >= end) cut++;
            if (cut == 3) return true;
            end = max(end, rectangles[i][3]);
        }
        return false;
    }
};

int main(){
    int n = 5;
    vector<vector<int>> rectangles = {{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}};
    // int n = 4;
    // vector<vector<int>> rectangles = {{0,0,1,1},{2,0,3,4},{0,2,2,3},{3,0,4,3}};
    // int n = 4;
    // vector<vector<int>> rectangles = {{0,2,2,4},{1,0,3,2},{2,2,3,4},{3,0,4,2},{3,2,4,4}};
    Solution S;
    cout << S.checkValidCuts(n, rectangles) << endl;
    return 0;
}