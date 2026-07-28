import os
import sys

class Solution:
    def smallestPalindrome(self, s: str) -> str:
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - ord('a')] += 1
        mid = ''
        ans = []
        for i in range(26):
            if cnt[i] > 0:
                ans.append(chr(ord('a') + i) * (cnt[i] // 2))
            if cnt[i] % 2 == 1:
                mid = chr(ord('a') + i)
        res = ''.join(ans)
        return res + mid + res[::-1]
    
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
        results.append(solution.smallestPalindrome(s))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')