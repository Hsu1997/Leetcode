#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        string after_smallest(n, ' ');
        char temp = 'z' + 1;
        for (int i = n - 1; i >= 0; i--){
            temp = min(temp, s[i]);
            after_smallest[i] = temp;
        }
        stack<char> sta;
        string ans;
        int idx = 0;
        while(ans.length() < n){
            if (idx < n && (sta.empty() || after_smallest[idx] < sta.top())){
                sta.push(s[idx++]);
            }
            else{
                ans += sta.top();
                sta.pop();
            }
        }
        return ans;
    }
};

int main(){
    string s = "zza";
    // string s = "bac";
    // string s = "bdda";
    Solution S;
    cout << S.robotWithString(s) << endl;
    return 0;
}