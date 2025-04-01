import sys
import os
from typing import List
import ast

class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        dp = [0] * n
        dp[n-1] = questions[n-1][0]
        for i in range(n-2, -1, -1):
            dp[i] = questions[i][0] + (dp[i + questions[i][1] + 1] if i + questions[i][1] + 1 < n else 0)
            dp[i] = max(dp[i], dp[i+1])
        return dp[0]
    
def readData(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            questions = [list(map(int, question.split(','))) for question in lines[0].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append(questions)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readData(filename)
    results = []
    solution = Solution()
    for questions in dataset:
        results.append(solution.mostPoints(questions))
    for index, result in enumerate(results):
        print(f'dataset {index+1} : {result}')
