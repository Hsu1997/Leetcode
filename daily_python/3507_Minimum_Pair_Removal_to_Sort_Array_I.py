import os
import sys
from typing import List

class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        n = len(nums)
        next = [i + 1 for i in range(n)]
        next[n - 1] = -1
        ans = 0
        while n - ans > 1:
            nonDecreasing = True
            curr = 0
            minsum = nums[curr] + nums[next[curr]]
            minidx = 0
            while curr != -1 and next[curr] != -1:
                if nums[curr] > nums[next[curr]]:
                    nonDecreasing = False
                currsum = nums[curr] + nums[next[curr]]
                if currsum < minsum:
                    minsum = currsum
                    minidx = curr
                curr = next[curr]
            if nonDecreasing:
                return ans
            nums[minidx] += nums[next[minidx]]
            next[minidx] = next[next[minidx]]
            ans += 1
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
        results.append(solution.minimumPairRemoval(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')