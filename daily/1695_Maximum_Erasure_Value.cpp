#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int>::iterator a = nums.begin();
        vector<int>::iterator b = nums.begin();
        int ans = 0;
        int temp = 0;
        vector<int> count(10001, 0);
        while(a != nums.end()){
            temp += *a;
            count[*a]++;
            while(count[*a] > 1){
                temp -= *b;
                count[*b]--;
                b++;
            }  
            ans = max(ans, temp);
            // cout << ans << endl;
            a++;
        }
        
        return ans;
    }
};

int main(){
    vector<int> nums = {4,2,4,5,6};
    Solution S;
    cout << S.maximumUniqueSubarray(nums) << endl;
    return 0;
}