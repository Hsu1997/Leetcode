import sys
import os
from typing import List

class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        dic = {}
        for s in arr:
            dic[s] = dic.get(s, 0) + 1
        for s in arr:
            if dic[s] == 1:
                k -= 1
            if k == 0:
                return s
        return ""
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            arr = lines[0].split('=')[1].strip()[1:-2].replace('"', "").split(',')
            k = int(lines[1].split('=')[1].strip().strip(';'))
            dataset.append((arr, k))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    solution = Solution()
    results = []
    for arr, k in dataset:
        results.append(solution.kthDistinct(arr, k))
    for index, result in enumerate(results):
        print(f'data {index+1} : {result}')
    