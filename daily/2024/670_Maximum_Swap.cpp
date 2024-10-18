#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        auto cmp = [](pair<int,int>& a, pair<int,int>& b){
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        int n = 0;
        vector<int> original;
        while(num){
            pq.push({num % 10, n});
            original.push_back(num % 10);
            num /= 10;
            n++;
        }
        int curr = n-1;
        while(!pq.empty()){
            auto [val, pos] = pq.top();
            pq.pop();
            if (pos == curr) curr--;
            else{
                int target = 0;
                while(original[target] != val) target++;
                swap(original[curr], original[target]);
                break;
            }
        }
        int ans = 0;
        for (int i = n-1; i >= 0; i--){
            ans = ans * 10 + original[i];
        }
        return ans;
    }
};

int main(){
    int num = 2763;
    // int num = 9973;
    Solution S;
    cout << S.maximumSwap(num) << endl;
    return 0;
}