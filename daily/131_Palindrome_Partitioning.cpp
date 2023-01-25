#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int n;
    string s;
    vector<string> temp;
    vector<vector<string>> ans;

    bool palindrome(int start, int end){
        while(start < end) if (s[start++] != s[end--]) return false;
        return true;
    }

    void helper(int start){
        if (start >= n) ans.push_back(temp);;
        for (int i = start; i < n; i++){
            while(s[start] != s[i] && i < n-1) i++;
            if (palindrome(start, i)){
                temp.push_back(s.substr(start, i - start + 1));
                helper(i+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string _s) {
        s = _s;
        n = s.length();
        helper(0);
        return ans;
    }
};

int main(){
    // string s = "aab";
    string s = "aa";
    Solution S;
    vector<vector<string>> ans = S.partition(s);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}