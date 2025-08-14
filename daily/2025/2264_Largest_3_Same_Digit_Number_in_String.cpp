#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int ans = -1;
        char prev = '#';
        int cnt = 0;
        for (char c : num){
            if (c != prev){
                prev = c;
                cnt = 0;
            }
            cnt++;
            if (cnt == 3){
                ans = max(ans, c - '0');
            }
        }
        return (ans != -1)? string(3, '0' + ans) : "";
    }
};

int main(){
    string num = "6777133339";
    // string num = "2300019";
    // string num = "42352338";
    Solution S;
    cout << S.largestGoodInteger(num) << endl;
    return 0;
}