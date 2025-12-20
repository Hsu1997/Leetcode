#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int r = strs.size();
        int c = strs[0].length();
        int ans = 0;
        for (int j = 0; j < c; j++){
            bool sorted = true;
            for (int i = 1; i < r; i++){
                if (strs[i][j] < strs[i-1][j]){
                    sorted = false;
                    break;
                }
            }
            ans += !sorted;
        }
        return ans;
    }
};

int main(){
    vector<string> strs = {"cba","daf","ghi"};
    // vector<string> strs = {"a","b"};
    // vector<string> strs = {"zyx","wvu","tsr"};
    Solution S;
    cout << S.minDeletionSize(strs) << endl;
    return 0;
}