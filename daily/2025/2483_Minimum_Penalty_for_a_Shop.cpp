#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int penalty = 0;
        int ans = 0;
        int min_penalty = penalty;
        for (int i = 1; i <= n; i++){
            if (customers[i-1] == 'Y') penalty--;
            else penalty++;
            if (penalty < min_penalty){
                ans = i;
                min_penalty = penalty;
            }
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