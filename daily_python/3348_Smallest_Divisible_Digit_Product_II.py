import os
import sys
from typing import List
from math import gcd

class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        temp = t
        for i in range(9, 1, -1):
            while temp % i == 0:
                temp //= i
        if temp > 1:
            return '-1'
        nums = [int(i) for i in num]
        n = len(nums)
        remain = [0] * (n + 1)
        remain[0] = t
        pos = n - 1
        for i in range(n):
            curr = nums[i]
            if curr == 0:
                pos = i
                break
            remain[i + 1] = remain[i] // gcd(remain[i], curr)
        if remain[n] == 1:
            return num
        for i in range(pos, -1, -1):
            while nums[i] < 9:
                nums[i] += 1
                currT = remain[i] // gcd(remain[i], nums[i])
                k = 9
                for j in range(n - 1, i, -1):
                    while currT % k != 0:
                        k -= 1
                    nums[j] = k
                    currT //= k
                if currT == 1:
                    return ''.join(map(str, nums))
        ans = []
        for i in range(9, 1, -1):
            while t % i == 0:
                ans.append(i)
                t //= i
        l = max(0, n + 1 - len(ans))
        for _ in range(l):
            ans.append(1)
        return ''.join(map(str, ans[::-1]))

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            num = lines[0].split('=')[1].strip()[1:-2]
            t = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((num, t))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for num, t in dataset:
        results.append(solution.smallestNumber(num, t))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')