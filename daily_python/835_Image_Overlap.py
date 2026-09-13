import os
import sys
from typing import List

class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n = len(img1)
        ans = 0
        for dx in range(- n + 1, n):
            for dy in range(- n + 1, n):
                cnt = 0
                for i in range(n):
                    for j in range(n):
                        if not (0 <= i + dx < n) or not (0 <= j + dy < n):
                            continue
                        if img1[i][j] == 1 and img2[i + dx][j + dy] == 1:
                            cnt += 1
                ans = max(ans, cnt)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            img1 = [list(map(int, row.split(','))) for row in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            img2 = [list(map(int, row.split(','))) for row in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((img1, img2))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for img1, img2 in dataset:
        results.append(solution.largestOverlap(img1, img2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')