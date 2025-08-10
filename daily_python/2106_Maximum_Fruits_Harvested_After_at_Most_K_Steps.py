import os
import sys
from typing import List

class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        def countPath(left, right):
            if fruits[right][0] <= startPos:
                return startPos - fruits[left][0]
            if fruits[left][0] >= startPos:
                return fruits[right][0] - startPos
            l = startPos - fruits[left][0]
            r = fruits[right][0] - startPos
            return min(l, r) * 2 + max(l, r)
        
        n = len(fruits)
        ans = 0
        acc = 0
        left = 0
        while left < n and startPos - fruits[left][0] > k:
            left += 1
        right = left
        while left < n and fruits[left][0] - startPos <= k:
            while right < n and countPath(left, right) <= k:
                acc += fruits[right][1]
                right += 1
            ans = max(ans, acc)
            acc -= fruits[left][1]
            left += 1
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            fruits = [list(map(int, fruit.split(','))) for fruit in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            startPos = int(lines[1].split('=')[1].strip()[:-1])
            k = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((fruits, startPos, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for fruits, startPos, k in dataset:
        results.append(solution.maxTotalFruits(fruits, startPos, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')