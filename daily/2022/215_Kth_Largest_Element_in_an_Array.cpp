#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    // O(n) find the kth largest number
    int findKthLargest(vector<int>& datas, int k){
        if (datas.size() <= 5){
            sort(datas.begin(), datas.end());
            return datas[datas.size() - k];
        }

        vector<int> group_of_midiums;
        vector<int> less_than_midium;
        vector<int> grather_than_midium;

        int group_num = ceil(datas.size() / 5);

        group_of_midiums.reserve(group_num);
        // less_than_midium.reserve(datas.size()/2+1);
        // grather_than_midium.reserve(datas.size()/2+1);

        while(datas.size() % 5 != 0){
            datas.push_back( numeric_limits<int>::min() );
        }

        for (int i = 0; i < group_num; i++){
            auto begin = datas.begin() + 5*i;
            sort(begin, begin + 5);
            group_of_midiums.push_back(*(begin + 2));
        }

        int medium;
        if (group_num == 1){
            medium = group_of_midiums.front();
        }
        else{
            medium = findKthLargest(group_of_midiums, group_of_midiums.size() / 2);
        }

        // divid to two group
        bool itself = true;
        for (int &data : datas){
            if (data > medium){
            grather_than_midium.push_back(data);
            }
            else if (data == medium && itself){
                itself = false;
            }
            else{
            less_than_midium.push_back(data);
            }

        }

        // cout << "less_than_midium : ";
        // for (auto i : less_than_midium) cout << i << " ";
        // cout << endl << "grather_than_midium : ";
        // for (auto i : grather_than_midium) cout << i << " ";
        // cout << endl;

        // two groups guarent that each subproblem has at least 1/4 size of original problem
        if (k <= grather_than_midium.size()){
            return findKthLargest(grather_than_midium, k);
        }
        else if (k == grather_than_midium.size() + 1){
            return medium;
        }
        else{
            return findKthLargest(less_than_midium, k - grather_than_midium.size() - 1);
        }
    }
};

int main(){
    // vector<int> nums = {3,2,1,5,6,4};
    // int k = 2;
    // vector<int> nums = {3,2,3,1,2,4,5,5,6};
    // int k = 4;
    // vector<int> nums = {7,6,5,4,3,2,1};
    // int k = 5;
    vector<int> nums = {3,3,3,3,3,3,3,3,3};
    int k = 8;
    Solution S;
    cout << S.findKthLargest(nums, k) << endl;
}