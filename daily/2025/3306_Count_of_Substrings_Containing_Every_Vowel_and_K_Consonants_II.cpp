#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return morethank(word, k) - morethank(word, k+1);
    }
    long long morethank(string word, int k){
        int n = word.size();
        int start = 0, end = 0;
        int consonant = 0;
        unordered_map<char,int> vowel;
        long long ans = 0;
        while(end < n){
            char added = word[end];
            if (isvowel(added)) vowel[added]++;
            else consonant++;
            while(vowel.size() == 5 && consonant >= k){
                ans += n - end;
                char del = word[start];
                if (isvowel(del)){
                    vowel[del]--;
                    if (vowel[del] == 0) vowel.erase(del);
                }
                else consonant--;
                start++;
            }
            end++;
        }
        return ans;
    }
    bool isvowel(char c){return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';}
};

int main(){
    string word = "aeioqq";
    int k = 1;
    // string word = "aeiou";
    // int k = 0;
    // string word = "ieaouqqieaouqq";
    // int k = 1;
    // string word = "iqeaouqi";
    // int k = 2;
    Solution S;
    cout << S.countOfSubstrings(word, k) << endl;
    return 0;
}