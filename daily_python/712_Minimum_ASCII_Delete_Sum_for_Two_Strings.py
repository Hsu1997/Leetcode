import sys
import os

class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)
        dp = [0] * n
        temp = [0] * n
        dp[0] = ord(s1[0]) if s1[0] == s2[0] else 0
        for j in range(1, n):
            dp[j] = max(dp[j-1], ord(s1[0]) if s1[0] == s2[j] else 0)
        for i in range(1, m):
            temp[0] = max(dp[0], ord(s1[i]) if s1[i] == s2[0] else 0)
            for j in range(1, n):
                if s1[i] == s2[j]:
                    temp[j] = dp[j-1] + ord(s1[i])
                else:
                    temp[j] = max(temp[j-1], dp[j])
            dp, temp = temp, dp
        ans = sum(ord(c) for c in s1)
        ans += sum(ord(c) for c in s2)
        return ans - 2 * dp[-1]

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s1 = lines[0].split('=')[1].strip()[1:-2]
            s2 = lines[1].split('=')[1].strip()[1:-2]
            dataset.append((s1, s2))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    for s1, s2 in dataset:
        result = []
        solution = Solution()
        results.append(solution.minimumDeleteSum(s1, s2))
    for index, result in enumerate(results):
        print(f'Example {index+1} : {result}')


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)