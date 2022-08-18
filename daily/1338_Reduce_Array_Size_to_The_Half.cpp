#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> m;
        for (auto i : arr) m[i]++;
        
        priority_queue<int> pq;
        for (auto i : m) pq.push(i.second);
        int temp = 0;
        int ans = 0;
        while(temp < arr.size()/2){
            temp += pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {3,3,3,3,5,5,5,2,2,7};
    // vector<int> arr = {7,7,7,7,7,7};
    Solution S;
    cout << S.minSetSize(arr) << endl;
    return 0;
}