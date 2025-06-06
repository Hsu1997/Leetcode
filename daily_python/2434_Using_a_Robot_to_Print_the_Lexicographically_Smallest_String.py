import os
import sys

class Solution:
    def robotWithString(self, s: str) -> str:
        n = len(s)
        suffix_smallest = [' '] * n
        minchar = 'z'
        for i in range(n-1, -1, -1):
            minchar = min(minchar, s[i])
            suffix_smallest[i] = minchar
        stack = []
        ans = []
        for i in range(n):
            while stack and suffix_smallest[i] >= stack[-1]:
                ans.append(stack.pop())
            stack.append(s[i])
        while stack:
            ans.append(stack.pop())
        return "".join(ans)

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
        results.append(solution.robotWithString(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')