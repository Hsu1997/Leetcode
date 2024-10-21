import os
import sys

class Solution:
    def recursion(self, s, i, curr, substr):
        if i == len(s):
            if curr not in substr:
                self.ans = max(self.ans, len(substr) + 1)
            return
        if curr and curr not in substr:
            substr.append(curr)
            self.recursion(s, i+1, s[i], substr)
            substr.pop()
        curr += s[i]
        self.recursion(s, i+1, curr, substr)
        
    def maxUniqueSplit(self, s: str) -> int:
        self.ans = 0
        substr = []
        self.recursion(s, 0, "", substr)
        return self.ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(s)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s in dataset:
        results.append(solution.maxUniqueSplit(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')