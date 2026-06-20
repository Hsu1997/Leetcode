#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if (restrictions.size() == 0) return n - 1;
        sort(restrictions.begin(), restrictions.end());
        if (restrictions.back()[0] != n) restrictions.push_back({n, n});
        int r = restrictions.size();
        // for (auto& restriction : restrictions) cout << restriction[0] << " " << restriction[1] << endl;
        vector<int> h(r, INT_MAX);
        int nextLimit = restrictions.back()[1];
        h[r-1] = restrictions.back()[1];
        for (int i = r - 2; i >= 0; i--){
            int d = restrictions[i+1][0] - restrictions[i][0];
            int currLimit = min(restrictions[i][1], nextLimit + d);
            h[i] = currLimit;
            nextLimit = h[i];
        }
        // cout << endl;
        // for (int i = 0; i < r; i++) cout << restrictions[i][0] << " " << h[i] << endl;
        // cout << endl;
        int prePos = 1;
        int preLimit = 0;
        int ans = 0;
        for (int i = 0; i < r; i++){
            int currPos = restrictions[i][0];
            int d =  currPos - prePos;
            // limit by pre, curr, next restriction
            int currLimit = min({preLimit + d, restrictions[i][0], h[i]});
            int hd = abs(currLimit - preLimit);
            // cout << currPos << " " << max(preLimit, currLimit) + (d - hd) / 2 << endl;
            ans = max(ans, max(preLimit, currLimit) + (d - hd) / 2);
            prePos = currPos;
            preLimit = currLimit;
        }
        return ans;
    }
};

int main(){
    int n = 5;
    vector<vector<int>> restrictions = {{2,1},{4,1}};
    // int n = 6;
    // vector<vector<int>> restrictions = {};
    // int n = 10;
    // vector<vector<int>> restrictions = {{5,3},{2,5},{7,4},{10,3}};
    // int n = 10;
    // vector<vector<int>> restrictions = {{8,5},{9,0},{6,2},{4,0},{3,2},{10,0},{5,3},{7,3},{2,5}};
    Solution S;
    cout << S.maxBuilding(n, restrictions) << endl;
    return 0;
}