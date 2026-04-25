#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<long long>& p, int d, int k, long long side, int n){
        for (int start = 0; start < n; start++){
            long long curr = p[start];
            long long limit = 4LL * side + curr - d;
            int cnt = 1;
            while(cnt < k){
                long long next = curr + d;
                auto ptr = lower_bound(p.begin(), p.end(), next);
                if (ptr == p.end() || *ptr > limit) break;
                cnt++;
                curr = *ptr;
            }
            if (cnt >= k) return true;
        }
        return false;
    }
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> p;
        for (auto& point : points){
            long long x = point[0];
            long long y = point[1];
            if (x == 0) p.push_back(y);
            else if (y == side) p.push_back(1LL * side + x);
            else if (x == side) p.push_back(3LL * side - y);
            else p.push_back(4LL * side - x);
        }
        sort(p.begin(), p.end());
        int left = 1;
        int right = side;
        while(left < right){
            int mid = left + (right - left + 1) / 2;
            if (check(p, mid, k, side, n)) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};

int main(){
    int side = 2;
    vector<vector<int>> points = {{0,2},{2,0},{2,2},{0,0}};
    int k = 4;
    // int side = 2;
    // vector<vector<int>> points = {{0,0},{1,2},{2,0},{2,2},{2,1}};
    // int k = 4;
    // int side = 2;
    // vector<vector<int>> points = {{0,0},{0,1},{0,2},{1,2},{2,0},{2,2},{2,1}};
    // int k = 5;
    Solution S;
    cout << S.maxDistance(side, points, k) << endl;
    return 0;
}