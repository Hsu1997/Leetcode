#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int i = 0;
        int j = height.size() - 1;
        while(i < j){
            ans = max(ans, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) i++;
            else j--;
        }
        return ans;
    }
};

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution S;
    cout << S.maxArea(height) << endl;
    return 0;
}