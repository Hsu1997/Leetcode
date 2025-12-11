#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> x_largest(n+1, 0);
        vector<int> x_smallest(n+1, n+1);
        vector<int> y_largest(n+1, 0);
        vector<int> y_smallest(n+1, n+1);
        for (auto& building : buildings){
            int x = building[0];
            int y = building[1];
            x_largest[x] = max(x_largest[x], y);
            y_largest[y] = max(y_largest[y], x);
            x_smallest[x] = min(x_smallest[x], y);
            y_smallest[y] = min(y_smallest[y], x);
        }
        int ans = 0;
        for (auto& building : buildings){
            int x = building[0];
            int y = building[1];
            if (x_largest[x] > y && x_smallest[x] < y && y_largest[y] > x && y_smallest[y] < x) ans++;
        }
        return ans;
    }
};

int main(){
    int n = 3;
    vector<vector<int>> buildings = {{1,2},{2,2},{3,2},{2,1},{2,3}};
    // int n = 3;
    // vector<vector<int>> buildings = {{1,1},{1,2},{2,1},{2,2}};
    // int n = 5;
    // vector<vector<int>> buildings = {{1,3},{3,2},{3,3},{3,5},{5,3}};
    Solution S;
    cout << S.countCoveredBuildings(n, buildings) << endl;
    return 0;
}