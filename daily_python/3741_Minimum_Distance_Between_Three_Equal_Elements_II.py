import os
import sys
from typing import List
from collections import defaultdict

class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        n = len(nums)
        m = defaultdict(list)
        ans = float('inf')
        for i in range(n):
            m[nums[i]].append(i)
        for v in m.values():
            if len(v) >= 3:
                for i in range(2, len(v)):
                    ans = min(ans, 2 * (v[i] - v[i-2]))
        return ans if ans != float('inf') else -1

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(nums)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums in dataset:
        results.append(solution.minimumDistance(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')