import os
import sys
from typing import List

class Solution:
    def search(self, items, price):
        left = 0
        right = len(items) - 1
        ans = 0
        while left <= right:
            mid = (left + right) // 2
            if price >= items[mid][0]:
                ans = max(ans, items[mid][1])
                left = mid + 1
            else:
                right = mid - 1
        return ans

    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        items.sort()
        M = 0
        for i in range(len(items)):
            M = max(M, items[i][1])
            items[i][1] = M
        ans = []
        for q in queries:
            ans.append(self.search(items, q))
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            items = [list(map(int, item.split(','))) for item in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            queries = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((items, queries))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for items, queries in dataset:
        results.append(solution.maximumBeauty(items, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')