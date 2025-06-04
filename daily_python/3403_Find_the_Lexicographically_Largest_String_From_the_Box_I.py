import os
import sys
from typing import List

class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        if numFriends == 1:
            return word
        n = len(word)
        ans = ""
        for start in range(n):
            l = min(n - numFriends + 1, n - start)
            ans = max(ans, word[start : start + l])
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            word = lines[0].split('=')[1].strip()[1:-2]
            numFriends = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((word, numFriends))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for word, numFriends in dataset:
        results.append(solution.answerString(word, numFriends))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')