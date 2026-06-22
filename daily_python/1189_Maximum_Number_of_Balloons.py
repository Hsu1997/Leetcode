import os
import sys
from typing import List

class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        cnt = [0] * 26
        for c in text:
            cnt[ord(c) - ord('a')] += 1
        cnt[ord('l') - ord('a')] //= 2
        cnt[ord('o') - ord('a')] //= 2
        return min(cnt[0], cnt[1], cnt[11], cnt[13], cnt[14])

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            text = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(text)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for text in dataset:
        results.append(solution.maxNumberOfBalloons(text))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')