#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26,0);
        vector<int> target(26,0);
        for (auto i : s1) target[i-'a']++;
        int target_len = s1.length();
        int count_len = 0;
        int n = s2.length();
        int start = 0;
        for (int i = 0; i < n; i++){
            if (target[s2[i]-'a'] == 0){
                while(start <= i){
                    if (target[s2[start]-'a'] != 0) count[s2[start]-'a']--,count_len--;
                    start++;
                }
            }
            else{
                while(count[s2[i]-'a'] >= target[s2[i]-'a']){
                    count[s2[start]-'a']--;
                    count_len--;
                    start++;
                }
                count_len++;
                count[s2[i]-'a']++;
                if (count_len == target_len) return true;
            }
        }
        return false;
    }
};

int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";
    // string s2 = "eidboaoo";
    Solution S;
    cout << S.checkInclusion(s1, s2) << endl;
    return 0;
}