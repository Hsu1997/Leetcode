import os
import sys
from typing import List

class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if sum > num * 9:
            return ''
        ans = '9' * (sum // 9)
        if sum % 9 > 0:
            ans += str(sum % 9)
        ans += '0' * (num - len(ans))
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            num = int(lines[0].split('=')[1].strip()[:-1])
            sum = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((num, sum))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for num, sum in dataset:
        results.append(solution.maxSumOfSquares(num, sum))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')