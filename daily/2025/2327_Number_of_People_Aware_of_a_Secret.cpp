#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1e9 + 7;
        vector<int> new_know(n + forget, 0);
        long long shared_acc = 0;
        long long know_acc = 0;
        new_know[0] = 1;
        know_acc = 1;
        for (int day = 1; day < n; day++){
            if (day - delay >= 0) shared_acc = (shared_acc + new_know[day - delay]) % mod;
            if (day - forget >= 0) shared_acc = (shared_acc - new_know[day - forget] + mod) % mod;
            new_know[day] = shared_acc;
            know_acc = (know_acc + new_know[day]) % mod;
            if (day - forget >= 0) know_acc = (know_acc - new_know[day - forget] + mod) % mod;
        }
        return know_acc;
    }
};

int main(){
    int n = 6;
    int delay = 2;
    int forget = 4;
    // int n = 4;
    // int delay = 1;
    // int forget = 3;
    // int n = 684;
    // int delay = 18;
    // int forget = 496;
    Solution S;
    cout << S.peopleAwareOfSecret(n, delay, forget) << endl;
    return 0;
}