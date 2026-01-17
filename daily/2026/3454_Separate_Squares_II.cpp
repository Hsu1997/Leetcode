#include <iostream>
#include <vector>
#include <set>

using namespace std;

class SegmentTree{
public:
    SegmentTree(vector<int>& x_index){
        n = x_index.size() - 1;
        x = x_index;
        cnt.resize(4 * n, 0);
        covered.resize(4 * n, 0);
    }
    void update(int qleft, int qright, int qval){
        modify(qleft, qright, qval, 0, n - 1, 0);
    }
    long long query() {return covered[0];};
private:
    // interval amount
    int n;
    vector<int> x;
    vector<int> cnt;
    vector<long long> covered;
    void modify(int qleft, int qright, int qval, int leftInterval, int rightInterval, int posInterval){
        if (qleft >= x[rightInterval + 1] || qright <= x[leftInterval]) return;
        if (qleft <= x[leftInterval] && x[rightInterval + 1] <= qright) cnt[posInterval] += qval;
        else{
            int mid = (leftInterval + rightInterval) / 2;
            modify(qleft, qright, qval, leftInterval, mid, posInterval * 2 + 1);
            modify(qleft, qright, qval, mid + 1, rightInterval ,posInterval * 2 + 2);
        }
        // push up, update covered
        if (cnt[posInterval] > 0) covered[posInterval] = x[rightInterval + 1] - x[leftInterval];
        else{
            // cnt == 0, covered determined by child
            // no child
            if (leftInterval == rightInterval) covered[posInterval] = 0;
            else covered[posInterval] = covered[posInterval * 2 + 1] + covered[posInterval * 2 + 2];
        }
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int, int, int, int>> events;
        set<int> xSet;
        for (auto& square : squares){
            int x = square[0];
            int y = square[1];
            int l = square[2];
            events.push_back({y, 1, x, x + l});
            events.push_back({y + l, -1, x, x + l});
            xSet.insert(x);
            xSet.insert(x + l);
        }
        sort(events.begin(), events.end());
        vector<int> x(xSet.begin(), xSet.end());
        SegmentTree ST(x);
        vector<long long> accArea;
        vector<int> width;
        vector<int> yPos;
        long long total_area = 0.0;
        int prevY = get<0>(events[0]);
        for (auto& [y, delta, xl, xr] : events){
            if (y != prevY){
                int len = ST.query();
                accArea.push_back(total_area);
                yPos.push_back(prevY);
                total_area += 1LL * (y - prevY) * len;
                width.push_back(len);
            }
            ST.update(xl, xr, delta);
            prevY = y;
        }
        // accArea.push_back(total_area);
        // width.push_back(ST.query());
        // yPos.push_back(prevY);

        // for(auto i : yPos) cout << i << " ";
        // cout << endl;
        // for(auto i : width) cout << i << " ";
        // cout << endl;
        // for(auto i : accArea) cout << i << " ";
        // cout << endl;

        // last one is 0, count total and get over
        // find first one greater than or equal to (total / 2) and get previous one
        long long target = (total_area + 1) / 2;
        int i = lower_bound(accArea.begin(), accArea.end(), target) - accArea.begin() - 1;
        double area = accArea[i];
        double w = width[i];
        return (double)yPos[i] + ((double)total_area / 2 - area) / w;
    }
};

// class SegmentTree {
// public:
//     SegmentTree(vector<int>& xs_) : xs(xs_) {
//         n = xs.size() - 1;
//         count.resize(4 * n, 0);
//         covered.resize(4 * n, 0);
//     }
//     void update(int qleft, int qright, int qval) {
//         modify(qleft, qright, qval, 0, n - 1, 0);
//     }
//     int query() { return covered[0]; }
// private:
//     int n;
//     vector<int> xs;
//     vector<int> count;
//     vector<int> covered;

//     void modify(int qleft, int qright, int qval, int left, int right, int pos) {
//         if (xs[right + 1] <= qleft || xs[left] >= qright) {
//             return;
//         }
//         if (qleft <= xs[left] && xs[right + 1] <= qright) {
//             count[pos] += qval;
//         } 
//         else {
//             int mid = (left + right) / 2;
//             modify(qleft, qright, qval, left, mid, pos * 2 + 1);
//             modify(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
//         }

//         if (count[pos] > 0) {
//             covered[pos] = xs[right + 1] - xs[left];
//         } 
//         else {
//             if (left == right) {
//                 covered[pos] = 0;
//             } 
//             else {
//                 covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
//             }
//         }
//     }
// };

// class Solution {
// public:
//     double separateSquares(vector<vector<int>>& squares) {
//         vector<tuple<int, int, int, int>> events;
//         set<int> xsSet;

//         for (auto& sq : squares) {
//             int x = sq[0], y = sq[1], l = sq[2];
//             int xr = x + l;
//             events.emplace_back(y, 1, x, xr);
//             events.emplace_back(y + l, -1, x, xr);
//             xsSet.insert(x);
//             xsSet.insert(xr);
//         }

//         // sort events by y-coordinate
//         sort(events.begin(), events.end());
//         // discrete coordinates
//         vector<int> xs(xsSet.begin(), xsSet.end());
//         // initialize the segment tree
//         SegmentTree segTree(xs);

//         vector<double> psum;
//         vector<int> widths;
//         double total_area = 0.0;
//         int prev = get<0>(events[0]);

//         // scan: calculate total area and record intermediate states
//         for (auto& [y, delta, xl, xr] : events) {
//             int len = segTree.query();
//             total_area += 1LL * len * (y - prev);
//             segTree.update(xl, xr, delta);
//             // record prefix sums and widths
//             psum.push_back(total_area);
//             widths.push_back(segTree.query());
//             prev = y;
//         }

//         // calculate the target area (half rounded up)
//         long long target = (long long)(total_area + 1) / 2;
//         // find the first position greater than or equal to target using binary
//         // search
//         int i = lower_bound(psum.begin(), psum.end(), target) - psum.begin() - 1;
//         // get the corresponding area, width, and height
//         double area = psum[i];
//         int width = widths[i];
//         int height = get<0>(events[i]);

//         return height + (total_area - area * 2) / (width * 2.0);
//     }
// };

int main(){
    // vector<vector<int>> squares = {{0,0,1},{2,2,1}};
    vector<vector<int>> squares = {{0,0,2},{1,1,1}};
    Solution S;
    cout << S.separateSquares(squares) << endl;
    return 0;
}