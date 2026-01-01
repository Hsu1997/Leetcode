import os
import sys
from typing import List
from collections import defaultdict

class Solution:
    def __init__(self):
        self.m = defaultdict(str)
        self.memo = defaultdict(str)

    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        for s in allowed:
            self.m[s[:2]] += s[-1]
        return self.dfs(bottom)
    
    def dfs(self, row) -> bool:
        n = len(row)
        if n == 1:
            self.memo[row] = True
            return True
        if row in self.memo:
            return self.memo[row]
        
        next_row = []
        curr = []
        self.buildNextRow(row, 0, curr, next_row)

        for nr in next_row:
            if self.dfs(nr):
                self.memo[row] = True
                return True
            
        self.memo[row] = False
        return False
    
    def buildNextRow(self, row, idx, curr, next_row) -> None:
        n = len(row)
        if idx == n - 1:
            next_row.append("".join(curr))
            return
        key = row[idx : idx+2]
        for c in self.m[key]:
            curr.append(c)
            self.buildNextRow(row, idx + 1, curr, next_row)
            curr.pop()

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            bottom = lines[0].split('=')[1].strip()[1:-2]
            allowed = list(lines[1].split('=')[1].strip()[2:-3].split('","'))
            dataset.append((bottom, allowed))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    for bottom, allowed in dataset:
        solution = Solution()
        results.append(solution.pyramidTransition(bottom, allowed))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')

# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)