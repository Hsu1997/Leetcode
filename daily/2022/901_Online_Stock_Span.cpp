#include <iostream>
#include <vector>

using namespace std;

class StockSpanner {
public:
    vector<int> p;
    vector<int> acc;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        int n = p.size()-1;
        int temp = n;
        
        while(temp >= 0 && price >= p[temp]){
            count += acc[temp];
            temp -= acc[temp];
        }

        p.push_back(price);
        acc.push_back(count);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main(){
    StockSpanner* S = new StockSpanner();
    cout << S->next(100) << endl;
    cout << S->next(80) << endl;
    cout << S->next(60) << endl;
    cout << S->next(70) << endl;
    cout << S->next(60) << endl;
    cout << S->next(75) << endl;
    cout << S->next(85) << endl;
    return 0;
}