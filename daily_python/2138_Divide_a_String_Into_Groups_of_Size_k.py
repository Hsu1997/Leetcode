import sys
import os
from typing import List

class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        n = len(s)
        ans = []
        s = s + fill * (k - n % k)
        for idx in range(0, n, k):
            ans.append(s[idx:idx + k])
        return ans
    
def readData(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            k = int(lines[1].split('=')[1][:-1])
            fill = lines[2].split('=')[1].strip()[1:-2]
            dataset.append((s, k, fill))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readData(filename)
    results = []
    solution = Solution()
    for s, k, fill in dataset:
        results.append(solution.divideString(s, k, fill))
    for index, result in enumerate(results):
        print(f'dataset {index+1} : {result}')
