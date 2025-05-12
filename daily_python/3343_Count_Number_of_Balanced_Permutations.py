import os
import sys
from typing import List

class Solution:
    def countBalancedPermutations(self, num: str) -> int:
        mod = int(1e9 + 7)
        total = 0
        n = len(num)
        count = [0] * 10
        for c in num:
            count[ord(c) - ord('0')] += 1
            total += ord(c) - ord('0')
        if total % 2 == 1:
            return 0
        target = total // 2
        oddMax = (n + 1) // 2
        ans = 0
        combination = [[0] * (oddMax + 1) for _ in range(oddMax + 1)]
        for i in range(oddMax + 1):
            combination[i][0] = combination[i][i] = 1
            for j in range(1, i):
                combination[i][j] = (combination[i-1][j-1] + combination[i-1][j]) % mod
        suffix = [0] * 11
        for i in range(9, -1, -1):
            suffix[i] = count[i] + suffix[i+1]

        dp = [[[-1] * (oddMax + 1) for _ in range(target + 1)] for _ in range(10)]
        def dfs(num: int, oddSum: int, oddCount: int) -> int:
            if oddSum > target or oddCount > oddMax or suffix[num] < oddMax - oddCount:
                return 0
            if num == 10:
                if oddSum == target and oddCount == oddMax:
                    return 1
                else:
                    return 0
            if dp[num][oddSum][oddCount] != -1:
                return dp[num][oddSum][oddCount]
            oddRemain = oddMax - oddCount
            evenRemain = suffix[num] - oddRemain
            res = 0
            for currTake in range(max(0, count[num] - evenRemain), min(count[num], oddRemain) + 1):
                res += ((((combination[oddRemain][currTake] * combination[evenRemain][count[num] - currTake]) % mod) * dfs(num + 1, oddSum + currTake * num, oddCount + currTake)) % mod)
                res %= mod
            dp[num][oddSum][oddCount] = res
            return res
        
        return dfs(0, 0, 0)

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            num = lines[0].split('=')[1].strip()[1:-2]
            dataset.append(num)
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for num in dataset:
        results.append(solution.countBalancedPermutations(num))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')