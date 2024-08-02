#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (string passenger : details) if ((passenger[11] - '0') * 10 + (passenger[12] - '0') > 60) ans++;
        return ans;
    }
};

int main(){
    vector<string> details = {"7868190130M7522","5303914400F9211","9273338290F4010"};
    // vector<string> details = {"1313579440F2036","2921522980M5644"};
    Solution S;
    cout << S.countSeniors(details) << endl;
    return 0;
}