#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ans(n,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i = 0; i < n; i++) pq.push({ratings[i],i});
        while(!pq.empty()){
            auto [rate, index] = pq.top();
            pq.pop();
            int temp = 1;
            if (index-1 >= 0 && ratings[index-1] < rate) temp = max(temp, ans[index-1]+1);
            if (index+1 < n && ratings[index+1] < rate) temp = max(temp, ans[index+1]+1);
            ans[index] = temp;
            // cout << "index " << index << " = " << temp << endl;
        }

        int a = 0;
        for (auto i : ans){
            // cout << i << " ";
            a += i;
        }
        // cout << endl;
        return a;
    }
};

int main(){
    vector<int> ratings = {1,0,2};
    // vector<int> ratings = {1,2,2};
    Solution S;
    cout << S.candy(ratings) << endl;
    return 0;
}