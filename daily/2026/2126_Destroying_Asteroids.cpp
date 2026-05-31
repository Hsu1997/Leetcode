#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m = mass;
        int mins[33];
        long long sums[33];
        fill(mins, mins + 33, INT_MAX);
        fill(sums, sums + 33, 0);
        for (int a : asteroids){
            int k = 32 - __builtin_clz(a);
            mins[k] = min(mins[k], a);
            sums[k] += a;
        }
        for (int i = 0; i < 33; i++){
            if (sums[i] == 0) continue;
            if (m < mins[i]) return false;
            m += sums[i];
        }
        return true;
    }
};

int main(){
    int mass = 10;
    vector<int> asteroids = {3,9,19,5,21};
    // int mass = 5;
    // vector<int> asteroids = {4,9,23,4};
    Solution S;
    cout << S.asteroidsDestroyed(mass, asteroids) << endl;
    return 0;
}