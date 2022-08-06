#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int round = minutesToTest / minutesToDie;
        int ans = 0;
        while (pow((round+1),ans) < buckets) ans++;
        return ans;
    }
};

int main(){
    // int buckets = 1000;
    // int minutesToDie = 15;
    // int minutesToTest = 60;
    int buckets = 4;
    int minutesToDie = 15;
    int minutesToTest = 30;
    Solution S;
    cout << S.poorPigs(buckets, minutesToDie, minutesToTest) << endl;
    return 0;
}