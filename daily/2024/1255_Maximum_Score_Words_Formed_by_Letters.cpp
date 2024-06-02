#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int ans = 0;

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26,0);
        for (auto i : letters) count[i-'a']++;
        dfs(words, score, count, 0, 0);
        return ans;
    }

private:
    void dfs(vector<string>& words, vector<int>& score, vector<int>& remain_char, int index, int s){
        if (index == words.size()){
            ans = max(ans, s);
            return;
        }
        dfs(words, score, remain_char, index + 1, s);
        vector<int> take_count = remain_char;
        int take_score = s;
        for (auto i : words[index]){
            take_count[i-'a']--;
            take_score += score[i-'a'];
            if (take_count[i-'a'] < 0) return;
        }
        dfs(words, score, take_count, index+1, take_score);
    }
};

int main(){
    vector<string> words = {"dog","cat","dad","good"};
    vector<char> letters = {'a','a','c','d','d','d','g','o','o'};
    vector<int> score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    // vector<string> words = {"xxxz","ax","bx","cx"};
    // vector<char> letters = {'z','a','b','c','x','x','x'};
    // vector<int> score = {4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10};
    // vector<string> words = {"leetcode"};
    // vector<char> letters = {'l','e','t','c','o','d'};
    // vector<int> score = {0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0};
    Solution S;
    cout << S.maxScoreWords(words, letters, score) << endl;
    return 0;
}