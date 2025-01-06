import os
import sys
from typing import List

class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        left = 0
        total = 0
        acc = 0
        for i in range(n-1, -1, -1):
            acc += total
            if boxes[i] == '1':
                total += 1
        ans = [0] * n
        ans[0] = acc
        for i in range(1, n):
            if boxes[i-1] == '1':
                left += 1
            ans[i] = ans[i-1] + left - (total - left)
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            boxes = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(boxes)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for boxes in dataset:
        results.append(solution.minOperations(boxes))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')