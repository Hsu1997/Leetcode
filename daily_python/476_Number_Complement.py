import os
import sys

class Solution:
    def findComplement(self, num: int) -> int:
        n = num.bit_length()
        mask = (1 << n) - 1
        return num ^ mask
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            num = int(lines[0].split('=')[1].strip()[:-1])
            dataset.append(num)
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for num in dataset:
        results.append(solution.findComplement(num))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')