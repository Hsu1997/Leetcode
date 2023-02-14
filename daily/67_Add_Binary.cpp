#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    char exclusive_or(char a, char b, char c){
        // cout << a << " " << b << " " << c << " : " << ((a != b) != (c == '1')? true : false) << endl;
        return ((a != b) != (c == '1')? true : false)? '1' : '0';
    }

    char adder_int(char a, char b, char c){
        if ((a == b  && a == '1') || (b == c && b == '1') || (a == c && c == '1')) return '1';
        else return '0';
    }

    string addBinary(string a, string b) {
        int len_a = a.length();
        int len_b = b.length();
        int len = max(a.length(), b.length());
        a = string(len - len_a, '0') + a;
        b = string(len - len_b, '0') + b;
        // cout << a << endl << b << endl;
        string ans;
        char adder = '0';
        for (int i = len-1; i >= 0; i--){
            ans = exclusive_or(a[i], b[i], adder) + ans;
            adder = adder_int(a[i], b[i], adder);
        }
        if (adder == '1') ans = adder + ans;
        return ans;
    }
};

int main(){
    // string a = "11";
    // string b = "1";
    string a = "1010";
    string b = "1011";
    Solution S;
    cout << S.addBinary(a,b) << endl;
    return 0;
}