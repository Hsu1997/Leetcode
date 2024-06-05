#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> count(26);
        vector<int> current(26);
        for (int i = 0; i < words[0].length(); i++) count[words[0][i]-'a']++;
        for (int i = 1; i < words.size(); i++){
            fill(current.begin(), current.end(), 0);
            for (int j = 0; j < words[i].length(); j++) current[words[i][j]-'a']++;
            for (int k = 0; k < 26; k++) count[k] = min(count[k], current[k]);
        }
        for (int i = 0; i < 26; i++){
            for (int c = 0; c < count[i]; c++) ans.push_back(string(1,'a'+i));
        }
        return ans;
    }
};

int main(){
    vector<string> words = {"bella","label","roller"};
    // vector<string> words = {"cool","lock","cook"};
    Solution S;
    vector<string> ans = S.commonChars(words);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}