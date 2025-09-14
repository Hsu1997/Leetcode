import os
import sys
from typing import List

class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        def delvowel(word):
            w = word.lower()
            return "".join('*' if c in 'aeiou' else c for c in w)
        words_perfect = set(wordlist)
        words_cap = {}
        words_vow = {}
        for word in wordlist[::-1]:
            words_cap[word.lower()] = word
            words_vow[delvowel(word)] = word
        ans = []
        for query in queries:
            if query in words_perfect:
                ans.append(query)
            elif query.lower() in words_cap:
                ans.append(words_cap[query.lower()])
            elif delvowel(query) in words_vow:
                ans.append(words_vow[delvowel(query)])
            else:
                ans.append("")
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            wordlist = list(lines[0].split('=')[1].strip()[2:-3].split('","'))
            queries = list(lines[1].split('=')[1].strip()[2:-3].split('","'))
            dataset.append((wordlist, queries))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for wordlist, queries in dataset:
        results.append(solution.spellchecker(wordlist, queries))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')