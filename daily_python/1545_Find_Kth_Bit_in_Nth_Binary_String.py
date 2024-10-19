import os
import sys

class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        flip = 0
        for i in range(n, 1, -1):
            mid = 1 << (i-1)
            if (k > mid):
                k = mid - (k - mid)
                flip += 1
            elif k == mid:
                return '1' if flip % 2 == 0 else '0'
            else:
                continue
        return '0' if flip % 2 == 0 else '1'
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((n, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, k in dataset:
        results.append(solution.findKthBit(n, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')