#include <iostream>
#include <vector>

using namespace std;

class MyCalendar {
public:
    struct event{
        int empty;
        int length;
        event* next = nullptr;
    };

    event* pseudo;

    MyCalendar() {
        event* root = new event{1,1000000000};
        pseudo = new event{0,-1,root};
    }
    
    bool book(int start, int end) {
        int time = 0;
        event* temp = pseudo;

        while(time <= start){
            if (temp->next->empty && time + temp->next->length >= end && time <= start){
                if (time != start){
                    event* front = new event{1,start-time,temp->next};
                    temp->next = front;
                    temp = temp->next;
                }
                event* now = new event{0,end-start,temp->next};
                temp->next = now;
                now->next->length -= (end-time);
                if (now->next->length == 0) now->next = now->next->next;
                return true;
            }
            else{
                temp = temp->next;
                time += temp->length;
            }
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main(){
    MyCalendar* cal = new MyCalendar();
    vector<vector<int>> book_event = {{10,20},{15,25},{20,30}};
    for (auto i : book_event) cout << cal->book(i[0], i[1]) << " ";
    cout << endl;
    return 0;
}