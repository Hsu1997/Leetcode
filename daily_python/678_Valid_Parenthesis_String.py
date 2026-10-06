import os
import sys

class Solution:
    def checkValidString(self, s: str) -> bool:
        n = len(s)
        open = 0
        close = 0
        for i in range(n):
            if s[i] == '(' or s[i] == '*':
                open += 1
            else:
                open -= 1
            if s[n - 1 - i] == ')' or s[n - 1 - i] == '*':
                close += 1
            else:
                close -= 1
            if open < 0 or close < 0:
                return False
        return True
    
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
        results.append(solution.checkValidString(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')