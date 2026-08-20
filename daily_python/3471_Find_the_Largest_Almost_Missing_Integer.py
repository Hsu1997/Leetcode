import os
import sys
from typing import List

class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)
        if k == n:
            return max(nums)
        cnt = [0] * 51
        for i in nums:
            cnt[i] += 1
        if k == 1:
            for i in range(50, -1, -1):
                if (cnt[i] == 1):
                    return i
        res = -1
        if cnt[nums[0]] == 1:
            res = max(res, nums[0])
        if cnt[nums[-1]] == 1:
            res = max(res, nums[-1])
        return res

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
        results.append(solution.largestInteger(nums, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')