#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map <char, string> tele_map = {{'2', "abc"},{'3', "def"},{'4', "ghi"},
                                             {'5', "jkl"},{'6', "mno"},{'7', "pqrs"},
                                             {'8', "tuv"},{'9', "wxyz"}};
    int n;
    vector<string> ans;

    vector<string> letterCombinations(string digits) {
        n = digits.length();
        if (n == 0) return ans;
        for (auto i : tele_map[digits[0]]){
            string temp;
            temp += i;
            // cout << temp << endl;
            subproblem(digits, 1, temp);
        }
        return ans;
    }

    void subproblem(string digits, int i, string temp){
        if (i == n){
            // cout << temp << endl;
            ans.push_back(temp);
        }
        else{
            for (auto j : tele_map[digits[i]]){
                subproblem(digits, i+1, temp+j);
            }
        }
    }
};

int main(){
    string digits = "23";
    Solution S;
    for (auto i : S.letterCombinations(digits)) cout << i << " ";
    cout << endl;
    return 0;
}