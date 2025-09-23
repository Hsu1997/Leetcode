#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr1 < version1.length() || ptr2 < version2.length()){
            string num1;
            string num2;
            while(ptr1 < version1.length() && version1[ptr1] != '.'){
                num1 += version1[ptr1];
                ptr1++;
            }
            while(ptr2 < version2.length() && version2[ptr2] != '.'){
                num2 += version2[ptr2];
                ptr2++;
            }
            int n1 = 0;
            if (!num1.empty()) n1 = stoi(num1);
            int n2 = 0;
            if (!num2.empty()) n2 = stoi(num2);
            if (n1 < n2) return -1;
            else if (n1 > n2) return 1;
            ptr1++;
            ptr2++;
        }
        return 0;
    }
};

int main(){
    string version1 = "1.2";
    string version2 = "1.10";
    // string version1 = "1.01";
    // string version2 = "1.001";
    // string version1 = "1.0";
    // string version2 = "1.0.0.0";
    Solution S;
    cout << S.compareVersion(version1, version2) << endl;
    return 0;
}