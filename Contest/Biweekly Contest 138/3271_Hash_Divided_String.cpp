#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string stringHash(string s, int k) {
        string ans;
        for (int i = 0; i < s.length(); i+=k){
            int temp = 0;
            for (int j = 0; j < k; j++){
                temp += (s[i+j]-'a');
            }
            temp %= 26;
            ans += 'a' + temp;
        }
        return ans;
    }
};

int main(){
    string s = "abcd";
    int k = 2;
    // string s = "mxz";
    // int k = 3;
    Solution S;
    cout << S.stringHash(s, k) << endl;
    return 0;
}