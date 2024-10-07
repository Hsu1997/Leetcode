#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> trans(string s){
        vector<string> v;
        int index = 0;
        int n = s.length();
        while(index < n){
            int start = index;
            int end = index;
            while(end < n && s[end] != ' ') end++;
            v.push_back(s.substr(start, end - start));
            index = end + 1;
        }
        return v;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1 = trans(sentence1);
        vector<string> s2 = trans(sentence2);
        if (s1.size() > s2.size()) swap(s1, s2);
        int i = 0;
        int j = s1.size() - 1;
        int diff = s2.size() - s1.size();
        while(i < s1.size() && s1[i] == s2[i]) i++;
        while(j >= 0 && s1[j] == s2[j+diff]) j--;
        return i > j;
    }
};

int main(){
    string sentence1 = "My name is Haley";
    string sentence2 = "My Haley";
    // string sentence1 = "of";
    // string sentence2 = "A lot of words";
    // string sentence1 = "Eating right now";
    // string sentence2 = "Eating";
    Solution S;
    cout << S.areSentencesSimilar(sentence1, sentence2) << endl;
    return 0;
}