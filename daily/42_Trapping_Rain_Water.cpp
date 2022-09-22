#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left = height;
        vector<int> right = height;
        int temp = 0;
        for (int i = 1; i < height.size(); i++) left[i] = max(left[i-1],left[i]);
        for (int i = height.size()-2; i >= 0; i--) right[i] = max(right[i], right[i+1]);
        int water = 0;
        int wall = 0;
        for (int i = 0; i < height.size(); i++){
            wall += height[i];
            water += min(left[i], right[i]);
        }
        return water - wall;
    }
};

int main(){
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height = {4,2,0,3,2,5};
    Solution S;
    cout << S.trap(height) << endl;
    return 0;
}