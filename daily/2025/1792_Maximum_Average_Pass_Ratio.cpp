#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [&](int c){
            double p = classes[c][0];
            double t = classes[c][1];
            return (p + 1.0) / (t + 1.0) - p / t;
        };
        auto compare = [&](int s1, int s2){
            return gain(s1) < gain(s2);
        };
        auto cmp2 = [&](int s1, int s2){
            long long p1 = classes[s1][0];
            long long t1 = classes[s1][1];
            long long p2 = classes[s2][0];
            long long t2 = classes[s2][1];
            long long l = (t1 - p1) * t2 * (t2 + 1);
            long long r = (t2 - p2) * t1 * (t1 + 1);
            return l < r;
        };
        // priority_queue<int, vector<int>, decltype(compare)> pq(compare);
        priority_queue<int, vector<int>, decltype(cmp2)> pq(cmp2);
        for (int i = 0; i < classes.size(); i++) pq.push(i);
        while(extraStudents--){
            int curr = pq.top();
            pq.pop();
            classes[curr][0]++;
            classes[curr][1]++;
            pq.push(curr);
        }
        double ans = 0;
        for (auto c : classes){
            ans += (double)c[0] / c[1];
        }
        ans /= classes.size();
        return ans;
    }
};

int main(){
    vector<vector<int>> classes = {{1,2},{3,5},{2,2}};
    int extraStudents = 2;
    // vector<vector<int>> classes = {{2,4},{3,9},{4,5},{2,10}};
    // int extraStudents = 4;
    Solution S;
    cout << S.maxAverageRatio(classes, extraStudents) << endl;
    return 0;
}