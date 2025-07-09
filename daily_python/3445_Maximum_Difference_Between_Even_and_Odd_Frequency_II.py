import os
import sys
from typing import List

class Solution:
    def maxDifference(self, s: str, k: int) -> int:
        def get_status(cnt_a: int, cnt_b: int) -> int:
            return ((cnt_a % 2) << 1) + (cnt_b % 2)
        n = len(s)
        ans = float('-inf')
        for first in ['0','1','2','3','4']:
            for second in ['0','1','2','3','4']:
                if first == second:
                    continue
                cnt_a, cnt_b, prev_cnt_a, prev_cnt_b = 0, 0, 0, 0
                best = [float('inf')] * 4
                left = -1
                for right in range(n):
                    cnt_a += (s[right] == first)
                    cnt_b += (s[right] == second)
                    while right - left >= k and cnt_b - prev_cnt_b >= 2:
                        prev_status = get_status(prev_cnt_a, prev_cnt_b)
                        best[prev_status] = min(best[prev_status], prev_cnt_a - prev_cnt_b)
                        left += 1
                        prev_cnt_a += (s[left] == first)
                        prev_cnt_b += (s[left] == second)
                    curr_status = get_status(cnt_a, cnt_b)
                    if best[curr_status ^ 2] != float('inf'):
                        ans = max(ans, cnt_a - cnt_b - best[curr_status ^ 2])
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((s, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, k in dataset:
        results.append(solution.maxDifference(s, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')