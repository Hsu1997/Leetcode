#include <iostream>
#include <vector>
#include <map>

using namespace std;

class MyCalendarTwo {
public:
    map<int,int> timeline;
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        int curr_event = 0;
        for (auto& [time, count] : timeline){
            curr_event += count;
            if (curr_event >= 3){
                timeline[start]--;
                timeline[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

int main(){
    MyCalendarTwo* myCalendarTwo = new MyCalendarTwo();
    cout << myCalendarTwo->book(10, 20) << " ";
    cout << myCalendarTwo->book(50, 60) << " ";
    cout << myCalendarTwo->book(10, 40) << " ";
    cout << myCalendarTwo->book(5, 15) << " ";
    cout << myCalendarTwo->book(5, 10) << " ";
    cout << myCalendarTwo->book(25, 55) << endl;
    return 0;
}