#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int a_count = 0;
        for (auto c : s) if (c == 'a') a_count++;
        int ans = min(a_count, n - a_count);
        int b_count = 0;
        for (int critical_point = 0; critical_point < n; critical_point++){
            if (s[critical_point] == 'a') a_count--;
            else b_count++;
            ans = min(ans, b_count + a_count);
        }
        return ans;
    }
};

int main(){
    string s = "aababbab";
    // string s = "bbaaaaabb";
    Solution S;
    cout << S.minimumDeletions(s) << endl;
    return 0;
}