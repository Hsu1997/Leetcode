#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int cnt_y = 0;
        int cnt_n = 0;
        for (char c : customers) if (c == 'Y') cnt_y++;
        int ans = -1;
        int min_penalty = n;
        for (int i = 0; i < n; i++){
            if (cnt_y + cnt_n < min_penalty){
                ans = i;
                min_penalty = cnt_y + cnt_n;
            }
            cnt_y -= (customers[i] == 'Y');
            cnt_n += (customers[i] == 'N');
        }
        if (cnt_n < min_penalty) ans = n;
        return ans;
    }
};

int main(){
    string customers = "YYNY";
    // string customers = "NNNNN";
    // string customers = "YYYY";
    Solution S;
    cout << S.bestClosingTime(customers) << endl;
    return 0;
}