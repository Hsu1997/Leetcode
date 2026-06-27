import sys
import os
from typing import List
from collections import Counter

class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        ans = (cnt.get(1, 0) - 1) // 2 * 2 + 1
        cnt.pop(1)
        for num in cnt:
            res = 1
            x = num
            while cnt.get(x, 0) > 1 and cnt.get(x * x, 0) > 0:
                x *= x
                res += 2
            ans = max(ans, res)
        return ans
    
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
        results.append(solution.maximumLength(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')