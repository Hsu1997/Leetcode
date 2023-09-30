#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m;
        for (int i = 0; i < order.length(); i++) m[order[i]] = i;
        for (int i = 1; i < words.size(); i++){
            string& s1 = words[i-1];
            string& s2 = words[i];
            bool legel = false;
            for (int k = 0; k < min(s1.length(),s2.length()); k++){
                if (m[s1[k]] > m[s2[k]]) return false;
                if (m[s1[k]] < m[s2[k]]){
                    legel = true;
                    break;
                }
            }
            if (!legel && s1.length() > s2.length()) return false;
        }
        return true;
    }
};

int main(){
    // vector<string> words = {"hello","leetcode"};
    // string order = "hlabcdefgijkmnopqrstuvwxyz";
    // vector<string> words = {"word","world","row"};
    // string order = "worldabcefghijkmnpqstuvxyz";
    vector<string> words = {"apple","app"};
    string order = "abcdefghijklmnopqrstuvwxyz";
    Solution S;
    cout << S.isAlienSorted(words, order) << endl;
    return 0;
}