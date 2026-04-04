import os
import sys
from typing import List

class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        if rows == 1:
            return encodedText
        n = len(encodedText)
        cols = n // rows
        ans = []
        for c in range(cols):
            i, j = 0, c
            while i < rows and j < cols:
                ans.append(encodedText[i * cols + j])
                i += 1
                j += 1
        return "".join(ans).rstrip()
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            encodedText = lines[0].split('=')[1].strip()[1:-2]
            rows = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((encodedText, rows))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for encodedText, rows in dataset:
        results.append(solution.decodeCiphertext(encodedText, rows))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')