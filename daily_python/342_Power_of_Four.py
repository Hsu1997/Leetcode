import os
import sys

class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n < 1:
            return False
        while n > 1:
            if n & 1 or n & 3:
                return False
            n >>= 2
        return n == 1
        
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
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n in dataset:
        results.append(solution.isPowerOfFour(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')