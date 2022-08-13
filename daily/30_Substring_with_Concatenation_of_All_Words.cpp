#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int word_len = words[0].length();
        int word_number = words.size();
        if (s.length() < word_len * word_number) return ans;

        unordered_map<string, int> count;
        for (auto i : words) count[i]++;

        for (int i = 0; i <= s.length() - word_len * word_number; i++){
            // cout << i << " : ";
            unordered_map<string, int> temp = count;
            bool push = false;
            for (int j = i; j < i + word_len * word_number; j += word_len){
                string now = s.substr(j, word_len);
                // cout << now << " ";
                if (temp.find(now) == temp.end() || temp[now] < 1) break;
                else temp[now]--;
                if (j == i + word_len * (word_number - 1)) push = true;
            }
            if (push) ans.push_back(i);
            // cout << endl;
        }

        return ans;
    }
};

int main(){
    // string s = "barfoothefoobarman";
    // vector<string> words = {"foo", "bar"};

    // string s = "wordgoodgoodgoodbestword";
    // vector<string> words = {"word","good","best","word"};

    // string s = "barfoofoobarthefoobarman";
    // vector<string> words = {"bar","foo","the"};

    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};

    Solution S;
    vector<int> ans = S.findSubstring(s, words);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}