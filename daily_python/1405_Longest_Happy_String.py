import os
import sys
import heapq

class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        pq = []
        ans = ""
        if a > 0:
            heapq.heappush(pq, (-a, 'a'))
        if b > 0:
            heapq.heappush(pq, (-b, 'b'))
        if c > 0:
            heapq.heappush(pq, (-c, 'c'))
        while pq:
            count, ch = heapq.heappop(pq)
            if len(ans) >= 2 and ans[-1] == ch and ans[-2] == ch:
                if not pq:
                    break
                count2, ch2 = heapq.heappop(pq)
                heapq.heappush(pq, (count, ch))
                ans += ch2
                count2 += 1
                if count2 != 0:
                    heapq.heappush(pq, (count2, ch2))
            else:
                ans += ch
                count += 1
                if count != 0:
                    heapq.heappush(pq, (count, ch))
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            a = int(lines[0].split('=')[1].strip()[:-1])
            b = int(lines[1].split('=')[1].strip()[:-1])
            c = int(lines[2].split('=')[1].strip()[:-1])
            dataset.append((a, b, c))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for a, b, c in dataset:
        results.append(solution.longestDiverseString(a, b, c))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')