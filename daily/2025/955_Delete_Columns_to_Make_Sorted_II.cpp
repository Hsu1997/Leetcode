#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int l = strs[0].length();
        vector<bool> need_check(n, true);
        int ans = 0;
        for (int j = 0; j < l; j++){
            vector<bool> temp(n, true);
            bool need_del = false;
            for (int i = 1; i < n; i++){
                if (strs[i][j] > strs[i-1][j]) temp[i] = false;
                if (need_check[i] && strs[i][j] < strs[i-1][j]){
                    need_del = true;
                    break;
                }
            }
            if (need_del) ans++;
            else{
                for (int i = 0; i < n; i++) need_check[i] = need_check[i] && temp[i];
            }
        }
        return ans;
    }
};

int main(){
    vector<string> strs = {"ca","bb","ac"};
    // vector<string> strs = {"xc","yb","za"};
    // vector<string> strs = {"zyx","wvu","tsr"};
    Solution S;
    cout << S.minDeletionSize(strs) << endl;
    return 0;
}