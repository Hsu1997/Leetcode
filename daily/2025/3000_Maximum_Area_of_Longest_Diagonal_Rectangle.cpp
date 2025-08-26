#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int len = 0;
        int area = 0;
        for (auto& rectangle : dimensions){
            int l = rectangle[0];
            int w = rectangle[1];
            if (l * l + w * w > len){
                len = l * l + w * w;
                area = l * w;
            }
            else if (l * l + w * w == len){
                area = max(area, l * w);
            }
        }
        return area;
    }
};

int main(){
    vector<vector<int>> dimensions = {{9,3},{8,6}};
    // vector<vector<int>> dimensions = {{3,4},{4,3}};
    // vector<vector<int>> dimensions = {{6,5},{8,6},{2,10},{8,1},{9,2},{3,5},{3,5}};
    Solution S;
    cout << S.areaOfMaxDiagonal(dimensions) << endl;
    return 0;
}