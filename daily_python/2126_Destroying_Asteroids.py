import os
import sys
from typing import List

class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        m = [100001] * 33
        s = [0] * 33
        for a in asteroids:
            k = a.bit_length()
            m[k] = min(m[k], a)
            s[k] += a
        for i in range(33):
            if s[i] == 0:
                continue
            if mass < m[i]:
                return False
            mass += s[i]
        return True

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            mass = int(lines[0].split('=')[1].strip()[:-1])
            asteroids = list(map(int, lines[1].split('=')[1].strip()[1:-2].split(',')))
            dataset.append((mass, asteroids))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for mass, asteroids in dataset:
        results.append(solution.asteroidsDestroyed(mass, asteroids))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')