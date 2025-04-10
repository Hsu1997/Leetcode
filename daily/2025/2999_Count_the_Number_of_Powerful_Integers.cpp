#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

class Solution {
public:
    long long count(string& x, string& s, int limit){
        if (x.length() < s.length()) return 0;
        if (x.length() == s.length()) return (x >= s)? 1 : 0;
        long long ans = 0;
        int preLen = x.length() - s.length();
        for (int i = 0; i < preLen; i++){
            if (limit < x[i] - '0'){
                ans += (long long)pow(limit+1, preLen - i);
                return ans;
            }
            ans += (long long)(x[i] - '0') * (long long)pow(limit+1, preLen - i - 1);
        }
        string suffix = x.substr(x.length() - s.length(), s.length());
        if (suffix >= s) ans++;
        return ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string up = to_string(finish);
        string down = to_string(start - 1);
        return count(up, s, limit) - count(down, s, limit);
    }
};

int main(){
    long long start = 1;
    long long finish = 6000;
    int limit = 4;
    string s = "124";
    // long long start = 15;
    // long long finish = 215;
    // int limit = 6;
    // string s = "10";
    // long long start = 1000;
    // long long finish = 2000;
    // int limit = 4;
    // string s = "3000";
    Solution S;
    cout << S.numberOfPowerfulInt(start, finish, limit, s) << endl;
    return 0;
}