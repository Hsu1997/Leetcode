import os
import sys

class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        n = len(goal)
        f = goal + "#" + s + s
        l = len(f)
        lps = [0] * l
        k = 0
        for i in range(1, l):
            while k > 0 and f[i] != f[k]:
                k = lps[k-1]
            if f[k] == f[i]:
                k += 1
            lps[i] = k
            if k == n:
                return True
        return False
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            goal = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((s, goal))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, goal in dataset:
        results.append(solution.rotateString(s, goal))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')