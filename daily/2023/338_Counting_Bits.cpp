#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        int pow = 0;
        for (int i = 1; i <= n; i++){
            // cout << "i = " << i << " ";
            if (i == (1<<(pow+1))){
                ans[i] = 1;
                pow++;
                // cout << "ans = 1, pow = " << pow << endl;
            }
            else{
                ans[i] = ans[i-(1<<pow)]+1;
                // cout << "ans = " << ans[i] << ", num " << i << "-" << (1<<pow) << " +1" << endl;
            }
        }
        return ans;
    }
};

int main(){
    int n = 8;
    Solution S;
    vector<int> ans = S.countBits(n);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}