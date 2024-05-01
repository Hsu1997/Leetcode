#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int to_int(char a){
        if (a <= 90) return (a - 'A');
        else return (a - 'a' + 26);
    }

    // a contain in b
    bool contain(vector<int> a, vector<int> b){
        if (a.size() != b.size()) return false;
        for (int i = 0; i < a.size(); i++){
            if (a[i] > b[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        string ans = "";
        int ans_length = INT_MAX;

        int i = 0;
        int j = t.size()-1;
        vector<int> count(52, 0);
        vector<int> target(52, 0);
        for (auto k : t) target[to_int(k)]++;

        for (int k = i; k <= j; k++) count[to_int(s[k])]++;

        while(j < s.size() && i <= j){
            if (contain(target, count)){
                if (j-i+1 < ans_length){
                    ans = s.substr(i, j-i+1);
                    ans_length = j-i+1;
                }
                count[to_int(s[i])]--;
                i++;
            }
            else if (j != s.size()-1){
                j++;
                count[to_int(s[j])]++;
            }
            else return ans;
        }
        return ans;
    }
};

int main(){
    // a-z : 97-122
    // A-Z : 65-90
    string s = "ADOBECODEBANC";
    string t = "ABC";
    // string s = "a";
    // string t = "a";
    // string s = "a";
    // string t = "aa";
    Solution S;
    cout << S.minWindow(s, t) << endl;
    return 0;
}