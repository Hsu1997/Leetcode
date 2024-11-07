#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> count(32, 0);
        for (int i : candidates){
            int pos = 0;
            while(i){
                if (i % 2) count[pos]++;
                i /= 2;
                pos++;
            }
        }
        int ans = 1;
        for (int c : count) ans = max(ans, c);
        return ans;
    }
};

int main(){
    vector<int> candidates = {16,17,71,62,12,24,14};
    // vector<int> candidates = {8,8};
    Solution S;
    cout << S.largestCombination(candidates) << endl;
    return 0;
}