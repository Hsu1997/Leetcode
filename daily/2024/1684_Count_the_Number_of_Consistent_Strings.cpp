#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int allow = 0;
        for (char c : allowed) allow |= (1 << (c - 'a'));
        int ans = 0;
        for (string s : words){
            bool is_allowed= true;
            for (char c : s){
                if ((allow & (1 << (c - 'a'))) == 0){
                    is_allowed = false;
                    break;
                }
            }
            ans += is_allowed;
        }
        return ans;
    }
};

int main(){
    string allowed = "ab";
    vector<string> words = {"ad","bd","aaab","baa","badab"};
    // string allowed = "abc";
    // vector<string> words = {"a","b","c","ab","ac","bc","abc"};
    Solution S;
    cout << S.countConsistentStrings(allowed, words) << endl;
    return 0;
}