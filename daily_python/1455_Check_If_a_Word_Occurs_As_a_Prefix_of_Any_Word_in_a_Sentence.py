import os
import sys
from typing import List

class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        n = len(sentence)
        m = len(searchWord)
        idx = ptr = 0
        ans = 0
        while idx < n:
            ans += 1
            while sentence[idx] == searchWord[ptr]:
                idx += 1
                ptr += 1
                if ptr == m:
                    return ans
            ptr = 0
            while idx < n and sentence[idx] != ' ':
                idx += 1
            idx += 1
        return -1
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            sentence = lines[0].split('=')[1].strip()[1:-2]
            searchWord = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((sentence, searchWord))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for sentence, searchWord in dataset:
        results.append(solution.isPrefixOfWord(sentence, searchWord))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')