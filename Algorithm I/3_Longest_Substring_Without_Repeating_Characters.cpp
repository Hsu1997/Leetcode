#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int number = 0;
        int count[128] {0};
        // front point to the first char of the substring
        string::iterator front = s.begin();
        
        for (string::iterator c = s.begin(); c != s.end(); c++){
            if (count[(int)*c] == 0){
                count[(int)*c]++;
                ans = max(ans, ++number);
                // cout << *c << " : " << ans << ",number = " << number << endl;
            }
            else{
                while( *front != *c){
                    count[(int)*front]--;
                    number--;
                    front++;
                }
                front++;
                // cout << *c << " : " << ans << ",number = " << number << endl;
            }
        }
        return ans;
    }
};

int main(){
    string s = "aabaab!bb";
    Solution A;
    cout << A.lengthOfLongestSubstring(s) << endl;
    return 0;
}