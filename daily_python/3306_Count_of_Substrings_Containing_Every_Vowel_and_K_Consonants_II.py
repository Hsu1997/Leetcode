import os
import sys
from typing import List

class Solution:
    def _isVowel(self, c: chr) -> bool:
        return c in "aeiou"
    def _valid(self, count: dict) -> bool:
        return all(vowel in count and count[vowel] > 0 for vowel in "aeiou")
    def countOfSubstrings(self, word: str, k: int) -> int:
        n = len(word)
        next_consonant = [n] * n
        idx = n
        for i in range(n-1, -1, -1):
            next_consonant[i] = idx
            if not self._isVowel(word[i]):
                idx = i
        start = 0
        end = 0
        consonant_count = 0
        count = {}
        ans = 0
        while end < n:
            added = word[end]
            if self._isVowel(added):
                count[added] = count.get(added, 0) + 1
            else:
                consonant_count += 1
            while start < end and self._valid(count) and consonant_count >= k:
                if consonant_count == k:
                    ans += next_consonant[end] - end
                delete = word[start]
                if self._isVowel(delete):
                    count[delete] -= 1
                else:
                    consonant_count -= 1
                start += 1
            end += 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            word = lines[0].split('=')[1].strip()[1:-2]
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((word, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for word, k in dataset:
        results.append(solution.countOfSubstrings(word, k))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')