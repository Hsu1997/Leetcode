import os
import sys

class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        if sentence[0] != sentence[-1]:
            return False
        n = len(sentence)
        i = 1
        while i < n:
            while i < n and sentence[i] != " ":
                i += 1
            if i == n:
                break
            if sentence[i-1] != sentence[i+1]:
                return False
            i += 1
        return True
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            sentence = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(sentence)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for sentence in dataset:
        results.append(solution.isCircularSentence(sentence))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')