#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0;
        int i = 0;
        int j = 0;
        int diff = 0;
        while(j < answerKey.length()){
            diff += (answerKey[j] == 'F');
            // cout << "i = " << i << ", j = " << j << ", diff = " << diff ;
            if (diff <= k){
                ans = max(ans, j - i + 1);
            }
            else{
                while(diff > k && i < answerKey.length()){
                    diff -= (answerKey[i] == 'F');
                    i++;
                }
            }
            j++;
            // cout << ", ans = " << ans << endl;
        }

        i = 0;
        j = 0;
        diff = 0;
        while(j < answerKey.length()){
            diff += (answerKey[j] == 'T');
            // cout << "i = " << i << ", j = " << j << ", diff = " << diff;
            if (diff <= k){
                ans = max(ans, j - i + 1);
            }
            else{
                while(diff > k && i < answerKey.length()){
                    diff -= (answerKey[i] == 'T');
                    i++;
                }
            }
            j++;
            // cout << ", ans = " << ans << endl;
        }
        return ans;
    }
};

int main(){
    // string answerKey = "TTFF";
    // int k = 2;
    string answerKey = "TTFTTFTT";
    int k = 1;
    Solution S;
    cout << S.maxConsecutiveAnswers(answerKey, k) << endl;
    return 0;
}