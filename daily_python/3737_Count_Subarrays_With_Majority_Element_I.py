import os
import sys
from typing import List

class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        cnt = [0] * n
        c = 0
        for i in range(n):
            c += 1 if nums[i] == target else -1
            cnt[i] = c
        curr = 0
        ans = 0
        for i in range(n):
            for j in range(i, n):
                if cnt[j] > curr:
                    ans += 1
            curr = cnt[i]
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            target = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nums, target))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, target in dataset:
        results.append(solution.countMajoritySubarrays(nums, target))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')