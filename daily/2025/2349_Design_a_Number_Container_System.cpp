#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class NumberContainers {
public:
    unordered_map<int,int> m;
    unordered_map<int,set<int>> i;
    
    NumberContainers() {}
    
    void change(int index, int number) {
        m[index] = number;
        i[number].insert(index);
    }
    
    int find(int number) {
        while(!i[number].empty()){
            int min_index = *i[number].begin();
            if (m[min_index] != number) i[number].erase(min_index);
            else return min_index;
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

int main(){
    NumberContainers* nc = new NumberContainers();
    cout << nc->find(10) << " "; // There is no index that is filled with number 10. Therefore, we return -1.
    nc->change(2, 10); // Your container at index 2 will be filled with number 10.
    nc->change(1, 10); // Your container at index 1 will be filled with number 10.
    nc->change(3, 10); // Your container at index 3 will be filled with number 10.
    nc->change(5, 10); // Your container at index 5 will be filled with number 10.
    cout << nc->find(10) << " "; // Number 10 is at the indices 1, 2, 3, and 5. Since the smallest index that is filled with 10 is 1, we return 1.
    nc->change(1, 20); // Your container at index 1 will be filled with number 20. Note that index 1 was filled with 10 and then replaced with 20. 
    cout << nc->find(10) << " "; // Number 10 is at the indices 2, 3, and 5. The smallest index that is filled with 10 is 2. Therefore, we return 2.
    cout << endl;
    return 0;
}