import os
import sys

class Solution:
    def minSteps(self, n: int) -> int:
        ans = 0
        prime = 2
        while n > 1:
            while n % prime == 0:
                ans += prime
                n /= prime
            prime += 1
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1][1:-1])
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
        results.append(solution.minSteps(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')