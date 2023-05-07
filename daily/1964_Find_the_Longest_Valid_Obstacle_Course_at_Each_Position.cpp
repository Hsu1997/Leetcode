#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
public:
    vector<int> s;

    FenwickTree(int n){
        s = vector<int>(n+1, 0);
    }

    void update(int n, int d){
        while(n < s.size()){
            s[n] = max(s[n], d);
            n += n & (-n);
        }
    }


    int query(int n){
        int ans = 0;
        while(n > 0){
            ans = max(ans, s[n]);
            n -= n & (-n);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        FenwickTree f(*max_element(obstacles.begin(), obstacles.end()));
        vector<int> ans;
        for (auto i : obstacles){
            int temp = f.query(i)+1;
            ans.push_back(temp);
            f.update(i,temp);
            // cout << i << " " << temp << endl;
        }
        return ans;
    }
};

int main(){
    // vector<int> obstacles = {1,2,3,2};
    // vector<int> obstacles = {2,2,1};
    vector<int> obstacles = {3,1,5,6,4,2};
    Solution S;
    vector<int> ans = S.longestObstacleCourseAtEachPosition(obstacles);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}