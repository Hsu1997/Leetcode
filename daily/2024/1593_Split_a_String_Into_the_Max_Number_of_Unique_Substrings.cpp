#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ans;
    void recursion(string& s, int i, string curr, unordered_set<string>& substr){
        if (i == s.length()){
            if (substr.find(curr) == substr.end()){
                ans = max(ans, (int)substr.size() + 1);
            }
            return;
        }
        if (curr != ""){
            if (substr.find(curr) == substr.end()){
                substr.insert(curr);
                recursion(s, i+1, string(1, s[i]), substr);
                substr.erase(curr);
            }
        }
        curr += s[i];
        recursion(s, i+1, curr, substr);
    }
    int maxUniqueSplit(string s) {
        ans = 1;
        unordered_set<string> substr;
        recursion(s, 0, "", substr);
        return ans;
    }
};

int main(){
    string s = "ababccc";
    // string s = "aba";
    // string s = "aa";
    Solution S;
    cout << S.maxUniqueSplit(s) << endl;
    return 0;
}