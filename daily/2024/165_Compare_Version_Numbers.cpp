#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        string::iterator s1 = version1.begin();
        string::iterator s2 = version2.begin();
        while(s1 != version1.end() || s2 != version2.end()){
            int a = 0;
            int b = 0;
            while(s1 != version1.end() && *s1 != '.'){
                a = a * 10 + (*s1 - '0');
                s1++;
            }
            while(s2 != version2.end() && *s2 != '.'){
                b = b * 10 + (*s2 - '0');
                s2++;
            }
            if (*s1 == '.') s1++;
            if (*s2 == '.') s2++;
            // cout << a << " " << b << endl;
            if (a < b) return -1;
            else if (a > b) return 1;
            else continue;
        }
        return 0;
    }
};

int main(){
    // string version1 = "1.01";
    // string version2 = "1.001";
    // string version1 = "1.0";
    // string version2 = "1.0.0";
    // string version1 = "0.1";
    // string version2 = "1.1";
    string version1 = "1.2147483647";
    string version2 = "1.2147483647";
    Solution S;
    cout << S.compareVersion(version1, version2) << endl;
    return 0;
}