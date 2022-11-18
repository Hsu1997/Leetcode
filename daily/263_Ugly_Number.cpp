#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        vector<int> prime = {2,3,5};
        for (auto i : prime){
            while(n > 1 && n % i == 0) n /= i;
        }
        return (n == 1)? true : false;
    }
};

int main(){
    // int n = 6;
    int n = 14;
    Solution S;
    cout << S.isUgly(n) << endl;
    return 0;
}