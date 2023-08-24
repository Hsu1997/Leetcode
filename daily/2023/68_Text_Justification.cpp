#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int index = 0;
        while(index < words.size()){
            int start = index;
            int word = 1;
            int acc_width = words[index].length();
            string temp = words[index];
            index++;
            // cout << "start at " << start << ", temp = " << temp << endl;
            while(index < words.size() && acc_width + words[index].length() < maxWidth){
                // cout << "add " << words[index] << endl;
                temp += " " + words[index];
                acc_width += words[index].length() + 1;
                index++, word++;
            }

            if (word == 1 || index == words.size()) temp += string(maxWidth-temp.length(), ' ');
            else{
                temp = "";
                int space = maxWidth;
                for (int i = start; i < index; i++) space -= words[i].length();
                for (int i = start; i < index-1; i++){
                    temp += words[i] + string(space/(word-1)+(space%(word-1) > 0), ' ');
                    space--;
                }
                temp += words[index-1];
            }
            // cout << "ans add " << temp << endl;
            ans.push_back(temp);
        }
        return ans;
    }
};

int main(){
    // vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> words = {"What","must","be","acknowledgment","shall","be"};
    int maxWidth = 16;
    Solution S;
    vector<string> ans = S.fullJustify(words, maxWidth);
    for (auto i : ans) cout << i << endl;
    return 0;
}