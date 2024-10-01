import os
import sys
from typing import List

class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        count = [0] * k
        for i in arr:
            count[(i % k + k) % k] += 1
        for i in range(1, k // 2 + 1):
            if count[i] != count[k - i]:
                return False
        if k % 2 == 0 and count[k // 2] % 2 == 1:
            return False
        return True
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            arr = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((arr, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for arr, k in dataset:
        results.append(solution.canArrange(arr, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')