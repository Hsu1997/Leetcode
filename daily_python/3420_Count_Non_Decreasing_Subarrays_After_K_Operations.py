import os
import sys
from typing import List
import heapq

class Solution:
    def countNonDecreasingSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        op = 0
        ans = 0
        pq = []
        cnt = [[] for _ in range(n)]
        pos = [n] * n
        sta = []
        left = 0
        for right in range(n):
            while sta and nums[right] >= nums[sta[-1]]:
                pos[sta[-1]] = right
                sta.pop()
            if sta:
                cnt[sta[-1]].append(right)
            sta.append(right)
            heapq.heappush(pq, (-nums[right], right))
            op += max(0, -pq[0][0] - nums[right])
            while op > k:
                for idx in cnt[left]:
                    op -= (nums[left] - nums[idx]) * (min(pos[idx], right + 1) - idx)
                left += 1
            while pq and pq[0][1] < left:
                heapq.heappop(pq)
            ans += right - left + 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[0:-1])
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
        results.append(solution.countNonDecreasingSubarrays(nums, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')