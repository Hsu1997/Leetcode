import os
import sys
from typing import List

class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        ans = []
        prefix = [arr[0]]
        for i in range(1, len(arr)):
            prefix.append(arr[i] ^ prefix[-1])
        for query in queries:
            if query[0] == 0:
                ans.append(prefix[query[1]])
            else:
                ans.append(prefix[query[1]] ^ prefix[query[0] - 1])
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            arr = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            queries = [list(map(int, i.split(','))) for i in list(lines[1].split('=')[1].strip()[2:-3].split('},{'))]
            dataset.append((arr, queries))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for arr, queries in dataset:
        results.append(solution.xorQueries(arr, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')