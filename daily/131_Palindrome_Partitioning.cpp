#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    
    bool is_palindrome(string& s, int i, int j){
        // int i = 0, j = s.length()-1;
        while(i < j) if (s[i++] != s[j--]) return false;
        return true;
    }

    void subproblem(string& s, vector<string>& temp, int index){
        // cout << "check " << s << endl;
        if (index == s.length()){
            ans.push_back(temp);
            return;
        };
        for (int i = index; i < s.length(); i++){
            // cout << "check " << s.substr(index, i + 1 - index) << " => " << is_palindrome(s, index, i) << endl;
            if (is_palindrome(s, index, i)){
                temp.push_back(s.substr(index, i + 1 - index));
                subproblem(s, temp, i + 1);
                temp.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        subproblem(s, temp, 0);
        return ans;
    }
};

int main(){
    Solution S;
    string s = "aab";
    // string s = "a";
    vector<vector<string>> ans = S.partition(s);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}