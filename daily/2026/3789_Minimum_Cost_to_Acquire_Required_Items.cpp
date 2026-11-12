#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (cost1 + cost2 <= costBoth) return 1LL * cost1 * need1 + 1LL * cost2 * need2;
        long long ans = 1LL * min(need1, need2) * costBoth;
        long long res = max(1LL * (need1 - min(need1, need2)) * min(costBoth, cost1), 1LL * (need2 - min(need1, need2)) * min(costBoth, cost2));
        return ans + res;
    }
};

int main(){
    int cost1 = 3;
    int cost2 = 2;
    int costBoth = 1;
    int need1 = 3;
    int need2 = 2;
    // int cost1 = 5;
    // int cost2 = 4;
    // int costBoth = 15;
    // int need1 = 2;
    // int need2 = 3;
    // int cost1 = 5;
    // int cost2 = 4;
    // int costBoth = 15;
    // int need1 = 0;
    // int need2 = 0;
    // int cost1 = 50;
    // int cost2 = 55;
    // int costBoth = 72;
    // int need1 = 5;
    // int need2 = 3;
    // int cost1 = 388168;
    // int cost2 = 988887;
    // int costBoth = 336014;
    // int need1 = 50411;
    // int need2 = 252237;
    Solution S;
    cout << S.minimumCost(cost1, cost2, costBoth, need1, need2) << endl;
    return 0;
}