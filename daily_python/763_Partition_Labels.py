import os
import sys
from typing import List, Optional

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        n = len(s)
        m = {}
        for i in range(n-1, -1, -1):
            if s[i] not in m:
                m[s[i]] = i
        last_pos = [m[ch] for ch in s]
        last_pos.append(n)
        curr_start = 0
        curr_end = last_pos[0]
        ans = []
        for i in range(n+1):
            if i > curr_end:
                ans.append(i - curr_start)
                curr_start = i
                curr_end = last_pos[i]
            curr_end = max(curr_end, last_pos[i])
        return ans
    
def readDataSeet(filename):
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
    dataset = readDataSeet(filename)
    results = []
    solution = Solution()
    for s in dataset:
        results.append(solution.partitionLabels(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')