#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int cnt = 0;
        char curr = '0';
        for (char c : s){
            if (c == curr) cnt++;
            curr = (curr == '0')? '1' : '0';
        }
        return min(cnt, n - cnt);
    }
};

int main(){
    string s = "0100";
    // string s = "10";
    // string s = "1111";
    Solution S;
    cout << S.minOperations(s) << endl;
    return 0;
}