#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target){
        int head = 0;
        int tail = nums.size()-1;
        while(tail - head > 1){
            if (nums.at(head + (tail-head)/2) > target) tail = head + (tail-head)/2 - 1;
            else if (nums.at(head + (tail-head)/2) == target) return head + (tail-head)/2;
            else head += (tail-head)/2 + 1;
        }
        if (nums.at(head) == target) return head;
        else if (nums.at(tail) == target) return tail;
        else return -1;
    };
};

int main(){
    int n[6] = {-1,0,3,5,9,12};
    vector<int> nums(n, n + 6);
    Solution A;
    cout << A.search(nums, 9) << endl;
}