#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> count;
        int ans = 0;
        for (string& curr : words){
            string temp = curr;
            swap(temp[0], temp[1]);
            if (count[temp]){
                count[temp]--;
                ans += 4;
            }
            else{
                count[curr]++;
            }
        }
        for (auto& [temp, c] : count){
            if (c > 0 && temp[0] == temp[1]){
                ans += 2;
                break;
            }
        }
        return ans;
    }
};

int main(){
    vector<string> words = {"lc","cl","gg"};
    // vector<string> words = {"ab","ty","yt","lc","cl","ab"};
    // vector<string> words = {"cc","ll","xx"};
    Solution S;
    cout << S.longestPalindrome(words) << endl;
    return 0;
}