#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        int ans = 0;
        for (int i : count){
            if (i % 2) ans += 1;
            else{
                ans += (i > 0)? 2 : 0;
            }
        }
        return ans;
    }
};

int main(){
    string s = "abaacbcbb";
    // string s = "aa";
    Solution S;
    cout << S.minimumLength(s) << endl;
    return 0;
}