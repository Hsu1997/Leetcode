#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        long long ans = 0;
        unordered_map<char,int> count;
        for (char c : word2) count[c]++;
        int need_to_match = count.size();
        int s = word1.length();
        int start = 0;
        int end = 0;
        // find => [start, end)
        while(start < s){
            while(end < s && need_to_match > 0){
                count[word1[end]]--;
                if (count[word1[end]] == 0) need_to_match--;
                end++;
            }
            if (end == s && need_to_match > 0) return ans;
            if (need_to_match == 0){
                ans += (s - (end - 1));
                // cout << "(start, end) = (" << start << ", " << end-1 << "), ans + " << (s - (end - 1)) << endl;
            }
            count[word1[start]]++;
            if (count[word1[start]] == 1) need_to_match++;
            start++;
        }
        return ans;
    }
};

int main(){
    string word1 = "bcca";
    string word2 = "abc";
    // string word1 = "abcabc";
    // string word2 = "abc";
    // string word1 = "abcabc";
    // string word2 = "aaabc";
    Solution S;
    cout << S.validSubstringCount(word1, word2) << endl;
    return 0;
}