#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        long int h_max = 0;
        long int w_max = 0;

        for (int i = 0; i < horizontalCuts.size()-1; i++){
            h_max = max(h_max, (long int)(horizontalCuts[i+1] - horizontalCuts[i]));
        }
        for (int i = 0; i < verticalCuts.size()-1; i++){
            w_max = max(w_max, (long int)(verticalCuts[i+1] - verticalCuts[i]));
        }
        // cout << h_max <<  " " << w_max << endl;
        return (h_max * w_max) % (int)(1e9+7);
    }
};

int main(){
    int h = 5;
    int w = 4;
    vector<int> horizontalCuts = {1,2,4};
    vector<int> verticalCuts = {1,3};
    Solution S;
    cout << S.maxArea(h, w, horizontalCuts, verticalCuts) << endl;
    return 0;
}