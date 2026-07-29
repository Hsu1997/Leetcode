#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static const int limit = 1000001;
    long long binomial(int n, int k, int l = limit){
        if (k > n) return 0;
        k = min(k, n - k);
        long long ans = 1;
        for (int i = 1; i <= k; i++){
            ans = ans * (n + 1 - i) / i;
            if (ans >= l) return l;
        }
        return ans;
    }
    long long permutation(int count[26], int total, int l = limit){
        long long p = 1;
        for (int i = 0; i < 26; i++){
            int c = count[i];
            if (c == 0) continue;
            p *= binomial(total, c, l);
            if (p >= l) return l;
            total -= c;
        }
        return p;
    }
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        char mid;
        for (char c : s) cnt[c - 'a']++;
        for (int i = 0; i < 26; i++){
            if (cnt[i] % 2 == 1) mid = 'a' + i;
            cnt[i] /= 2;
        }
        if (permutation(cnt, n / 2, k + 1) < k) return "";
        string left(n / 2, ' ');
        for (int i = 0; i < n / 2; i++){
            for (int c = 0; c < 26; c++){
                if (cnt[c] == 0) continue;
                char curr = 'a' + c;
                cnt[c]--;
                long long p = permutation(cnt, n / 2 - 1 - i, k + 1);
                if (p < k){
                    k -= p;
                    cnt[c]++;
                }
                else{
                    left[i] = curr;
                    break;
                }
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        string ans;
        if (n % 2 == 1) ans = left + mid + right;
        else ans = left + right;
        return ans;
    }
};

int main(){
    string s = "abba";
    int k = 2;
    // string s = "aa";
    // int k = 2;
    // string s = "bacab";
    // int k = 1;
    Solution S;
    cout << S.smallestPalindrome(s, k) << endl;
    return 0;
}