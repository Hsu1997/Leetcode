#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int total_0 = 0;
        int total_1 = 0;
        for (auto i : s){
            if (i == '0') total_0++;
            else total_1++;
        }
        int acc_0 = 0;
        int acc_1 = 0;
        int ans = min(total_0, total_1);
        // cout << total_0 << " " << total_1 << endl;
        for (int i = 0; i < s.length(); i++){
            // cout << acc_1 + total_0 - acc_0 << " ";
            ans = min(ans, acc_1 + total_0 - acc_0);
            acc_0 += (s[i] == '0');
            acc_1 += (s[i] == '1');
        }
        // cout << endl;
        return ans;
    }
};

int main(){
    // string s = "00110";
    // string s = "010110";
    string s = "00011000";
    Solution S;
    cout << S.minFlipsMonoIncr(s) << endl;
    return 0;
}