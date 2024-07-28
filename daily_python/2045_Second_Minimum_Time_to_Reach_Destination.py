import sys
import os
import ast
from typing import List
from heapq import heappush, heappop

class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
        e = [[] for _ in range(n)]
        for edge in edges:
            start_node = edge[0]-1
            end_node = edge[1]-1
            e[start_node].append(end_node)
            e[end_node].append(start_node)
        pq = []
        heappush(pq, (0,0))
        arrive_time = [[] for _ in range(n)]

        while pq:
            time_used, start = heappop(pq)
            if (start == n-1):
                if len(arrive_time[start]) == 0:
                    arrive_time[start].append(time_used)
                elif time_used > arrive_time[start][0]:
                    return time_used
            if (time_used // change) % 2:
                time_used = ((time_used // change) + 1) * change
            start_walking_time = time_used + time
            for neighbor in e[start]:
                if len(arrive_time[neighbor]) == 0 or (start_walking_time > arrive_time[neighbor][-1] and len(arrive_time[neighbor]) < 2):
                    heappush(pq, (start_walking_time, neighbor))
                    arrive_time[neighbor].append(start_walking_time)
        return -1

def readfiledata(filename):
    data = []
    with open(filename, 'r') as file:
        context = file.read().strip()
        blocks = context.split('\n\n')
        for block in blocks:
            lines = block.split('\n')
            n = int(lines[0].split('=')[1].strip().strip(';'))
            time = int(lines[2].split('=')[1].strip().strip(';'))
            change = int(lines[3].split('=')[1].strip().strip(';'))
            edges_str = lines[1].split('=')[1].strip().strip(';')[1:-1]
            edges_str = edges_str.replace('{','[').replace('}',']')
            edges = ast.literal_eval(edges_str)
            if all(isinstance(edge, list) for edge in edges):
                edges = list(edges)
            else:
                edges = [edges]
            data.append((n, edges, time, change))
    return data

if __name__ == '__main__':
    if (len(sys.argv) == 1):
        currfile = os.path.basename(__file__)
        # currfile = os.path.abspath(__file__)
        filename = os.path.splitext(currfile)[0] + '.txt'
    else:
        filename = sys.argv[1]
    
    dataset = readfiledata(filename)
    solution = Solution()
    results = []
    for n, edges, time, change in dataset:
        results.append(solution.secondMinimum(n, edges, time, change))
    for index, result in enumerate(results):
        print(f'Dataset {index+1} : {result}')