#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculate_distance(vector<int> a, vector<int> b){
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<bool> choose(points.size(), false);
        vector<int> distance(points.size(), numeric_limits<int>::max());
        int last_change_point = 0;
        int temp_min_point;
        int total_distance = 0;

        choose[0] = true;
        for (int times = 1; times < points.size(); times++){
            int temp_distance = numeric_limits<int>::max();
            for (int i = 1; i < points.size(); i++){
                if (choose[i] == false){
                    distance[i] = min(distance[i], calculate_distance(points[last_change_point], points[i]));
                    if (distance[i] < temp_distance){
                        temp_distance = distance[i];
                        temp_min_point = i;
                    }
                }
            }
            total_distance += temp_distance;
            choose[temp_min_point] = true;
            last_change_point = temp_min_point;
        }
        return total_distance;
    }
};

int main(){
    vector<vector<int>> points = {{3,12}, {-2,5}, {-4,1}};
    Solution S;
    cout << S.minCostConnectPoints(points) << endl;
    return 0;
}