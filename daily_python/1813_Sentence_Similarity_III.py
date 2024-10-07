import os
import sys

class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        word1 = sentence1.split(' ')
        word2 = sentence2.split(' ')
        if len(word1) > len(word2):
            word1, word2 = word2, word1
        start = 0
        end = len(word1) - 1
        dif = len(word2) - len(word1)
        while(start < len(word1) and word1[start] == word2[start]):
            start += 1
        while(end >= 0 and word1[end] == word2[end + dif]):
            end -= 1
        return start > end
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            sentence1 = lines[0].split('=')[1].strip()[1:-2]
            sentence2 = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((sentence1, sentence2))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for sentence1, sentence2 in dataset:
        results.append(solution.areSentencesSimilar(sentence1, sentence2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')