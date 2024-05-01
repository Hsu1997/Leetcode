#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s){
        if (s.length() < 2) return s.length();

        int calculate[127] = {0};
        int i = 0;
        int j = 0;
        int temp = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++){
            temp++;
            calculate[s[i]]++;
            while(calculate[s[i]] > 1){
                calculate[s[j++]]--;
                temp--;
            }
            ans = max(ans, temp);
        }

        return ans;
    }
};

int main(){
    string s = "aabcabc";
    Solution S;
    cout << S.lengthOfLongestSubstring(s) << endl;
    return 0;
}