import os
import sys
from typing import List, Optional

class Solution:
    def canChange(self, start: str, target: str) -> bool:
        n = len(start)
        start_idx = target_idx = 0
        while start_idx < n or target_idx < n:
            while start_idx < n and start[start_idx] == '_':
                start_idx += 1
            while target_idx < n and target[target_idx] == '_':
                target_idx += 1
            if start_idx == n or target_idx == n:
                return start_idx == target_idx
            if start[start_idx] != target[target_idx] or (start[start_idx] == 'L' and target_idx > start_idx) or (start[start_idx] == 'R' and start_idx > target_idx):
                return False
            start_idx += 1
            target_idx += 1
        return True
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            start = lines[0].split('=')[1].strip()[1:-2]
            target = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((start, target))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for start, target in dataset:
        results.append(solution.canChange(start, target))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')