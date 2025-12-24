#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0;
        for (int i : apple) total += i;
        sort(capacity.begin(), capacity.end(), greater<int>());
        int ans = 0;
        while(ans < capacity.size() && total > 0){
            total -= capacity[ans];
            ans++;
        }
        return ans;
    }
};

int main(){
    vector<int> apple = {1,3,2};
    vector<int> capacity = {4,3,1,5,2};
    // vector<int> apple = {5,5,5};
    // vector<int> capacity = {2,4,2,7};
    Solution S;
    cout << S.minimumBoxes(apple, capacity) << endl;
    return 0;
}