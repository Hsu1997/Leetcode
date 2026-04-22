import os
import sys
from typing import List

class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        ans = []
        for query in queries:
            for target in dictionary:
                diff = 0
                for i in range(len(query)):
                    if query[i] != target[i]:
                        diff += 1
                    if diff > 2:
                        break
                if diff <= 2:
                    ans.append(query)
                    break
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            queries = list(lines[0].split('=')[1].strip()[2:-3].split(','))
            dictionary = list(lines[1].split('=')[1].strip()[2:-3].split(','))
            dataset.append((queries, dictionary))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for queries, dictionary in dataset:
        results.append(solution.twoEditWords(queries, dictionary))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')