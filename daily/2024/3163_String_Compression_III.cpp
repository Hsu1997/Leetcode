#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string ans;
        int s = word.length();
        char temp = word[0];
        int count = 1;
        for (int i = 1; i < s; i++){
            if (count == 9 || word[i] != temp){
                ans += to_string(count) + temp;
                temp = word[i];
                count = 1;
            }
            else{
                count += 1;
            }
        }
        ans += to_string(count) + temp;
        return ans;
    }
};

int main(){
    string word = "abcde";
    // string word = "aaaaaaaaaaaaaabb";
    Solution S;
    cout << S.compressedString(word) << endl;
    return 0;
}