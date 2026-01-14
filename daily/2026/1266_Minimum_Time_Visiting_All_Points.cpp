#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        for (int i = 1; i < n; i++){
            ans += max(abs(points[i][0] - points[i-1][0]), abs(points[i][1] - points[i-1][1]));
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> points = {{1,1},{3,4},{-1,0}};
    // vector<vector<int>> points = {{3,2},{-2,2}};
    Solution S;
    cout << S.minTimeToVisitAllPoints(points) << endl;
    return 0;
}