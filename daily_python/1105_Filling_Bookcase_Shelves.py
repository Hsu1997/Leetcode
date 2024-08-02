import os
import sys
from typing import List
import ast

class Solution:
    def helper(self, index, curWidth, curHeight, totalHeight) -> None:
        if index == len(self.books):
            return
        curBookWidth = self.books[index][0]
        curBookHeight = self.books[index][1]
        if curWidth + curBookWidth <= self.shelfWidth:
            AddedHeight = max(0, curBookHeight - curHeight)
            if (totalHeight + AddedHeight < self.dp[index][curWidth + curBookWidth]):
                self.dp[index][curWidth + curBookWidth] = totalHeight + AddedHeight
                self.helper(index+1, curWidth+curBookWidth, curHeight+AddedHeight, totalHeight+AddedHeight)
        if totalHeight + curBookHeight < self.dp[index][curBookWidth]:
            self.dp[index][curBookWidth] = totalHeight + curBookHeight
            self.helper(index+1, curBookWidth, curBookHeight, totalHeight + curBookHeight)

    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        self.books = books
        self.shelfWidth = shelfWidth
        self.dp = [[float('inf')] * (shelfWidth + 1) for _ in range(len(books))]
        self.helper(0, 0, 0, 0)
        return min(self.dp[-1])

def openFileData(filename: str):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            books = lines[0].split('=')[1].strip().strip(';').replace('{', '[').replace('}',']')
            books = ast.literal_eval(books)
            shelfWidth = int(lines[1].split('=')[1].strip().strip(';'))
            dataset.append((books, shelfWidth))
    return dataset

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        path = os.path.basename(__file__)
        filename = os.path.splitext(path)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = openFileData(filename)
    solution = Solution()
    results = []
    for books, shelfWidth in dataset:
        results.append(solution.minHeightShelves(books, shelfWidth))
    for index, result in enumerate(results):
        print(f'dataset {index+1} : {result}')