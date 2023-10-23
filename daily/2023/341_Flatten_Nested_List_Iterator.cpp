#include <iostream>
#include <vector>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    vector<int> v;
    int ptr = 0;

    NestedIterator(vector<NestedInteger> &nestedList) {
        round(nestedList);
    }

    void round(const vector<NestedInteger> &nestedList){
        for (int i = 0; i < nestedList.size(); i++){
            if (nestedList[i].isInteger()) v.push_back(nestedList[i].getInteger());
            else round(nestedList[i].getList());
        }
    }
    
    int next() {
        return v[ptr++];
    }
    
    bool hasNext() {
        return ptr < v.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main(){
    return 0;
}