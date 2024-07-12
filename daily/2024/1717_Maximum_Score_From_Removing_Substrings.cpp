#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int start = 0;
        int end = 0;
        int ans = 0;
        char better = (x < y)? 'b' : 'a';
        while(start < n){
            if (s[start] != 'a' && s[start] != 'b') start++;
            else{
                end = start;
                while(end < n && (s[end] == 'a' || s[end] == 'b')) end++;
                int temp_max_count = 0;
                for (int i = start; i < end; i++) temp_max_count += (s[i] == 'a');
                temp_max_count = min(temp_max_count, end - start - temp_max_count);
                int temp_better_count = 0;
                int temp_better_comfirm = 0;
                for (int i = start; i < end; i++){
                    if (s[i] == better) temp_better_count++;
                    else{
                        if (temp_better_count) temp_better_comfirm++, temp_better_count--;
                    }
                }
                ans += temp_better_comfirm * max(x,y) + (temp_max_count - temp_better_comfirm) * min(x, y);
                start = end + 1;
            }
        }
        return ans;
    }
};

int main(){
    string s = "cdbcbbaaabab";
    int x = 4;
    int y = 5;
    // string s = "aabbaaxybbaabb";
    // int x = 5;
    // int y = 4;
    Solution S;
    cout << S.maximumGain(s, x, y) << endl;
    return 0;
}