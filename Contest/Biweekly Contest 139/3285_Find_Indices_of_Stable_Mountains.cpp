#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> ans;
        for (int i = 0; i < height.size()-1; i++){
            if (height[i] > threshold) ans.push_back(i+1);
        }
        return ans;
    }
};

int main(){
    vector<int> height = {1,2,3,4,5};
    int threshold = 2;
    // vector<int> height = {10,1,10,1,10};
    // int threshold = 3;
    // vector<int> height = {10,1,10,1,10};
    // int threshold = 10;
    Solution S;
    vector<int> ans = S.stableMountains(height, threshold);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}