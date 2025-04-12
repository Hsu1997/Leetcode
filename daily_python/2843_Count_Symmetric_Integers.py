import os
import sys

class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        ans = 0
        for num in range(low, high+1):
            if num < 100:
                if num % 11 == 0:
                    ans += 1
            elif 1000 <= num < 10000:
                if (num // 1000 + ((num // 100) % 10)) == (((num % 100) // 10) + (num % 10)):
                    ans += 1
        return ans
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            low = int(lines[0].split('=')[1].strip()[:-1])
            high = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((low, high))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for low, high in dataset:
        results.append(solution.countSymmetricIntegers(low, high))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')