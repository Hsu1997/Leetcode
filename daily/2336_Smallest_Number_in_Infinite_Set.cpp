#include <iostream>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

class SmallestInfiniteSet {
public:
    int smallest = 1;
    set<int> s;

    SmallestInfiniteSet() {
    }
    
    int popSmallest() {
        int ans;
        if (s.empty()){
            ans = smallest;
            smallest++;
        }
        else{
            ans = *s.begin();
            s.erase(ans);
        }
        return ans;
    }
    
    void addBack(int num) {
        if (num >= smallest || s.count(num)) return;
        else s.insert(num);
    }
};

int main(){
    SmallestInfiniteSet* smallestInfiniteSet = new SmallestInfiniteSet();
    smallestInfiniteSet->addBack(2);                    // 2 is already in the set, so no change is made.
    cout << smallestInfiniteSet->popSmallest() << endl; // return 1, since 1 is the smallest number, and remove it from the set.
    cout << smallestInfiniteSet->popSmallest() << endl; // return 2, and remove it from the set.
    cout << smallestInfiniteSet->popSmallest() << endl; // return 3, and remove it from the set.
    smallestInfiniteSet->addBack(1);                     // 1 is added back to the set.
    cout << smallestInfiniteSet->popSmallest() << endl; // return 1, since 1 was added back to the set and is the smallest number, and remove it from the set.
    cout << smallestInfiniteSet->popSmallest() << endl; // return 4, and remove it from the set.
    cout << smallestInfiniteSet->popSmallest() << endl; // return 5, and remove it from the set.
    return 0;
}