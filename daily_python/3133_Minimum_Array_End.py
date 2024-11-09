import os
import sys

class Solution:
    def minEnd(self, n: int, x: int) -> int:
        n -= 1
        mask = 1
        
        while n:
            if (x & mask) == 0:
                x |= (n & 1) * mask
                n >>= 1
            mask <<= 1
        return x
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            x = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((n, x))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, x in dataset:
        results.append(solution.minEnd(n, x))
    for index, result in enumerate(results):
        print(f'Example : {index + 1} : {result}')