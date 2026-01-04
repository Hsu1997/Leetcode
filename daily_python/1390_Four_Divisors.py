import os
import sys
from typing import List

class Solution:
    def sumOfDivisor(self, num) -> int:
        cnt = 2
        ans = 1 + num
        for i in range(2, num):
            if i * i > num:
                return ans if cnt == 4 else 0
            if num % i == 0:
                cnt += 2 if i * i != num else 1
                if cnt > 4:
                    return 0
                ans += i + num // i
        return ans if cnt == 4 else 0
    
    def sumFourDivisors(self, nums: List[int]) -> int:
        ans = 0
        for num in nums:
            ans += self.sumOfDivisor(num)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            dataset.append(nums)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums in dataset:
        results.append(solution.sumFourDivisors(nums))
    for index, result in enumerate(results):
        print(f'Example : {index + 1} : {result}')