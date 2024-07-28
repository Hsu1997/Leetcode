from typing import List
import os
import sys

class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        INF = int(1e9 + 7)
        two_point_path = [[INF] * n for _ in range(n)]
        for i in range(n):
            two_point_path[i][i] = 0
        for start, end, weight in edges:
            two_point_path[start][end] = weight
            two_point_path[end][start] = weight
        # Floyd-Warshall Algorithm (Choose k in the middle in the path)
        self.floyd(n, two_point_path)
        return self.get_city_with_fewest_reachable(n, two_point_path, distanceThreshold)

    def floyd(self, n: int, two_point_path: List[List[float]]):
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    two_point_path[i][j] = min(two_point_path[i][j], two_point_path[i][k] + two_point_path[k][j])

    def get_city_with_fewest_reachable(self, n: int, two_point_path: List[List[int]], distanceThreshold: int) -> int:
        most_isolate = -1
        minimum = int(1e9+7)
        for i in range(n):
            count = 0
            for j in range(n):
                if i == j:
                    continue
                if two_point_path[i][j] != int(1e9+7) and two_point_path[i][j] <= distanceThreshold:
                    count += 1
            if count <= minimum:
                most_isolate = i
                minimum = count
        return most_isolate        

def readDataFromFile(filename: str):
    data = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        blocks = content.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0])
            edges = []
            for line in lines[1:-1]:
                u, v, w = map(int, line.split())
                edges.append([u, v, w])
            distanceThreshold = int(lines[-1])
            data.append((n, edges, distanceThreshold))
    return data

if __name__ == "__main__":
    # filename = '1334_Find_the_City_With_the_Smallest_Number_of_Neighbors_at_a_Threshold_Distance.txt'
    if len(sys.argv) == 1:
        current_script = os.path.basename(__file__)
        filename = os.path.splitext(current_script)[0] + '.txt'
    else:
        filename = sys.argv[1]
    dataset = readDataFromFile(filename)
    solution = Solution()
    results = []
    for n, edges, distanceThreshold in dataset:
        result = solution.findTheCity(n, edges, distanceThreshold)
        results.append(result)
    for i, result in enumerate(results):
        print(f"Result for dataset {i+1} : {result}")