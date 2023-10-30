#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int ans = 0;
        int round = minutesToTest/minutesToDie;
        while(pow((round+1), ans) < buckets) ans++;
        return ans;
    }
};

int main(){
    int buckets = 4;
    int minutesToDie = 15;
    // int minutesToTest = 15;
    int minutesToTest = 30;
    Solution S;
    cout << S.poorPigs(buckets, minutesToDie, minutesToTest) << endl;
    return 0;
}