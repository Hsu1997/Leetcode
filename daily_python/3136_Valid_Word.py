import os
import sys

class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False
        vowel = False
        consonant = False
        for c in word:
            if c.isalpha():
                if c.lower() in "aeiou":
                    vowel = True
                else:
                    consonant = True
            elif not c.isdigit():
                return False
        return vowel and consonant
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            word = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(word)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for word in dataset:
        results.append(solution.isValid(word))
    for index, result in enumerate(results):
        print(f'Example : {index + 1} : {result}')