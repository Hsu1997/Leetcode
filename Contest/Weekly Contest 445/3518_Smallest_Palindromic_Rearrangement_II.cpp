#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    long long maxK = 1000001;

    long long binom(int n, int k){
        if (k > n) return 0;
        if (n - k < k) k = n - k;
        long long ans = 1;
        for (int i = 0; i < k; i++){
            // cout << " * " << (n - i) << " / " << (i + 1) << " ";
            ans = ans * (n - i) / (i + 1);
            if (ans >= maxK) return maxK;
        }
        return ans;
    }
    long long count_permutation(int count[26]){
        int total = 0;
        for (int i = 0; i < 26; i++) total += count[i];
        long long permutation = 1;
        for (int i = 0; i < 26; i++){
            int curr_cnt = count[i];
            permutation *= binom(total, curr_cnt);
            if (permutation >= maxK){
                // cout << "break " << endl;
                return maxK;
            }
            total -= curr_cnt;
        }
        // cout << endl;
        return permutation;
    }

    string smallestPalindrome(string s, int k) {
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;
        int n = s.length();
        char middle = 0;
        for (int i = 0; i < 26; i++){
            if (count[i] % 2 == 1) middle = 'a' + i;
            count[i] /= 2;
        }
        // cout << count_permutation(count) << endl;
        if (count_permutation(count) < k) return "";
        string ans;
        // for (int i = 0; i < 26; i++) if (count[i]) cout << char('a'+i) << " = " << count[i] << " ";
        // cout << endl;
        for (int i = 0; i < n / 2; i++){
            for (int c = 0; c < 26; c++){
                if (count[c] == 0) continue;
                count[c]--;
                long long perm = count_permutation(count);
                // cout << "Index = " << i << " : , cahr = " << char('a' + c) << ", permutation = " << perm << endl;
                if (perm >= k){
                    ans += 'a' + c;
                    break;
                }
                else{
                    count[c]++;
                    k -= perm;
                }
            }
        }
        string tail = ans;
        reverse(tail.begin(), tail.end());
        if (n % 2 == 1) ans += middle;
        ans += tail;
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
    // string s = "kkkk";
    // int k = 1;
    // string s = "xjqeogxsqbhcchbqsxgoeqjx";
    // int k = 997471;
    // string s = "tbixkfceldrpmtamugcpdbioybbirtkerqldejzqkfbwcdwxawkcyxsgkptjggbszihsidpjliwrabzrxkwjzqrnddvecbxzddmimqjwdjlljpyououegrhdufudkrsiplappdgttgdppalpisrkdufudhrgeuouoypjlljdwjqmimddzxbcevddnrqzjwkxrzbarwiljpdishizsbggjtpkgsxyckwaxwdcwbfkqzjedlqrektribbyoibdpcgumatmprdlecfkxibt";
    // int k = 745714;
    Solution S;
    cout << S.smallestPalindrome(s, k) << endl;
    return 0;
}