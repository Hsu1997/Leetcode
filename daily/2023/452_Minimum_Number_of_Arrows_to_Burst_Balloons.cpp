#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        // for (auto i : points) cout << i[0] << " " << i[1] << endl;
        int ans = 0;
        int now = -1;
        while(now+1 < points.size()){
            now++, ans++;
            // cout << "round " << ans << " : ";
            int start = points[now][0];
            int end = points[now][1];
            // cout << "start = " << start << ", end = " << end;
            int smallest = end;
            int smallest_index = now;
            while(now+1 < points.size() && points[now+1][0] <= end){
                now++;
                if (smallest >= points[now][1]){
                    smallest = points[now][1];
                    smallest_index = now;
                }
            }
            // cout << ", smallest = " << smallest << ", index = " << smallest_index << endl;
            now = smallest_index;
            if (now == points.size()-1) return ans;
            while(now+1 < points.size() && points[now+1][0] <= smallest) now++;
        }   
        return ans;
    }
};

int main(){
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    // vector<vector<int>> points = {{1,2},{3,4},{5,6},{7,8}};
    // vector<vector<int>> points = {{1,2},{2,3},{3,4},{4,5}};
    // vector<vector<int>> points = {{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
    Solution S;
    cout << S.findMinArrowShots(points) << endl;
    return 0;
}