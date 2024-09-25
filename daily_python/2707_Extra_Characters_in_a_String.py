import os
import sys
from typing import List

class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        n = len(s)
        dp = [0] * (n+1)
        dictionary_set = set(dictionary)
        for i in range(n-1, -1, -1):
            dp[i] = dp[i+1] + 1
            for j in range(i+1, n+1):
                if s[i:j] in dictionary_set:
                    dp[i] = min(dp[i], dp[j])
        return dp[0]
    
def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            s = lines[0].split('=')[1].strip()[1:-2]
            dictionary = list(lines[1].split('=')[1].strip()[2:-3].split('","'))
            dataset.append((s, dictionary))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for s, dictionary in dataset:
        results.append(solution.minExtraChar(s, dictionary))
    for index, result in enumerate(results):
        print(f'Example : {index + 1} : {result}')