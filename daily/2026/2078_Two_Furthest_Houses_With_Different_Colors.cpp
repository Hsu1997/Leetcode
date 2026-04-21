#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        if (colors[0] != colors[n-1]) return n-1;
        int ans = -1;
        for (int i = 1; i < n - 1; i++){
            if (colors[i] != colors[0]){
                ans = max({ans, i, n - 1 - i});
            }
        }
        return ans;
    }
};

int main(){
    vector<int> colors = {1,1,1,6,1,1,1};
    // vector<int> colors = {1,8,3,8,3};
    // vector<int> colors = {0,1};
    Solution S;
    cout << S.maxDistance(colors) << endl;
    return 0;
}