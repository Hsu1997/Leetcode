import os
import sys
from typing import List

class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)
        d = [0] * (n + 1)
        for start, end, dir in shifts:
            dir = 1 if dir == 1 else -1
            d[start] += dir
            d[end+1] -= dir
        acc = 0
        ans = []
        for i in range(n):
            acc += d[i]
            curr = (ord(s[i]) - ord('a') + acc) % 26
            ans.append(chr(curr + ord('a')))
        return "".join(ans)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            shifts = [list(map(int, i.split(','))) for i in lines[1].split('=')[1].strip()[2:-3].split("},{")]
            dataset.append((s, shifts))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, shifts in dataset:
        results.append(solution.shiftingLetters(s, shifts))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')