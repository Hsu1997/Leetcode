import os
import sys
from typing import List

class Solution:
    def cost(self, pre_status, curr_status):
        if pre_status == 26:
            return 0
        prex = pre_status // 6
        prey = pre_status % 6
        x = curr_status // 6
        y = curr_status % 6
        return abs(prex - x) + abs(prey - y)
    
    def minimumDistance(self, word: str) -> int:
        n = len(word)
        dp = [float('inf')] * (27 * 27)
        dp[26 * 27 + 26] = 0
        for c in word:
            typing = ord(c) - ord('A')
            temp = [float('inf')] * (27 * 27)
            # left hand typing
            for right in range(27):
                curr = (typing, right)
                for pre_left in range(27):
                    if dp[pre_left * 27 + right] == float('inf'):
                        continue
                    temp[typing * 27 + right] = min(temp[typing * 27 + right], dp[pre_left * 27 + right] + self.cost(pre_left, typing))
        
            # right hand typing
            for left in range(27):
                curr = (left, typing)
                for pre_right in range(27):
                    if dp[left * 27 + pre_right] == float('inf'):
                        continue
                    temp[left * 27 + typing] = min(temp[left * 27 + typing], dp[left * 27 + pre_right] + self.cost(pre_right, typing))
            dp = temp.copy()
        return min(dp)
    
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
        results.append(solution.minimumDistance(word))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')