import os
import sys
from typing import List

class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        n = len(arr)
        M = max(arr)
        acc = [0] * (M + 1)
        ans = 0
        for j in range(1, n - 1):
            for i in range(arr[j-1], M + 1):
                acc[i] += 1
            for k in range(j + 1, n):
                second = arr[j]
                third = arr[k]
                if abs(second - third) > b:
                    continue
                left = max(second - a, third - c, 0)
                right = min(second + a, third + c, M)
                if left > right:
                    continue
                if left == 0:
                    ans += acc[right]
                else:
                    ans += acc[right] - acc[left - 1]
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            arr = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            a = int(lines[1].split('=')[1].strip()[:-1])
            b = int(lines[2].split('=')[1].strip()[:-1])
            c = int(lines[3].split('=')[1].strip()[:-1])
            dataset.append((arr, a, b, c))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for arr, a, b, c in dataset:
        results.append(solution.countGoodTriplets(arr, a, b, c))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')