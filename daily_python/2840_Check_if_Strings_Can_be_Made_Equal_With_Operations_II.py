import os
import sys
from collections import Counter

class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        # n = len(s1)
        # oddcnt = [0] * 26
        # evencnt = [0] * 26
        # for i in range(n):
        #     if i % 2 == 0:
        #         oddcnt[ord(s1[i]) - ord('a')] += 1
        #         oddcnt[ord(s2[i]) - ord('a')] -= 1
        #     else:
        #         evencnt[ord(s1[i]) - ord('a')] += 1
        #         evencnt[ord(s2[i]) - ord('a')] -= 1
        # return all(oddcnt[i] == 0 for i in range(26)) and all(evencnt[i] == 0 for i in range(26))
        return Counter(s1[::2]) == Counter(s2[::2]) and Counter(s1[1::2]) == Counter(s2[1::2])

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
        results.append(solution.checkStrings(s1, s2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')