import os
import sys
from typing import List

class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        ans = 0
        duplicate_group = 0
        count = {}
        n = len(nums)
        acc = 0
        for i in range(k):
            if nums[i] not in count:
                count[nums[i]] = 1
            else:
                count[nums[i]] += 1
            if count[nums[i]] == 2:
                duplicate_group += 1
            acc += nums[i]
        if duplicate_group == 0:
            ans = acc
        for i in range(k, n):
            added = nums[i]
            delet = nums[i-k]
            acc += added - delet
            if added not in count:
                count[added] = 1
            else:
                count[added] += 1
            if count[added] == 2:
                duplicate_group += 1
            count[delet] -= 1
            if count[delet] == 1:
                duplicate_group -= 1
            elif count[delet] == 0:
                del count[delet]
            if duplicate_group == 0:
                ans = max(ans, acc)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1][:-1])
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
        results.append(solution.maximumSubarraySum(nums, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')