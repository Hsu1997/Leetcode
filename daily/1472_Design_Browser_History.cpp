#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BrowserHistory {
public:
    struct node{
        string url;
        node* next;
        node* front;
        node() {};
        node(string s) : url(s), next(nullptr), front(nullptr) {};
    };

    node* temp;
    BrowserHistory(string homepage) {
        temp = new node(homepage);
        // cout << temp->url << endl;
    }
    
    void visit(string url) {
        temp->next = new node(url);
        temp->next->front = temp;
        temp = temp->next;
        // cout << temp->url << endl;
        return;
    }
    
    string back(int steps) {
        while(steps--){
            if (temp->front) temp = temp->front;
            else break;
        }
        // cout << temp->url << endl;
        return temp->url;
    }
    
    string forward(int steps) {
        while(steps--){
            if (temp->next) temp = temp->next;
            else break;
        }
        // cout << temp->url << endl;
        return temp->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main(){
    BrowserHistory* browserHistory = new BrowserHistory("leetcode.com");
    browserHistory->visit("google.com");       // You are in "leetcode.com". Visit "google.com"
    browserHistory->visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
    browserHistory->visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
    browserHistory->back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
    browserHistory->back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
    browserHistory->forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
    browserHistory->visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
    browserHistory->forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
    browserHistory->back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
    browserHistory->back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
    return 0;
}