#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string ans(n, '?');
        char curr = 'a';
        for (int i = 0; i < n; i++){
            if (ans[i] == '?'){
                if (curr > 'z') return "";
                ans[i] = curr++;
                for (int j = i + 1; j < n; j++) if (lcp[i][j] > 0) ans[j] = ans[i];
            }
        }
        for (int i = n - 1; i >= 0; i--){
            for (int j = n - 1; j >= 0; j--){
                if (ans[i] != ans[j]){
                    if (lcp[i][j] > 0) return "";
                }
                else{
                    if (i == n - 1 || j == n - 1){
                        if (lcp[i][j] != 1) return "";
                    }
                    else{
                        if (lcp[i][j] != lcp[i+1][j+1] + 1) return "";
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> lcp = {{4,0,2,0},{0,3,0,1},{2,0,2,0},{0,1,0,1}};
    // vector<vector<int>> lcp = {{4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,1}};
    // vector<vector<int>> lcp = {{4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,3}};
    Solution S;
    cout << S.findTheString(lcp) << endl;
    return 0;
}