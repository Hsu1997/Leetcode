import os
import sys
from typing import List

class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        maxv = max(nums)
        count = [0] * (maxv+1)
        for num in nums:
            count[max(0, num-k)] += 1
            if num+k+1 <= maxv:
                count[num+k+1] -= 1
        ans = 0
        curr = 0
        for i in count:
            curr += i
            ans = max(ans, curr)
        return ans

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
        results.append(solution.maximumBeauty(nums, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')