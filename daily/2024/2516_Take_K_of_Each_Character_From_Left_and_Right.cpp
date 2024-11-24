#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        int n = s.length();
        if (n < k * 3) return -1;
        vector<int> count(3, 0);
        for (char c : s) count[c-'a']++;
        if (count[0] < k || count[1] < k || count[2] < k) return -1;
        int ans = n;
        int left = 0;
        for (int right = 0; right < n; right++){
            count[s[right]-'a']--;
            while(left <= right && (count[0] < k || count[1] < k || count[2] < k)){
                count[s[left]-'a']++;
                left++;
            }
            ans = min(ans, n - (right - left + 1));
        }
        return ans;
    }
};

int main(){
    string s = "aabaaaacaabc";
    int k = 2;
    // string s = "a";
    // int k = 1;
    // string s = "a";
    // int k = 0;
    // string s = "cbbac";
    // int k = 1;
    // string s = "aabbccca";
    // int k = 2;
    Solution S;
    cout << S.takeCharacters(s, k) << endl;
    return 0;
}