#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        unordered_set<string> s;

        for (int i = 1; i <= str1.length(); i++){
            if (str1.length() % i != 0) continue;
            string divisor = str1.substr(0, i);
            bool is_divisor = true;
            for (int start = i; start < str1.length(); start += i){
                if (str1.substr(start, i) != divisor){
                    is_divisor = false;
                    break;
                }
            }
            if (is_divisor) s.insert(divisor);
        }
        // for (auto i : s) cout << i << endl;
        
        string ans = "";

        for (int i = 1; i <= str2.length(); i++){
            if (str2.length() % i != 0) continue;
            string divisor = str2.substr(0, i);
            bool is_divisor = true;
            for (int start = i; start < str2.length(); start += i){
                if (str2.substr(start, i) != divisor){
                    is_divisor = false;
                    break;
                }
            }
            if (is_divisor && s.find(divisor) != s.end()) ans = divisor;
        }

        return ans;
    }
};

int main(){
    string str1 = "ABCABC";
    string str2 = "ABC";
    // string str1 = "ABABAB";
    // string str2 = "AB";
    // string str1 = "LEET";
    // string str2 = "CODE";
    Solution S;
    cout << S.gcdOfStrings(str1, str2) << endl;
    return 0;
}