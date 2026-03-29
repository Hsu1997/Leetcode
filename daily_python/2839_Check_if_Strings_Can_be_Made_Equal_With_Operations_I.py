import os
import sys

class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        return ((s1[0] == s2[0] and s1[2] == s2[2]) or (s1[0] == s2[2] and s1[2] == s2[0])) and ((s1[1] == s2[1] and s1[3] == s2[3]) or (s1[1] == s2[3] and s1[3] == s2[1]))
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s1 = lines[0].split('=')[1].strip()[1:-2]
            s2 = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((s1, s2))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s1, s2 in dataset:
        results.append(solution.canBeEqual(s1, s2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')