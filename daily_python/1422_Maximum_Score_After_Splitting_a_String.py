import os
import sys
from typing import List

class Solution:
    def maxScore(self, s: str) -> int:
        left = 0 if s[0] == '1' else 1
        right = s.count('1') - (1 if s[0] == '1' else 0)
        ans = left + right
        for i in range(1, len(s)-1):
            if s[i] == '0':
                left += 1
            else:
                right -= 1
            ans = max(ans, left + right)
        return ans
    
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
        results.append(solution.maxScore(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')