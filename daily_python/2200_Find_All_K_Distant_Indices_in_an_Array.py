import os
import sys
from typing import List

class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        n = len(nums)
        ans = []
        count = 0
        for i in range(k):
            if nums[i] == key:
                count += 1
        for i in range(n):
            if i - k - 1 >= 0 and nums[i - k - 1] == key:
                count -= 1
            if i + k < n and nums[i + k] == key:
                count += 1
            if count > 0:
                ans.append(i)
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            key = int(lines[1].split('=')[1].strip()[:-1])
            k = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((nums, key, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, key, k in dataset:
        results.append(solution.findKDistantIndices(nums, key, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')