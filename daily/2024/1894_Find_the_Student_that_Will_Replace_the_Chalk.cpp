#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long acc = 0;
        for (int i : chalk) acc += i;
        k %= acc;
        for (int i = 0; i < chalk.size(); i++){
            k -= chalk[i];
            if (k < 0) return i;
        }
        return -1;
    }
};

int main(){
    vector<int> chalk = {5,1,5};
    int k = 22;
    // vector<int> chalk = {3,4,1,2};
    // int k = 25;
    Solution S;
    cout << S.chalkReplacer(chalk, k) << endl;
    return 0;
}