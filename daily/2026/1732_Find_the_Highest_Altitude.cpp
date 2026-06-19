#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int ans = 0;
        int acc = 0;
        for (int i = 0; i < n; i++){
            acc += gain[i];
            ans = max(ans, acc);
        }
        return ans;
    }
};

int main(){
    vector<int> gain = {-5,1,5,0,-7};
    // vector<int> gain = {-4,-3,-2,-1,4,3,2};
    Solution S;
    cout << S.largestAltitude(gain) << endl;
    return 0;
}