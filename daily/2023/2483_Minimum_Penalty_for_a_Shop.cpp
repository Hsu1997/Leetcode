#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int count = 0;
        for (auto i : customers) count += (i == 'Y');
        int penalty = count;
        int best_penalty = count;
        int ans = 0;
        for (int i = 1; i <= n; i++){
            if (customers[i-1] == 'Y') penalty--;
            else penalty++;
            if (penalty < best_penalty) best_penalty = penalty, ans = i;
        }
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