#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int get_status(int count_a, int count_b){
        return ((count_a % 2) << 1) + (count_b % 2);
    }

    int maxDifference(string s, int k) {
        int n = s.length();
        int ans = INT_MIN;
        for (char first = '0'; first <= '4'; first++){
            for (char second = '0'; second <= '4'; second++){
                if (first == second) continue;
                int first_acc = 0;
                int second_acc = 0;
                int first_prev = 0;
                int second_prev = 0;
                int best_prev_acc[4] = {INT_MAX, INT_MAX, INT_MAX ,INT_MAX};
                int left = -1;
                for (int right = 0; right < n; right++){
                    first_acc += (s[right] == first);
                    second_acc += (s[right] == second);
                    while(right - left >= k && second_acc - second_prev >= 2){
                        int prev_status = get_status(first_prev, second_prev);
                        best_prev_acc[prev_status] = min(best_prev_acc[prev_status], first_prev - second_prev);
                        left++;
                        first_prev += (s[left] == first);
                        second_prev += (s[left] == second);
                    }
                    int curr_status = get_status(first_acc, second_acc);
                    if (best_prev_acc[curr_status ^ 2] != INT_MAX){
                        ans = max(ans, first_acc - second_acc - best_prev_acc[curr_status ^ 2]);
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    string s = "12233";
    int k = 4;
    // string s = "1122211";
    // int k = 3;
    // string s = "110";
    // int k = 3;
    Solution S;
    cout << S.maxDifference(s, k) << endl;
    return 0;
}