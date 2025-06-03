import sys
import os
from typing import List

class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        ans = [1] * n
        for i in range(1, n):
            if ratings[i] > ratings[i-1]:
                ans[i] = ans[i-1] + 1
        for i in range(n-2, -1, -1):
            if ratings[i] > ratings[i+1]:
                ans[i] = max(ans[i], ans[i+1] + 1)
        return sum(ans)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            ratings = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(ratings)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for ratings in dataset:
        results.append(solution.candy(ratings))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')