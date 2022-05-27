#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while(num > 1){
            cout << num << endl;
            if (num % 2 == 0){
                num = num >> 1;
                ans++;
            }
            else{
                num = num >> 1;
                ans += 2;
            }
        }
        return (ans)? ans+1 : ans;
    }
};

int main(){
    int num = 14;
    Solution S;
    cout << S.numberOfSteps(num) << endl;
    return 0;
}