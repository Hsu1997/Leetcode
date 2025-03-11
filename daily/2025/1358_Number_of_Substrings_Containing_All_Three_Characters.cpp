#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int start = 0;
        int end = 0;
        int ans = 0;
        int count[3] = {0, 0, 0};
        while(end < n){
            count[s[end] - 'a']++;
            while(start <= end && valid(count)){
                ans += (n - end);
                count[s[start++] - 'a']--;
            }
            end++;
        }
        return ans;
    }
    bool valid(int count[3]){
        return count[0] > 0 && count[1] > 0 && count[2] > 0;
    }
};

int main(){
    string s = "abcabc";
    // string s = "aaacb";
    // string s = "abc";
    Solution S;
    cout << S.numberOfSubstrings(s) << endl;
    return 0;
}