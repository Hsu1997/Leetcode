#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> m;
        for (auto& reserved : reservedSeats){
            int r = reserved[0];
            int c = reserved[1] - 1;
            m[r] |= (1 << c);
        }
        int ans = 0;
        for (auto& [r, c] : m){
            if ((c & (15 << 1)) == 0) ans++;
            if ((c & (15 << 5)) == 0) ans++;
            if ((c & (15 << 1)) && (c & (15 << 5)) && ((c & (15 << 3)) == 0)) ans++;
        }
        ans += (n - m.size()) * 2;
        return ans;
    }
};

int main(){
    int n = 3;
    vector<vector<int>> reservedSeats = {{1,2},{1,3},{1,8},{2, 6},{3,1},{3,10}};
    // int n = 2;
    // vector<vector<int>> reservedSeats = {{2,1},{1,8},{2,6}};
    // int n = 4;
    // vector<vector<int>> reservedSeats = {{4,3},{1,4},{4,6},{1,7}};
    Solution S;
    cout << S.maxNumberOfFamilies(n, reservedSeats) << endl;
    return 0;
}