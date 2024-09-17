import os
import sys
from typing import List

class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        dict = {}
        for s in list(s1.split(' ')):
            if s not in dict:
                dict[s] = 1
            else:
                dict[s] += 1
        for s in list(s2.split(' ')):
            if s not in dict:
                dict[s] = 1
            else:
                dict[s] += 1
        ans = []
        for key, val in dict.items():
            if val == 1:
                ans.append(key)
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s1 = lines[0].split('=')[1].strip()[1:-2]
            s2 = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((s1,s2))
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
        results.append(solution.uncommonFromSentences(s1, s2))
    for index, result in enumerate(results):
        print(f'Exaple {index + 1} : {result}')