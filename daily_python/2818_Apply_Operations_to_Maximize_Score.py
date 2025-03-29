import os
import sys
from typing import List, Optional

class Solution:
    def get_primes(self, limit: int) -> List[int]:
        is_prime = [True] * (limit + 1)
        primes = []
        for number in range(2, limit + 1):
            if not is_prime[number]:
                continue
            primes.append(number)
            for multiple in range(number * number, limit + 1, number):
                is_prime[multiple] = False
        return primes
    def powMod(self, base: int, exponent: int, mod: int) -> int:
        ans = 1
        while exponent:
            if exponent % 2 == 1:
                ans = ans * base % mod
            base = base * base % mod
            exponent //= 2
        return ans
    def maximumScore(self, nums: List[int], k: int) -> int:
        mod = int(1e9+7)
        n = len(nums)
        score = [0] * n
        max_element = max(nums)
        prime = self.get_primes(max_element)

        for i in range(n):
            num = nums[i]
            for p in prime:
                if p * p > num:
                    break
                if num % p != 0:
                    continue
                score[i] += 1
                while num % p == 0:
                    num //= p
            if num > 1:
                score[i] += 1
        # print(score)
        sta = []
        nextDominant = [n] * n
        prevDominant = [-1] * n
        for i in range(n):
            while sta and score[i] > score[sta[-1]]:
                nextDominant[sta[-1]] = i
                sta.pop()
            if sta:
                prevDominant[i] = sta[-1]
            sta.append(i)
        count = [0] * n
        for i in range(n):
            count[i] = (i - prevDominant[i]) * (nextDominant[i] - i)
        numOfOperation = []
        for i in range(n):
            numOfOperation.append((nums[i], count[i]))
        numOfOperation = sorted(numOfOperation)
        # print(numOfOperation)
        ans = 1
        while k:
            num, val = numOfOperation[-1]
            numOfOperation.pop()
            op = min(k, val)
            ans = ans * self.powMod(num, op, mod) % mod
            k -= op
        return int(ans)
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            nums = list(map(int, lines[0].split('=')[1].strip()[1:-2].split(',')))
            k = int(lines[1].split('=')[1].strip()[:-1])
            dataset.append((nums, k))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for nums, k in dataset:
        results.append(solution.maximumScore(nums, k))
    for index, result in enumerate(results):
        print(f'Example {index} : {result}')