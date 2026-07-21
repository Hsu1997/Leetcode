#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int cnt = 0;
        int maxtwointerval = 0;
        int prev = -1;
        int curr = 0;
        for (char c : s){
            if (c == '0'){
                curr++;
                if (prev > 0) maxtwointerval = max(maxtwointerval, prev + curr);
            }
            else{
                cnt++;
                if (curr){
                    prev = curr;
                    curr = 0;
                }
            }
        }
        return cnt + maxtwointerval;
    }
};

int main(){
    string s = "01";
    // string s = "0100";
    // string s = "1000100";
    // string s = "01010";
    Solution S;
    cout << S.maxActiveSectionsAfterTrade(s) << endl;
    return 0;
}