import os
import sys
from typing import List

class Solution:
    def update(self, count: List[int], val: int, d: int) -> None:
        for i in range(32):
            if (val >> i) & 1:
                count[i] += d
    def convert(self, count: List[int]) -> int:
        ans = 0
        for i in range(32):
            if count[i]:
                ans |= (1 << i)
        return ans
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        start = 0
        end = 0
        ans = float('INF')
        count = [0] * 32
        while(end < n):
            self.update(count, nums[end], 1)
            while (start <= end and self.convert(count) >= k):
                ans = min(ans, end - start + 1)
                self.update(count, nums[start], -1)
                start += 1
            end += 1
        return ans if ans != float('INF') else -1
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nums, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, k in dataset:
        results.append(solution.minimumSubarrayLength(nums, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')