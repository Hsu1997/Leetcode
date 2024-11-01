import os
import sys

class Solution:
    def makeFancyString(self, s: str) -> str:
        ans = s[0]
        n = len(s)
        count = 1
        for i in range(1, n):
            if s[i] == ans[-1]:
                if count >= 2:
                    continue
                else:
                    ans += s[i]
                    count += 1
            else:
                ans += s[i]
                count = 1
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
        results.append(solution.makeFancyString(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')