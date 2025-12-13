#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool valid(string& s){
        if (s == "") return false;
        for (char c : s){
            if (!isalnum(c) && c != '_') return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> order = {"electronics", "grocery", "pharmacy", "restaurant"};
        vector<string> ans;
        int n = code.size();
        for (int k = 0; k < 4; k++){
            vector<string> temp;
            for (int i = 0; i < n; i++){
                if (businessLine[i] == order[k] && valid(code[i]) && isActive[i]) temp.push_back(code[i]);
            }
            sort(temp.begin(), temp.end());
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        return ans;
    }
};

int main(){
    vector<string> code = {"SAVE20","","PHARMA5","SAVE@20"};
    vector<string> businessLine = {"restaurant","grocery","pharmacy","restaurant"};
    vector<bool> isActive = {true,true,true,true};
    // vector<string> code = {"GROCERY15","ELECTRONICS_50","DISCOUNT10"};
    // vector<string> businessLine = {"grocery","electronics","invalid"};
    // vector<bool> isActive = {false,true,true};
    Solution S;
    vector<string> ans = S.validateCoupons(code, businessLine, isActive);
    for (string s : ans) cout << s << " ";
    cout << endl;
    return 0;
}