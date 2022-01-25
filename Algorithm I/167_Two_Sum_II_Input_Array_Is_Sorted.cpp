#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int a = 0;
        int b = numbers.size() - 1;
        int now = 0;
        vector<int> solution;
        while (a < b){
            now = numbers.at(a) + numbers.at(b);
            if (now < target){
                a++;
            }
            else if (now > target){
                b--;
            }
            else{
                solution.push_back(a+1);
                solution.push_back(b+1);
                return solution;
            }
        }
    };
};

int main(){
    int n[3] = {2,3,4};
    vector<int> numbers(n, n + sizeof(n) / sizeof(n[0]));
    int target = 6;
    Solution A;
    vector<int> ans;
    ans = A.twoSum(numbers, target);
    cout << ans[0] << " " << ans[1] << endl;
}