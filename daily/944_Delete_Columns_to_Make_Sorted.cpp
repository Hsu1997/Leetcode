#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if (strs.size() < 2) return 0;
        int ans = 0;
        int n = strs[0].length();
        for (int i = 0; i < n; i++){
            for (int s = 1; s < strs.size(); s++){
                if (strs[s][i] < strs[s-1][i]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<string> strs = {"abc", "bce", "cae"};
    // vector<string> strs = {"cba","daf","ghi"};
    // vector<string> strs = {"a","b"};
    // vector<string> strs = {"zyx","wvu","tsr"};
    Solution S;
    cout << S.minDeletionSize(strs) << endl;
    return 0;
}