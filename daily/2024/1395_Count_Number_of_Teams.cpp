#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class BIT {
public:
    BIT(vector<int>& nums){
        n = nums.size();
        tree = vector<int>(n+1, 0);
        for (int i = 0; i < n; i++) update(i, nums[i]);
    }
    void update(int index, int value){
        index++;
        while(index <= n){
            tree[index] += value;
            index += index & -index;
        }
    }
    int query(int index){
        index++;
        int ans = 0;
        while(index > 0){
            ans += tree[index];
            index -= index & -index;
        }
        return ans;
    }
    int range_query(int left, int right) {return query(right) - query(left - 1);}
private:
    int n;
    vector<int> tree;
};

class Solution {
public:
    int numTeams(vector<int>& rating){
        int n = rating.size();
        int M = *max_element(rating.begin(), rating.end());
        vector<int> count(M+1, 0);
        BIT left_BIT(count);
        BIT right_BIT(count);
        for (auto i : rating) right_BIT.update(i, 1);
        int ans = 0;
        for (int middle_index = 0; middle_index < n; middle_index++){
            int num = rating[middle_index];
            right_BIT.update(num, -1);
            int left_smaller = left_BIT.range_query(1, num - 1);
            // int left_larger = left_BIT.range_query(num + 1, M);
            int left_larger = middle_index - left_smaller;
            int right_smaller = right_BIT.range_query(1, num - 1);
            // int right_larger = right_BIT.range_query(num + 1, M);
            int right_larger = n - 1 - middle_index - right_smaller;
            ans += left_smaller * right_larger + left_larger * right_smaller;
            left_BIT.update(num, 1);
        }
        return ans;
    }
};

// class Solution {
// public:
//     int numTeams(vector<int>& rating) {
//         int ans = 0;
//         ans += count(rating);
//         reverse(rating.begin(), rating.end());
//         ans += count(rating);
//         return ans;
//     }
//     int count(vector<int>& rating) {
//         int ans = 0;
//         map<int,int> m1;
//         map<int,int> m2;
//         for (int num : rating){
//             // cout << num << " : " << endl;
//             for (auto i : m2){
//                 if (i.first >= num) break;
//                 ans += i.second;
//             }
//             m1[num] = 1;
//             int temp = 0;
//             for (auto i : m1){
//                 if (i.first >= num) break;
//                 temp += i.second;
//             }
//             m2[num] = temp;
//             // cout << "ans = " << ans << endl;
//         }
//         return ans;
//     }
// };

int main(){
    vector<int> rating = {2,5,3,4,1};
    // vector<int> rating = {2,1,3};
    // vector<int> rating = {1,2,3,4};
    Solution S;
    cout << S.numTeams(rating) << endl;
    return 0;
}