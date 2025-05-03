#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = INT_MAX;
        for (int k = 1; k <= 6; k++){
            int t = 0;
            int b = 0;
            bool valid = true;
            for (int i = 0; i < n; i++){
                if (tops[i] != k && bottoms[i] != k){
                    valid = false;
                    break;
                }
                t += (tops[i] == k);
                b += (bottoms[i] == k);
            }
            if (valid) ans = min({ans, (n - t), (n - b)});
        }
        return (ans == INT_MAX)? -1 : ans;
    }
};

int main(){
    vector<int> tops = {2,1,2,4,2,2};
    vector<int> bottoms = {5,2,6,2,3,2};
    // vector<int> tops = {3,5,1,2,3};
    // vector<int> bottoms = {3,6,3,3,4};
    Solution S;
    cout << S.minDominoRotations(tops, bottoms) << endl;
    return 0;   
}