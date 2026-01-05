#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct PairHash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

class Solution {
public:
    int gcd(int x, int y){
        if (y == 0) return x;
        return gcd(y, x % y);
    }

    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<pair<int,int>, vector<float>, PairHash> slopeToIntercept;
        unordered_map<pair<int,int>, vector<pair<int,int>>, PairHash> midpointToSlope;
        for (int i = 0; i < n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dx = x2 - x1;
                int dy = y2 - y1;
                if (dx < 0){
                    dx = -dx;
                    dy = -dy;
                }
                float intercept;
                if (dx == 0){
                    dy = 1;
                    intercept = x1;
                }
                else if (dy == 0){
                    dx = 1;
                    intercept = y1;
                }
                else{
                    int g = gcd(abs(dx), abs(dy));
                    dx /= g;
                    dy /= g;
                    // intercept = (float)(y1 * dx - x1 * dy) / dx;
                    intercept = (float)(y1 * dx - x1 * dy);
                }
                slopeToIntercept[{dx,dy}].push_back(intercept);
                midpointToSlope[{x1 + x2, y1 + y2}].push_back({dx, dy});
            }
        }
        int ans = 0;
        for (auto& [_, intercept] : slopeToIntercept){
            unordered_map<float, int> cnt1;
            for (float i : intercept) cnt1[i]++;
            int acc = 0;
            for (auto& [_, c] : cnt1){
                ans += acc * c;
                acc += c;
            }
        }
        for (auto& [_, slope] : midpointToSlope){
            unordered_map<pair<int,int>, int, PairHash> cnt2;
            for (pair<int,int> s : slope) cnt2[s]++;
            int acc = 0;
            for (auto& [_, c]: cnt2){
                ans -= acc * c;
                acc += c;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> points = {{-3,2},{3,0},{2,3},{3,2},{2,-3}};
    // vector<vector<int>> points = {{0,0},{1,0},{0,1},{2,1}};
    // vector<vector<int>> points = {{67,14},{45,-86},{-98,14},{73,-86},{22,47},{73,71},{-32,14},{-42,-16},{33,-69},{-42,47},{73,92},{58,-56},{-32,-20},{-42,8},{71,-86}};
    Solution S;
    cout << S.countTrapezoids(points) << endl;
    return 0;
}