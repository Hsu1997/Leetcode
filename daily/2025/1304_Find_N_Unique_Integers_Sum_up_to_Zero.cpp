#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        for (int i = 1; i < n; i++) ans[i] = i;
        ans[0] = -n * (n - 1) / 2;
        return ans;
    }
};

int main(){
    int n = 5;
    // int n = 3;
    // int n = 1;
    // int n = 2;
    Solution S;
    vector<int> ans = S.sumZero(n);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}