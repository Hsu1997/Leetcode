#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int table[10001] = {0};
        int max_num = 0;
        for (int i : nums){
            table[i] += i;
            max_num = max(i, max_num);
        }
        // think which method would like to use
        int back_one = 0;
        int back_two = 0;
        int size = nums.size();
        int current;
        if (max_num < size + size * log2(size)){
            back_one = table[1];
            for (int i = 2; i <= max_num; i++){
                current = back_one;
                back_one = max(table[i] + back_two, back_one);
                back_two = current;
            }
        }
        else{
            vector<int> key = {};
            for (int i = 0; i <= max_num; i++){
                if (table[i] != 0) key.push_back(i);
            }
            sort(key.begin(), key.end());
            back_one = table[key.at(0)];
            for (int i = 1; i < key.size(); i++){
                current = back_one;
                back_one = max(table[key.at(i)] + back_two, back_one);
                back_two = current;
            }
        }
        return back_one;
    }
};

int main(){
    vector<int> nums = {2,2,3,3,3,4};
    Solution S;
    cout << S.deleteAndEarn(nums) << endl;
    return 0;
}