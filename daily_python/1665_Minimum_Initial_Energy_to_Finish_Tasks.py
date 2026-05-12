import os
import sys
from typing import List

class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key = lambda x: x[1] - x[0], reverse = True)
        ans = 0
        for task in tasks[::-1]:
            ans += task[0]
            ans = max(ans, task[1])
        return ans

def ReadFileData(filename: str):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            tasks = [list(map(int, task.split(','))) for task in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((tasks))
    return dataset


if __name__ == '__main__':
    if (len(sys.argv) == 1):
        pathname = os.path.basename(__file__)
        filename = os.path.splitext(pathname)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = ReadFileData(filename)
    solution = Solution()
    results = []
    for tasks in dataset:
        results.append(solution.minimumEffort(tasks))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')
