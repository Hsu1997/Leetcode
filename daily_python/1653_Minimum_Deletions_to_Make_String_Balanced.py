import os
import sys
from typing import List

class Solution:
    def minimumDeletions(self, s: str) -> int:
        acount = s.count('a')
        ans = min(len(s) - acount, acount)
        bcount = 0
        for c in s:
            if c == 'a':
                acount -= 1
            else:
                bcount += 1
            ans = min(ans, acount + bcount)
        return ans

def ReadFileData(filename: str):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        lines = content.split('\n')
        for line in lines:
            data = line.split('=')[1].strip().strip('\";')
            dataset.append(data)
    return dataset


if __name__ == '__main__':
    if (len(sys.argv) == 1):
        pathname = os.path.basename(__file__)
        filename = os.path.splitext(pathname)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = ReadFileData(filename)
    solution = Solution()
    results = []
    for data in dataset:
        results.append(solution.minimumDeletions(data))
    for index, result in enumerate(results):
        print(f'data {index+1} : {result}')
