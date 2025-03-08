import os
import sys
from typing import List

class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        seen = set()
        sorted_tiles = "".join(sorted(tiles))
        return self.create_sequence(sorted_tiles, "", 0, seen) - 1
    
    def factorial(self, n):
        if n < 2:
            return 1
        result = 1
        for i in range(2, n+1):
            result *= i
        return result
    
    def count_permutation(self, s):
        total = self.factorial(len(s))
        count = [0] * 26
        for c in s:
            count[ord(c) - ord('A')] += 1
        for c in count:
            total //= self.factorial(c)
        return total
    
    def create_sequence(self, s, curr, idx, seen):
        if idx == len(s):
            if curr not in seen:
                seen.add(curr)
                return self.count_permutation(curr)
            return 0
        return self.create_sequence(s, curr + s[idx], idx+1, seen) + self.create_sequence(s, curr, idx+1, seen)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            tiles = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(tiles)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for tiles in dataset:
        results.append(solution.numTilePossibilities(tiles))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')