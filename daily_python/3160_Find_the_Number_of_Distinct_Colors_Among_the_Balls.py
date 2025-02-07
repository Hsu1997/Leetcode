import os
import sys
from typing import List

class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        q = len(queries)
        ans = []
        color_count = {}
        ball_color = {}
        for b, c in queries:
            if b in ball_color:
                prev_color = ball_color[b]
                color_count[prev_color] -= 1
                if color_count[prev_color] == 0:
                    del color_count[prev_color]
            ball_color[b] = c
            color_count[c] = color_count.get(c,0) + 1
            ans.append(len(color_count))
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            limit = int(lines[0].split('=')[1].strip()[:-1])
            queries = [list(map(int, i.split(','))) for i in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((limit, queries))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for limit, queries in dataset:
        results.append(solution.queryResults(limit, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')
