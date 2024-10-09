import os
import sys

class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        ans = 0
        open = 0
        for c in s:
            if c == '(':
                open += 1
            else:
                if open == 0:
                    ans += 1
                else:
                    open -= 1
        return ans + open
    
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
        results.append(solution.minAddToMakeValid(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')