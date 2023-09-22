#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto i = s.begin();
        for (auto& c : t){
            if (*i == c) i++;
        }
        return (i == s.end());
    }
};

int main(){
    // string s = "abc";
    string s = "axc";
    string t = "ahbgdc";
    Solution S;
    cout << S.isSubsequence(s, t) << endl;
    return 0;
}