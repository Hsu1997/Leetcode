#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int acc = 0;
        int ans = 0;
        for (auto i : gain){
            acc += i;
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