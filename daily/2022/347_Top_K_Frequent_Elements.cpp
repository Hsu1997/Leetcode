#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void print_pair_vector(vector<pair<int, int> > &vec){
    for (auto i : vec) cout << i.first << " : " << i.second << "   ";
    cout << endl;
}

// greater is > and sort from max to min
// less is < and sort from min to max
// min heap use ">" ; max heap use "<"
struct greater_pair{
    bool operator()(pair<int, int> a, pair<int, int> b) const{
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int i : nums) count[i]++;

        vector< pair<int, int> > heap;
        for (auto &i : count){
            if (heap.size() < k){
                heap.push_back(make_pair(i.first, i.second));
                
                if(heap.size() == k){
                    make_heap(heap.begin(), heap.end(), greater_pair());
                    // cout << "after sort" << endl;
                    // print_pair_vector(heap);
                }
                continue;
            }
            else{
                if (i.second > heap.front().second){
                    heap.push_back(make_pair(i.first, i.second));
                    push_heap(heap.begin(), heap.end(), greater_pair());
                    pop_heap(heap.begin(), heap.end(), greater_pair());
                    heap.pop_back();
                    // print_pair_vector(heap);
                }
            }
        }
        vector<int> ans;
        for (auto i : heap) ans.push_back(i.first);
        return ans;
    }
};

int main(){
    vector<int> nums = {1,1,1,1,1,1,2,2,2,2,2,3,3,3,3,4,4,4,5,5,6};
    int k = 4;
    Solution S;
    vector<int> ans = S.topKFrequent(nums, k);
    for(auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}