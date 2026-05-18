import os
import sys
from typing import List

class Solution:
    def minJumps(self, arr: List[int]) -> int:
        n = len(arr)
        m = {}
        for i in range(n):
            if arr[i] in m:
                m[arr[i]].append(i)
            else:
                m[arr[i]] = [i]
        curr = [0]
        visited = {0}
        steps = 0
        while curr:
            temp = []
            for i in curr:
                if i == n - 1:
                    return steps
                if i - 1 >= 0 and i - 1 not in visited:
                    visited.add(i - 1)
                    temp.append(i - 1)
                if i + 1 < n and i + 1 not in visited:
                    visited.add(i + 1)
                    temp.append(i + 1)
                if arr[i] in m:
                    for j in m[arr[i]]:
                        if j not in visited:
                            visited.add(j)
                            temp.append(j)
                    m[arr[i]].clear()
            steps += 1
            curr = temp
        return arr
    

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            arr = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(arr)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for arr in dataset:
        results.append(solution.minJumps(arr))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')