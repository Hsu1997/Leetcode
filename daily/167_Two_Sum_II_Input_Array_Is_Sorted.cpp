#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        while(numbers[i] + numbers[j] != target){
            if (numbers[i] + numbers[j] < target) i++;
            else j--;
        }
        return {i+1, j+1};
    }
};

int main(){
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    Solution S;
    vector<int> ans = S.twoSum(numbers, target);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}