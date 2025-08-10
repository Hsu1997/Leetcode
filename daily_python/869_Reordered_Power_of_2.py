import os
import sys
from typing import List

class Solution:
    def count_digits(self, x: int) -> List[int]:
        cnt = [0] * 10
        while x:
            cnt[x % 10] += 1
            x //= 10
        return cnt
    
    def reorderedPowerOf2(self, n: int) -> bool:
        target = self.count_digits(n)
        for i in range(32):
            if self.count_digits(1 << i) == target:
                return True
        return False

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            dataset.append(n)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n in dataset:
        results.append(solution.reorderedPowerOf2(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')