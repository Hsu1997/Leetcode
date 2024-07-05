#include <iostream>
#include <vector>

using namespace std;

class SummaryRanges {
public:
    vector<bool> v;
    SummaryRanges() {
        v.resize(1e4+1, 0);
    }
    
    void addNum(int value) {
        v[value] = true;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int start = 0;
        int end = 0;
        while(start < v.size()){
            if (!v[start]) start++;
            else{
                end = start;
                while(end < v.size()-1 && v[end]) end++;
                ans.push_back({start, end-1});
                start = end;
            }
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

void print_vv(const vector<vector<int>>& v) {
    for (auto& i : v) cout << "[" << i[0] << "," << i[1] << "]" << " ";
    cout << endl;
}

int main(){
    SummaryRanges* summaryRanges = new SummaryRanges();
    summaryRanges->addNum(1);      // arr = [1]
    print_vv(summaryRanges->getIntervals()); // return [[1, 1]]
    summaryRanges->addNum(3);      // arr = [1, 3]
    print_vv(summaryRanges->getIntervals()); // return [[1, 1], [3, 3]]
    summaryRanges->addNum(7);      // arr = [1, 3, 7]
    print_vv(summaryRanges->getIntervals()); // return [[1, 1], [3, 3], [7, 7]]
    summaryRanges->addNum(2);      // arr = [1, 2, 3, 7]
    print_vv(summaryRanges->getIntervals()); // return [[1, 3], [7, 7]]
    summaryRanges->addNum(6);      // arr = [1, 2, 3, 6, 7]
    print_vv(summaryRanges->getIntervals()); // return [[1, 3], [6, 7]]
    return 0;
}