#include <iostream>

using namespace std;

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int output = 0;
        // the target can only delete the least significant bit 0 (division 2) or plus 1
        // if target bits is more than startvalue, we eliminate the bits as fast as possiable.
        while(target > startValue){
            // if target the least significant bit is 1, we only can plus 1.
            if (target % 2 != 0) target++;
            // if target the least significant bit is 0, we only can divide 2 (if we plus 1, than we need to plus 1 again, it cost 3 times to get Y/2 + 1; and we can divide 2 than plus 1 to get the same result but only cost 2 times operations.)
            else target /= 2;
            output++;
        }
        output += (startValue - target);
        return output;
        // if we want to get a smaller number, we have 2 choices:plus first and divide first:
        // (1) (Y + 2 * N) / 2 = Y/2 + N => 2N+1 times
        // (2) (Y) / 2 + 1 * N = Y/2 + N => 1N+1 times
        // So we always divide first.
    }
};

int main(){
    int startValue = 2;
    int target = 3;
    Solution S;
    cout << S.brokenCalc(startValue, target) << endl;
    return 0;
}