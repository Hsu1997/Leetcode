import os
import sys

class Solution:
    def minOperations(self, s: str) -> int:
        cnt = 0
        n = len(s)
        for i in range(n):
            if i % 2 == 0:
                if s[i] == '0':
                    cnt += 1
            else:
                if s[i] == '1':
                    cnt += 1
        return min(cnt, n - cnt)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(s)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s in dataset:
        results.append(solution.minOperations(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')