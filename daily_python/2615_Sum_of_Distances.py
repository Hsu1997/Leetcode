import os
import sys
from typing import List

class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        cnt = {}
        for i in range(n):
            curr = nums[i]
            if curr in cnt:
                ans[i] += cnt[curr][0] * i - cnt[curr][1]
                cnt[curr][0] += 1
                cnt[curr][1] += i
            else:
                cnt[curr] = [1, i]
        cnt.clear()
        for i in range(n-1, -1, -1):
            curr = nums[i]
            if curr in cnt:
                ans[i] += cnt[curr][1] - cnt[curr][0] * i
                cnt[curr][0] += 1
                cnt[curr][1] += i
            else:
                cnt[curr] = [1, i]
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
        results.append(solution.distance(nums))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')