import os
import sys
from collections import defaultdict
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n1 = len(s1)
        n2 = len(s2)
        if n1 > n2:
            return False
        count = defaultdict(int)
        for c in s1:
            count[c] += 1
        needed = len(count)
        for i in range(n1):
            count[s2[i]] -= 1
            if count[s2[i]] == 0:
                needed -= 1
        if needed == 0:
            return True
        for i in range(n1, n2, 1):
            count[s2[i]] -= 1
            if count[s2[i]] == 0:
                needed -= 1
            count[s2[i-n1]] += 1
            if count[s2[i-n1]] == 1:
                needed += 1
            if needed == 0:
                return True
        return False
    
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
        results.append(solution.checkInclusion(s1, s2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')