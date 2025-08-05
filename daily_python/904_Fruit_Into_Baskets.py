import sys
import os
from typing import List, Optional
from collections import deque

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        n = len(fruits)
        start = 0
        basket = {}
        for end in range(n):
            basket[fruits[end]] = basket.get(fruits[end], 0) + 1
            if len(basket.items()) > 2:
                basket[fruits[start]] -= 1
                if basket[fruits[start]] == 0:
                    basket.pop(fruits[start])
                start += 1
        return end - start + 1
        
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            fruits = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(fruits)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for fruits in dataset:
        results.append(solution.totalFruit(fruits))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')