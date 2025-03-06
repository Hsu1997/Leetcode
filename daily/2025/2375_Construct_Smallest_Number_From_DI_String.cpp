#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        pattern = 'I' + pattern;
        int n = pattern.size();
        string ans;
        ans.reserve(n);
        int idx = 0;
        while (idx < n){
            int count = 0;
            while(idx + 1 < n && pattern[idx+1] == 'D') count++, idx++;
            int base = ans.size() + 1;
            while(count >= 0){
                ans.push_back('0' + base + count);
                count--;
            }
            idx++;
        }
        return ans;
    }
};

int main(){
    string pattern = "IIIDIDDD";
    // string pattern = "DDD";
    Solution S;
    cout << S.smallestNumber(pattern) << endl;
    return 0;
}