#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int check = 0;
        // cout << check << endl;
        for (auto i : sentence){
            check |= 1 << (i - 'a');
            if (check == (1 << 26) - 1) return true;
        }
        return false;
    }
};

int main(){
    string sentence = "thequickbrownfoxjumpsoverthelazydog";
    // string sentence = "leetcode";
    Solution S;
    cout << S.checkIfPangram(sentence) << endl;
    return 0;
}