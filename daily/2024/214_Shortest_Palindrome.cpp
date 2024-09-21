#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool is_palindrome(string& s, int left, int right){
        int n = right - left + 1;
        if (n < 2) return true;
        int mid = left + n / 2;
        if (n % 2 == 0 && s[mid] != s[mid - 1]) return false;
        int p_left = mid - 1 - (n % 2 == 0);
        int p_right = mid + 1;
        while(p_left >= left && p_right <= right){
            if (s[p_left] != s[p_right]) return false;
            p_left--, p_right++;
        }
        return true;
    }
    string shortestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;
        for (int end = n - 1; end >= 0; end--){
            if (is_palindrome(s, 0, end)){
                // cout << "end = " << end << endl;
                string front = s.substr(end + 1);
                reverse(front.begin(), front.end());
                return front + s;
            }
        }
        string front = s;
        reverse(front.begin(), front.end());
        return front + s;
    }
};
// left------------right
// 0-------(4)---------8 n = 9
// 0------4-(5)--------9 n = 10

int main(){
    string s = "aacecaaa";
    Solution S;
    cout << S.shortestPalindrome(s) << endl;
    return 0;
}