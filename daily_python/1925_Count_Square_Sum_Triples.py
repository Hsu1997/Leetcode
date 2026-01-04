import os
import sys
import math

class Solution:
    def countTriples(self, n: int) -> int:
        ans = 0
        for a in range(1, n+1):
            for b in range(1, n+1):
                c = round(math.sqrt(a * a + b * b))
                if c <= n and c * c == a * a + b * b:
                    ans += 1
        return ans

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
        results.append(solution.countTriples(n))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')