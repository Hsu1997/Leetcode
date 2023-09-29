#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    float slope(vector<int> a, vector<int> b){
        if (a[0]-b[0] != 0) return (float)(a[1]-b[1]) / (float)(a[0]-b[0]);
        else return 0;
    }
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        unordered_map<int,int> x_count;
        for (int i = 0; i < points.size(); i++){
            x_count[points[i][0]]++;
            ans = max(ans, x_count[points[i][0]]);
            unordered_map<float,int> count;
            for (int j = 0; j < points.size(); j++){
                if (i != j && points[i][0] != points[j][0]){
                    count[slope(points[i], points[j])]++;
                    // cout << slope(points[i], points[j]) << " : " << count[slope(points[i], points[j])] << endl;
                    ans = max(ans, count[slope(points[i], points[j])]+1);
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    // vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    Solution S;
    cout << S.maxPoints(points) << endl;
    return 0;
}