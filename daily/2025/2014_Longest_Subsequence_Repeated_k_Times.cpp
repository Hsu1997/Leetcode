#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string& s, string& sub, int k){
        int pos = 0;
        int cnt = 0;
        for (char c : s){
            if (c == sub[pos]) pos++;
            if (pos == sub.length()){
                cnt++;
                if (cnt == k) return true;
                pos = 0;
            }
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;
        vector<char> candidate;
        queue<string> que;
        for (int i = 25; i >= 0; i--) if (count[i] >= k){
            candidate.push_back('a' + i);
            que.push(string(1, 'a' + i));
        }
        string ans = "";
        while(!que.empty()){
            string curr = que.front();
            que.pop();
            if (curr.length() > ans.length()) ans = curr;
            for (char c : candidate){
                string temp = curr + c;
                if (isSubsequence(s, temp, k)) que.push(temp);
            }
        }
        return ans;
    }
};

int main(){
    string s = "letsleetcode";
    int k = 2;
    // string s = "bb";
    // int k = 2;
    // string s = "ab";
    // int k = 2;
    Solution S;
    cout << S.longestSubsequenceRepeatedK(s, k) << endl;
    return 0;
}