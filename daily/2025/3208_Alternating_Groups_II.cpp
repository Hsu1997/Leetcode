#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int curr_invalid = 0;
        for (int i = 1; i < k; i++) if (colors[i] == colors[i-1]) curr_invalid++;
        int ans = (curr_invalid == 0);
        for (int i = 0; i < n - 1; i++){
            curr_invalid  = curr_invalid - (colors[i] == colors[(i+1)%n]) + (colors[(i+k)%n] == colors[(i+k-1)%n]);
            if (curr_invalid == 0) ans++;
        }
        return ans;
    }
};

int main(){
    vector<int> colors = {0,1,0,1,0};
    int k = 3;
    // vector<int> colors = {0,1,0,0,1,0,1};
    // int k = 6;
    // vector<int> colors = {1,1,0,1};
    // int k = 4;
    Solution S;
    cout << S.numberOfAlternatingGroups(colors, k) << endl;
    return 0;
}