#include <iostream>
#include <vector>

using namespace std;

class MyCalendar {
public:
    vector<pair<int,int>> calendar;

    MyCalendar() {}

    // find the first position greater than or equal to the start
    int find_pos(int start, int end){
        int l = 0;
        int r = calendar.size() - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if (calendar[mid].first < start) l = mid + 1;
            else r = mid;
        }
        return r;
    }
    bool book(int start, int end) {
        int n = calendar.size();
        int pos;
        if (calendar.empty() || start > calendar.back().first) pos = n;
        else pos = find_pos(start, end);
        if (pos < n && calendar[pos].first < end) return false;
        if (pos - 1 >= 0 && calendar[pos-1].second > start) return false;
        calendar.insert(calendar.begin() + pos, {start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main(){
    MyCalendar* myCalendar = new MyCalendar();
    // cout << myCalendar->book(10, 20) << " ";
    // cout << myCalendar->book(15, 25) << " ";
    // cout << myCalendar->book(20, 30) << " ";
    
    cout << myCalendar->book(48, 50) << " ";
    cout << myCalendar->book(0, 6) << " ";
    cout << myCalendar->book(6, 13) << " ";
    cout << myCalendar->book(8, 13) << " ";
    cout << myCalendar->book(15, 23) << " ";
    cout << myCalendar->book(49, 50) << " ";
    cout << myCalendar->book(45, 50) << " ";
    cout << myCalendar->book(29, 34) << " ";
    cout << myCalendar->book(3, 12) << " ";
    cout << myCalendar->book(38, 44) << " ";
    cout << endl;
    return 0;
}