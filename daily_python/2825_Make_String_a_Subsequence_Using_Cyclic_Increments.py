import os
import sys

class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        n1 = len(str1)
        n2 = len(str2)
        k = 0
        for i in range(n1):
            curr = str1[i]
            curr_plus = chr((ord(curr) - ord('a') + 1) % 26 + ord('a'))
            if str2[k] == curr or str2[k] == curr_plus:
                k += 1
            if k == n2:
                return True
        return False
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            str1 = lines[0].split('=')[1].strip()[1:-2]
            str2 = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((str1, str2))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for str1, str2 in dataset:
        results.append(solution.canMakeSubsequence(str1, str2))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')