#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        string convert;
        for (char c : s) convert += to_string(c - 'a' + 1);
        // cout << convert << endl;
        string ans = convert;
        while(k--){
            int temp = 0;
            for (char c : ans) temp += (c - '0');
            ans = to_string(temp);
        }
        return stoi(ans);
    }
};

int main(){
    string s = "iiii";
    int k = 1;
    // string s = "leetcode";
    // int k = 2;
    // string s = "zbax";
    // int k = 2;
    Solution S;
    cout << S.getLucky(s, k) << endl;
    return 0;
}