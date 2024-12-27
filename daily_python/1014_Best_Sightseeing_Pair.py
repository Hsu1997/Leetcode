import os
import sys
from typing import List

class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        n = len(values)
        ans = float('-inf')
        curr = values[0]
        for i in range(1, n):
            ans = max(ans, curr + values[i] - i)
            curr = max(curr, values[i] + i)
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            values = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(values)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for values in dataset:
        results.append(solution.maxScoreSightseeingPair(values))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
