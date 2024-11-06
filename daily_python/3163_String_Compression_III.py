import os
import sys

class Solution:
    def compressedString(self, word: str) -> str:
        prev = word[0]
        count = 1
        ans = ""
        for i in range(1,len(word)):
            if word[i] != prev or count == 9:
                ans += str(count) + prev
                prev = word[i]
                count = 1
            else:
                count += 1
        ans += str(count) + prev
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(s)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s in dataset:
        results.append(solution.compressedString(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')