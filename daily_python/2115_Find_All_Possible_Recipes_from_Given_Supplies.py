import os
import sys
from typing import List
from collections import defaultdict, deque, defaultdict

class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        n = len(recipes)
        recipeToIndex = {recipe : idx for idx, recipe in enumerate(recipes)}
        canMade = set(supplies)
        graph = defaultdict(list)
        indegree = [0] * n
        for i in range(n):
            for ingredent in ingredients[i]:
                if ingredent not in canMade:
                    graph[ingredent].append(recipes[i])
                    indegree[i] += 1
        que = deque(idx for idx, count in enumerate(indegree) if count == 0)
        ans = []
        while que:
            curr = que.popleft()
            ans.append(recipes[curr])
            for neighbor in graph[recipes[curr]]:
                idx = recipeToIndex[neighbor]
                indegree[idx] -= 1
                if indegree[idx] == 0:
                    que.append(idx)
        return ans

def readDataSet(filename):
    dataset = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            recipes = list(lines[0].split('=')[1].strip()[2:-3].split('","'))
            ingredients = [ingredient.split('","') for ingredient in lines[1].split('=')[1].strip()[3:-4].split('"},{"')]
            supplies = list(lines[2].split('=')[1].strip()[2:-3].split('","'))
            dataset.append((recipes, ingredients, supplies))
    return dataset

if __name__ == '__main__':
    if len(sys.argv) == 1:
        filename = os.path.splitext(__file__)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataSet(filename)
    results = []
    solution = Solution()
    for recipes, ingredients, supplies in dataset:
        results.append(solution.findAllRecipes(recipes, ingredients, supplies))
    for index, result in enumerate(results):
        print(f'Example {index + 1} : {result}')