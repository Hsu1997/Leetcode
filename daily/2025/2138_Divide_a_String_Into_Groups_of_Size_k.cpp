#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> ans;
        s = s + string(k - n % k, fill);
        for (int i = 0; i < n; i += k){
            ans.push_back(s.substr(i, k));
        }
        return ans;
    }
};

int main(){
    string s = "abcdefghi";
    int k = 3;
    char fill = 'x';
    // string s = "abcdefghij";
    // int k = 3;
    // char fill = 'x';
    Solution S;
    vector<string> ans = S.divideString(s, k, fill);
    for (string i : ans) cout << i << " ";
    cout << endl;
    return 0;
}