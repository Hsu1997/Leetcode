#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        };
        sort(points.begin(), points.end(), cmp);
        int ans = 0;
        int n = points.size();
        for (int i = 0; i < n; i++){
            int hightest = -1;
            for (int j = i + 1; j < n; j++){
                if (points[j][1] > points[i][1]) continue;
                if (points[j][1] > hightest){
                    hightest = points[j][1];
                    ans++;
                }
                else continue;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    // vector<vector<int>> points = {{6,2},{4,4},{2,6}};
    // vector<vector<int>> points = {{3,1},{1,3},{1,1}};
    // vector<vector<int>> points = {{0,0},{0,3}};
    Solution S;
    cout << S.numberOfPairs(points) << endl;
    return 0;
}