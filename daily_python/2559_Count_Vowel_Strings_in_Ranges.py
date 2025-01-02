import os
import sys
from typing import List

class Solution:
    def is_vowel(self, c):
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        acc = []
        if self.is_vowel(words[0][0]) and self.is_vowel(words[0][-1]):
            acc.append(1)
        else:
            acc.append(0)
        for i in range(1, len(words)):
            if self.is_vowel(words[i][0]) and self.is_vowel(words[i][-1]):
                acc.append(1 + acc[-1])
            else:
                acc.append(acc[-1])
        ans = []
        for start, end in queries:
            if start == 0:
                ans.append(acc[end])
            else:
                ans.append(acc[end] - acc[start-1])
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            words = list(lines[0].split('=')[1].strip()[2:-3].split('","'))
            queries = [list(map(int, i.split(','))) for i in lines[1].split('=')[1].strip()[2:-3].split('},{')]
            dataset.append((words, queries))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for words, queries in dataset:
        results.append(solution.vowelStrings(words, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')