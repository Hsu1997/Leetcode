#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s, string t) {
        int ans = 0;
        long long mod = 100000000000007;
        int n1 = s.length();
        int n2 = t.length();
        vector<long long> hash_mod(max(n1, n2));
        hash_mod[0] = 1;
        for (int i = 1; i < hash_mod.size(); i++){
            hash_mod[i] = (hash_mod[i-1] * 27) % mod;
        }
        unordered_set<long long> sset;
        unordered_set<long long> tset;
        for (int i = 0; i < n1; i++){
            long long curr = 0;
            for (int j = i; j < n1; j++){
                curr = (curr * 27 + (s[j] - 'a' + 1)) % mod;
                sset.insert(curr);
            }
        }
        sset.insert(0);
        for (int i = 0; i < n2; i++){
            long long curr = 0;
            long long rev = 0;
            for (int j = i; j < n2; j++){
                curr = (curr * 27 + (t[j] - 'a' + 1)) % mod;
                rev = ((t[j] - 'a' + 1) * hash_mod[j-i] + rev) % mod;
                if (sset.find(rev) != sset.end()) ans = max(ans, (j-i+1)*2);
                tset.insert(curr);
            }
        }
        tset.insert(0);
        // cout << "Temp ans = " << ans << endl;
        for (int i = 0; i < n1; i++){
            if ((i+1) * 2<= ans) continue;
            int l = i;
            int r = i;
            while(l >= 0 && r < n1 && s[l] == s[r]){
                ans = max(ans, r - l + 1);
                int k = l - 1;
                long long temp = 0;
                while(k >= 0){
                    temp = (temp * 27 + (s[k] - 'a' + 1)) % mod;
                    if (tset.find(temp) != tset.end()){
                        ans = max(ans, r - l + 1 + (l - k) * 2);
                        k--;
                    }
                    else{
                        break;
                    }
                }
                l--, r++;
            }
            if (i+1 < n1 && s[i] == s[i+1]){
                int l = i;
                int r = i+1;
                while(l >= 0 && r < n1 && s[l] == s[r]){
                    ans = max(ans, r - l + 1);
                    int k = l - 1;
                    long long temp = 0;
                    while(k >= 0){
                        temp = (temp * 27 + (s[k] - 'a' + 1)) % mod;
                        if (tset.find(temp) != tset.end()){
                            ans = max(ans, r - l + 1 + (l - k) * 2);
                            k--;
                        }
                        else{
                            break;
                        }
                    }
                    l--, r++;
                }
            }
        }

        for (int i = 0; i < n2; i++){
            if ((n2-i) * 2 <= ans) continue;
            int l = i;
            int r = i;
            while(l >= 0 && r < n2 && t[l] == t[r]){
                ans = max(ans, r - l + 1);
                int k = r + 1;
                long long temp = 0;
                while(k < n2){
                    temp = ((t[k] - 'a' + 1) * hash_mod[k - r - 1] + temp) % mod;
                    if (sset.find(temp) != sset.end()){
                        ans = max(ans, r - l + 1 + (k - r) * 2);
                        k++;
                    }
                    else{
                        break;
                    }
                }
                l--, r++;
            }
            if (i+1 < n2 && t[i] == t[i+1]){
                int l = i;
                int r = i+1;
                while(l >= 0 && r < n2 && t[l] == t[r]){
                    ans = max(ans, r - l + 1);
                    int k = r + 1;
                    long long temp = 0;
                    while(k < n2){
                        temp = ((t[k] - 'a' + 1) * hash_mod[k - r - 1] + temp) % mod;
                        if (sset.find(temp) != sset.end()){
                            ans = max(ans, r - l + 1 + (k - r) * 2);
                            k++;
                        }
                        else{
                            break;
                        }
                    }
                    l--, r++;
                }
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
    string s = "tmvblwyunlbwywuuqgewbohxylifcaynqoljpfjnspjogcmceymjokyyrsdmsqppimkdfjtewhhglnhseczeyquwfffkkujleozqihkfpxdeqnojlqzamhnmhseqleowxkrhzmsrsnayhookdqpptfxkfwixhrtdbpwzyfogliixuasokuesgsnvcprjzlrrysndvukidfdukpgihuagxqfeuirrdrgjayrossteehrqcgocgqxjhremnngrzitcbvdlapuypdkzvgoxedxvgceyudivakzpgxisvnlkbjhmzgcwtavgbufzqmgwlvxeqmbmvcnmxnkwobsmbyvzbyobmpxurmfsdydfmwajjrmirzgbglkqsxhobvekbguucvnmlmjlridskdauxlkapapopylbpormppxxeeavwxpwhedcuiuxplviuxmgumlzrfmhywxlgqmyjnitlmzksjaqoahrcmacooezuyvbtlgmklvvtrjvarhabxthlhhuyofkewlphznnyiqeactlmkomvjhzewgickvtxhuxgficebjlxpfnkzkaallvooegnjkimandnosgqfsjjhjkvlujqbqiifczeexewggdvsybeuyjjbacwiwmqavdfvajgdjldzwwamnmtvt";
    string t = "gignohodjlytmrdvfxsiwjzgcpjrgxcbuzvuwvxactmapoxiseswemrgqcrowztnwskpoqiaakjowzyndkriwmiilapasatwookngbqlsdjaqfblmfzmutzrdiqaozxtzjfeelswpzidajibnibnbrdzjzesxexxxtmrjkmjfuxldakaklohcfgniltrlfvrboqbtmstuimnmbicjwqiqpuevjfzvfjkjdjnebvlxqsosrtgkiwgtupnrvcungoxambphusdvevtdqsgujozuaofbdqvynpcbxlyokvuyrwtyyculkjcxweeodvajnapbhhnpyciessfsbppubkqkrvomduaiksdwhfwqmepkmtgzmzthfpbilrvxurbyygwluscmhuxfwwfarmlnkibbowwaaeffkwrrhnqvwdtsqpywenynaqackxzqmmdjonivdmycfwhnfhrnnurdpwyqptdroiicfyhdfxtggvjnvvcpdnhsrbqpcjtlgqmccywarghlheoaeshiyyhihirqtltsehcfwwakzjzvsgtnevmuceeqsicfkhuqqofjfbwodgwcgxvxtlgdxpllurhkyonkxcvdhnmccoskwkygvotgibntzcxuhyddgcpmatvcvdviiirpzdjlrvejqekeszkijpvhnoemggjxchiumvbbghmzlixiceevrolhlagrxuyeikyiuqzmxravrtkkwfinerbjnyhhorzmdwccwlggjxqrvrmxb";
    // string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    // string t = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    Solution S;
    cout << S.longestPalindrome(s, t) << endl;
    return 0;
}