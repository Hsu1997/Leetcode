import os
import sys
from typing import List

class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        m = len(languages)
        skill = [[0] * n for _ in range(m)]
        for i in range(m):
            for l in languages[i]:
                skill[i][l-1] = 1
        s = set()
        for friendship in friendships:
            a = friendship[0] - 1
            b = friendship[1] - 1
            communicate = False
            for l in range(n):
                if skill[a][l] and skill[b][l]:
                    communicate = True
                    break
            if not communicate:
                s.add(a)
                s.add(b)
        ans = m
        for l in range(n):
            curr = 0
            for i in s:
                if skill[i][l] == 0:
                    curr += 1
            ans = min(ans, curr)
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip()[:-1])
            languages = [list(map(int, l.split(','))) for l in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            friendships = [list(map(int, f.split(','))) for f in lines[2].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((n, languages, friendships))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for n, languages, friendships in dataset:
        results.append(solution.minimumTeachings(n, languages, friendships))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')