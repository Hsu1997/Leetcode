#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        int i = 1;
        if (sentence[0] != sentence.back()) return false;
        while(i < n){
            while(i < n && sentence[i] != ' ') i++;
            if (i >= n-1) break;
            if (sentence[i-1] != sentence[i+1]) return false;
            i++;
        }
        return true;
    }
};

int main(){
    string sentence = "leetcode exercises sound delightful";
    // string sentence = "eetcode";
    // string sentence = "Leetcode is cool";
    Solution S;
    cout << S.isCircularSentence(sentence) << endl;
    return 0;
}