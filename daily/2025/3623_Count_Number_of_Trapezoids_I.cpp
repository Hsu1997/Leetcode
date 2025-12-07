#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        int mod = 1e9 + 7;
        unordered_map<int,long> cnt;
        for (auto& p : points) cnt[p[1]]++;
        long ans = 0;
        long acc = 0;
        long total = 0;
        for (auto& [y, c] : cnt){
            long curr = (c * (c - 1) / 2) % mod;
            ans = (ans + (acc * curr)) % mod;
            acc = (acc + curr) % mod;
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> points = {{1,0},{2,0},{3,0},{2,2},{3,2}};
    // vector<vector<int>> points = {{0,0},{1,0},{0,1},{2,1}};
    // vector<vector<int>> points = {{87,-39},{12,-94},{-30,-11},{-76,-11}};
    Solution S;
    cout << S.countTrapezoids(points) << endl;
    return 0;
}