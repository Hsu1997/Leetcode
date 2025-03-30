#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        int ans = 0;
        // p : longest palindrome length start at index i
        vector<int> p(n1, 0);
        vector<vector<bool>> s_palindrome(n1, vector<bool>(n1, false));
        for (int start = n1 - 1; start >= 0; start--){
            for (int end = start; end < n1; end++){
                if (s[start] == s[end] && (end - start + 1 <= 2 || s_palindrome[start+1][end-1])){
                    s_palindrome[start][end] = true;
                    p[start] = max(p[start], end - start + 1);
                    ans = max(ans, p[start]);
                }
            }
        }
        // q : longest palindrome length end at index i
        vector<int> q(n2, 0);
        vector<vector<bool>> t_palindrome(n2, vector<bool>(n2, false));
        for (int start = n2 - 1; start >= 0; start--){
            for (int end = start; end < n2; end++){
                if (t[start] == t[end] && (end - start + 1 <= 2 || t_palindrome[start+1][end-1])){
                    t_palindrome[start][end] = true;
                    q[end] = max(q[end], end - start + 1);
                    ans = max(ans, q[end]);
                }
            }
        }
        // dp[i][j] : longest palindrome start at s[i] and end at t[j], each can be empty
        vector<vector<int>> dp(n1, vector<int>(n2, 0));
        for (int i = n1 - 1; i >= 0; i--){
            for (int j = 0; j < n2; j++){
                dp[i][j] = max(p[i], q[j]);
                if (s[i] == t[j]){
                    dp[i][j] = max(dp[i][j], 2);
                    // s[i] + [s[i+1]...dp part...t[j-1]] + t[j]
                    if (i + 1 < n1 && j - 1 >= 0) dp[i][j] = max(dp[i][j], 2 + dp[i+1][j-1]);
                    // s[i] + s[i+1....] + t[j]
                    if (i + 1 < n1) dp[i][j] = max(dp[i][j], 2 + p[i+1]);
                    // s[i] + t[....j-1] + t[j]
                    if (j - 1 >= 0) dp[i][j] = max(dp[i][j], 2 + q[j-1]);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

int main(){
    // string s = "a";
    // string t = "a";
    // string s = "abc";
    // string t = "def";
    // string s = "b";
    // string t = "aaaa";
    // string s = "abcde";
    // string t = "ecdba";
    // string s = "zzzzzzzzzzzzzzzzzzzzzzzzzzz";
    // string t = "zzzzzzzzzzzzzzzzzzzzzzzzzz";
    // string s = "tmvblwyunlbwywuuqgewbohxylifcaynqoljpfjnspjogcmceymjokyyrsdmsqppimkdfjtewhhglnhseczeyquwfffkkujleozqihkfpxdeqnojlqzamhnmhseqleowxkrhzmsrsnayhookdqpptfxkfwixhrtdbpwzyfogliixuasokuesgsnvcprjzlrrysndvukidfdukpgihuagxqfeuirrdrgjayrossteehrqcgocgqxjhremnngrzitcbvdlapuypdkzvgoxedxvgceyudivakzpgxisvnlkbjhmzgcwtavgbufzqmgwlvxeqmbmvcnmxnkwobsmbyvzbyobmpxurmfsdydfmwajjrmirzgbglkqsxhobvekbguucvnmlmjlridskdauxlkapapopylbpormppxxeeavwxpwhedcuiuxplviuxmgumlzrfmhywxlgqmyjnitlmzksjaqoahrcmacooezuyvbtlgmklvvtrjvarhabxthlhhuyofkewlphznnyiqeactlmkomvjhzewgickvtxhuxgficebjlxpfnkzkaallvooegnjkimandnosgqfsjjhjkvlujqbqiifczeexewggdvsybeuyjjbacwiwmqavdfvajgdjldzwwamnmtvt";
    // string t = "gignohodjlytmrdvfxsiwjzgcpjrgxcbuzvuwvxactmapoxiseswemrgqcrowztnwskpoqiaakjowzyndkriwmiilapasatwookngbqlsdjaqfblmfzmutzrdiqaozxtzjfeelswpzidajibnibnbrdzjzesxexxxtmrjkmjfuxldakaklohcfgniltrlfvrboqbtmstuimnmbicjwqiqpuevjfzvfjkjdjnebvlxqsosrtgkiwgtupnrvcungoxambphusdvevtdqsgujozuaofbdqvynpcbxlyokvuyrwtyyculkjcxweeodvajnapbhhnpyciessfsbppubkqkrvomduaiksdwhfwqmepkmtgzmzthfpbilrvxurbyygwluscmhuxfwwfarmlnkibbowwaaeffkwrrhnqvwdtsqpywenynaqackxzqmmdjonivdmycfwhnfhrnnurdpwyqptdroiicfyhdfxtggvjnvvcpdnhsrbqpcjtlgqmccywarghlheoaeshiyyhihirqtltsehcfwwakzjzvsgtnevmuceeqsicfkhuqqofjfbwodgwcgxvxtlgdxpllurhkyonkxcvdhnmccoskwkygvotgibntzcxuhyddgcpmatvcvdviiirpzdjlrvejqekeszkijpvhnoemggjxchiumvbbghmzlixiceevrolhlagrxuyeikyiuqzmxravrtkkwfinerbjnyhhorzmdwccwlggjxqrvrmxb";
    // string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    // string t = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    string s = "iiye";
    string t = "i";
    Solution S;
    cout << S.longestPalindrome(s, t) << endl;
    return 0;
}