#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) return {0};
        vector<int> ans = {0,1};
        int pow = 1;
        while((1 << pow) <= n){
            int k = ans.size();
            for (int i = 0; i < k; i++){
                if (ans.size() == n+1) return ans;
                ans.push_back(ans[i]+1);
            }
            pow++;
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