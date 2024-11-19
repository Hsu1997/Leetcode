import os
import sys
from typing import List

class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        ans = [0] * n
        if k == 0:
            return ans
        acc = 0
        for i in range(abs(k)):
            acc += code[i]
        for i in range(n):
            acc -= code[i]
            acc += code[(i+abs(k))%n]
            if k > 0:
                ans[i] = acc
            else:
                ans[(i+abs(k)+1)%n] = acc
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            code = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1][:-1])
            dataset.append((code, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for code, k in dataset:
        results.append(solution.decrypt(code, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')