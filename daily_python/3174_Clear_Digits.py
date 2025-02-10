import os
import sys

class Solution:
    def clearDigits(self, s: str) -> str:
        n = len(s)
        d = 0
        ans = []
        for i in range(n-1, -1, -1):
            if s[i].isdigit():
                d += 1
            else:
                if d > 0:
                    d -= 1
                else:
                    ans.append(s[i])
        ans = ''.join(reversed(ans))
        return ans

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
        results.append(solution.clearDigits(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')